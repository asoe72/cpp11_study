#include "../stdafx.h"
#include <thread>
#include "AtomicFixture.h"


void async_write_foo(int thread_no, AtomicFixture* afp)
{
	for (int i = 0; ; i++)
	{
		BigFoo foo_for_init(i);
		afp->foo = foo_for_init;

		if (afp->req_end_write) break;
	}
}


void async_read_foo(int thread_no, AtomicFixture* afp)
{
	for (int i = 0; i < 10000; i++)
	{
		BigFoo foo = afp->foo;
		if (foo.all_data_same()==false) {
			printf("[thread %d] data integrity broken!! (i=%d)\r\n", thread_no, i);
		}
	}
}


// --------------------------------------------------------
void sync_write_foo(int thread_no, AtomicFixture* afp)
{
	for (int i = 0; ; i++)
	{
		BigFoo foo_for_init(i);
		afp->atomic_foo = foo_for_init;

		if (afp->req_end_write) break;
	}
}


void sync_read_foo(int thread_no, AtomicFixture* afp)
{
	for (int i = 0; i < 10000; i++)
	{
		BigFoo foo = afp->atomic_foo;
		if (foo.all_data_same() == false) {
			printf("[thread %d] data integrity broken!! (i=%d)\r\n", thread_no, i);
		}
	}
}


// --------------------------------------------------------
void sync_write_foo2(int thread_no, AtomicFixture* afp)
{
	for (int i = 0;; i++)
	{
		BigFoo2 foo2(i, i);
		afp->atomic_foo2 = foo2;
			// overriding �� operator=()�� ȣ��Ǵ°� �ƴ϶�,
			// memory ���縦 �����ϴ� ���� �ڵ尡 �����.
			// memory ���簡 �Ұ��� Ŭ������ atomic ��� �Ұ�. mutex�� ���°� �´�.

		if (afp->req_end_write) break;
	}
}


void sync_read_foo2(int thread_no, AtomicFixture* afp)
{
	for (int i = 0; i < 10000; i++)
	{
		BigFoo2 foo = afp->atomic_foo2;
		if (foo.check_integrity() == false) {
			printf("[thread %d] data integrity broken!! (i=%d)\r\n", thread_no, i);
		}
	}
}


// --------------------------------------------------------
int AtomicFixture::test_async()
{
	printf("-----------------------------------------------\r\n");
	printf("AtomicFixture::test_async() \r\n");
	printf("-----------------------------------------------\r\n");

	req_end_write = false;
	std::thread th1(async_write_foo, 1, this);
	std::thread th2(async_read_foo, 2, this);
		
	th2.join();
	req_end_write = true;
	th1.join();

	return 0;
}


int AtomicFixture::test_sync()
{
	printf("-----------------------------------------------\r\n");
	printf("AtomicFixture::test_sync() \r\n");
	printf("-----------------------------------------------\r\n");

	req_end_write = false;
	std::thread th1(sync_write_foo, 1, this);
	std::thread th2(sync_read_foo, 2, this);

	th2.join();
	req_end_write = true;
	th1.join();

	return 0;
}


int AtomicFixture::test_sync2()
{
	printf("-----------------------------------------------\r\n");
	printf("AtomicFixture::test_sync2() \r\n");
	printf("-----------------------------------------------\r\n");

	req_end_write = false;
	std::thread th1(sync_write_foo2, 1, this);
	std::thread th2(sync_read_foo2, 2, this);

	th2.join();
	req_end_write = true;
	th1.join();

	return 0;
}

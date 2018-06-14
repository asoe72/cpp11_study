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

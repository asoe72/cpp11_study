#include <atomic>


class BigFoo
{
public:
	static const int data_size = 10000;
	BigFoo() {
		for (int i = 0; i < data_size; i++)
		{
			data[i] = 0;
		}
	};

	BigFoo(int init_val) {
		for (int i = 0; i < data_size; i++)
		{
			data[i] = init_val;
		}
	};

	bool all_data_same() const
	{
		for (int i = 1; i < data_size; i++)
		{
			if (data[i] != data[i-1]) {
				return false;
			}
		}
		return true;
	};

	int data[data_size];
};


// --------------------------------------------------------
class BigFoo2
{
public:
	BigFoo2()
		: data1(0), data2(0){}

	BigFoo2(int dt1, int dt2)
		: data1(dt1), data2(dt2){}
	

	BigFoo2& operator=(const BigFoo2& rhs)
	{
		data1 = rhs.data1;
		data2 = rhs.data2;
	};


	bool check_integrity() const
	{
		return(data1 == data2);
	};

	int data1 = 0;
	int data2 = 0;
};


// --------------------------------------------------------
class AtomicFixture
{
public:
	int test_async();
	int test_sync();
	int test_sync2();

public:
	BigFoo foo;
	BigFoo2 foo2;
	bool req_end_write = false;
	std::atomic<BigFoo> atomic_foo;
	std::atomic<BigFoo2> atomic_foo2;
};

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


class AtomicFixture
{
public:
	int test_async();
	int test_sync();

public:
	BigFoo foo;
	bool req_end_write = false;
	std::atomic<BigFoo> atomic_foo;
};

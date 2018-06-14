#include <atomic>


struct FooStruct
{
	int data1;
	int data2;
};


class FooWithoutCtor
{
public:
	int data1 = 1;
	int data2 = 2;
};


class FooWithCtor
{
public:
	FooWithCtor()
		: data1(3), data2(4)
	{}


	FooWithCtor(int _data1, int _data2)
		: data1(_data1), data2(_data2)
	{}

public:
	int data1 = 1;
	int data2 = 2;
};


class UniformInitFixture
{
public:
	int test();

private:
	std::atomic<int> atomic_int_ = 3;

	FooStruct fs0;
	//FooStruct fs1{ 11, 11 };		// list initialization 
	//FooStruct fs2 = { 12, 12 };	// list initialization 
	//FooStruct fs3(13, 13);		// expected type specifier

	FooWithoutCtor fwoc0;
	//FooWithoutCtor fwoc1{ 11, 11 };		// argument list
	//FooWithoutCtor fwoc2 = { 12, 12 };	// argument list
	//FooWithoutCtor fwoc3(13, 13);			// expected type specifier

	FooWithCtor fwc0;
	FooWithCtor fwc1{ 21, 21 };
	FooWithCtor fwc2 = { 22, 22 };
	//FooWithCtor fwc3(23, 23);			// expected type specifier

	// uncopyable
	std::atomic<FooStruct> afs0;
	std::atomic<FooWithoutCtor> afwoc0;
	std::atomic<FooWithCtor> afwc0;
	//std::atomic<FooWithCtor> afwc1{ 21, 21 };		// argument list
	//std::atomic<FooWithCtor> afwc2 = { 22, 22 };	// argument list
};

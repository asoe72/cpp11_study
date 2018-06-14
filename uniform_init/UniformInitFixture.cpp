#include "../stdafx.h"
#include "UniformInitFixture.h"


int UniformInitFixture::test()
{
	printf("-----------------------------------------------\r\n");
	printf("AtomicFixture::test_init() \r\n");
	printf("-----------------------------------------------\r\n");
	printf("atomic_int_=%d \r\n", atomic_int_);
	
	printf("fs0= { %d, %d } \r\n", fs0.data1, fs0.data2);	// garbage
	printf("fwoc0= { %d, %d } \r\n", fwoc0.data1, fwoc0.data2);	// 1, 2
	printf("fwc0= { %d, %d } \r\n", fwc0.data1, fwc0.data2);	// 3, 4
	printf("fwc1= { %d, %d } \r\n", fwc1.data1, fwc1.data2);	// 21, 21
	printf("fwc2= { %d, %d } \r\n", fwc2.data1, fwc2.data2);	// 22, 22

	FooStruct fs = afs0;
	printf("aus0= { %d, %d } \r\n", fs.data1, fs.data2);
	FooWithoutCtor fwoc0 = afwoc0;
	printf("afwoc0= { %d, %d } \r\n", fwoc0.data1, fwoc0.data2);
	FooWithCtor fwc0 = afwc0;
	printf("afwc0= { %d, %d } \r\n", fwc0.data1, fwc0.data2);

	return 0;
}

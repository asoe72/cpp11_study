#include "AutoFixture.h"
#include <initializer_list>


int AutoFixture::test()
{
	auto x1 = 27;
	auto x2(27);
	auto x3 = { 27 };
	auto x4{ 27 };
	//auto x5 = { 1, 2, 3.0 };	// compile-error

	return 0;
}

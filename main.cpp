#include "stdafx.h"

#include "rvalue_ref/RValueRefFixture.h"
#include "auto/AutoFixture.h"


int rvalue_ref_test();


int main(int argc, char* argv[])
{
	RValueRefFixture rvr_fx;
	rvr_fx.test();

	AutoFixture auto_fx;
	auto_fx.test();

	return 0;
}


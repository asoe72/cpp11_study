#include "stdafx.h"

#include "rvalue_ref/RValueRefFixture.h"
#include "auto/AutoFixture.h"
#include "uniform_init/UniformInitFixture.h"
#include "atomic/AtomicFixture.h"


int rvalue_ref_test();


int main(int argc, char* argv[])
{
	RValueRefFixture rvr_fx;
	rvr_fx.test();

	AutoFixture auto_fx;
	auto_fx.test();

	UniformInitFixture uniform_init;
	uniform_init.test();

	AtomicFixture atomic_fx;
	atomic_fx.test_async();
	atomic_fx.test_sync();


	return 0;
}


#include "BigObject.h"
#include "ObjectFactory.h"
#include "RValueRefFixture.h"


int RValueRefFixture::test()
{
	creator_test();
	creator_with_factory_test();
	assignment_test();
	assignment_with_factory_test();

	return 0;
}


int RValueRefFixture::creator_test()
{
	// 생성자 호출
	BigObject big_obj1(1000, 1);

	// 생성자 호출
	BigObject big_obj2(BigObject(1000, 2));

	// 복사생성자 호출
	BigObject big_obj3(big_obj1);

	// 이동생성자 호출
	BigObject big_obj4({ 1000, 4 });

	// 이동생성자 호출
	BigObject big_obj5(std::move(big_obj1));

	return 0;
}


int RValueRefFixture::creator_with_factory_test()
{
	ObjectFactory object_factory;

	// 복사생성자 호출
	BigObject big_obj1(object_factory.make_object("BigObject"));

	// 이동생성자 호출
	BigObject big_obj2(std::move(object_factory.make_object("BigObject")));

	return 0;
}


int RValueRefFixture::assignment_test()
{
	BigObject big_obj1(3, 1);

	// 이동 대입연산자
	big_obj1 = BigObject(6, 2);

	// ? 대입연산자
	BigObject big_obj3(9, 3);
	big_obj1 = big_obj3;

	return 0;
}


int RValueRefFixture::assignment_with_factory_test()
{
	ObjectFactory object_factory;

	BigObject big_obj1(3, 1);

	// 복사 대입연산자
	big_obj1 = object_factory.make_object("BigObject");

	// 이동 대입연산자
	big_obj1 = std::move(object_factory.make_object("BigObject"));
		

	return 0;
}

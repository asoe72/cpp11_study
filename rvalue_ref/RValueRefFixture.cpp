#include "BigObject.h"
#include "ObjectFactory.h"
#include "RValueRefFixture.h"


int RValueRefFixture::test()
{
	creator_test();
	creator_with_factory_test();
	assignment_test();
	assignment_with_factory_test();
	func_param_test();
	func_param_forward_test();

	return 0;
}


int RValueRefFixture::creator_test()
{
	// 생성자 호출
	BigObject big_obj1(1000, 1);

	// 생성자 미호출 (최적화에 의해 생략?)
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

	// 복사 대입연산자
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


int RValueRefFixture::func_param_test()
{
	BigObject big_obj1(10, 100);
	
	// 복사 전달
	auto sz1 = get_size(big_obj1);

	// 이동 전달
	auto sz2 = get_size(BigObject(20, 200));

	// 이동 전달
	auto sz3 = get_size({ 30, 300 });

	return sz1 + sz2 + sz3;
}


int RValueRefFixture::func_param_forward_test()
{
	BigObject big_obj1(10, 100);

	// 복사 전달
	auto sz1 = func_call_copy(big_obj1);

	// 복사 전달
	auto sz2 = func_call_copy(BigObject(20, 200));

	// 복사 전달
	auto sz3 = func_call_forward(big_obj1);

	// 이동 전달
	auto sz4 = func_call_forward(BigObject(20, 200));

	return sz1 + sz2 + sz3 + sz4;
}


// 복사 오버로딩
int RValueRefFixture::get_size(const BigObject& rhs)
{
	return rhs.size();
}


// 이동 오버로딩
int RValueRefFixture::get_size(BigObject&& rhs)
{
	return rhs.size();
}

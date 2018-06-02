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
	// ������ ȣ��
	BigObject big_obj1(1000, 1);

	// ������ ȣ��
	BigObject big_obj2(BigObject(1000, 2));

	// ��������� ȣ��
	BigObject big_obj3(big_obj1);

	// �̵������� ȣ��
	BigObject big_obj4({ 1000, 4 });

	// �̵������� ȣ��
	BigObject big_obj5(std::move(big_obj1));

	return 0;
}


int RValueRefFixture::creator_with_factory_test()
{
	ObjectFactory object_factory;

	// ��������� ȣ��
	BigObject big_obj1(object_factory.make_object("BigObject"));

	// �̵������� ȣ��
	BigObject big_obj2(std::move(object_factory.make_object("BigObject")));

	return 0;
}


int RValueRefFixture::assignment_test()
{
	BigObject big_obj1(3, 1);

	// �̵� ���Կ�����
	big_obj1 = BigObject(6, 2);

	// ? ���Կ�����
	BigObject big_obj3(9, 3);
	big_obj1 = big_obj3;

	return 0;
}


int RValueRefFixture::assignment_with_factory_test()
{
	ObjectFactory object_factory;

	BigObject big_obj1(3, 1);

	// ���� ���Կ�����
	big_obj1 = object_factory.make_object("BigObject");

	// �̵� ���Կ�����
	big_obj1 = std::move(object_factory.make_object("BigObject"));
		

	return 0;
}

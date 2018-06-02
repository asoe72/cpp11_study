#include "../stdafx.h"
#include "BigObject.h"
#include "ObjectFactory.h"

using std::string;


BigObject& ObjectFactory::make_object(const string& type)
{
	if (type == "BigObject")
	{
		auto objp = new BigObject(1000, 6);
		return *objp;
	}
	else
	{
		auto objp = new BigObject(1, 0);
		return *objp;
	}
}

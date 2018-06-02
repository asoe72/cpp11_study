#include <string>


class BigObject;


class ObjectFactory
{
public:
	BigObject& make_object(const std::string& type);
};

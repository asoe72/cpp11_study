#include "../stdafx.h"
#include <utility>
#include "BigObject.h"


BigObject::BigObject(int size, int offset)
	: size_(size)
	, big_data(new int[size])
{
	for (int i = 0; i < size; i++)
	{
		big_data[i] = offset+i;
	}
}


/// @brief		복사생성자
BigObject::BigObject(const BigObject& rhs)
	: size_(rhs.size())
	, big_data(new int[rhs.size()])
{
	auto sz = sizeof(int) * size_;
	
	memcpy(big_data, rhs.big_data, sz);
}


/// @brief		이동생성자
BigObject::BigObject(BigObject&& rhs)
	: size_(0)
	, big_data(NULL)
{
	std::swap(size_, rhs.size_);
	std::swap(big_data, rhs.big_data);
}


BigObject::~BigObject()
{
	if (big_data) {
		delete[] big_data;
	}
}


// ----------------------------------------------
/// @brief		복사 대입연산자
BigObject& BigObject::operator = (const BigObject& rhs)
{
	delete[] big_data;
	
	size_ = rhs.size();
	big_data = new int[size_];
	auto sz = sizeof(int) * rhs.size();

	memcpy(big_data, rhs.big_data, sz);

	return *this;
}


/// @brief		이동 대입연산자
BigObject& BigObject::operator = (BigObject&& rhs)
{
	std::swap(size_, rhs.size_);
	std::swap(big_data, rhs.big_data);

	return *this;
}

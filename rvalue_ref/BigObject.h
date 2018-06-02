
class BigObject
{
public:
	BigObject(int size, int offset);
	BigObject(const BigObject& rhs);
	BigObject(BigObject&& rhs);
	~BigObject();

	BigObject& operator = (const BigObject& rhs);
	BigObject& operator = (BigObject&& rhs);
	
	int size() const { return size_; }

private:
	int size_;
	int* big_data;
};

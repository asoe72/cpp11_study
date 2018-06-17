
class BigObject;

class RValueRefFixture
{
public:
	int test();

protected:
	int creator_test();
	int creator_with_factory_test();
	int assignment_test();
	int assignment_with_factory_test();
	int func_param_test();
	int func_param_forward_test();

protected:
	int get_size(const BigObject& rhs);
	int get_size(BigObject&& rhs);
	
	template<typename T>
	int func_call_copy(T&& rhs) {
		return get_size(rhs);
	}

	template<typename T>
	int func_call_forward(T&& rhs) {
		return get_size(std::forward<T>(rhs));
	}
};

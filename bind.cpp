// std::bind()

int sum(int a, int b)
{
	return a+b;
}

auto func = std::bind(sum, std::placeholder::_1, std::placeholder::_2);

int re = func(10, 20);

/*
10이 a로 들어가고
20이 b로 들어감
*/

auto func2 = std::bind(sum, 10, std::placeholder::_1);
int re2 = func(20);


////////////////////////////////////////////////////////////

class A {
public:
	int sum(int a, int b) {
		return a+b;
	}
	
	void bindFunc(std::function<int(int, int)>& func) {
		func = std::bind(&A::sum, this, std::placeholder::_1, std::placeholder::_2);	
	}
}

A a;

auto func;		// std::function<int(int, int)> func;
a.bindFunc(func);
func(10, 20);



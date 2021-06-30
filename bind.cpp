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

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
//using namespace std;

int main()
{

	// vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> vec1(nums, nums+10);	// 범위를 줌
	
//	vector<int> vec2(10, 0 ); 		// size 10인데 0으로 모두 채움
//	vector<int> vec3;				// default 생성
//	vector<int> vec4 = vec1;		// 복사생성자
//	vector<int> vec5(vec1.begin(), vec1.begin() + 5);


//	for (int i=0; i != vec1.size(); ++i)
	for (vector<int>::size_type i=0; i != vec1.size(); ++i)
		cout << vec1[i] * vec1[i] << endl;
	

	return 0;
}

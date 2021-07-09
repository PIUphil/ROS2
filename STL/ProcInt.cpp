// proc_int  프로시져 인트 procedure int 순차적 정수
// 반복문 써서 같은 타입의 자료를 입력.출력할 때
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::back_inserter;
using std::copy;
using std::istream_iterator;
using std::ostream_iterator;


int main() {
    vector<int> nums;
    int num;
//    while (cin >> num)
//        nums.push_back(num);

    copy(istream_iterator<int>(cin),  istream_iterator<int>(),back_inserter(nums));
    // istream_iterator<int>(cin) : int형 자료를 연속적으로 받을 때 사용
    // istream_iterator<int>() : 생성자를 호출하면 마지막 위치를 의미함


//    for(vector<int>::const_iterator iter = nums.cbegin() ; iter!=nums.cend() ; ++iter)
//        cout << *iter << " "

    copy(nums.cbegin(), nums.cend(), ostream_iterator<int>(cout, " "));  // " " : 구분자

    cout << endl;

    return 0;
}


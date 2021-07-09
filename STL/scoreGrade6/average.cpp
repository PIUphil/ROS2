#include <vector>
#include <stdexcept>
#include <numeric>

#include "average.h"

using std::vector;
using std::accumulate;
using std::domain_error;


double average(const vector<double>& vec)
{
	if (vec.size()==0) {
		// throw 0;
		throw domain_error("vector is empty");
	}
	
//	double sum = 0.0;

//	for(vector<double>::size_type i=0 ; i!=vec.size() ; ++i)
//		sum += vec[i];

    double sum = accumulate(vec.cbegin(), vec.cend(), 0.0);  // accumulate  누적합계 (시작, 끝, 초기값)

	return sum / vec.size();
}


#include <algorithm>

#include "StringPic.h"

using std::max;
using std::string;

StringPic::StringPic(const std::vector<std::string>& rhs)
    : data_(rhs)        // 복사생성자가 호출이되어 초기화
{}

PicBase::hsize_type StringPic::width() const
{
    string::size_type maxLen = 0;
    for(auto iter = data_.cbegin() ; iter!=data_.cend() ; ++iter)
    {
        maxLen = max(maxLen, iter->size());
    }

    return maxLen;
}

PicBase::vsize_type StringPic::height() const
{
    return data_.size();
}

void StringPic::display(std::ostream& out, vsize_type row, bool isPad) const
{
    PicBase::hsize_type start = 0;
    if (row < this->height())
    {
        out << data_[row];
        start = data_[row].size();
    }

    if (isPad)
        PicBase::pad(out, start, this->width());
}

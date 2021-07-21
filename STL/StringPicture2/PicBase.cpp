#include "PicBase.h"

void PicBase::pad(std::ostream& out, hsize_type begin, hsize_type end)
{
//    while(begin != end)
//    {
//        out << " ";
//        ++begin;
//    }

    //out << std::string(end-begin, ' ');
    out << Str(end-begin, ' ');
}
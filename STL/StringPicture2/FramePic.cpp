#include "FramePic.h"

FramePic::FramePic(const Handle<PicBase>& rhs)
    : hPic_(rhs)
{}


PicBase::hsize_type FramePic::width() const
{
    return hPic_->width() + 4;
}

PicBase::vsize_type FramePic::height() const
{
    return hPic_->height() + 4;
}

void FramePic::display(std::ostream& out, vsize_type row, bool isPad) const
{
    if (row >= height())
    {
        if(isPad)
            PicBase::pad(out, 0, this->width());
    }

    else
    {
        if(row==0 || row==this->height()-1)
        {
//            out << std::string(this->width(), '*');
            out << Str(this->width(), '*');

        }
        else if (row==1 || row==this->height()-2)
        {
            out << "*";
            PicBase::pad(out, 1, this->width() - 1);
            out << "*";
        }
        else
        {
            out << "* ";
            this->hPic_->display(out, row-2, true);
            out << " *";
        }
    }
}
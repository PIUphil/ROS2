#include <algorithm>

#include "VCatPic.h"


VCatPic::VCatPic(const Handle<PicBase>& hTop, const Handle<PicBase>& hBottom)
    : hTop_(hTop) , hBottom_(hBottom)            // shallow_copy
{}

PicBase::hsize_type VCatPic::width() const
{
    return std::max(hTop_->width(), hBottom_->width());
}

PicBase::vsize_type VCatPic::height() const
{
    return hTop_->height() + hBottom_->height();
}

void VCatPic::display(std::ostream& out, vsize_type row, bool isPad) const
{
    PicBase::hsize_type i = 0;

    if(row < hTop_->height())
    {
        hTop_->display(out, row, isPad);
        i = hTop_->width();
    }
    else if (row < this->height())
    {
        hBottom_->display(out, row-hTop_->height(), isPad);
        i = hBottom_->width();
    }

    if (isPad)
        PicBase::pad(out, i, this->width());

}

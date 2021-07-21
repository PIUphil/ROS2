#include <algorithm>

#include "HCatPic.h"


HCatPic::HCatPic(const Handle<PicBase>& hLeft, const Handle<PicBase>& hRight)
    :hLeft_(hLeft), hRight_(hRight)
{}


PicBase::hsize_type HCatPic::width() const
{
    return hLeft_->width() + hRight_->width();
}

PicBase::vsize_type HCatPic::height() const
{
    return std::max(hLeft_->height(), hRight_->height());
}

void HCatPic::display(std::ostream& out, vsize_type row, bool isPad) const
{
    hLeft_->display(out, row, isPad || row < hRight_->height());
    hRight_->display(out, row, isPad);
}

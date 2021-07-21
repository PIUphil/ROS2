#include "Picture.h"
#include "FramePic.h"
#include "HCatPic.h"
#include "VCatPic.h"
#include "StringPic.h"


std::ostream& operator<<(std::ostream& out, const Picture& rhs)
{
    const PicBase::vsize_type height = rhs.hPic_->height();

    for(PicBase::vsize_type i=0 ; i!=height ; ++i)
    {
        rhs.hPic_->display(out, i, false);
        out << std::endl;
    }

    return out;
}


Picture Picture::frame(const Picture& pic)
{
    return new FramePic(pic.hPic_);
}

//Picture Picture::reframe(const Picture& pic)
//{
//    return new FramePic(pic.hPic_);
//}


Picture Picture::hcat(const Picture& pic1, const Picture& pic2)
{
    return new HCatPic(pic1.hPic_, pic2.hPic_);
}

Picture Picture::vcat(const Picture& pic1, const Picture& pic2)
{
    return new VCatPic(pic1.hPic_, pic2.hPic_);
}


Picture::Picture(PicBase *hPic)
    : hPic_(hPic)
{}

//Picture::Picture(const std::vector<std::string>& pic)
//    : hPic_(new StringPic(pic))
//{}
Picture::Picture(const Vec<Str>& pic)
    : hPic_(new StringPic(pic))
{}
#ifndef STRINGPICTURE_HCATPIC_H
#define STRINGPICTURE_HCATPIC_H

#include "Handle.h"
#include "PicBase.h"


class HCatPic : public PicBase {
friend class Picture;

public:
    virtual ~HCatPic() {}

    virtual PicBase::hsize_type width() const;
    virtual PicBase::vsize_type height() const;
    virtual void display(std::ostream& out, vsize_type row, bool isPad) const;

private:
    Handle<PicBase> hLeft_;
    Handle<PicBase> hRight_;


    HCatPic(const Handle<PicBase>& hLeft, const Handle<PicBase>& hRight);


};


#endif //STRINGPICTURE_HCATPIC_H

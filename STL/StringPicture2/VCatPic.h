#ifndef STRINGPICTURE_VCATPIC_H
#define STRINGPICTURE_VCATPIC_H

#include "Handle.h"
#include "PicBase.h"


class VCatPic : public PicBase {
friend class Picture;

public:
    virtual ~VCatPic() {}

    virtual PicBase::hsize_type width() const;
    virtual PicBase::vsize_type height() const;
    virtual void display(std::ostream& out, vsize_type row, bool isPad) const;

private:
    Handle<PicBase> hTop_;
    Handle<PicBase> hBottom_;

    VCatPic(const Handle<PicBase>& hTop, const Handle<PicBase>& hBottom);

};


#endif //STRINGPICTURE_VCATPIC_H

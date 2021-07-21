#ifndef STRINGPICTURE_FRAMEPIC_H
#define STRINGPICTURE_FRAMEPIC_H

#include "PicBase.h"
#include "Handle.h"
//#include "Picture.h"


class FramePic : public PicBase {
friend class Picture;

public:


    virtual ~FramePic() {}

    virtual PicBase::hsize_type width() const;
    virtual PicBase::vsize_type height() const;
    virtual void display(std::ostream& out, vsize_type row, bool isPad) const;

    static void reframe(char ch);


private:

    static char boarderChar;

    FramePic(const Handle<PicBase>& rhs);

    Handle<PicBase> hPic_;          // PicBase로 해두면, 다른 자식들도 가리킬 수 있음
};


#endif //STRINGPICTURE_FRAMEPIC_H

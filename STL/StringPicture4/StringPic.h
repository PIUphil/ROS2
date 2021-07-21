#ifndef STRINGPICTURE_STRINGPIC_H
#define STRINGPICTURE_STRINGPIC_H

#include <iostream>
//#include <vector>
//#include <string>

#include "PicBase.h"
#include "Vec.h"
#include "Str.h"


class StringPic : public PicBase {
//friend class Picture;

public:
    virtual ~StringPic() {}

    virtual PicBase::hsize_type width() const;
    virtual PicBase::vsize_type height() const;
    virtual void display(std::ostream& out, vsize_type row, bool isPad) const;

    StringPic(const Vec<Str>& rhs);

private:
    Vec<Str> data_;

    // 복사생성자, 치환연산, 소멸자는 그냥 씀,,


};


#endif //STRINGPICTURE_STRINGPIC_H

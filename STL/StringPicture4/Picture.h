#ifndef STRINGPICTURE_PICTURE_H
#define STRINGPICTURE_PICTURE_H

#include <iostream>
//#include <vector>
//#include <string>

#include "Handle.h"
#include "PicBase.h"
#include "Vec.h"
#include "Str.h"
#include "Student_info.h"


class Picture {         // 핸들클래스
friend std::ostream& operator<<(std::ostream& out, const Picture& rhs);

public:
    static Picture frame(const Picture& pic);
    static Picture hcat(const Picture& pic1, const Picture& pic2);
    static Picture vcat(const Picture& pic1, const Picture& pic2);

    static void reframe(char ch);

    Picture(PicBase *hPic);
    Picture(const Vec<Str>& pic = Vec<Str>());       // default


private:
    Handle<PicBase> hPic_;
};



#endif //STRINGPICTURE_PICTURE_H

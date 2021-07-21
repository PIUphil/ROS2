#ifndef STRINGPICTURE_PICBASE_H
#define STRINGPICTURE_PICBASE_H

#include <iostream>
//#include <string>
//#include <vector>
#include "Vec.h"
#include "Str.h"

// 순수가상함수만 가지는 클래스 --> 자바에선 '인터페이스'라고 함 - 함수들의 동작(behavior)만 가짐

class PicBase {             // 추상기저클래스(ABC)
//friend class Picture;
//friend class HCatPic;
//friend class VCatPic;
//friend class FramePic;
//class Picture;
//friend std::ostream& operator<<(std::ostream& out, const Picture& rhs);


public:
typedef Str::size_type hsize_type;
typedef Vec<Str>::size_type vsize_type;

    static void pad(std::ostream& out, hsize_type begin, hsize_type end);

    virtual ~PicBase() {}

    virtual hsize_type width() const = 0;       // 순수가상함수
    virtual vsize_type height() const = 0;
    virtual void display(std::ostream& out, vsize_type row, bool isPad) const = 0;

private:


};


#endif //STRINGPICTURE_PICBASE_H

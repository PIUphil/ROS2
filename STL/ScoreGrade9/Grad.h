#ifndef SCOREGRADE9_GRAD_H
#define SCOREGRADE9_GRAD_H


#include "Core.h"

class Grad : public Core {
public:
    Grad();
    Grad(std::istream& in);

    std::istream& read(std::istream& in);
    double grade() const;

private:
    double thesis_;

};


#endif //SCOREGRADE9_GRAD_H

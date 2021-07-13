#ifndef SCOREGRADE9_CORE_H
#define SCOREGRADE9_CORE_H


#include <iostream>
#include <string>
#include <vector>


std::istream& read_hw(std::istream& in, std::vector<double>& homeworks);


class Core {
public:
    Core();
    Core(std::istream& in);
    std::istream& read(std::istream& in);

    std::string name() const;
    double grade() const;


protected:
    double midterm_;
    double finalterm_;
    std::vector<double> homeworks_;

    std::istream& read_common(std::istream& in);

private:
    std::string name_;

};


#endif //SCOREGRADE9_CORE_H

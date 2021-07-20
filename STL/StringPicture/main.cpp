#include <iostream>
#include <vector>
#include <string>

#include "Picture.h"

using namespace std;


int main()
{
    vector<string> words;
    words.push_back("wonderful tonight");
    words.push_back("just the way you are");
    words.push_back("butter");
    words.push_back("knockin on the heaven's door");

    Picture pic = words;
    cout << pic;

    Picture pic2 = Picture::frame(pic);
    cout << pic2;

    Picture pic3 = Picture::vcat(pic, pic2);
    cout << pic3;

    Picture pic4 = Picture::hcat(pic, pic2);
    cout << pic4;

    return 0;
}

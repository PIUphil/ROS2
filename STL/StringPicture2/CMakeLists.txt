cmake_minimum_required(VERSION 3.19)
project(StringPicture2)

set(CMAKE_CXX_STANDARD 14)

add_executable(StringPicture2 main.cpp PicBase.cpp PicBase.h StringPic.cpp StringPic.h VCatPic.cpp VCatPic.h HCatPic.cpp HCatPic.h FramePic.cpp FramePic.h Picture.cpp Picture.h Vec.h Str.h Str.cpp Handle.cpp)
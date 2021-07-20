cmake_minimum_required(VERSION 3.19)
project(StringPicture)

set(CMAKE_CXX_STANDARD 14)

add_executable(StringPicture main.cpp PicBase.cpp PicBase.h StringPic.cpp StringPic.h VCatPic.cpp VCatPic.h HCatPic.cpp HCatPic.h FramePic.cpp FramePic.h Picture.cpp Picture.h)
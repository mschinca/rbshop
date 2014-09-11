#ifndef IMAGE_H
#define IMAGE_H 1

#include "rbshop.h"

void rbshop_init_image();

//load an image: class method
// function declaration
VALUE rbshop_image_load(VALUE klass, VALUE rb_path); //2nd: ruby type

#endif /* IMAGE_H */

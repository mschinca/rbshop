#ifndef IMAGE_H
#define IMAGE_H 1

#include "rbshop.h"

void rbshop_init_image();
void rbshop_image_free(MagickWand *wand);


//load an image: class method
// function declaration
VALUE rbshop_image_load(VALUE klass, VALUE rb_path); //2nd: ruby type
VALUE rbshop_image_get_width(VALUE self);
VALUE rbshop_image_get_height(VALUE self);

#endif /* IMAGE_H */

#include "image.h"

extern VALUE rb_mRbshop; /* it's a ruby type, defined in rbshop.c */

VALUE rb_cRbshopImage;

/* we have a module, we need to define a class inside the module */
void rbshop_init_image(){
  rb_cRbshopImage = rb_define_class_under(
    rb_mRbshop, // the module where it's defined
    "Image",  // the name of the class
    rb_cObject  //The class parent, it inherhits from Object
  );

  //load class methods
  // Rbshop::Image.load(path)

  rb_define_singleton_method(
    rb_cRbshopImage,   // where I define this,
    "load",            //method name
    rbshop_image_load, //what c function do I call
    1                  // number of arguments
  );

}

VALUE
rbshop_image_load(VALUE klass, VALUE rb_path){
  return rb_path;
}


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

  //Rbshop::Image#width
  rb_define_method(
    rb_cRbshopImage,  //where I define this
    "width", //method name in ruby
    rbshop_image_get_width, //what C function
    0
  );
}

void rbshop_image_free(MagickWand *wand){
  DestroyMagickWand(wand);
}

VALUE
rbshop_image_load(VALUE klass, VALUE rb_path){
  // insert a type check, it is a macro
  Check_Type(rb_path, T_STRING);

  // get the path as C string
  char *path;
  path = StringValueCStr(rb_path); // give me the c address of where the var lives

  //we have the  path, now we load the image
  //initialize the GraphicsMagick handler
  MagickWand *wand;
  wand = NewMagickWand();

  //load the image
  if(!MagickReadImage(wand, path)){
    DestroyMagickWand(wand);  // freeing memory, if read fails I have to clean memory
    return Qnil;
  }

  //I have a C type, which is still useless
  //I need to wrap a Ruby object with our C type

  VALUE instance;
  instance = Data_Wrap_Struct(
    rb_cRbshopImage,   //the type of the instance
    0,                 //GC mark function, telling the GC not to clean this object up
    rbshop_image_free, //GC callback
    wand //I'm wrapping the wand library
    );
  return instance;
}


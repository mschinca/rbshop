#include "rbshop.h"

VALUE rb_mRbshop;

void
Init_rbshop(void)
{
  rb_mRbshop = rb_define_module("Rbshop");

  //define and initialize the Image class
  rbshop_init_image();
}

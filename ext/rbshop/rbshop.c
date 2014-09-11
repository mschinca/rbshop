#include "rbshop.h"

VALUE rb_mRbshop;

void
Init_rbshop(void)
{
  rb_mRbshop = rb_define_module("Rbshop");
}

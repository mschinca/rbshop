require "mkmf" #bunch of ruby files to manage dependencies

pkg_config("GraphicsMagickWand")
create_makefile("rbshop")

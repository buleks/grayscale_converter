#include "ImageBuilder.h"
#include <iostream>


bool ImageBuilder::readfile(std::string img_filename)
{
	bitmap = FreeImage_Load(FIF_JPEG,img_filename.c_str(),BMP_DEFAULT);
	if(!bitmap)
	{
		std::cout<<"Cannot open image file:"<<img_filename;
		return false;
	}
	return true;
}

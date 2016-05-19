#include "ImagePNG.h"

void ImagePNG::save(std::string name)
{
	FreeImage_Save(FIF_PNG,bitmap,name.c_str(),0);
}

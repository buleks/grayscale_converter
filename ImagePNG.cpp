#include "ImagePNG.h"

void ImagePNG::save(std::string name)
{
	std::string filename = name+".png";
	if(bitmap != nullptr)
	{
		FreeImage_Save(FIF_PNG,bitmap,filename.c_str(),0);
	}
}

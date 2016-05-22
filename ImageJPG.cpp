#include "ImageJPG.h"

void ImageJPG::save(std::string name)
{
	if(bitmap != nullptr)
	{
		FreeImage_Save(FIF_JPEG,bitmap,name.c_str(),0);
	}
}

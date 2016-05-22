#include "ImageJPG.h"

void ImageJPG::save(std::string name)
{
	std::string filename = name+".jpg";
	if(bitmap != nullptr)
	{
		FreeImage_Save(FIF_JPEG,bitmap,filename.c_str(),0);
	}
}

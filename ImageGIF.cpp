#include "ImageGIF.h"
#include <FreeImage.h>

void ImageGIF::save(std::string name)
{
	std::string filename = name+".gif";
	if(bitmap != nullptr)
	{
		FIBITMAP *bit8_bitmap;
		bit8_bitmap = FreeImage_ConvertTo8Bits(bitmap);
		FreeImage_Save(FIF_GIF,bit8_bitmap,filename.c_str(),0);
		FreeImage_Unload(bit8_bitmap);	
	}
}

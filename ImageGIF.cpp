#include "ImageGIF.h"
#include <FreeImage.h>
#include <iostream>
void ImageGIF::save(std::string name)
{
	std::string filename = name+".gif";
	if(bitmap != nullptr)
	{
		FIBITMAP *bit8_bitmap;
		int colors = FreeImage_GetColorsUsed(bitmap);
		if(colors == 256)
		{
			bit8_bitmap = FreeImage_ConvertTo8Bits(bitmap);
		}else
		{
				bit8_bitmap = FreeImage_ColorQuantize(bitmap,FIQ_WUQUANT);
		}
		
	

		FreeImage_Save(FIF_GIF,bit8_bitmap,filename.c_str(),0);
		FreeImage_Unload(bit8_bitmap);	
	}
}

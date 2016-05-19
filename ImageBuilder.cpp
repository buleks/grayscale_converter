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

void ImageBuilder::rotate()
{
	FIBITMAP *old_bitmap = bitmap;
	bitmap = FreeImage_Rotate(bitmap,90);
	FreeImage_Unload(old_bitmap);	
}
void ImageBuilder::grayscale()
{
	FIBITMAP *old_bitmap = bitmap;
	bitmap = FreeImage_ConvertToGreyscale(bitmap);
	FreeImage_Unload(old_bitmap);
}

void ImageBuilder::addmark(std::string sign)
{
	RGBQUAD color;
	
	int  i, j;
	int x_prev = 0;


	int w = FreeImage_GetWidth(bitmap);
	int h = FreeImage_GetHeight(bitmap);
	
	do 
	{
			error = FT_Init_FreeType( &library );
			error = FT_New_Face( library,"/usr/share/fonts/truetype/freefont/FreeSans.ttf",0,&face );
			if(error)
			{
				std::cout<<"Font loading error";
				break;
			}
			
			error = FT_Set_Char_Size(
									face,    /* handle to face object           */
									0,       /* char_width in 1/64th of points  */
									16*64,   /* char_height in 1/64th of points */
									0,     /* horizontal device resolution    */
									0 );   /* vertical device resolution      */
	
			slot = face->glyph;
		//std::cout<<"Wymiary:"<<w<<","<<h<<std::endl;
			for(int s =0; s < sign.length();s++)
			{
				
				error = FT_Load_Char( face, sign[s], FT_LOAD_RENDER );
				if ( error )
				continue; 
				//show_font(&slot->bitmap);
				for ( i = 0; i < slot->bitmap.rows; i++ )
				{
					for ( j = 0; j <slot->bitmap.width; j++ )
					{
						if(slot->bitmap.buffer[i * slot->bitmap.width + j] != 0)
						{
							color.rgbRed = 255.0;
							color.rgbGreen = 0.0 ;
							color.rgbBlue = 0.0;
							FreeImage_SetPixelColor(bitmap,x_prev+j,50-i,&color);
						}
					}
				
				}
				x_prev += slot->bitmap.width;
				

			}
			break;
		
	}while(1);
	
	
	FT_Done_Face    ( face );
	FT_Done_FreeType( library );
	
	
}



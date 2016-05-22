#include "ImageBuilder.h"
#include <iostream>


bool ImageBuilder::readfile(std::string img_filename)
{
	FREE_IMAGE_FORMAT format;

	format = FreeImage_GetFileType(img_filename.c_str());
	if(format == FIF_UNKNOWN )
	{
		std::cout<<"File: "<<img_filename<<" unknown format"<<std::endl;
		return false;
	}

	bitmap = FreeImage_Load(format,img_filename.c_str(),BMP_DEFAULT);
	if(!bitmap)
	{
		std::cout<<"Cannot open image file:"<<img_filename<<std::endl;
		return false;
	}
	return true;
}

void ImageBuilder::rotatecw()
{
	FIBITMAP *old_bitmap = bitmap;
	bitmap = FreeImage_Rotate(bitmap,270);
	FreeImage_Unload(old_bitmap);	
}
void ImageBuilder::rotateccw()
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

void ImageBuilder::addmark(std::string sign,MarkerPosition pos,uint32_t xoffset,uint32_t yoffset)
{
	RGBQUAD color;
	
	int  i, j;
	int x_prev = 0;

	int w = FreeImage_GetWidth(bitmap);
	int h = FreeImage_GetHeight(bitmap);
	
	int y_mark_offset=0;
	int x_mark_offset=0;
	
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
		

			
			
			if(pos == BOTTOM_RIGHT || pos == TOP_RIGHT )
			{
				//calculate sign width
				int sign_width = 0;
				for(int s =0; s < sign.length();s++)
				{
					error = FT_Load_Char( face, sign[s], FT_LOAD_RENDER );
					if ( error )
					continue; 
					
					sign_width+= slot->bitmap.width;
				}
				x_mark_offset = w - sign_width-2*xoffset;
				
			}
			
			int letter_diff = 0; 
			int first_letter_height = 0;
			for(int s =0; s < sign.length();s++)
			{
				//std::cout<<slot->bitmap.rows<<std::endl;
				error = FT_Load_Char( face, sign[s], FT_LOAD_RENDER );
				if ( error )
				continue; 
				if(s == 0 )
				{
					first_letter_height=slot->bitmap.rows;
				}
				if(pos == TOP_LEFT || pos == TOP_RIGHT )
				{
					letter_diff = first_letter_height-slot->bitmap.rows ;
					//std::cout<<letter_diff<<std::endl;
					y_mark_offset = h-yoffset-slot->bitmap.rows-2*letter_diff;
					if(y_mark_offset > h || y_mark_offset < 0)
					{
						y_mark_offset - slot->bitmap.rows;
					}
				}
				
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
							int x_coord = x_prev+j+xoffset+x_mark_offset;
							int y_coord = yoffset-i+y_mark_offset;
							if(x_coord < w && y_coord < h)
							{
								FreeImage_SetPixelColor(bitmap,x_coord,y_coord,&color);
							}
						}
					}
				
				}
				x_prev += slot->bitmap.width+2;
				

			}
			break;
		
	}while(1);
	
	
	FT_Done_Face    ( face );
	FT_Done_FreeType( library );
	
	
}



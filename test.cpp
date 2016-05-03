#include <iostream>
#include <FreeImage.h>
#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H



using namespace std;


FT_Error error;

	FT_Library  library;
	FT_Face     face;
	FT_GlyphSlot  slot;
	FT_Vector     pen;   

void sign_image(FIBITMAP *bitmap,string sign)
{
	RGBQUAD color;

	
	int  i, j;
	int x_prev = 0;


	int w = FreeImage_GetWidth(bitmap);
	int h = FreeImage_GetHeight(bitmap);
	
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
					color.rgbRed = (double)slot->bitmap.buffer[i * slot->bitmap.width + j];
					color.rgbGreen = (double)slot->bitmap.buffer[i * slot->bitmap.width + j] ;
					color.rgbBlue = (double)slot->bitmap.buffer[i * slot->bitmap.width + j];
					FreeImage_SetPixelColor(bitmap,x_prev+j,50-i,&color);
				}
			}
		
		}
		x_prev += slot->bitmap.width;
		

	}
}
int main()
{
	
	
	error = FT_Init_FreeType( &library );
	error = FT_New_Face( library,"/usr/share/fonts/truetype/freefont/FreeSans.ttf",0,&face );
	if(error)
	{
		cout<<"Font loading error";
		return 1;
	}
	error = FT_Set_Char_Size(
          face,    /* handle to face object           */
          0,       /* char_width in 1/64th of points  */
         16*64,   /* char_height in 1/64th of points */
		  0,     /* horizontal device resolution    */
          0 );   /* vertical device resolution      */
	
	 slot = face->glyph;
	
	
	cout<<"Hello"<<endl;
	FreeImage_Initialise();
	cout<<"FreeImage:"<<FreeImage_GetVersion()<<endl;
	//cout<<FreeImage_GetCopyrightMessage()<<endl;
	FIBITMAP *bitmap = FreeImage_Allocate(100,100,24);
	
	if(!bitmap)
	{
		cout<<"Nie mozna utworzyc obrazka";
		return 1;
	}
	
	RGBQUAD color;
	for (int i =0;i<100;i++)
	{
		for(int e=0;e<100;e++)
		{
			color.rgbRed = 0;
			color.rgbGreen = (double)i / 100 *255.0;
			color.rgbBlue = (double)e / 100 *255.0;
			FreeImage_SetPixelColor(bitmap,i,e,&color);
		}
	}
	FreeImage_Save(FIF_PNG,bitmap,"file.png",0);
	FIBITMAP *rotated;
	rotated = FreeImage_Rotate(bitmap,90);
	FreeImage_Save(FIF_PNG,rotated,"file1.png",0);
	FIBITMAP *scaled;
	scaled = FreeImage_Rescale(bitmap,50,50,FILTER_BILINEAR);
	FreeImage_Save(FIF_PNG,scaled,"file2.png",0);
	FIBITMAP *gray;
	gray = FreeImage_ConvertToGreyscale(bitmap);
	FreeImage_Save(FIF_PNG,gray,"file3.png",0);
	
	
	string tekst = "Z&G";
	sign_image(bitmap,tekst);

	FreeImage_Save(FIF_PNG,bitmap,"file4.png",0);
	
	FreeImage_DeInitialise();
	
	  FT_Done_Face    ( face );
  FT_Done_FreeType( library );
	return 0;
}

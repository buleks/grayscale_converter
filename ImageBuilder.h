
#ifndef IMAGEBUILDER__H
#define IMAGEBUILDER__H

#include <string>
#include <FreeImage.h>
#include <ft2build.h>
#include FT_FREETYPE_H


class ImageBuilder {
	
	protected:
	FIBITMAP *bitmap;
	
	private:
	FT_Error error;
	FT_Library  library;
	FT_Face     face;
	FT_GlyphSlot  slot;
	FT_Vector     pen;  
	
	 
	
	public:
	bool readfile(std::string img_filename);
	void rotate()
	{
		bitmap = FreeImage_Rotate(bitmap,90);	
	}
	
	
};

#endif

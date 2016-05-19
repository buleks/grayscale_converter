
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
	ImageBuilder()
	{
		
	}
	
	~ImageBuilder()
	{
		FreeImage_Unload(bitmap);
	}
	
	bool readfile(std::string img_filename);
	void rotate();
	void grayscale();
	void addmark(std::string sign);
	
};

#endif

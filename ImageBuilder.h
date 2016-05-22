
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
	enum MarkerPosition {BOTTOM_LEFT=1,TOP_LEFT,BOTTOM_RIGHT,TOP_RIGHT};
	ImageBuilder()
	{
		
	}
	
	~ImageBuilder()
	{
		FreeImage_Unload(bitmap);
	}
	
	bool readfile(std::string img_filename);
	void rotatecw();
	void rotateccw();
	void grayscale();
	void addmark(std::string sign,MarkerPosition pos,uint32_t xoffset,uint32_t yoffset);
	virtual void save(std::string name) = 0;
	
};

#endif

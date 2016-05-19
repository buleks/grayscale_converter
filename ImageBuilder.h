
#ifndef IMAGEBUILDER__H
#define IMAGEBUILDER__H

#include <string>
#include <FreeImage.h>
#include <ft2build.h>
#include FT_FREETYPE_H


class ImageBuilder {
	
	FT_Error error;
	FT_Library  library;
	FT_Face     face;
	FT_GlyphSlot  slot;
	FT_Vector     pen;   
	
	public:
	void readfile(std::string img_filename);
	
	
};

#endif

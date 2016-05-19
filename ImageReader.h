#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>
#include <iostream>
#include "ImageBuilder.h"
#include <FreeImage.h>
#include <ft2build.h>
#include FT_FREETYPE_H


class ImageReader {
	private:
	ImageBuilder *img;
	bool mark;
	bool rotate;
	bool grayscale;
	
	
	public:
	ImageReader() : mark(false),rotate(false),grayscale(false)
	{
		FreeImage_Initialise();
		std::cout<<"FreeImage:"<<FreeImage_GetVersion()<<std::endl;
	}
	
	void convert(void);
	void set_parameters(bool mark,bool rotate,bool grayscale);
	void set_image(ImageBuilder *image,std::string filename);
};

#endif

#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>
#include <iostream>
#include "ImageBuilder.h"
#include <FreeImage.h>
#include <ft2build.h>
#include FT_FREETYPE_H


class ImageReader {
	
	public:
		
	enum MarkCorner {EMPTY_MARK=0,BOTTOM_LEFT,TOP_LEFT,RIGHT_BOTTOM,RIGHT_TOP};
	enum Rotationdir {NONE_ROTATION=0,CW,CCW}; 
		
	struct Mark {
		std::string mark_txt;
		MarkCorner position;
	};

	
	private:
	ImageBuilder *img;
	Mark  enable_mark;
	Rotationdir enable_rotate;
	bool enable_grayscale;
	
	
	public:
	
	
	ImageReader()  : enable_rotate(NONE_ROTATION),enable_grayscale(false),enable_mark({"",EMPTY_MARK})
	{
		FreeImage_Initialise();
		std::cout<<"FreeImage:"<<FreeImage_GetVersion()<<std::endl;
	}
	
	~ImageReader()
	{
		FreeImage_DeInitialise();
	}
	void convert(void);
	void addmark(Mark mark);
	void converttograyscale();
	void rotate(Rotationdir dir);
	//void set_parameters(bool mark,bool rotate,bool grayscale);
	void set_image(ImageBuilder *image,std::string filename);
};

#endif

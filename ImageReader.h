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
		
	enum MarkPosition {BOTTOM_LEFT=1,TOP_LEFT,BOTTOM_RIGHT,TOP_RIGHT};
	enum Rotationdir {NONE_ROTATION=0,CW,CCW}; 
		
	struct Mark {
		std::string mark_txt;
		MarkPosition position;
		bool show;
		unsigned int xoffset;
		unsigned int yoffset;
	};

	
	private:
	ImageBuilder *img;
	Mark  enable_mark;
	Rotationdir enable_rotate;
	bool enable_grayscale;
	
	
	public:
	
	
	ImageReader()  : enable_rotate(NONE_ROTATION),enable_grayscale(false),enable_mark({"",BOTTOM_RIGHT,false,50,50})
	{
		FreeImage_Initialise();
		//std::cout<<"FreeImage:"<<FreeImage_GetVersion()<<std::endl;
	}
	
	~ImageReader()
	{
		FreeImage_DeInitialise();
	}
	void convert(void);
	void addmark(Mark mark);
	void addmark(std::string text);
	void setmarkposition(MarkPosition position);
	void setmarkxoffset(unsigned int xoffset);
	void setmarkyoffset(unsigned int yoffset);
	void converttograyscale();
	void rotate(Rotationdir dir);
	bool set_image(ImageBuilder *image,std::string filename);
};

#endif

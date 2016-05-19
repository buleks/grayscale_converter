#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>
#include "ImageBuilder.h"

class ImageReader {
	private:
	ImageBuilder *img;
	bool mark;
	bool rotate;
	bool grayscale;
	
	
	public:
	ImageReader() : mark(false),rotate(false),grayscale(false)
	{
		
	}
	
	void convert(void);
	void set_parameters(bool mark,bool rotate,bool grayscale);
	void set_image(ImageBuilder *image,std::string filename);
};

#endif

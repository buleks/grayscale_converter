#include "ImageReader.h"
#include <iostream>

void ImageReader::convert(void)
{
	
}
void ImageReader::set_parameters(bool mark,bool rotate,bool grayscale)
{
	mark = mark;
	rotate = rotate;
	grayscale = grayscale;
}
void ImageReader::set_image(ImageBuilder *image,std::string filename)
{ 
	img = image;
	img.readfile(filename);
}

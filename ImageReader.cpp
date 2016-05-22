#include "ImageReader.h"
#include <iostream>

void ImageReader::converttograyscale()
{
	this->enable_grayscale = true;	
}

void ImageReader::rotate(Rotationdir dir)
{
	enable_rotate = dir;
}
void ImageReader::addmark(Mark mark)
{
	enable_mark = mark;
}
void ImageReader::convert(void)
{
	
	if(enable_rotate == CW)
	{
		img->rotatecw();
	} 
	else if(enable_rotate == CCW)
	{
		img->rotateccw();
	}
	if(enable_mark.position != EMPTY_MARK)
	{
		img->addmark(enable_mark.mark_txt,(ImageBuilder::MarkerPosition)enable_mark.position,50,50);
	}
	if(enable_grayscale)
	{
		img->grayscale();
	}
}
void ImageReader::set_image(ImageBuilder *image,std::string filename)
{ 
	img = image;
	img->readfile(filename);
}

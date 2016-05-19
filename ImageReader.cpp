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
	if(enable_grayscale)
	{
		img->grayscale();
	}
//	if(mark)
//	{
	//	img->addmark("Z&G");
	//}
}
//void ImageReader::set_parameters(bool mark,bool rotate,bool grayscale)
//{
//	this->mark = mark;
//	this->rotate = rotate;
//	this->grayscale = grayscale;
//}
void ImageReader::set_image(ImageBuilder *image,std::string filename)
{ 
	img = image;
	img->readfile(filename);
}

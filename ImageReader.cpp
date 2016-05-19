#include "ImageReader.h"
#include <iostream>

void ImageReader::convert(void)
{
	
//	if(rotate)
//	{
	//	img->rotate();
//	}
//	if(grayscale)
//	{
//		img->grayscale();
//	}
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

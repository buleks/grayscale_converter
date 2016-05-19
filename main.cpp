#include <iostream>
#include <string>
#include "ImageReader.h"
#include "ImagePNG.h"
using namespace std;


int main()
{
	ImagePNG img;
	ImageReader conv;
	conv.set_image(&img,"Main.jpg");
	//conv.set_parameters(true,false,false);
	conv.convert();
	img.save("test.png");
	return 0;
}

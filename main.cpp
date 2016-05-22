#include <iostream>
#include <string>
#include "ImageReader.h"
#include "ImagePNG.h"
#include "ImageJPG.h"
#include "ImageGIF.h"
#include <unistd.h>

using namespace std;


int main(int argc, char **argv)
{
	char c;
	ImageBuilder *img = nullptr;
	ImageReader conv;
	while ((c = getopt (argc, argv, "gt:sr:")) != -1)
	{
		switch(c)
		{
			case 'g': //grayscale
				conv.converttograyscale();
			break;
			
			case 's': //source
			
			break;
			
			case 't': //file type
				if(optarg != 0)
				{
					if(strcmp("png",optarg) ==0 )
					{
						//default is png
					}else if(strcmp("jpg",optarg) ==0 )
					{
						img = new ImageJPG();
						
					}else if(strcmp("gif",optarg) ==0 )
					{
						img = new ImageGIF();
					}else if(strcmp("tiff",optarg) ==0 )
					{
						
					}else if(strcmp("bmp",optarg) ==0 )
					{
						
					}else
					{
						cout<<"\nDestination file type unknown";
					}
				}
			break;
			
			case 'r': //rotate
				if(optarg != 0)
				{
					if(strcmp("cw",optarg) ==0 )
					{
						conv.rotate(ImageReader::CW);
					}else if(strcmp("ccw",optarg) ==0)
					{
						conv.rotate(ImageReader::CCW);
					}else
					{
						cout<<"\nInvalid option for -r(rotate) argument";
					}
				}
			break;
			
			case '?':
				cout<<"\nUnknown argument";
				return 1;
			break;
			
			
		}
	}
	
	if(img == nullptr)
	{
		img = new ImagePNG();
	}

	conv.set_image(img,"Main.jpg");
	conv.addmark({"Z&G",ImageReader::TOP_RIGHT});
	conv.convert();
	img->save("test");
	delete img;
	return 0;
}

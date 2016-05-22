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
	while ((c = getopt (argc, argv, "gt:sr:m:vhp:")) != -1)
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
					}	
					else
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
			
			case 'm':
				if(optarg != 0)
				{
					conv.addmark(optarg);
				}
			break;
			
			case 'p':
				if(optarg != 0)
				{
					
				}
			break;
			
			case 'v':
				cout<<"Version 0.0.1"<<endl;
				return 0;
			break;
			
			case 'h':
				cout<<"\nArguments -r ccw,cw - rotate image"<<endl;
				cout<<"-t jpg,gif,png - output format type"<<endl;
				cout<<"-m text - add string marker on image"<<endl;
				cout<<"-p bl,br,tl,tr - specify marker position default br(bottom right)"<<endl;
				cout<<"-g - converts image to grayscale"<<endl;
				cout<<"-v - shows version"<<endl;
				return 0;
			break;
			
			case '?':
				cout<<"\nUnknown argument, use -h for description";
				return 1;
			break;
			
			
		}
	}
	
	if(img == nullptr)
	{
		img = new ImagePNG();
	}

	conv.set_image(img,"Main.jpg");
	conv.convert();
	img->save("test");
	delete img;
	return 0;
}

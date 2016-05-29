#include <iostream>
#include <string>
#include "ImageReader.h"
#include "ImagePNG.h"
#include "ImageJPG.h"
#include "ImageGIF.h"
#include <unistd.h>

using namespace std;

string Outputfilename(const string source);

int main(int argc, char **argv)
{
	char c;
	string source_filename;
	ImageBuilder *img = nullptr;
	ImageReader conv;
	do
	{
		while ((c = getopt (argc, argv, "gt:r:m:vhp:x:y:")) != -1)
		{
			switch(c)
			{
				case 'g': //grayscale
					conv.converttograyscale();
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
							cout<<"Invalid argument for option -r(rotate) argument\n";
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
						if(strcmp("bl",optarg) ==0 )
						{
							conv.setmarkposition(ImageReader::BOTTOM_LEFT);
						}else if(strcmp("tl",optarg) ==0 )
						{
							conv.setmarkposition(ImageReader::TOP_LEFT);
						} else if(strcmp("tr",optarg) ==0 )
						{
							conv.setmarkposition(ImageReader::TOP_RIGHT);
						} else if(strcmp("br",optarg) ==0 ){
						}
						else
						{
							cout<<"Invalid argument for option -p. Specify -h for help"<<endl;
						}
					}
				break;
				
				case 'x':
					if(optarg != 0)
					{
						int offset = atoi(optarg);
						if(offset != 0 && offset > 0)
						{
							conv.setmarkxoffset(offset);
						}else
						{
							cout<<"Invalid number for -x option"<<endl;
						}
					}
					
				break;
				
				case 'y':
					if(optarg != 0)
					{
						int offset = atoi(optarg);
						if(offset != 0 && offset > 0)
						{
							conv.setmarkyoffset(offset);
						}else
						{
							cout<<"Invalid number for -y option"<<endl;
						}
					}
				break;
				
				case 'v':
					cout<<"Version 0.0.1"<<endl;
					goto PROGRAM_CLOSE;
				break;
				
				case 'h':
					cout<<"\nArguments -r ccw,cw - rotate image"<<endl;
					cout<<"-t jpg,gif,png - output format type"<<endl;
					cout<<"-m text - add string marker on image"<<endl;
					cout<<"-p bl,br,tl,tr - specify marker position default br(bottom right)"<<endl;
					cout<<"-x - x offset for marker from corner(default 50px)"<<endl;
					cout<<"-y - y offset for marker from corner(default 50px)"<<endl;
					cout<<"-g - converts image to grayscale"<<endl;
					cout<<"-v - shows version"<<endl;
					goto PROGRAM_CLOSE;
				break;
				
				case '?':
					cout<<"Unknown argument, use -h for description\n";
					goto PROGRAM_CLOSE;
				break;
				
				
			}
		}
		

		
		if(img == nullptr)
		{
			img = new ImagePNG();
		}
		
		int index;
		bool img_found = false;
		for (index = optind; index < argc; index++)
		{
	
			 if(conv.set_image(img,argv[index]))
			 {
				 source_filename = argv[index];
				 img_found = true;
				 break;
			 }
		}
		
		if(!img_found)
		{
			cout<<"Enter properly image file name to convert\n";
			break;
		}

		
		conv.convert();
		img->save(Outputfilename(source_filename));
		break;
	}while(true);
	
	PROGRAM_CLOSE:
	delete img;
	return 0;
}

string Outputfilename(const string source)
{
	 string prefix = source;
	 for(string::const_iterator i = source.begin(); i <= source.end(); ++i) 
	 {
		 if(*i == '.')
		 {
			 prefix = source.substr(0,i-source.begin());
			 break;
		 }
	 }
	return prefix+"_m";
}

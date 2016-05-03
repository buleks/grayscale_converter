#include <iostream>
#include <FreeImage.h>

using namespace std;

int main()
{
	
	cout<<"Hello"<<endl;
	FreeImage_Initialise();
	cout<<"FreeImage:"<<FreeImage_GetVersion()<<endl;
	//cout<<FreeImage_GetCopyrightMessage()<<endl;
	FIBITMAP *bitmap = FreeImage_Allocate(100,100,24);
	
	if(!bitmap)
	{
		cout<<"Nie mozna utworzyc obrazka";
		return 1;
	}
	
	RGBQUAD color;
	for (int i =0;i<100;i++)
	{
		for(int e=0;e<100;e++)
		{
			color.rgbRed = 0;
			color.rgbGreen = (double)i / 100 *255.0;
			color.rgbBlue = (double)e / 100 *255.0;
			FreeImage_SetPixelColor(bitmap,i,e,&color);
		}
	}
	FreeImage_Save(FIF_PNG,bitmap,"file.png",0);
	FIBITMAP *rotated;
	rotated = FreeImage_Rotate(bitmap,90);
	FreeImage_Save(FIF_PNG,rotated,"file1.png",0);
	FIBITMAP *scaled;
	scaled = FreeImage_Rescale(bitmap,50,50,FILTER_BILINEAR);
	FreeImage_Save(FIF_PNG,scaled,"file2.png",0);
	FIBITMAP *gray;
	gray = FreeImage_ConvertToGreyscale(bitmap);
	FreeImage_Save(FIF_PNG,gray,"file3.png",0);
	FreeImage_DeInitialise();
	return 0;
}

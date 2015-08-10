#include <opencv2/highgui/highgui.hpp>
#include "iANPRinterface.h"
#include "iANPR.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#define NUMBERS_QUANTITY 10

void clean(char** a)
{
	if(a != NULL)
	{
		for(int j=0;j<NUMBERS_QUANTITY;j++) delete [] a[j];
		delete [] a;	
	}
}

std::vector<std::string> getNumber(std::string url,  char* ntype)
{
	IplImage* Img = 0;
	IplImage* grayImg = 0;
	std::vector<std::string> result; 


	char * writable = new char[url.size() + 1];
	for (unsigned int i = 0; i < url.size(); i++)
		writable[i] = url[i];
	writable[url.size()] = '\0'; // don't forget the terminating 0

	if (strcmp (ntype, "0") && strcmp (ntype, "1") && strcmp (ntype, "2") && strcmp (ntype, "3") &&
	strcmp (ntype, "4") && strcmp (ntype, "5") && strcmp (ntype, "6") && strcmp (ntype, "7") &&
	strcmp (ntype, "100") && strcmp (ntype, "101") && strcmp (ntype, "102") && strcmp (ntype, "103") &&
	strcmp (ntype, "104") && strcmp (ntype, "201") && strcmp (ntype, "202") && strcmp (ntype, "203") &&
	strcmp (ntype, "300") && strcmp (ntype, "301") && strcmp (ntype, "302"))
	{
		printf  ("type_number is incorrect. Please refer to program help %s /? or to iANPR SDK documentation\n", ntype);
		return result;
	}	
	else 
		Img = cvLoadImage( writable, CV_LOAD_IMAGE_COLOR  );

	if (!Img)
	{
		printf( "Can't load file!\n");
		return result;
	}
	delete[] writable;

	CvRect Rects[100];
	int all = NUMBERS_QUANTITY;
	char** res = new char*[all];
	for(int j=0;j<all;j++) res[j] = new char[20];
	ANPR_OPTIONS a;
	a.Detect_Mode = ANPR_DETECTCOMPLEXMODE;
	a.min_plate_size = 500;
	a.max_plate_size = 50000;
	a.max_text_size = 20;		
	a.type_number = atoi (ntype);		
	a.flags = 0;

	
	int i = -9999;
	if (a.type_number == 4 || a.type_number == 7)
		i = anprPlate( Img,  a, &all, Rects, res ); 
	else
	{		
		grayImg = cvCreateImage (cvGetSize (Img), 8, 1);
		cvCvtColor (Img, grayImg, CV_BGR2GRAY);
		i = anprPlate( grayImg,  a, &all, Rects, res ); 
	}
	

	if ( i != 0 )
	{
		printf( "Error:%d\n", i );
		return result;
	}

	for(int j=0;j<all;j++)
	{
		result.push_back(res[j]);
	}

	cvReleaseImage ( &Img );
	cvReleaseImage ( &grayImg );
	clean(res);
	return result;
}


int main(void)
{
	std::string url = "../testImages/test.jpg";
	char* type = "7";
	std::vector<std::string> res = getNumber(url, type);
	if(res.size() != 0)
	{
		for(unsigned int j = 0; j < res.size(); j++ ) 
		{	
			std::cout<<res[j]<<std::endl;
		}
	}
	return 0;
}
/******************************************************************************
	(C) 2015. IntBuSoft. http://intbusoft.com
	iANPRinterface.h - version 1.3
*******************************************************************************/
#pragma once
#include "iANPR.h"
#include <opencv2/imgproc/imgproc.hpp>

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateMemory( char* in_buffer, int size_buffer, ANPR_OPTIONS Options, int* AllNumber, CvRect* Rects, char** Texts );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateMemoryRect( char* in_buffer, int size_buffer, CvRect Rect, ANPR_OPTIONS Options, int* AllNumber, CvRect* Rects, char** Texts );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateMat( cv::Mat Image, ANPR_OPTIONS Options, int* AllNumber, CvRect* Rects, char** Texts );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateMatRect( cv::Mat Image, CvRect Rect, ANPR_OPTIONS Options, int* AllNumber, CvRect* Rects, char** Texts );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateXML( IplImage* Image, ANPR_OPTIONS Options, char* xml_buffer, int* size_xml_buffer );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateRectXML( IplImage* Image, CvRect Rect, ANPR_OPTIONS Options, char* xml_buffer, int* size_xml_buffer );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateMemoryXML( char* in_buffer, int size_buffer, ANPR_OPTIONS Options, char* xml_buffer, int* size_xml_buffer );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateMemoryRectXML( char* in_buffer, int size_buffer, CvRect Rect, ANPR_OPTIONS Options, char* xml_buffer, int* size_xml_buffer );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateMatXML( cv::Mat Image, ANPR_OPTIONS Options, char* xml_buffer, int* size_xml_buffer );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateMatRectXML( cv::Mat Image, CvRect Rect, ANPR_OPTIONS Options, char* xml_buffer, int* size_xml_buffer );
/******************************************************************************
	(C) 2015. IntBuSoft. http://intbusoft.com
	iANPR.h - version 1.3		
*******************************************************************************/
#pragma once

#include "iANPRerror.h"
#include "opencv2/core/core_c.h"
#include "opencv2/imgproc/imgproc_c.h"

// Методы детектирования автомобильного номера
// Методы, основанные на детектировании номера целиком
#define ANPR_DETECTMODE1			0x01  // Простая адаптивная обработка
#define ANPR_DETECTMODE2			0x02  // Адаптивная обработка с дополнительной фильтрацией изображения
#define ANPR_DETECTMODE3			0x04  // Блочная адаптивная обработка
// Методы, основанные на выделении частей номера
#define ANPR_DETECTMODE4			0x08  // Простая адаптивная обработка с внутренним анализом	номера

#define ANPR_DETECTCOMPLEXMODE		ANPR_DETECTMODE2 | ANPR_DETECTMODE3 | ANPR_DETECTMODE4

// Типы распознаваемых автомобильных номеров
// На вход поступает изображение в градациях серого
#define	ANPR_RUSSIAN_BASE			0  // Базовые
#define	ANPR_RUSSIAN_BASE2			1  // Базовые и транзитные
#define	ANPR_RUSSIAN_EXTENDED		2  // Базовые, транзитные и номера прицепов
#define ANPR_RUSSIAN_PUBLIC			3  // Только общественный транспорт
#define ANPR_RUSSIAN_POLICE			5  // Только номера полиции
#define ANPR_RUSSIAN_ARMY			6  // Только военные номера
// ВНИМАНИЕ!!! Следующие конфигурации работают только для цветных изображений
#define	ANPR_RUSSIAN_EXTENDED2		4  // Базовые, транзитные и номера прицепов и ANPR_RUSSIAN_PUBLIC
#define	ANPR_RUSSIAN_FULL			7  // ANPR_RUSSIAN_EXTENDED2 + ANPR_RUSSIAN_POLICE + ANPR_RUSSIAN_ARMY

// Номера Казахстана
// На вход поступает изображение в градациях серого
#define ANPR_KAZ_1993_PRIVATE		100
#define ANPR_KAZ_1993_ORGANIZATION	101
#define ANPR_KAZ_2012_PRIVATE		102
#define ANPR_KAZ_2012_ORGANIZATION	103
#define ANPR_KAZ_BASE				104   // ANPR_KAZ_1993_PRIVATE + ANPR_KAZ_1993_ORGANIZATION + ANPR_KAZ_2012_PRIVATE + ANPR_KAZ_2012_ORGANIZATION

// Номера Туркменистана
// На вход поступает изображение в градациях серого
#define ANPR_TM_2009				201
#define ANPR_TM_PRIVATE_BEFORE_2009	202
#define ANPR_TM_BASE				203  // ANPR_TM_2009 + ANPR_TM_PRIVATE_BEFORE_2009

// Номера Беларуси
#define ANPR_BY_TRUCK				300 // ANPR_BY_2004_TRUCK + ANPR_BY_1992_TRUCK
#define ANPR_BY_2004_TRUCK			301 // Грузовые автомобили и автобусы с 2004г.
#define ANPR_BY_1992_TRUCK			302 // Грузовые автомобили и автобусы с 1992г.

// Заполнение flags в ANPR_OPTIONS
#define DEBUG_RECOGNITION_MODE		0x01  // Будут выводиться все распознанные номера, в том числе и с неопределенными символами (знак вопроса)

struct ANPR_OPTIONS
{
	int min_plate_size; // Минимальная площадь номера
	int max_plate_size; // Максимальная площадь номера
	int Detect_Mode; // Режимы детектирования	
	int max_text_size; // Максимальное количество символов номера + 1
	int type_number; // Тип автомобильного номера 
	int flags; // Дополнительные опции
};

int
#ifdef WIN32
__stdcall 
#endif 
anprPlate( IplImage* Image, ANPR_OPTIONS Options, int* AllNumber, CvRect* Rects, char** Texts, void* param = NULL );

int
#ifdef WIN32
__stdcall 
#endif 
anprPlateRect( IplImage* Image, CvRect Rect, ANPR_OPTIONS Options, int* AllNumber, CvRect* Rects, char** Texts, void* param = NULL );

void
#ifdef WIN32
__stdcall 
#endif 
LicenseValue( char* lic );
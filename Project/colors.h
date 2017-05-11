
#ifndef _COLORS_H_INCLUDED
#define _COLORS_H_INCLUDED

/*****************************
Library for printing colored text in console
******************************
WARNING: The library will work on most UNIX systems and
	is not supported in Win32 console component of Microsoft Windows 
	before Windows 10 update TH2
more information here: https://en.wikipedia.org/wiki/ANSI_escape_code
*****************************/

char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
char magenta[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
char cyan[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
char white[] = { 0x1b, '[', '1', ';', '3', '7', 'm', 0 };

#endif // COLORS_H_INCLUDED


#ifndef CONSOLE_H
#define CONSOLE_H


#include <iostream>
#include "colors.h"

using namespace std;



template <typename T>
void printRed(T message){
	cout << red << message;	
	cout << white;
}


template <typename T>
void printGreen(T message){
	cout << green << message;	
	cout << white;
}


template <typename T>
void printYellow(T message){
	cout << yellow << message;	
	cout << white;
}


template <typename T>
void printBlue(T message){
	cout << blue << message;	
	cout << white;
}


template <typename T>
void printMagenta(T message){
	cout << magenta << message;	
	cout << white;
}


template <typename T>
void printCyan(T message){
	cout << cyan << message;	
	cout << white;
}


template <typename T>
void printWhite(T message){
	cout << white << message;	
}


template <typename T>
void printError(T error){
	printRed("-!--EROARE--- ");
	printRed(error);
	printRed("\n");
}	


template <typename T>
void printWarning(T warning){
	printYellow("-!--ATENTIE--- ");
	printYellow(warning);
	printYellow("\n");
}	


template <typename T>
void printSuccess(T success){
	printGreen("---SUCCESS--- ");
	printGreen(success);
	printGreen("\n");
}	





#endif
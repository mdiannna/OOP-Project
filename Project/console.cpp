#include "console.h"
#include "colors.h"



void printRed(string message){
	cout << red << message;	
	cout << white;
}


void printGreen(string message){
	cout << green << message;	
	cout << white;
}


void printYellow(string message){
	cout << yellow << message;	
	cout << white;
}


void printBlue(string message){
	cout << blue << message;	
	cout << white;
}


void printMagenta(string message){
	cout << magenta << message;	
	cout << white;
}


void printCyan(string message){
	cout << cyan << message;	
	cout << white;
}


void printWhite(string message){
	cout << white << message;	
}



void printError(string error){
	printRed("-!--EROARE--- " + error + "\n");
}	


void printWarning(string warning){
	printYellow("-!--ATENTIE--- " + warning + "\n");
}	


void printSuccess(string success){
	printGreen("---SUCCESS--- " + success + "\n");
}	
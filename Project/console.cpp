#include "console.h"
#include "colors.h"



void printRed(string message){
	cout << red << message;	
}


void printGreen(string message){
	cout << green << message;	
}


void printYellow(string message){
	cout << yellow << message;	
}


void printBlue(string message){
	cout << blue << message;	
}


void printMagenta(string message){
	cout << magenta << message;	
}


void printCyan(string message){
	cout << cyan << message;	
}



void printError(string error){
	printRed("-!--EROARE---" + error + "\n");
}	


void printWarning(string warning){
	printYellow("-!--ATENTIE---" + warning + "\n");
}	


void printSuccess(string success){
	printGreen("-+--SUCCESS---" + success + "\n");
}	
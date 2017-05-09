#include "util.h"
#include <string> 


/************************/
// Date functions
/************************/
void Date::setDate(int day, int month, int year){
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::setDay(int day){
	this->day = day;
}

void Date::setMonth(int month){
	this->month = month;
}

void Date::setYear(int){
	this->year = year;
}

//TO DO: properly format date
string Date::getDateAsString(){
	string result = "";
	result = result + to_string(this->day) + "." 
				+ to_string(this->month) + "." 
				+ to_string(this->year);
	return result;
}

int Date::getDay(){
	return this->day;
}

int Date::getMonth(){
	return this->month;
}

string Date::getYear(){
	return this->year;
}

string Date::getDayAsString(){
	return to_string(this->day);
}

string Date::getMonthAsString(){
	return to_string(this->month);
}

string Date::getYearAsString(){
	return to_string(this->year);
}


/************************/
// Time functions
/************************/
void Time::setTime(int hour, int minute, int second){
	this->hour = hour;
	this->minute = minute;
	this->second = second;

}

void Time::setHour(int hour){
	this->hour = hour;
}

void Time::setMinute(int minute){
	this->minute = minute;
}

void Time::setSecond(int second){
	this->second = second;
}

int Time::getHour(){
	return this->hour;
}

int Time::getMinute(){
	return this->minute;
}
string Time::getSecond(){
	return this->second;
}

//TO DO: properly format time
string Time::getTimeAsString(){
	string result = "";
	result = result + to_string(this->hour) + ":" 
				+ to_string(this->minute) + ":" 
				+ to_string(this->second);
	return result;
}

string Time::getHourAsString(){
	return to_string(this->hour);
}
string Time::getMinuteAsString(){
	return to_string(this->minute);
}
string Time::getSecondAsString(){
	return to_string(this->second);
}
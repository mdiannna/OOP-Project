#include "util.h"
#include <ctime>
#include <string>

using namespace std;

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


void Date::setYear(int year){
	this->year = year;
}


string Date::getDateAsString() const{
	return convertDateToString(*this);
}


int Date::getDay() const{
	return this->day;
}


int Date::getMonth() const{
	return this->month;
}


int Date::getYear() const{
	return this->year;
}


string Date::getDayAsString() const{
	return to_string(this->day);
}


string Date::getMonthAsString() const{
	return to_string(this->month);
}


string Date::getYearAsString() const{
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


int Time::getHour() const{
	return this->hour;
}


int Time::getMinute() const{
	return this->minute;
}


int Time::getSecond() const{
	return this->second;
}


string Time::getTimeAsString() const{
	return convertTimeToString(*this);
}


string Time::getHourAsString() const{
	return to_string(this->hour);
}


string Time::getMinuteAsString() const{
	return to_string(this->minute);
}


string Time::getSecondAsString() const{
	return to_string(this->second);
}


/********************/
// Non-class members
/********************/

Date getDateNow(){
	Date result;

	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    result.setYear(now->tm_year + 1900);
    result.setMonth(now->tm_mon + 1);
    result.setDay(now->tm_mday);

	return result;
}


string getDateNowAsString(){
	Date result = getDateNow();
	return convertDateToString(result);
}


//TO DO: properly format date as string
string convertDateToString(Date d){
	string result = "";
	string day = to_string(d.getDay());
	string month = to_string(d.getMonth());
	string year = to_string(d.getYear());

	if(day.length() < 2)
		day = "0" + day;
	if(month.length() < 2)
		month = "0" + month;

	result = result + day + "." + month + "." + year;
	return result;
}


Time getTimeNow(){
	Time result;

	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    result.setHour(now->tm_hour);
    result.setMinute(now->tm_min);
    result.setSecond(now->tm_sec);

    return result;
}


string getTimeNowAsString(){
	Time result = getTimeNow();
	return convertTimeToString(result);
}


string convertTimeToString(Time t){
	string result = "";
	string hour = to_string(t.getHour());
	string minute = to_string(t.getMinute());
	string second = to_string(t.getSecond());

	if(hour.length() < 2)
		hour = "0" + hour;
	if(minute.length() < 2)
		minute = "0" + minute;
	if(second.length() < 2)
		second = "0" + second;

	result = result + hour + ":" + minute + ":" + second;
	return result;
}
/********************/

/********************/
//Operators overloading
/********************/
ostream& operator<<(ostream & out, const Date& date){
	out << date.getDateAsString();
	return out;
}


ostream& operator<<(ostream &out, const Time& time){
	out << time.getTimeAsString();
	return out;
}


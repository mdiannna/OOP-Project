#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <string> 

using namespace std;


class Date{
	int day;
	int month;
	int year;

public:
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay();
	int getMonth();
	int getYear();
	string getDateAsString();
	string getDayAsString();
	string getMonthAsString();
	string getYearAsString();
//TO DO
	string getDateNowAsString();
};



class Time{
	int hour;
	int minute;
	int second;
public:
	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	int getHour();
	int getMinute();
	int getSecond();
	string getTimeAsString();	
	string getHourAsString();
	string getMinuteAsString();
	string getSecondAsString();
//TO DO
	string getTimeNowAsString();	
};

#endif // UTIL_H_INCLUDED
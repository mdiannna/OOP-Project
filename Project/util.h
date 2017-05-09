#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED


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
	
};

#endif // UTIL_H_INCLUDED
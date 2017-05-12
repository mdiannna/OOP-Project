#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <string> 
#include <sstream>

using namespace std;
/********************/
//Class Date
/********************/


/********************/
//Implementation of to_String function
/********************/
template <typename T>
std::string to_string(const T& value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}


/********************/
//Class Date
/********************/
class Date{
	int day;
	int month;
	int year;

public:
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	string getDateAsString() const;
	string getDayAsString() const;
	string getMonthAsString() const;
	string getYearAsString() const;
	string getDateNowAsString() const;

	friend ostream& operator<<(ostream &, const Date&);	
};


/********************/
// Class Time
/********************/

class Time{
	int hour;
	int minute;
	int second;
public:
	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	string getTimeAsString() const;	
	string getHourAsString() const;
	string getMinuteAsString() const;
	string getSecondAsString() const;
	string getTimeNowAsString() const;	

	friend ostream& operator<<(ostream &, const Time&);
	
};



/********************/
// non class member functions
/********************/
string convertDateToString(Date);
Date getDateNow();
string getDateNowAsString();
string convertTimeToString(Time);
Time getTimeNow();
string getTimeNowAsString();


#endif // UTIL_H_INCLUDED
#ifndef _TIMESTAMP_H_
#define _TIMESTAMP_H_

#include <iostream>
#include <string>
using namespace std;

class TimeStamp {

public:
	TimeStamp(int hours = 0, int minutes = 0, int seconds = 0, int miliseconds = 0);
	TimeStamp(long miliseconds); 
	TimeStamp(double seconds); 


    static bool doesOverlap(TimeStamp& previousTime, TimeStamp& thisTime);
    static bool doesOverlap(TimeStamp& thisTime, TimeStamp& nextTime, int);
    static bool doesOverlap(TimeStamp& previousTime, TimeStamp& thisTime, TimeStamp& nextTime);

	 bool isBefore(const TimeStamp& ts) const;
	 bool isAfter(const TimeStamp& ts) const;

	 bool operator==(const TimeStamp& ts) const;
	 bool operator!=(const TimeStamp& ts) const;
	 bool operator>(const TimeStamp& ts) const;
	 bool operator<(const TimeStamp& ts) const;
     bool operator<=(const TimeStamp& ts) const;
     bool operator>=(const TimeStamp& ts) const;
	
	 int getHours(void) const { return hours; }
	 int getMinutes(void) const { return minutes; }
	 int getSeconds(void) const { return seconds; }
	 int getMiliseconds(void) const { return miliseconds; }

     void setHours(int hours) { this->hours = hours; }
     void setMinutes(int minutes) { this->minutes = minutes; }
     void setSeconds(int seconds) { this->seconds = seconds; }
     void setMiliseconds(int miliseconds) { this->miliseconds = miliseconds; }

	 double getTimeInSeconds(void) const { return hours * 3600 + minutes * 60 + seconds + miliseconds / 1000.0; }

private:
	int hours; 
	int minutes; 
	int seconds; 
	int miliseconds; 
};


#endif // !_TimeStamp_h_


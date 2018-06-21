#include "TimeStamp.h"

TimeStamp::TimeStamp(int hours, int minutes, int seconds, int miliseconds) {
    this->hours = hours;
    this->minutes = minutes % 60;
    this->seconds = seconds % 60;
    this->miliseconds = miliseconds % 1000;
}

TimeStamp::TimeStamp(long miliseconds) {
	this->miliseconds = miliseconds % 1000;
	miliseconds /= 1000;
	this->seconds = miliseconds % 60;
	miliseconds /= 60;
	this->minutes = miliseconds % 60;
	miliseconds /= 60;
	this->hours = miliseconds % 24;

}

TimeStamp::TimeStamp(double seconds) {
	this->miliseconds = ((int)(seconds * 1000)) % 1000;
	this->seconds =( (int) seconds )% 60;
	seconds /= 60;
	this->minutes = ( (int) seconds ) % 60;
	seconds /= 60;
	this->hours = ((int)seconds) % 24;

}

bool TimeStamp::doesOverlap(TimeStamp &previousTime, TimeStamp &thisTime) {
    return thisTime < previousTime;
}

bool TimeStamp::doesOverlap(TimeStamp& thisTime, TimeStamp& nextTime, int) {
    return thisTime > nextTime;
}

bool TimeStamp::doesOverlap(TimeStamp& previousTime, TimeStamp& thisTime, TimeStamp& nextTime) {
    return thisTime < previousTime || thisTime > nextTime;
}

 bool TimeStamp::isBefore(const TimeStamp & ts) const {
	if (hours > ts.hours) {
		return false;
	} else if (hours < ts.hours) {
		return true;
	} else if (minutes > ts.minutes) { // hours == ts.hours
		return false;
	} else if (minutes < ts.minutes) {
		return true;
	} else if (seconds > ts.seconds) { // hours == ts.hours && minutes == ts.minutes
		return false;
	} else if (seconds < ts.seconds) {
		return true;
	} else if (miliseconds > ts.miliseconds) { // hours == ts.hours && minutes == ts.minutes && seconds == ts.seconds
		return false;
	} else if (miliseconds < ts.miliseconds) {
		return true;
	} else { // *this == ts
		return false;
	}
}

 bool TimeStamp::isAfter(const TimeStamp & ts) const {
    return !isBefore(ts) && !operator==(ts);
}

 bool TimeStamp::operator==(const TimeStamp & ts) const {
	return hours == ts.hours && minutes == ts.minutes && seconds == ts.seconds && miliseconds == ts.miliseconds;
}

 bool TimeStamp::operator!=(const TimeStamp & ts) const {
	return !operator==(ts);
}

 bool TimeStamp::operator>(const TimeStamp & ts) const {
	return isAfter(ts);
}

 bool TimeStamp::operator<(const TimeStamp & ts) const {
     return isBefore(ts);
 }

 bool TimeStamp::operator<=(const TimeStamp &ts) const {
     return operator<(ts) || operator==(ts);
 }

 bool TimeStamp::operator>=(const TimeStamp &ts) const {
     return operator>(ts) || operator==(ts);
 }

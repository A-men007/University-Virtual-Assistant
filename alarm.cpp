#include <iostream>
#include "alarm.h"
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <math.h>
//namespace
using namespace std;

alarm::alarm(string alarmEvent, int year, int month, int mday, int hour, int mint){
	//initialize all of its variables
	this->event = alarmEvent;
	this->year = year - 1900;
    this->month = month - 1;
    this-> mday = mday;
    this-> hour = hour;
    this-> mint = mint;
    this-> status = true; //the alarm is active(on) by default
	}

int alarm::counterToAlarm(){//this will calculate the seconds we need to reach the alarm time from current time
    	time_t timer;
    	struct tm alarmDate = {0};
    	int seconds;

    	alarmDate.tm_hour = this->hour;
    	alarmDate.tm_min= this->mint;
    	alarmDate.tm_sec = 0;
    	alarmDate.tm_year = this->year;
    	alarmDate.tm_mon = this ->month;
	alarmDate.tm_mday = this ->mday;

    	time(&timer);  /* get current time; same as: timer = time(NULL)  */

    	seconds = difftime(timer,mktime(&alarmDate));//time difference in seconds from alarm time to current time
    
    	return seconds;
}
string alarm::notifyUser(){
    	if (this-> triggerAlarm()==true){
        	cout<< "It's time for "<< (this->event);
    }
	else{//reminder
        	
		int seconds = this -> counterToAlarm();
		int day, hour, minutes;
		day = floor(seconds / (24 * 3600));
		seconds = seconds % (24 * 3600);
		hour = floor(seconds / 3600);
		seconds %= 3600;
		minutes = floor(seconds / 60);
		seconds %= 60;
		cout << abs(day) << " day(s) " << abs(hour) << " hour(s) "<< abs(minutes)<< " minute(s) " << abs(seconds) << " second(s) until " << this->event; 
		return "\n";
	}
	return 0;}

string alarm::getEvent(){
		return this->event;
	}
void alarm::setAlarmOff(){
    	this -> status =false;
}

bool alarm::triggerAlarm(){//check if the alarm have been triggered
    	bool trigger = false;
    	if(this->counterToAlarm() == 0 && this->status == true){
        	trigger = true;
    }
    	return trigger;
}


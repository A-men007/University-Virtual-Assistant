#ifndef ALARM_H
#define ALARM_H

#include <string>
//namespace
using namespace std;


class alarm{
	private:
		string event;
		int year;
		int month;
		int mday;
		int hour;
		int mint;
		bool status;
	
	public:
		alarm(string, int, int, int, int, int);
		int counterToAlarm();
		string notifyUser();
       	string getEvent();
		void setAlarmOff();
		bool triggerAlarm();
		
};

#endif

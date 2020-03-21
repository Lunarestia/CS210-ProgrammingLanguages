//============================================================================
// Name        : Project1_Clock.cpp
// Author      : Luna Saccoia
// Version     :
// Copyright   : CS210-SNHU
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

//declare classes for 12 hour and 24 hour clocks
class standardTime;
class militaryTime;

//enum for AM and PM for 12 hour clock
enum AMorPM {
	AM, PM
} AMPM;

//class Clock with variables for hour, minute and second
class Clock {

public:
	int hour;
	int minute;
	int second;
};

//class for 12 hour clock which inherits the public Clock class
class standardTime : public Clock {

public:
	standardTime(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
		AMPM = AM;
	}

//if-else statement to set hours to 0 or add one hour
void addOneHour() {
	if (hour == 11) {
		hour = 0;
	} else {
		hour += 1;
	}
}

//if-else statement to set minutes to 0 or add one minute
void addOneMinute() {
	if (minute == 59) {
		minute = 0;
		addOneHour();
	} else {
		minute += 1;
	}
}

//if-else statement to set seconds to 0 or add one second
void addOneSecond() {
	if (second == 59) {
		second = 0;
		addOneMinute();
	} else {
		second += 1;
	}
}

//set friend function
friend void showTime(const standardTime&, const militaryTime&);
};

//class for 24 hour clock which inherits the public Clock class
class militaryTime : public Clock {

public:
	militaryTime(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}

//if-else statement to set hour to 0 or add one hour
void addOneHour() {
	if (hour == 23) {
		hour = 0;
	} else {
		hour += 1;
	}
}

//if-else statement to set minute to 0 or add one minute
void addOneMinute() {
	if (minute == 59) {
		minute = 0;
		addOneMinute();
	} else {
		minute += 1;
	}
}

//if-else statement to set second to 0 or add one second
void addOneSecond() {
	if (second == 59) {
		second = 0;
		addOneSecond();
	} else {
		second += 1;
	}
}

//set friend function
friend void showTime(const standardTime&, const militaryTime&);
};

//display clock output for both clocks displaying current time
void showTime(const standardTime&, const militaryTime&) {

	time_t timeNow = time(0);
	tm *sTime = localtime(&timeNow);
	tm *mTime = localtime(&timeNow);
	time (&timeNow);

	cout << "***************************      ***************************" << endl;
	cout << "*      12-Hour Clock      *      *      24-Hour Clock      *" << endl;
	cout << "*      ";

	bool AM = true;

	if (mTime->tm::tm_hour > 12) {
		cout << "0" << mTime->tm::tm_hour - 12 << ":";
		AM = false;
	} else if (sTime->tm::tm_hour < 10) {
		cout << "0" << sTime->tm::tm_hour << ":";
	} else {
		cout << sTime->tm::tm_hour << ":";
	}

	if (sTime->tm::tm_min < 10) {
		cout << "0" << sTime->tm::tm_min << ":";
	} else {
		cout << sTime->tm::tm_min << ":";
	}

	if (sTime->tm::tm_sec < 10) {
		cout << "0" << sTime->tm::tm_sec;
	} else {
		cout << sTime->tm::tm_sec;
	}

	if (AM) {
		cout << " AM";
	} else {
		cout << " PM";
	}

	cout << "        *      *      ";

	if (mTime->tm::tm_hour < 10) {
		cout << "0" << mTime->tm::tm_hour << ":";
	} else {
		cout << mTime->tm::tm_hour << ":";
	}

	if (mTime->tm::tm_min < 10) {
		cout << "0" << mTime->tm::tm_min << ":";
	} else {
		cout << mTime->tm::tm_min << ":";
	}

	if (mTime->tm::tm_sec < 10) {
		cout << "0" << mTime->tm::tm_sec;
	} else {
		cout << mTime->tm::tm_sec;
	}

	cout << "           *" << endl;
	cout << "***************************      ***************************" << endl;

	return;
}

int main() {

	vector <int> time12Hour {11, 59, 59};
	militaryTime time24Hour(23, 59, 59);
	showTime(time12Hour, time24Hour);

	//Show menu
	while(true) {
		cout << "***************************" << endl;
		cout << "*    1 - Add One Hour     *" << endl;
		cout << "*    2 - Add One Minute   *" << endl;
		cout << "*    3 - Add One Second   *" << endl;
		cout << "*    4 - Exit Program     *" << endl;
		cout << "***************************" << endl;

		int userInput;

		cout << "Please enter selection, press 4 to exit: ";
		cin >> userInput;

		//switch statement to translate user input in to correct function
		switch (userInput) {
			case 1:
				time12Hour.addOneHour();
				time24Hour.addOneHour();
				showTime(time12Hour, time24Hour);
				break;

			case 2:
				time12Hour.addOneMinute();
				time24Hour.addOneMinute();
				showTime(time12Hour, time24Hour);
				break;

			case 3:
				time12Hour.addOneSecond();
				time24Hour.addOneSecond();
				showTime(time12Hour, time24Hour);
				break;

			case 4:
				cout << "Goodbye";
				exit(1);
				break;

			default:
				cout << "Invalid selection" << endl;
				break;
		}
		return 0;
	}
}

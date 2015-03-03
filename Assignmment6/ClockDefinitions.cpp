#include <sstream>
#include <ostream>
#include "Clock.h"
using namespace std;
clock::clock() : hours(1),minutes(1), currentTimer(1), timerCount(1)
{
}

clock::clock(int hour, int minute)
{
	hours          = hour;
	minutes        = minute;
	currentTimer   = 0;
	timerCount     = 0;
	timerComplete      = false;
	timerSet           = true;

}

clock::clock(const clock & otherClock)
{
	hours 		 = otherClock.hours;
	minutes		 = otherClock.minutes;
	currentTimer = 0;
	timerCount   = 0;
	timerComplete       = false;
	timerSet           = true;


}

clock::~clock()
{
}

const clock & clock::operator = (const clock & rhs)
{
	if(this == &rhs)
	{
		return *this;
	}

	minutes = rhs.minutes;
	hours   = rhs.hours;

	return *this;
}



//
//
//void setTimer(int timerAmount);

void clock::incrementSysClock()
{

	if(timerSet)
	{
		incrementTimer();
	}
	if(minutes == 59)
	{
		if(hours == 12)
		{
			hours = 1;
		}
		else
		{
			hours++;

		}

		minutes = 0;
	}
	else
	{

		minutes++;

	}


//	cerr << "hours: "   << hours     << endl;
//	cerr << "minutes: " << minutes   << endl << endl;
}
void clock::clearTimer()
{
	currentTimer  = 0;
	timerCount    = 0;
	timerComplete = false;
	timerSet      = false;
}


void clock::setTimer(int timerAmount)
{
	currentTimer  = timerAmount;
	timerCount    = 0;
	timerComplete = false;
	timerSet      = true;
}


bool clock::isTimerComplete()
{
	return timerComplete;
}

void clock::incrementTimer()
{
	if(timerCount == currentTimer - 1)
	{
		timerCount   = 0;
		currentTimer  = 0;
		timerComplete = true;
		timerSet      = false;

	}
	else
	{
		++timerCount;
	}
}

string clock::getCurrentTime()
{
	ostringstream out;
	string time;



	if(hours < 10 && minutes < 10)
	{
		out << "0" << hours << ":" << "0" << minutes;
	}
	else if(hours < 10)
	{
		out << "0" << hours << ":" << minutes;
	}
	else if(minutes < 10)
	{
		out << hours << ":" << "0" << minutes;
	}
	else
	{
		out << hours << ":" << minutes;
	}
	time = out.str();
	out.str("");

	return time;
}


void clock::setNewTime(int hour, int minute)
{
	hours   = hour;
	minutes = minute;
}
//	void setNewTime(string someNewTime);
//	void setNewTime(int someNewTime);
//	string getCurrentTime();
//	int getHour();
//	int getMinute();

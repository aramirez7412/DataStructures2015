#include <iostream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class clock
{
private:
	int hours;
	int minutes;
	int currentTimer;
	int timerCount;

	bool timerComplete;
	bool timerSet;



public:

	clock();
	clock(int hour, int minute);
	clock(const clock & otherClock);
	~clock();

	const clock & operator = (const clock & rhs);

	void setTimer(int timerAmount);
	void incrementTimer();
	void setNewTime(int hours, int minutes);
	string getCurrentTime();
	int getHour();
	int getMinute();
	void incrementSysClock();
	bool isTimerComplete();
	void clearTimer();


//	int return

};


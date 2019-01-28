//
// Created by Mela on 2019-01-27.
//

#ifndef UNTITLED_TIMER_H
#define UNTITLED_TIMER_H


class Timer {
private:
	/// The clock time when the timer started
	int startTicks;

	/// The timer status
	bool started;

public:
	//Initializes variables
	Timer();

	//The various clock actions
	void start();
	void stop();

	//Gets the timer's time
	int get_ticks();

	//Checks the status of the timer
	bool is_started();
};


#endif //UNTITLED_TIMER_H

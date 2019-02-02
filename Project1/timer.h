//
// Created by Mela on 2019-01-27.
//

#ifndef UNTITLED_TIMER_H
#define UNTITLED_TIMER_H


class Timer {
private:
	int startTicks;
	bool started;

public:
	Timer();

	void start();
	void stop();

	int get_ticks();
	bool is_started();
};


#endif //UNTITLED_TIMER_H

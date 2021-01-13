#pragma once

#include "Singleton.h"
#include "SDL.h"

class TimeManager :public Singleton<TimeManager>
{
	friend class Singleton<TimeManager>;

private:
	double deltaTime;
	double timeScale;
	double currentTime;

	TimeManager();
	~TimeManager();
public:
	void Init(void);
	void Update(void);

	double getDeltaTime();
	double getUnscaledDeltaTime();
	int getCurrentTime();

	void setTimeScale(double scale);
};
#pragma once
#include "TimeManager.h"


TimeManager::TimeManager()
{
	deltaTime = 0;
	timeScale = 1;
	currentTime = 0;
}

TimeManager::~TimeManager()
{

}

void TimeManager::Init() {
	
}

void TimeManager::Update() {

	deltaTime = SDL_GetTicks() - currentTime;
	currentTime = SDL_GetTicks();
}

double TimeManager::getDeltaTime()
{
	return (deltaTime/1000) * timeScale;
}
double TimeManager::getUnscaledDeltaTime() {
	return (deltaTime / 1000);
}

int TimeManager::getCurrentTime()
{
	return currentTime;
}

void TimeManager::setTimeScale(double scale)
{
	if (scale < 0) {
		scale = 0;
	}
	timeScale = scale;
}

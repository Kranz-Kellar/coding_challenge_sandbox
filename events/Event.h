#pragma once

enum EventType {
	EV_NONE,
	EV_KEYBOARD,
	EV_MOUSE,
	EV_SYSTEM //Слишко обобщённо. Стоит разбить на несколько частей
};

class Event
{
public:
	EventType type;

	Event() : type(EV_NONE) {}
};


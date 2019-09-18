#pragma once

enum EventType {
	EV_DEBUG,
	//Keys
	EV_KEY_W,
	EV_KEY_S,
	EV_KEY_A,
	EV_KEY_D,
	EV_KEY_ESC
};

class Event
{
public:
	EventType type;

	Event(EventType _type) : type(_type) {}
};


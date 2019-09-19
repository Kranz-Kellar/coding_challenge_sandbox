#pragma once

enum EventType {
	EV_NONE,
	EV_KEYBOARD,
	EV_MOUSE,
	EV_SYSTEM //������ ���������. ����� ������� �� ��������� ������
};

class Event
{
public:
	EventType type;

	Event() : type(EV_NONE) {}
};


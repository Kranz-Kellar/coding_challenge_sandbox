#pragma once


#include "../System.h"
#include "IDrawData.h"


class IRenderer : public System
{
public:
	void virtual Draw2DObject(IDrawData* drawData) = 0;
	virtual ~IRenderer() {};
};


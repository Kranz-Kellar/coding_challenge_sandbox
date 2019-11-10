#pragma once


#include "System.h"
#include "renderer/IDrawData.h"


class IRenderer : public System
{
	void Init();
public:
	IRenderer();

	void virtual Draw2DObject(IDrawData* drawData) = 0;
	virtual ~IRenderer() {};
};


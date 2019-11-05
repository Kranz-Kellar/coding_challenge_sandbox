#pragma once


#include "../System.h"
#include "IDrawData.h"

namespace Erbium {

	class IRenderer : public Module
	{
	public:
		void virtual Draw2DObject(IDrawData* drawData) = 0;
		virtual ~IRenderer() {};
	};

}
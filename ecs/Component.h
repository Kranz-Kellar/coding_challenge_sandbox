#pragma once

#include "..//util/UniqueId.h"
#include <string>


namespace Erbium {

	class Component {
		UniqueId id;


		void* operator new(std::size_t count) = delete;
		void* operator new[](std::size_t count) = delete;
	};

}
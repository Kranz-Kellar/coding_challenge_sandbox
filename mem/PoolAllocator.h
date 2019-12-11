#pragma once

#include <vector>
#include "..//Logger.h"


namespace Erbium {

	struct {
		uint8_t* mem;

	};


	template<class T, uint32_t size = 200>
	class PoolAllocator
	{

		uint8_t* mem;
		size_t sizeOfMemChunk;
		uint32_t sizeOfPool;

		std::vector<T*> chunks;
	public:
		PoolAllocator() {
			sizeOfMemChunk = sizeof(T);
			sizeOfPool = size;
		}
		void* allocate();
		void free();

	};

}


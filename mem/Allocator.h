#pragma once
#include <string>
#include <memory>
#include "..//Logger.h"

namespace Erbium {

	struct MemBuffer {
		uint8_t* memory;
		size_t maxSize;
		size_t curentOffset;
	};


	class Allocator
	{
		MemBuffer* buffer;
	public:

		Allocator(size_t size);
		void* allocate(size_t size);
		void free(size_t size);
		void getNewMemory(size_t size);
		void freeAllMemory();
		size_t getAmountOfFreeMemory();
		size_t getAmountOfMaxMemory();
		size_t getAmountOfUsedMemory();
		~Allocator();

	};

}


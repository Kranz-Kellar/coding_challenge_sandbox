#include "Allocator.h"


Allocator::Allocator(size_t size) : buffer() {
	void* ptr = malloc(size);
	if (ptr == nullptr) {
		Logger::Log("Allocator::ctor is failed. Malloc returns nullptr", LOG_ERROR);
		return;
	}

	buffer = new MemBuffer();
	buffer->memory = static_cast<uint8_t*>(ptr);
	buffer->maxSize = size;
	buffer->curentOffset = 0;
};

void* Allocator::allocate(size_t size) {
	if (size > buffer->maxSize) {
		Logger::Log("Allocator::Trying to allocate invalid size of memory. Size was " + std::to_string(size), LOG_ERROR);
		return nullptr;
	}

	if (buffer->maxSize - buffer->curentOffset < size) {
		Logger::Log("Allocator::Not enough memory", LOG_ERROR);
		return nullptr;
	}

	void* ptr = buffer->memory + buffer->curentOffset;
	buffer->curentOffset += size;
	return ptr;
}


void Allocator::free(size_t size) {
	if (size > buffer->maxSize || size > buffer->curentOffset) {
		Logger::Log("Allocator::Trying to free invalid size of memory. Size was " + std::to_string(size), LOG_ERROR);
		return;
	}

	buffer->curentOffset -= size;
}

void Allocator::getNewMemory(size_t size) {
	if (buffer->memory != nullptr) {
		Logger::Log("Allocator::Trying to get more memory without freeing the previous chunk of memory", LOG_ERROR);
		return;
	}
	void* memPtr = malloc(size);
	if (memPtr == nullptr) {
		Logger::Log("Allocator::ctor is failed. Malloc returns nullptr", LOG_ERROR);
		return;
	}

	buffer = new MemBuffer();
	buffer->memory = static_cast<uint8_t*>(memPtr);
	buffer->maxSize = size;
	buffer->curentOffset = 0;
}

void Allocator::freeAllMemory() {
	std::free(buffer->memory);
	buffer->memory = nullptr;
	buffer->curentOffset = 0;
	buffer->maxSize = 0;
}

size_t Allocator::getAmountOfFreeMemory() {
	return buffer->maxSize - buffer->curentOffset;
}

size_t Allocator::getAmountOfMaxMemory() {
	return buffer->maxSize;
}

size_t Allocator::getAmountOfUsedMemory() {
	return buffer->curentOffset;
}

Allocator::~Allocator() {
	freeAllMemory();
}
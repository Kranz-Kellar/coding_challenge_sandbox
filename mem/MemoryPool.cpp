#include "MemoryPool.h"

using namespace Erbium;

template<class T>
MemoryPool<T>::MemoryPool(uint32_t countOfMemoryChunks)
{
	this->countOfChunks = countOfMemoryChunks;
}

template<class T>
inline T MemoryPool<T>::Allocate()
{
	return T();
}

template<class T>
void MemoryPool<T>::Free(T object)
{
	return T();
}

template<class T>
void MemoryPool<T>::CreateNewPool()
{

}

template<class T>
void MemoryPool<T>::ResetPool()
{
	this->memoryAllocator.freeAllMemory();
	
}

template<class T>
inline size_t MemoryPool<T>::getSizeOfChunk()
{
	return this->sizeOfChunk;
}

template<class T>
inline uint32_t MemoryPool<T>::getCountOfChunk()
{
	return this->countOfChunks;
}

template<class T>
inline uint32_t MemoryPool<T>::getCountOfUsedChunks()
{
	return this->countOfUsedChunks;
}

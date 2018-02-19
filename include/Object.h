#pragma once

template<typename Type>
class Object final{
	int32_t referenceNumber=0;
	Type * data;
	std::mutex m;
	bool loaded=false;
	public:
	Object();
	~Object();
	int32_t incrementReferenceNumber();
	int32_t decrementReferenceNumber();
	bool isLoaded();
	void unlockMutex();
	void lockMutex();
	void setRawPointer(Type * dataPtr);
	Type& get();
};

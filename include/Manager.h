#pragma once

template<typename Type>
class Manager final{
	public:
	Manager(){}
	Object<Type> * getObject(ILoader<Type> & loader);
	void incrementReferenceNumber(ILoader<Type> & loader);
	void decrementReferenceNumber(ILoader<Type> & loader);
	virtual ~Manager(){}
	private:
	std::unordered_map< ILoader<Type> , Object<Type>* , LoaderHasher<Type>> map;
};
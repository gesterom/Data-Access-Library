#pragma once

template<typename Type>
class Manager final{
	public:
	Manager(){}
	Object<Type> * getObject(Loader<Type> & loader);
	void incrementReferenceNumber(Loader<Type> & loader);
	void decrementReferenceNumber(Loader<Type> & loader);
	virtual ~Manager(){}
	private:
	std::unordered_map< Loader<Type> , Object<Type>* , LoaderHasher<Type>> map;
};
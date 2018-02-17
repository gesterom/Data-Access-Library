#pragma once

template<typename Type>
class LoaderHasher{
	public:
	LoaderHasher(){}
	std::size_t operator() (ILoader<Type> const & l) const;

};

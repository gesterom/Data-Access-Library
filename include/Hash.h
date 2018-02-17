#pragma once

template<typename Type>
class LoaderHasher{
	public:
	LoaderHasher(){}
	std::size_t operator() (Loader<Type> const & l) const;

};

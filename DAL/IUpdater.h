#pragma once

template<typename Type>
class IUpdater {
  public:
	virtual void update( Type& ) = 0;
	virtual IUpdater<Type>* getCopyPtr()const = 0;
	virtual ~IUpdater() {}
};
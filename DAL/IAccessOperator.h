#pragma once

template<typename Type>
class IAccessOperator {
  public:
	virtual Type* load() = 0;
	virtual void update( Type& ) = 0;
	virtual std::string toString() = 0;
	virtual IAccessOperator<Type>* getCopyPtr()const = 0;
	virtual ~IAccessOperator() {}
};
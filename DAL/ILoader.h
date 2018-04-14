#pragma once

template<typename Type>
class ILoader {
  public:
	virtual Type* load() = 0;
	virtual std::string toString() = 0;
	virtual ILoader<Type>* getCopyPtr()const = 0;
	virtual ~ILoader() {}
};
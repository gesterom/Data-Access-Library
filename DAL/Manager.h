#pragma once

template<typename Type>
class Manager final {
  public:
	Manager() {}
	Object<Type>* getObject( IAccessOperator<Type>& access );
	void incrementReferenceNumber( IAccessOperator<Type>& access );
	void decrementReferenceNumber( IAccessOperator<Type>& access );
	virtual ~Manager() {}
  private:
	std::unordered_map< std::string, Object<Type>* > map;
	std::mutex mMag;
};
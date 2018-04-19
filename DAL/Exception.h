#pragma once

class NotImplemented : public std::exception {
	std::string msg;
  public:
	NotImplemented( std::string name ) : msg( name ) {}
	std::string get() {
		return msg;
	}
	virtual const char* what() const noexcept override {
		return msg.c_str();
	}
};
class NullReferenceException : public std::exception {
  public :
	NullReferenceException() {}
};

class ThisIsNotPossible : public std::exception {
	std::string msg;
  public:
	ThisIsNotPossible( std::string name ) : msg( name ) {
		//std::cout << msg << std::endl;
	}
	std::string get() {
		return msg;
	}
	virtual const char* what() const noexcept override {
		return msg.c_str();
	}
};


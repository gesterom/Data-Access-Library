#include <iostream>
#include "../DAL/DAL.h"
#include <fstream>
#include <string>


// my simple domain class
class User{
	int id;
	std::string name;
	int balance;
	public:
		User(int id, std::string name, int balance){
			this->id = id ;
			this->name = name;
			this->balance=balance;
		}
		int getBalance(){return this->balance;}
		std::string getName(){return this->name;}
};

template<typename Type>
class Loader{};

//loader(builder) to create instance of my class(User)
template<>
class Loader <User> : public DAL::ILoader<User>{
	private:
	std::string path;
	int m_id;
	std::string toString_ret;
	
	public:
	Loader(std::string filename,int id) : path(filename), m_id(id){
		toString_ret = "{ "+this->path+", "+std::to_string(this->m_id)+" }";
	}
	virtual User * load() override { //load data from database (or in this case file, this is no mater)
		std::fstream file;
		int t_id;
		int t_balance;
		std::string t_name;
		file.open(path.c_str(),std::ios::in);
		for (int i=0;i<=m_id and file.good();i++){		//stiupid algoritm to get value of object from file ;
			file>>t_id;
			file>>t_balance;
			file>>t_name;
		}
		file.close();
		return new User(t_id,t_name,t_balance);
	}
	virtual std::string toString(){ //this function is used as key is std::unordered_map (hashmap), 
						// so we propone to this func return value witch you get from constructor
		return toString_ret; // smal optimalization for so much call of this function
	}
	virtual DAL::ILoader<User> * getNewPtrToCopyOfThisLader()const { //this function is used in copy constructor of Reference
		return new Loader<User>(this->path,this->m_id);
	}
	virtual ~Loader(){}
};


class Factory{ //very usefull in this case
			//you dont need database connection in business logic or in this case filename of database
	private:
	std::string name;
	public:
	Factory(std::string nameOfFile) : name(nameOfFile){}
	DAL::Reference<User> getNewReferenecToUser(int id){
		return DAL::Reference<User>(new Loader<User>(name,id)); // this is all 
						 // but we propone to use template class factory for generic name ;) 
	}
};

void printOfBalance(Factory f, int id){ //business logic (very very simple)
	auto user = f.getNewReferenecToUser(id); //you dont need database connection or anythings ;) (no more to identify user)
	std::cout<<"User ["<<id<<"] Balace is :"<<(*user).getBalance()<<" $ Name is : "<<(*user).getName()<<std::endl;
}

int main(){
	Factory factory{"./dataSimple3.data"};
	int userid;
	std::cout<<"Please enter ID user to print Balace : ";
	std::cin>>userid;
	printOfBalance(factory,userid);
	
}








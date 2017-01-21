#include "object.h"
#include "Person.h"
#include <sstream>
using namespace std;
Person::Person(){

}

Person::Person(string name, int age){
	this->name = name;
	this->age = age;
}

string Person::toString()const{
	stringstream ss;
	ss << "Name "<< name;
	ss << endl; 
	ss << "Age"<< age;
	return ss.str();
}

bool Person::equals(object* other)const{
	if(!dynamic_cast<Person*>(other)){
		return false;
	}
	Person* p = dynamic_cast<Person*>(other);
	return p-> name == name;
}
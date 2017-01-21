#include <sstream>
#include "object.h"
using namespace std;
object::object(){
}

object::~object(){
}

string object::toString()const{
	stringstream ss;
	ss<<"Object@"<<this;
	return ss.str();
}

bool object::equals(object* other)const{
	return other==this;

}
#pragma once
#include <string>
using namespace std;
class object{
public:
	object();
	virtual ~object();
	virtual string toString()const;
	virtual bool equals(object*)const;
};



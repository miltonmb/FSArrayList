#pragma once
class Person: public object{
	string name;
	int age;

	public:
		Person();
		Person(string,int);
		virtual string toString()const;
		virtual bool equals(object*)const;
};




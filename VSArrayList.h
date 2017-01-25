#pragma once
#include "ADTList.h"
#include "object.h"
using namespace std;
class VSArrayList: public ADTList{
	object** array;
	int currentCapacity;
	int delta;

	public:
		VSArrayList(int,int);
		virtual ~VSArrayList();
		virtual bool insert(object*, int);
		virtual object* remove(int);
		virtual object* first()const;
		virtual object* last()const;
		virtual void clear();
		virtual int indexOf(object*)const;
		virtual object* get(int);
		virtual bool isEmpty()const;
		virtual int Capacity()const;
		virtual bool isFull()const;
		void resize();

};

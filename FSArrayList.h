#pragma once
#include "ADTList.h"
#include "object.h"
using namespace std;
class FSArrayList:public ADTList{
	int capacity;
	object** array;

	public:
		FSArrayList();
		FSArrayList(int);
		virtual ~FSArrayList();
		virtual bool insert(object*, int);
		virtual object* remove(int);
		virtual object* first()const;
		virtual object* last()const;
		virtual void clear();
		virtual int indexOf(object*)const;
		virtual object* get(int);
		virtual int Capacity()const;
		virtual bool isEmpty()const;
		virtual bool isFull()const;
};





#pragma once
#include "object.h"
class ADTList{
		protected:
			int size;
		public:
			ADTList();
			virtual ~ADTList();
			int Size()const;
			virtual bool insert(object*, int)=0;
			virtual object* remove(int)=0;
			virtual object* first()const=0;
			virtual object* last()const=0;
			virtual void clear()=0;
			virtual int indexOf(object*)const=0;
			virtual object* get(int)=0;
			virtual int Capacity()const=0;
			virtual bool isEmpty()const=0;
			virtual bool isFull()const=0;

};


#include "FSArrayList.h"
#include "ADTList.h"
#include "object.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;
FSArrayList::FSArrayList(){
	
}
FSArrayList::FSArrayList(int capacity){
	this-> capacity = capacity;
	array = new object*[capacity];
	if(!array){
		cerr << "Out of memory"<<endl;
		exit(EXIT_FAILURE);
	}
}

FSArrayList::~FSArrayList(){
	for (int i = 0; i < size; ++i){
		if(!array){
			delete array[i];
			
		}
		delete [] array;
	}
}

bool FSArrayList::insert(object* e, int p){
	if(p < 0 || p > Size()){
		return false;
	}
	if(isFull()){
		return false;
	}

	for (int i = size; i > p; i--){
		array[i]=array[i-1];
	}
	array[p]=e;
	size++;
	return true;
}

object* FSArrayList::remove(int p){
	object* deletedItem= array[p];
	if(p < 0 || p > Size()){
		return NULL;
	}
	if(isFull()){
		return NULL;
	}
	for (int i = 1; i < size; ++i){
		array[i] = array[i+1];
	}
	size --;
	return deletedItem;

}

object* FSArrayList::first()const {
	if (array[0]==NULL){
		return NULL;
	}
	return array[0];
}

object* FSArrayList::last()const{
	return array[size-1];
}



void FSArrayList::clear(){
	for(int i = 0; i < Size();i++){
		 if(array[i]){
			delete array[i];
			array[i]=NULL;
		}	
	}
}
int FSArrayList::indexOf(object* e)const {
	for (int i = 0; i < size; ++i){
		if (e -> equals(array[i])){
			return i;
		}
	}
	return -1;
}

object* FSArrayList::get(int p){
	object* getObj = array[p];

	return getObj;
}

int FSArrayList::Capacity()const {
	return this -> capacity;
}

bool FSArrayList::isEmpty()const {
	if (size == 0)
	{
		return true;
	}
	return false;
}

bool FSArrayList::isFull()const {
	if (capacity == Size())
	{
		return true;
	}

	return false;
}
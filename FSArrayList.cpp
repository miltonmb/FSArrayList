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
	if(!isEmpty()){
		object* deletedItem= array[p];
		delete array[p];
		if(p < 0 || p > Size()){
			return 0;
		}
		for (int i = p; i < size; ++i){
			array[i] = array[i+1];
		}
		size --;
		return deletedItem;
	}else{
		return 0;
	}
}

object* FSArrayList::first()const {
	if(!isEmpty()){
		if (array[0]==0){
			return 0;
		}
		return array[0];
	}else{
		return 0;
	}
}

object* FSArrayList::last()const{
	if(!isEmpty()){
		return array[size-1];
	}else{
		return 0;
	}	
}



void FSArrayList::clear(){
	for(int i = 0; i < Size();i++){
		 if(array[i]){
			delete array[i];
			array[i]= 0;
		}	
	}
	size  = 0;
}
int FSArrayList::indexOf(object* e)const {
	if(!isEmpty()){
		for (int i = 1; i < size; ++i){
			if (e -> equals(array[i])){
				return i;
			}
		}
	return -1;
	}
}

object* FSArrayList::get(int p){
	if(!isEmpty()){
		if(p < 0 || p>Size()){
			return 0;
		}else{
			object* getObj = array[p];
			return getObj;
		}
	}else{
		return 0;
	}
}

int FSArrayList::Capacity()const {
	return this -> capacity;
}

bool FSArrayList::isEmpty()const {
	if (size == 0){
		return true;
	}
	return false;
}

bool FSArrayList::isFull()const {
	if (capacity == Size()){
		return true;
	}

	return false;
}
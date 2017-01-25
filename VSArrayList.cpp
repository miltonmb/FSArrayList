#include "VSArrayList.h"
#include "ADTList.h"
#include "object.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;

VSArrayList::VSArrayList(int tamanio,int delta){
	this->delta = delta;
	array = new object*[tamanio];
	if(!array){
		cerr << "Out of memory"<<endl;
		exit(EXIT_FAILURE);
	}
}

VSArrayList::~VSArrayList(){
	for (int i = 0; i < size; ++i){
		if(!array){
			delete array[i];
			
		}
		delete [] array;
	}
}

bool VSArrayList::insert(object* e, int p){
	if(p < 0 || p > Size()){
		return false;
	}
	if(size == currentCapacity){
		resize();
	}
	for (int i = size; i > p; i--){
		array[i]=array[i-1];
	}
	array[p]=e;
	size++;
	return true;
}

object* VSArrayList::remove(int p){
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

object* VSArrayList::first()const {
	if(!isEmpty()){
		if (array[0]==0){
			return 0;
		}
		return array[0];
	}else{
		return 0;
	}
}

object* VSArrayList::last()const{
	if(!isEmpty()){
		return array[size-1];
	}else{
		return 0;
	}	
}



void VSArrayList::clear(){
	for(int i = 0; i < Size();i++){
		 if(array[i]){
			delete array[i];
			array[i]= 0;
		}	
	}
	size  = 0;
}
int VSArrayList::indexOf(object* e)const {
	if(!isEmpty()){
		for (int i = 1; i < size; ++i){
			if (e -> equals(array[i])){
				return i;
			}
		}
	return -1;
	}
}

object* VSArrayList::get(int p){
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

int VSArrayList::Capacity()const {
	return this -> currentCapacity;
}

bool VSArrayList::isEmpty()const {
	if (size == 0){
		return true;
	}
	return false;
}

bool VSArrayList::isFull()const {
	return false;
}

void VSArrayList::resize(){
	object** temp = 0;
	temp = new object*[currentCapacity+delta];
	//validar memoria
	for (int i = 0; i < currentCapacity; ++i){
		temp[i]=array[i];
	}
	delete[] array;
	array = temp;
	currentCapacity += delta;
}





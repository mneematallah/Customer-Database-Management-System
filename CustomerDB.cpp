// CRM in C++ <CostumerDB.cpp>
// EE 312 Project 7 submission by
// <Moustafa Neematallah>
// <man3394>
// Slip days used: <0>
// Spring 2023

#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    int i=0;
    while(i<this->length){
        if(name == this->data[i].name){
            return this->data[i];
        }
        i++;
    }
    if(this->length>=this->capacity){
        this->capacity *= 2;
        Customer* new_data = new Customer[this->capacity];
        for (int i = 0; i < this->length; i++) {
            new_data[i] = this->data[i];
        }
        delete [] data;
        this->data = new_data;
    }
    this->data[this->length].name = name;
    this->data[this->length].bottles=0;
    this->data[this->length].rattles=0;
    this->data[this->length].diapers=0;
    this->length++;
    return this->data[this->length-1];
}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here
    int i=0;
    if(this->length==0) {
        return 0;
    }//If many costumers in directory, go through anf look for name
    while(i<this->length){
        if(name==data[i].name){
            return true;
        }
        i++;
    }
    return false;
}

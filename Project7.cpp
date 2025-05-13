// CRM in C++ <CostumerDB.cpp>
// EE 312 Project 7 submission by
// <Moustafa Neematallah>
// <man3394>
// Slip days used: <0>
// Spring 2023

#include <stdio.h>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"

void readString(UTString&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

void processPurchase() {
    UTString costumerName;
    UTString itemType;
    int Quantity;
    readString(costumerName);
    readString(itemType);
    readNum(Quantity);
    int inventory;
    inventory= *selectInventItem(itemType);
    if(Quantity<=0){
        return;
    }
    if((itemType=="Bottles")) {
        if(num_bottles>=Quantity){
            *selectInventItem(itemType, database[costumerName])=*selectInventItem(itemType, database[costumerName])+Quantity;
        }else{
            printf("Sorry %s, we only have %d Bottles\n",costumerName.c_str(), inventory);
        }
    }
    if((itemType=="Rattles")) {
        if (num_rattles >= Quantity) {
            *selectInventItem(itemType, database[costumerName])=*selectInventItem(itemType, database[costumerName])+Quantity;
            database[costumerName].rattles += Quantity;
        } else {
            printf("Sorry %s, we only have %d Rattles\n", costumerName.c_str(), inventory);
        }
    }
    if((itemType=="Diapers")) {
        if (num_diapers >= Quantity) {
            *selectInventItem(itemType, database[costumerName])=*selectInventItem(itemType, database[costumerName])+Quantity;
        } else {
            printf("Sorry %s, we only have %d Diapers\n", costumerName.c_str(), inventory);
        }
    }
    //if(!database.isMember(costumerName)){
    //    return;
    //}
    *selectInventItem(itemType)= *selectInventItem(itemType)-Quantity;
    //&& database.isMember(costumerName)
}

void processSummarize() {
    printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n", num_bottles, num_diapers, num_rattles);
    printf("we have had a total of %d different customers\n", database.size());
    Customer* MaxDiapers= findMax("Diapers");
    Customer* MaxRattles= findMax("Rattles");
    Customer* MaxBottles= findMax("Bottles");
    if((MaxBottles==NULL)){
        printf("no one has purchased any Bottles\n");
    }else{
        printf("%s has purchased the most Bottles (%d)\n", MaxBottles->name.c_str(), MaxBottles->bottles);
    }
    if((MaxDiapers==NULL)){
        printf("no one has purchased any Diapers\n");
    }else{
        printf("%s has purchased the most Diapers (%d)\n", MaxDiapers->name.c_str(), MaxDiapers->diapers);
    }
    if( (MaxRattles==NULL)){
        printf("no one has purchased any Rattles\n");
    }else{
        printf("%s has purchased the most Rattles (%d)\n", MaxRattles->name.c_str(), MaxRattles->rattles);
    }
}



void processInventory() {
    UTString itemType;
    int Quantity;
    readString(itemType);
    readNum(Quantity);
    int inventory;
    inventory= *selectInventItem(itemType);
    if(Quantity<0){
    }else if(itemType=="Bottles"){
        inventory=inventory+Quantity;
        num_bottles=inventory;
    }else if(itemType=="Rattles"){
        inventory=inventory+Quantity;
        num_rattles=inventory;
    }else if(itemType=="Diapers"){
        inventory=inventory+Quantity;
        num_diapers=inventory;
    }

}

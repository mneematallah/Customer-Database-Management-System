# CRM in C++ – Customer Database Management

This project implements a simple **Customer Relationship Management (CRM)** system in C++ for tracking product purchases by customers. It was developed as **Project 7** for **EE 312 – Software Design and Implementation**, Spring 2023, under Prof. Edison Thomaz at The University of Texas at Austin.

## Objective

The goal was to build a basic in-memory customer database system that supports:
- Efficient customer lookup by name
- Automatic customer creation upon first access
- Purchase tracking of three products: **bottles**, **rattles**, and **diapers**

This project gave practice with:
- C++ class design and memory management
- Operator overloading
- Dynamic arrays and resizing
- Custom string class implementation (`UTString`)

## Project Structure

- `Customer.h`: Defines the `Customer` struct to hold customer names and product purchase counts.
- `CustomerDB.h` / `CustomerDB.cpp`: Implements a dynamic array-based database that stores and retrieves customer data by index or name.
- `UTString.h`: Custom lightweight string class used for memory-safe string handling and comparisons.

## Key Features

- **Dynamic Customer Lookup**: Accessing a customer via `CustomerDB[name]` will automatically add them to the database if they don't already exist.
- **Custom UTString Class**: Lightweight string wrapper supporting equality and ordering comparisons.
- **Dynamic Array Growth**: CustomerDB doubles its capacity as needed when new customers are added.
- **Purchase Tracking**: Tracks three product types for each customer (`bottles`, `rattles`, `diapers`).

## Sample Functionalities

- `db["Alice"]` → Adds or retrieves customer “Alice”
- `db.isMember("Bob")` → Checks if “Bob” exists in the database
- `db.clear()` → Clears and resets the database

## Testing & Submission
All dynamic memory operations were managed using heap-allocated arrays.

The system was tested with edge cases including:

Multiple customers with the same name

Empty database operations

Auto-expansion on capacity overflow

## Author
Moustafa Neematallah

## Example Use

```cpp
CustomerDB db;
db["Alice"].bottles += 2;
db["Bob"].rattles += 1;

if (db.isMember("Charlie")) {
    std::cout << "Charlie exists!\n";
} else {
    std::cout << "Charlie not found.\n";
}

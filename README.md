# Car-Dealership-Project
Created a C++ Car Dealership Project using the concepts of Object Oriented Programming (OOP) and Data File Handling. Manages the day to day operations of a car dealership, including managing customer and employee databases, generating invoices for purchases, and details of the cars available. 

# Objective
The Car Dealership program has been developed to store information pertaining to the variety of cars and customers. A provision has been made for customers to purchase a car of their choice as well.

# Abstract
This program is mainly run by the employees at the dealership, for three different purposes:
1. Car Details: Under this submenu, the employee can perform the following;
    •	Add the details of a car model to the list of available models.
    •	View the list of available models.
    •	Propagate updates to the details of available models.
    •	Remove a particular model from the list of available models.
2. Customer Details: Under this submenu, the employee can perform the following;
    •	View the details of customers who have purchased a car(s) from the dealership.
    •	Propagate updates to the details of the customers.
    •	Delete the record of a particular customer.
3. Booking: Under this submenu, the employee assists the customer in booking a car of their choice and specification. After entering the necessary details, an invoice is generated which prints the net payable amount for the customer.

# Files Generated
In this program, the following files were generated in order to store the data related to cars and customers;
1.	Cars.dat: Used to store the specifications of different models of cars.
2.	CustCar.dat: Used for storing information related to the customer.

# Functions Used
In this program, the following functions were made use of;
•	void AddCars(): Used for adding details of a car.
•	void ModifyCars(): Used for modifying the details of a car.
•	void DelCars(): Used for deleting the record of a car.
•	void ViewCars(): Used for viewing the list of available cars.
•	int GetModelNo(): Used for returning private data member ModelNo of class Cars.
•	long int ReturnBasePrice(): Used for returning private data member BasePrice of class Cars.
•	char *GetModelName(): Used for returning private data member ModelName of class Cars. 
•	char *ReturnEng(): Used for returning private data member Engine of class Cars.
•	void AddCust(): Used to add customer details.
•	void ViewCust(): Used to view customer details.
•	void DelCust(): Used to delete customer details.
•	void ModifyCust(): Used to modify customer details.
•	void Booking(): Used when customer has to book a car.
•	int GetCustNo(): Used for returning private data member CustNo of class CustCar.
•	char *GetCustName(): Used for returning private data member CustName of class CustCar.

![image](https://user-images.githubusercontent.com/81959120/149126941-9bf5fa52-ee44-48b5-9fde-21db19e1d3b7.png)



# Linked List Car Rental Management

## This program manages a car rental system using three linked lists for cars:
Available cars, Rented cars, Repair cars

### Key Features:
1. Adding Cars: Cars can be added to the available-for-rent list.
2. Returning Cars: Handles cars returned from customers, either adding them to the available or repair list.
3. Transferring Cars: Moves cars from the repair list to the available list.
4. Renting Cars: Allocates the first car in the available list to a customer with an expected return date.
5. Sorting: Maintains the lists sorted either by mileage or return date, depending on the context.
6. Saving and Loading: Reads and writes car details to text files (available.txt, rented.txt, repair.txt).
7. Error Handling: Ensures logical data validation, like non-decreasing mileage on returns.

### Linked Lists
The program maintains three separate linked lists for the cars:
- **Available for rent** (sorted by mileage, least to greatest)
- **Rented** (sorted by expected return date, earliest first)
- **In repair**

### Transactions
The program will prompt the user to input a transaction code, and it will perform the respective action. The transaction codes are:

- `1` - Add a new car to the available list (prompt for plate number and mileage).
- `2` - Add a returned car to the available list (prompt for plate number and mileage).
- `3` - Add a returned car to the repair list (prompt for plate number and mileage).
- `4` - Transfer a car from repair to available list (prompt for plate number).
- `5` - Rent the first available car (prompt for expected return date in yymmdd format).
- `6` - Print all lists (no additional prompt needed).
- `7` - Quit the program.

### Rental Charges
For each car that is returned (transaction 2 or 3), the following charges are applied:
- A **flat rate of $80.00** for up to 200 km.
- **15 cents per km** for each additional km over 200.

### Program Quit
When the user selects the quit option (`7`), the program stores the data from all the lists into a file. The next time the program starts, it reads the data from this file and restores the lists.

### Initial Setup
- When the program runs for the first time, it should load data from initial txt files that contain at least 5 cars in each list (available, rented, and in repair).

### Files
The program consists of 4 files, as follows:

1. **main.c**: Contains the `main()` function, which controls the flow of the program.
2. **main.h**: Contains the structure definitions and function prototypes.
3. **functions.c**: Contains all the function implementations that are called by the `main()` function.
4. **makefile**
**available.txt**: Contains a list of all cars available for rent.
**rented.txt**: Contains a list of all cars that have been rented.
**repair.txt**: Contains a list of all cars that are currently under repair.

### Compiling the Program
To compile and run the program, follow these steps:

1. In the directory where the files are saved, type:
	make 

This will compile all necessary files into an executable.

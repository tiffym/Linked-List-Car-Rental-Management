#include "q1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/*
 * A basic menu-based structure has been provided
*/

int main() {
    // Our three Linked Lists
    struct car *available_head = NULL;
    struct car *rented_head = NULL;
    struct car *repair_head = NULL;

    // Read existing data from files
    read_file_into_list("available.txt", &available_head);
    read_file_into_list("rented.txt", &rented_head);
    read_file_into_list("repair.txt", &repair_head);

    int choice;
    char plate[7];  // Matching the size from q1.h
    int mileage, return_date;

    do {
        prompt();
        printf("Enter a Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            // Add a new car to the available-for-rent list
            printf("Enter plate number: ");
            scanf("%s", plate);
            printf("Enter mileage: ");
            scanf("%d", &mileage);
            if (is_plate_in_list(available_head, plate) || is_plate_in_list(rented_head, plate) || is_plate_in_list(repair_head, plate)) {
                printf("Car with plate number %s already exists.\n", plate);
            } else {
                insert_to_list(&available_head, plate, mileage, -1);
                sort_list(&available_head, true, false);
                printf("Car with plate %s added to available-for-rent list.\n", plate);
            }
            break;
        
        case 2:
            // Add a returned car to the available-for-rent list
            printf("Enter plate number: ");
            scanf("%s", plate);
            printf("Enter current mileage: ");
            scanf("%d", &mileage);
            struct car *returned_car = remove_car_from_list(&rented_head, plate);
            if (returned_car) {
                if (mileage >= returned_car->mileage) {
                    double profit = profit_calculator(returned_car->mileage, mileage);
                    printf("Charge for the car: $%.2f\n", profit);
                    insert_to_list(&available_head, plate, mileage, -1);
                    sort_list(&available_head, true, false);
                    free(returned_car);
                } else {
                    printf("Error: Returned mileage cannot be less than the previous mileage.\n");
                    insert_to_list(&rented_head, plate, returned_car->mileage, returned_car->return_date);
                }
            } else {
                printf("Car not found in the rented list.\n");
            }
            break;

        case 3:
            // Add a returned car to the repair list
            printf("Enter plate number: ");
            scanf("%s", plate);
            printf("Enter current mileage: ");
            scanf("%d", &mileage);
            returned_car = remove_car_from_list(&rented_head, plate);
            if (returned_car) {
                if (mileage >= returned_car->mileage) {
                    double profit = profit_calculator(returned_car->mileage, mileage);
                    printf("Charge for the car: $%.2f\n", profit);
                    insert_to_list(&repair_head, plate, mileage, -1);
                    free(returned_car);
                } else {
                    printf("Error: Returned mileage cannot be less than the previous mileage.\n");
                    insert_to_list(&rented_head, plate, returned_car->mileage, returned_car->return_date);
                }
            } else {
                printf("Car not found in the rented list.\n");
            }
            break;

        case 4:
            // Transfer a car from the repair list to the available-for-rent list
            printf("Enter plate number: ");
            scanf("%s", plate);
            struct car *repair_car = remove_car_from_list(&repair_head, plate);
            if (repair_car) {
                insert_to_list(&available_head, plate, repair_car->mileage, -1);
                sort_list(&available_head, true, false);
                free(repair_car);
                printf("Car with plate %s transferred to available-for-rent list.\n", plate);
            } else {
                printf("Car not found in the repair list.\n");
            }
            break;

        case 5:
            // Rent the first available car
            printf("Enter expected return date (yymmdd): ");
            scanf("%d", &return_date);
            struct car *first_available = remove_first_from_list(&available_head);
            if (first_available) {
                first_available->return_date = return_date;
                insert_to_list(&rented_head, first_available->plate, first_available->mileage, return_date);
                sort_list(&rented_head, false, true);
                printf("Car with plate %s rented. Expected return date: %d\n", first_available->plate, return_date);
                free(first_available);
            } else {
                printf("No available cars for rent.\n");
            }
            break;

        case 6:
            // Print all the lists
            printf("Available-for-rent cars:\n");
            print_list(available_head);
            printf("Rented cars:\n");
            print_list(rented_head);
            printf("In-repair cars:\n");
            print_list(repair_head);
            break;

        case 7:
            // Quit and save data to files
            write_list_to_file("available.txt", available_head);
            write_list_to_file("rented.txt", rented_head);
            write_list_to_file("repair.txt", repair_head);
            printf("Exiting program...\n");
            free_list(&available_head);
            free_list(&rented_head);
            free_list(&repair_head);
            return 0;

        default:
            printf("Invalid transaction code.\n");
            break;
        }
        
    } while (true);

    return 0;
}

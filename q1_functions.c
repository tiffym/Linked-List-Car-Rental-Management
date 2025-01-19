#include "q1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* function will display the primary user interface */
void prompt() {
    printf("1. Add a new car to the available-for-rent list,\n");
    printf("2. Add a returned car to the available-for-rent list,\n");
    printf("3. Add a returned car to the repair list,\n");
    printf("4. Transfer a car from the repair list to the available-for-rent list,\n");
    printf("5. Rent the first available car,\n");
    printf("6. Print all the lists,\n");
    printf("7. Quit.\n");
}

/* Inserts a new car into the linked list */
struct car * insert_to_list(struct car **head, char plate[], int mileage, int return_date) {
    struct car *new_car = (struct car *) malloc(sizeof(struct car));
    strcpy(new_car->plate, plate);
    new_car->mileage = mileage;
    new_car->return_date = return_date;
    new_car->next = *head;
    *head = new_car;
    return new_car;
}

/* Prints all the cars in the list */
void print_list(struct car *head) {
    struct car *current = head;
    while (current) {
        printf("Plate: %s, Mileage: %d", current->plate, current->mileage);
        if (current->return_date != -1) {
            printf(", Return Date: %d", current->return_date);
        }
        printf("\n");
        current = current->next;
    }
}

/* Checks if a car's plate is already in the list */
bool is_plate_in_list(struct car *head, char plate[]) {
    struct car *current = head;
    while (current) {
        if (strcmp(current->plate, plate) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

/* Sorts the list of cars */
void sort_list(struct car **head, bool sort_by_mileage, bool sort_by_return_date) {
    if (*head == NULL) return;

    bool swapped;
    struct car *ptr1;
    struct car *lptr = NULL;

    do {
        swapped = false;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if ((sort_by_mileage && ptr1->mileage > ptr1->next->mileage) ||
                (sort_by_return_date && ptr1->return_date > ptr1->next->return_date)) {
                swap(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

/* Swaps two cars in the list */
void swap(struct car *a, struct car *b) {
    char temp_plate[7];
    strcpy(temp_plate, a->plate);
    strcpy(a->plate, b->plate);
    strcpy(b->plate, temp_plate);

    int temp_mileage = a->mileage;
    a->mileage = b->mileage;
    b->mileage = temp_mileage;

    int temp_return_date = a->return_date;
    a->return_date = b->return_date;
    b->return_date = temp_return_date;
}

/* Removes a car from the list by its plate number */
struct car * remove_car_from_list(struct car **head, char plate[]) {
    struct car *temp = *head, *prev = NULL;

    if (temp != NULL && strcmp(temp->plate, plate) == 0) {
        *head = temp->next;
        return temp;
    }

    while (temp != NULL && strcmp(temp->plate, plate) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return NULL;

    prev->next = temp->next;
    return temp;
}

/* Removes the first car from the list */
struct car * remove_first_from_list(struct car **head) {
    if (*head == NULL) return NULL;

    struct car *temp = *head;
    *head = (*head)->next;
    return temp;
}

/* Calculates the profit based on the mileage difference */
double profit_calculator(int initial_mileage, int final_mileage) {
    int mileage_diff = final_mileage - initial_mileage;
    if (mileage_diff <= 200) {
        return 80.00;
    } else {
        return 80.00 + (mileage_diff - 200) * 0.15;
    }
}

/* Writes the list of cars to a file */
void write_list_to_file(char *filename, struct car *head) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    struct car *current = head;
    while (current) {
        // Write each car in the format: plate,mileage,return_date
        fprintf(file, "%s,%d,%d\n", current->plate, current->mileage, current->return_date);
        current = current->next;
    }

    fclose(file);
}

/* Reads car details from a file and adds them to the list */
void read_file_into_list(char *filename, struct car **head) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char plate[7];  // Matching q1.h plate size
    int mileage, return_date;

    while (fscanf(file, "%[^,],%d,%d\n", plate, &mileage, &return_date) != EOF) {
        insert_to_list(head, plate, mileage, return_date);
    }

    fclose(file);
}

/* Frees all the memory allocated for the cars in the list */
void free_list(struct car **head) {
    struct car *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

#include <stdio.h>
#define ROWS 5
#define COLUMNS 2

int parking_lot[ROWS][COLUMNS] = {0}; // 0 indicates empty, 1 indicates occupied

// Function to find the least row and column with the fewest cars parked
void find_least_row_column(int *row, int *column) {
    int min_cars = ROWS * COLUMNS + 1; // Initialize to a value greater than maximum possible cars
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLUMNS; j++) {
            if (parking_lot[i][j] == 1) {
                count++;
            }
        }
        if (count < min_cars) {
            min_cars = count;
            *row = i;
        }
    }
    *column = min_cars % COLUMNS; // Choose the column in the least row with the fewest cars
}

// Function to park a car
void park_car() {
    int row, column;
    find_least_row_column(&row, &column);
    if (parking_lot[row][column] == 0) {
        parking_lot[row][column] = 1;
        printf("Car parked at row %d, column %d\n", row + 1, column + 1);
    } else {
        printf("Error: Parking space already occupied\n");
    }
}

// Function to remove a car
void remove_car() {
    // Implementation to remove a car from a specific row and column
}

int main() {
    int choice;
    do {
        printf("\nSmart Parking System\n");
        printf("1. Park Car\n");
        printf("2. Remove Car\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                park_car();
                break;
            case 2:
                remove_car();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}
    

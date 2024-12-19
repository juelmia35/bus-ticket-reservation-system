#include <stdio.h>
#include <string.h>

char routes[3][50] = {"DAC to CTG", "DAC to SYL", "DAC to COX"};
int availableBuses[3] = {2, 1, 3};
int prices[3] = {1000, 1500, 2000};
int seats[3][52] = {{0}, {0}, {0}}; // 0 = available, 1 = booked
int bookedSeats[3] = {0, 0, 0};     // Tracks the number of booked seats per route

int main() {
    int choice, seat, route, numSeats;
    int totalPrice = 0;

    while (1) {
        printf("\nBus Ticket Reservation\n");
        printf("1. Available Routes and Buses\n");
        printf("2. Available Seats for a Route\n");
        printf("3. Book Seats\n");
        printf("4. Show Total Price\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            for (int i = 0; i < 3; i++) {
                printf("Route %d: %s (Available Buses: %d) (Price: %d)\n", i + 1, routes[i], availableBuses[i], prices[i]);
            }
        } else if (choice == 2) {
            printf("Enter route number (1-3): ");
            scanf("%d", &route);
            if (route < 1 || route > 3) {
                printf("Invalid route number.\n");
                continue;
            }
            printf("Available seats for Route %d:\n", route);
            for (int i = 0; i < 52; i++) {
                if (seats[route - 1][i] == 0) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        } else if (choice == 3) {
            printf("Enter route number (1-3): ");
            scanf("%d", &route);
            if (route < 1 || route > 3) {
                printf("Invalid route number.\n");
                continue;
            }

            if (bookedSeats[route - 1] == 52) {
                printf("All seats are booked for this route.\n");
                continue;
            }

            printf("How many seats do you want to book? ");
            scanf("%d", &numSeats);

            if (bookedSeats[route - 1] + numSeats > 52) {
                printf("Not enough seats. We have only %d seats .\n", 52 - bookedSeats[route - 1]);
                continue;
            }

            for (int i = 0; i < numSeats; i++) {
                printf("Enter seat number to book (1-52): ");
                scanf("%d", &seat);
                if (seat < 1 || seat > 52) {
                    printf("Invalid seat number. Try again.\n");
                    i--;
                    continue;
                }
                if (seats[route - 1][seat - 1] == 1) {
                    printf("Seat %d is already booked. Choose another seat.\n", seat);
                    i--;
                    continue;
                } else {
                    seats[route - 1][seat - 1] = 1;
                    bookedSeats[route - 1]++;
                    printf("Seat %d booked successfully\n", seat);
                    totalPrice += prices[route - 1];
                }
            }
        } else if (choice == 4) {
            printf("Total Price: %d\n", totalPrice);
        } else if (choice == 5) {
            printf("Exiting... Have a nice day\n");
            printf("Thank you for choosing us\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

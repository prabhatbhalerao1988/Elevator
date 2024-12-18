#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep() function

#define MAX_FLOORS 10

int main() 
{
    int current_floor = 1;  // Initial floor (1st floor)
    int destination_floor,i;

    printf("Welcome to the Elevator Simulation!\n");
    printf("We have %d floors in the building (1 to %d).\n", MAX_FLOORS, MAX_FLOORS);

    while(1) 
	{
        // Display the current floor
        printf("\nElevator is at floor %d\n", current_floor);

        // Ask the user for the destination floor
        printf("Enter the destination floor (1 to %d, 0 to exit): ", MAX_FLOORS);
        scanf("%d", &destination_floor);

        // Exit condition (if the user enters 0)
        if (destination_floor == 0) 
		{
            printf("Exiting the elevator simulation. Thank you!\n");
            break;
        }

        // Check if the entered floor is valid
        if (destination_floor < 1 || destination_floor > MAX_FLOORS) 
		{
            printf("Invalid floor! Please enter a floor between 1 and %d.\n", MAX_FLOORS);
            continue;
        }

        // Move the elevator to the destination floor
        if (current_floor < destination_floor)
		 {
            printf("\nElevator is moving up...\n");
            for ( i = current_floor; i <= destination_floor; i++)
			 {
                sleep(3);  // Simulate the elevator moving slowly
                printf("\nElevator is at floor %d\n", i);
            }
        } 
		else if (current_floor > destination_floor) 
		{
            printf("\nElevator is moving down...\n");
            for ( i = current_floor; i >= destination_floor; i--)
			 {
                sleep(2);  // Simulate the elevator moving slowly
                printf("\nElevator is at floor %d\n", i);
                
            }
        }

        // Update the current floor to the destination floor
        current_floor = destination_floor;

        // Optionally, add a pause before the next request
        printf("Press Enter to continue...\n");
        getchar(); // To consume the leftover newline from the previous input
        getchar(); // Wait for user to press Enter
    }

    return 0;
}


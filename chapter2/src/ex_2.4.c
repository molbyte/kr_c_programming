#include <stdio.h>

void call_count() {
    static int count = 0; // Static variable to keep track of the number of calls
    count++; // Increment the count each time the function is called
    printf("Function called %d times\n", count); // Print the current count
}

int main() {
    call_count();
    call_count();
    call_count();
    return 0;
}
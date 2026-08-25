#include <stdio.h>

void call_count(void) {
    static int count = 0; // Static variable to keep track of the number of calls
    count++; // Increment the count each time the function is called
    printf("Function called %d times\n", count); // Print the current count
}

// void call_count() 使用 void call_count(void) 的形式声明函数，表示该函数不接受任何参数。这样更为规范。
// ()只是表示参数未指定，而不是函数不接受任何参数

int main() {
    call_count();
    call_count();
    call_count();
    return 0;
}
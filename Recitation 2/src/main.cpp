#include <mbed.h>

/* Recitation 2 - Part [2]: C Programming Examples
[1] - Student FAQ's
[2] - Pointers Recap
[3] - Basic Structs
[4] - Structs with Arrays
[5] - Next Recitation --> Assembly Programming!! */

struct Student {
    char name[50];  // Member to store the student's name
    int age;        // Member to store the student's age
    float marks[5]; // Array of marks with 5 elements
};

int main() {
    // Initialize struct with name, age, and an array of marks
    struct Student student1 = {"John", 20, {90, 85, 88, 92, 80}};  

    while (1) {  // Infinite loop to keep the program running
        printf("Student Name: %s\n", student1.name);  // Print student's name
        printf("Marks: ");  // Print label for marks
        for (int i = 0; i < 5; i++) {  // Loop through the marks array
            printf("%.2f ", student1.marks[i]);  // Print each mark
        }
        printf("\n");
        thread_sleep_for(1000);  // Delay of 1000 milliseconds (1 second)
    }

}




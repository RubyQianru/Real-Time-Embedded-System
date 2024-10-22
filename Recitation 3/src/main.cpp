#include <mbed.h>
#include <string.h>

// =================================================
// * Recitation 3: Introduction to ARM Assembly *
// =================================================

// Recitation Map: https://docs.google.com/presentation/d/1W_f03eiEv7zdlYqQ3ergh2QOTMvK_fGHvitYb6CEtew/edit?usp=sharing


// TODOs:
// [1] Function to add two numbers in C
// [2] Function to add two numbers in C (pass by reference) 
// [3] Function to add two numbers in ASM (ARM Assembly) 
// [4] Function to add elements in an array in ASM (ARM Assembly)
// [5] Function to add elements in an array in ASM (ARM Assembly Variation) (Optimized?)
// [6] Factorial Function in Assembly!

// At the End: A Quick advice on What Not to Do for Submissions!

// Assembly Directives: https://sourceware.org/binutils/docs/as/ARM-Directives.html


// Example 1

// prototype for assembly add
extern "C" uint32_t add_asm(uint32_t a, uint32_t b);

// add values in c style
uint32_t add_c(uint32_t a, uint32_t b) {
  return a+b;
}

// add by reference
uint32_t add_by_ref(uint32_t* a, uint32_t* b) {
  return (*a)+(*b);

}

int main() {

  uint32_t integer1 = 2;
  uint32_t integer2 = 3;


  while(1) {
    // add using c function
    uint32_t result = add_c(integer1, integer2);
    printf("result:  %d  \n", result);

    //add using assembly function
    uint32_t result_asm = add_asm(integer1, integer2);
    printf("result_asm:  %d  \n", result_asm);

    // add by reference
    uint32_t result_ref = add_by_ref(&integer1, &integer2);
    printf("result_ref:  %d  \n", result_ref);

    thread_sleep_for(500);
  }
}



/*  Example 2
#define N 3
extern "C" uint32_t summation1(uint8_t* arr, uint32_t n);

extern "C" uint32_t summation2(uint8_t* arr, uint32_t n);
extern "C" uint32_t summation3(uint8_t* arr, uint32_t n);
int main() {

  uint8_t myInts[5] = {1, 2, 3, 4, 5};
  while(1) {
    uint32_t result1 = summation1(myInts, N);
    printf("result1: %d \n", result1);
    thread_sleep_for(500);
    
    // uint32_t result2 = summation2(myInts, N);
    // printf("result2: %d \n", result2);
    // thread_sleep_for(500);

    // uint32_t result3 = summation3(myInts, N);
    // printf("result3: %d \n", result3);
    // thread_sleep_for(500);
    

  }


}
//*/

// Example 3

// extern "C" uint32_t factorial(uint32_t n);

// int main() {
//     uint32_t n = 6;
//     uint32_t result = factorial(n);

//     while(1){
          
//         printf("Factorial of %u is %u\n", n, result);
//     }

// }
















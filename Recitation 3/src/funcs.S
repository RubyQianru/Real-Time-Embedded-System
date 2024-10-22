.syntax unified           // Use the unified assembly language syntax for both ARM and Thumb instructions.

.global add_asm           // Declare add_asm function as globally accessible (to be called from other files like C/C++).

.global summation1        // Declare summation1 function as globally accessible.
.global summation2        // Declare summation2 function as globally accessible.
.global summation3        // Declare summation3 function as globally accessible.

.global factorial         // Declare factorial function as globally accessible.

/////////////////////////////////////////////////////
// Function: add_asm
// This function takes two arguments in r0 and r1, adds them, and returns the result in r0.
/////////////////////////////////////////////////////
add_asm:
    add r0, r0, r1        // r0 = r0 + r1 (adds the value of r1 to r0 and stores the result in r0)
    bx lr                 // Branch to link register (return from function)

/////////////////////////////////////////////////////
// Function: summation1
// This function sums up an array of bytes.
// Parameters:
// - r0: pointer to the array (base address of the array).
// - r1: number of elements in the array.
// Returns the sum of all the elements in r0.
/////////////////////////////////////////////////////
summation1:
    mov r4, #0            // Initialize r4 (sum accumulator) to 0
add_loop1:
    ldrb r2, [r0], #1     // Load a byte from the address in r0 into r2, increment r0 by 1
    add r4, r4, r2        // Add the value in r2 to r4 (accumulate the sum)
    subs r1, r1, #1       // Subtract 1 from r1 (decrement loop counter)
    bne add_loop1         // Branch if not equal to zero (continue looping if r1 is not zero)
    mov r0, r4            // Move the final sum from r4 to r0 (this is the return value)
    bx lr                 // Return from the function (branch to the link register)

/////////////////////////////////////////////////////
// Function: summation2
// This is a variant of summation1, but uses conditional execution for more efficient code.
// It sums up an array of bytes with optimized conditional execution.
// Parameters are the same as summation1.
/////////////////////////////////////////////////////
summation2:
    mov r4, #0            // Initialize r4 (sum accumulator) to 0
    add r1, r1, #1        // Add 1 to r1 to account for loop offset (adjustment for loop logic)
add_loop2:
    subs r1, r1, #1       // Decrement r1 (loop counter)
    ldrb r2, [r0], #1     // Load a byte from the address in r0 into r2, increment r0 by 1
    IT NE                 // Instruction to execute the next instruction only if the result is not zero
    addne r4, r4, r2      // Add r2 to r4 (accumulate the sum) if r1 is not zero
    bne add_loop2         // Branch if not equal to zero (continue looping if r1 is not zero)
    mov r0, r4            // Move the final sum from r4 to r0 (this is the return value)
    bx lr                 // Return from the function (branch to the link register)

/////////////////////////////////////////////////////
// Function: summation3
// Another variant of the summation function that uses double conditional execution (ITT NE).
// Parameters are the same as summation1.
/////////////////////////////////////////////////////
summation3:
    mov r4, #0            // Initialize r4 (sum accumulator) to 0
    add r1, r1, #1        // Add 1 to r1 to account for loop offset (adjustment for loop logic)
add_loop3:
    subs r1, r1, #1       // Decrement r1 (loop counter)
    ITT NE                // Execute the next two instructions only if r1 is not zero
    ldrbne r2, [r0], #1   // Load byte from array into r2 and increment r0 if r1 is not zero
    addne r4, r4, r2      // Add r2 to r4 (accumulate the sum) if r1 is not zero
    bne add_loop2         // Branch if not equal to zero (continue looping if r1 is not zero)
    mov r0, r4            // Move the final sum from r4 to r0 (this is the return value)
    bx lr                 // Return from the function (branch to the link register)

/////////////////////////////////////////////////////
// Function: factorial
// Recursive factorial function.
// Parameter is just the needed integer for computing the factorial.
/////////////////////////////////////////////////////
factorial:
    cmp r0, #1            // Compare n (in r0) with 1
    ble base_case         // If n <= 1, branch to base_case
    push {r1, lr}         // Save r1 and link register (lr) to the stack
    mov r1, r0            // Move n (from r0) into r1 to preserve it for multiplication
    sub r0, r0, #1        // n = n - 1
    bl factorial          // Recursive call to factorial function
    mul r0, r0, r1        // Multiply result with n stored in r1
    pop {r1, lr}          // Restore r1 and link register from the stack
    bx lr                 // Return from function

base_case:
    mov r0, #1            // Base case: return 1 when n <= 1
    bx lr                 // Return from function




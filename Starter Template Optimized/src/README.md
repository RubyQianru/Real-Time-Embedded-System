# C++

## Preporcessor Directives

### #define

Define a variable called Macro name to any kind of a variable, inline function, formula that can be used by the program during its runtime.

```cpp
#define MACRO_NAME value
#define PI 3.14
```

### #include

```cpp
#include <mbed.h> // Standard library
#include "mbed.h" // If we define something
```

## Variables and Data Types

### Boolean

- Unsigned
- True & False.

```cpp
bool button_on = true;
bool button_off = False;
```

### Char

Unsigned 8 bit.

```cpp
char my_char = 'A';
char char_list[100] = '1';
```

### Float

Unsigned 32 bit.

```cpp
float my_float = 0.12;
```

### Integer

```cpp
int my_integer = 1;
```

### Undsigned

- Used across different hardwares. Like using the program on Arduino.

```cpp
uint32_t register1 = 32;
uint32_t register1_hex = 0x21213212;
uint32_t register1_bin = 0b00000010'000000001;
uint8_t demo = 'a';
```

## Volatile

When you declare a variable as volatile, it prevents the compiler from optimizing out reads or writes to the variable, ensuring that the program always accesses its current value directly from memory, rather than relying on a cached or optimized version.

Hardware Registers in Embedded Systems: In embedded systems, hardware registers (e.g., I/O ports, memory-mapped peripherals) often change outside the control of the program. Declaring a register as volatile ensures that each access reads the actual current value from the hardware.

## Pointers

```cpp
uint32_t *my_ptr = &register1;

volatile int v = 6;
v = 5;
v = 4;
v = 3;

volatile int *v_ptr = &v;
*v_ptr = 7;
*v_ptr = 8;
*v_ptr = 9;

```

## Defining and Declaring Functions

```cpp

uint32_t add_two_numbers(uint32_t a, uint32_t b){
  uint32_t res = a + b;
  return res;
}

int main() {
  while (1) {
    uint32_t num1 = 2, num2 = 1;
    uint32_t to_print = add_two_numbers(num1, num2);
  }
}
```

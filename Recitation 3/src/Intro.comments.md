Do Not Do This! --> g++ -S donotdo.cpp

Questions:

1. What's the difference between .s and .S?
2. What's the difference between .syntax unified and .syntax divided?
3. Assembler Directives?
4. How does printf connect to the serial monitor?
5. What board do we use?
6. Info about the stm32f429 discovery board?

7. What's the difference between .s and .S?

The distinction between .s and .S files usually pertains to how the assembler processes these files.
Both are used for assembly language source code, but they are treated differently by the GNU assembler (as)
and other tools in the toolchain, such as gcc.

.s Files: These are assembly code files that the assembler expects to be preprocessed already or not in need of preprocessing.
This means they are taken as-is, without running through the C preprocessor. Therefore, directives like #include or #define are not processed in .s files.

.S Files: These files are treated as source code that needs to be preprocessed.
This means the C preprocessor will run over .S files before the assembly process begins.
This allows the use of C preprocessor directives (#include, #define, #if, etc.),
making it possible to include headers, define macros, and conditionally compile sections of assembly code, among other things.

2. What's the difference between .syntax unified and .syntax divided?

.syntax unified: This directive is used with the newer, Unified Assembly Language (UAL),
which supports both ARM and Thumb instructions in a consistent manner. Unified syntax
simplifies writing assembly code that is compatible across different ARM architectures by providing a common syntax for instructions, regardless of whether they are executed in ARM or Thumb mode.

.syntax divided: This directive indicates that the assembler should use the older, divided syntax,
where ARM and Thumb instructions have distinct syntaxes. This mode is less commonly used in modern development, as UAL offers a more streamlined approach to writing assembly code for ARM processors.

3. Assembler Directives?

The .global directive in assembly language programming is used to declare a symbol (usually a function or a variable) as global, making it visible to the linker. This means that the symbol can be accessed from other modules or files beyond the one in which it's defined.

Storage class specifiers in C are used to describe the lifetime and visibility (scope) of variables and functions within the program.
In C, the extern keyword is used to declare a variable or function without actually defining it. It tells the compiler that the definition of the variable or function exists elsewhere.

.arm: This directive switches the assembly mode to ARM. Instructions following this directive are interpreted as ARM instructions.

.thumb: Switches to Thumb mode, where instructions are interpreted as Thumb instructions, which are more compact.

.thumb_func: This directive is used in Thumb mode to declare the following symbol as a function.
This is necessary for correct linking and execution, as it allows the linker to handle the symbol appropriately for Thumb code.
example:-
.thumb
.thumb_func
myFunction:

.force_thumb: This directive forces the assembler to interpret the following code as Thumb,
even if the mode was previously set to ARM. This is useful for mixed-mode assembly files.

.align: This directive aligns the next instruction or data at a specified boundary.
This is important for performance optimization and meeting certain architectural requirements.

.thumb_set: This directive is not standard and seems to be a mix-up or confusion with other directives.
The typical use case in Thumb code would be to use .thumb or .thumb_func to set the mode or declare functions.

4. How does printf connect to the serial monitor?
   -Serial Port Initialization --> Retargeting --> Overriding --> Overloading the Library/Function --> Serial Monitor receives data/characters

5. Info about the stm32f429 discovery board?

   1. Microprocessor

      STM32F429ZI Microcontroller: This microcontroller features an ARM Cortex-M4 processor core.
      The Cortex-M4 core includes a Floating Point Unit (FPU) which supports single-precision IEEE-754 floating-point calculations.
      The STM32F429ZI operates at frequencies up to 180 MHz and offers a high level of integration. It includes up to 2MB of flash memory
      and up to 256KB of SRAM, various peripherals for connectivity, analog interfaces, and much more.

   2. Register Map

      - The STM32F429ZI microcontroller, like other STM32 devices, has a comprehensive set of registers used to control
        its operation and peripherals. The register map includes:
      - Core Registers: These include general-purpose registers (R0 to R15), the stack pointer (SP), the link register (LR), the program counter (PC), and the special-purpose registers like the Program Status Register (PSR).
      - Control and Status Registers: Such as the Control Register (CONTROL), the MSP (Main Stack Pointer), and the PSP (Process Stack Pointer).
      - System Control Registers: Including the System Control Block (SCB) registers, which are part of the Cortex-M4 core and control things like the overall system configuration, fault configuration, and system handler priority.
      - Peripheral Registers: Each peripheral (e.g., GPIO, USART, SPI, I2C) has its own set of registers for control, status, and data handling. These are detailed in the STM32F429ZI reference manual.

   3. Condition Flags and xPSR Register

      - Condition Flags: The condition flags are part of the Application Program Status Register (APSR),which itself is part of the xPSR (eXtended Program Status Register). The condition flags include:
      - N (Negative): Set if the result of the operation is negative.
      - Z (Zero): Set if the result of the operation is zero.
      - C (Carry): Set if there was a carry out from the most significant bit during addition, or a borrow during subtraction.
      - V (Overflow): Set if the operation resulted in an arithmetic overflow.
      - xPSR Register: The xPSR register combines the APSR with the IPSR (Interrupt Program Status Register) and EPSR (Execution Program Status Register). The IPSR indicates the exception number of the current interrupt service routine (ISR), and the EPSR contains execution state information. In the context of the Cortex-M4:
      - The APSR portion provides the condition flags for arithmetic operations.
      - The IPSR portion indicates which interrupt or exception is active.
      - The EPSR portion is used to control and indicate the execution state,
        including whether the processor is in Thumb state (as Cortex-M4 only supports Thumb instruction set).

Notes:

---------REGISTER Map------------------------------------------------------------------------------------------------------------------------

Register Name Purpose
R0 - R3 General-purpose registers Used for passing function arguments and storing return values. Caller-save registers.
R4 - R11 General-purpose registers Typically used to store local variables. Callee-save registers.
R12 Intra-procedure call Scratch register used during function calls. Caller-save.
R13 Stack Pointer (SP) Points to the top of the stack. Can be MSP or PSP depending on the execution mode.
R14 Link Register (LR) Stores the return address for function calls. Holds the address of the instruction to return to.
R15 Program Counter (PC) Holds the address of the next instruction to be executed.
xPSR Program Status Register Holds flags (e.g., Zero, Negative), interrupt status, and processor state information.
CONTROL Control Register Controls stack pointer selection and privilege mode (privileged or unprivileged).
FPSCR Floating Point Status Holds status flags and control bits for floating-point operations.
S0-S31 Floating Point Registers Registers used for single-precision floating-point arithmetic (if the FPU is enabled).

---------ADDRESSING MODES---------------------------------------------------------------------------------------

### Explanation of **`[r0]`** Addressing Method:

In ARM assembly, **`[r0]`** is an example of **register indirect addressing**. It means that the memory address is stored in the register (`r0` in this case), and the instruction operates on the **value** stored at that memory location. This addressing mode allows the processor to access data in memory through a register, which holds the address of the memory location.

# **Example**:

```assembly
ldr r1, [r0]  // Load the value at the memory address stored in r0 into r1
```

- **`r0`** holds a memory address.
- The instruction **`ldr r1, [r0]`** will read the value stored at that memory address and place it into register `r1`.

If `r0` holds the value `0x20000000` (an address), the processor will load the value stored at memory location `0x20000000` into `r1`.

# How Does It Work?

- **Register Indirect Addressing**: The address of the data is **indirectly** specified by a register (in this case, `r0`).
- This is often used when dealing with arrays, buffers, or memory-mapped peripherals, where `r0` might point to a base address in memory, and the processor will access data at that address.

---

# Addressing Methods Available for STM32F429ZI

The ARM Cortex-M4 processor (used in the STM32F429ZI) supports various addressing modes, which are critical in accessing data in memory or registers efficiently. Here’s a list of the available addressing methods with explanations and examples relevant to your tech stack (PlatformIO, VSCode, Mbed OS).

# 1. **Register Indirect Addressing (`[r0]`)**

- **Explanation**: The memory address is stored in a register, and the data is accessed using that address.
- **Example**:

  ```assembly
  ldr r1, [r0]  // Load the value from the memory address stored in r0 into r1
  str r2, [r0]  // Store the value in r2 into the memory address stored in r0
  ```

- **Use Case**: This is useful when `r0` contains the address of a variable or peripheral register, and you need to load or store data at that address.

# 2. **Register Indirect with Immediate Offset (`[r0, #4]`)**

- **Explanation**: The base address is stored in a register (`r0`), and an immediate offset is added to calculate the final memory address.
- **Example**:

  ```assembly
  ldr r1, [r0, #4]  // Load the value from the address (r0 + 4) into r1
  str r2, [r0, #8]  // Store the value in r2 at the address (r0 + 8)
  ```

- **Use Case**: Commonly used for accessing array elements or memory-mapped peripheral registers that are spaced apart by a known offset.

# 3. **Pre-Indexed Addressing (`[r0, #4]!`)**

- **Explanation**: Adds an immediate offset to the base address in `r0`, and the result is **stored back** into `r0`.
- **Example**:

  ```assembly
  ldr r1, [r0, #4]!  // Load value from (r0 + 4) into r1, then update r0 to r0 + 4
  ```

- **Use Case**: This mode is useful when iterating through an array or buffer, as it automatically updates the base address after accessing the data.

# 4. **Post-Indexed Addressing (`[r0], #4`)**

- **Explanation**: The data is accessed from the base address stored in `r0`, and after the access, the offset is added to `r0`.
- **Example**:

  ```assembly
  ldr r1, [r0], #4  // Load the value at the address in r0 into r1, then increment r0 by 4
  ```

- **Use Case**: This is useful for stepping through an array or memory block, where you want to increment the pointer after each access.

# 5. **Literal Addressing (`=0x20000000`)**

- **Explanation**: Loads a constant address or value into a register.
- **Example**:

  ```assembly
  ldr r0, =0x20000000  // Load the address 0x20000000 into r0
  ```

- **Use Case**: Used to load memory-mapped peripheral addresses or constant data values into registers.

# 6. **Immediate Addressing (`#value`)**

- **Explanation**: The data is provided directly in the instruction as an immediate value.
- **Example**:

  ```assembly
  mov r0, #10  // Move the immediate value 10 into r0
  ```

- **Use Case**: Used when you need to load a small constant value into a register.

# 7. **Scaled Register Offset Addressing (`[r0, r1, LSL #2]`)**

- **Explanation**: The address is calculated by adding a **scaled** register (`r1`) to the base register (`r0`). The scaling is done using a left shift.
- **Example**:

  ```assembly
  ldr r2, [r0, r1, LSL #2]  // Load from the address (r0 + (r1 << 2)) into r2
  ```

- **Use Case**: Useful for accessing arrays where each element is larger than 1 byte, such as accessing 32-bit words from an array of 32-bit integers.

---

# Use Cases with STM32F429ZI Board:

1. **Memory-Mapped Peripherals**:
   The STM32F429ZI board uses **memory-mapped I/O** for peripheral access (e.g., GPIO, UART, ADC). You use **register indirect addressing** (and its variants) to interact with these peripheral registers.

   Example: Accessing a GPIO register:

   ```assembly
   ldr r0, =0x40020000   // Load the base address of GPIOA (0x40020000) into r0
   ldr r1, [r0, #0x14]   // Load the GPIOA output data register (ODR) value into r1
   ```

2. **Array or Buffer Access**:
   For accessing arrays or buffers in memory, indirect addressing with an offset or post-indexed addressing is commonly used to iterate through the elements.

   Example: Summing an array of 32-bit integers:

   ```assembly
   mov r0, #0            // Initialize sum in r0
   mov r1, #10           // Set the number of elements in r1
   ldr r2, =array        // Load the base address of the array into r2
   ```

sum_loop:
ldr r3, [r2], #4 // Load the next element, then increment pointer by 4 (size of int)
add r0, r0, r3 // Add the value to the sum
subs r1, r1, #1 // Decrement the loop counter
bne sum_loop // Repeat if the loop counter is not zero

```

3. **Pointer Arithmetic**:
Register indirect with pre-indexed or post-indexed addressing modes are often used in pointer arithmetic, especially when you need to access consecutive memory locations (like in a buffer).

---

# Summary of Addressing Modes:

| **Addressing Mode**                    | **Example**                 | **Description**                                                                                          |
|----------------------------------------|-----------------------------|----------------------------------------------------------------------------------------------------------|
| **Register Indirect**                  | `[r0]`                      | Access memory at the address stored in `r0`.                                                              |
| **Register Indirect with Offset**      | `[r0, #4]`                  | Access memory at the address `r0 + 4`.                                                                    |
| **Pre-Indexed Addressing**             | `[r0, #4]!`                 | Access memory at `r0 + 4`, then update `r0` to `r0 + 4`.                                                  |
| **Post-Indexed Addressing**            | `[r0], #4`                  | Access memory at `r0`, then update `r0` to `r0 + 4`.                                                      |
| **Literal Addressing**                 | `ldr r0, =0x20000000`       | Load the value or address `0x20000000` into `r0`.                                                         |
| **Immediate Addressing**               | `mov r0, #10`               | Load the immediate value 10 into `r0`.                                                                    |
| **Scaled Register Offset Addressing**  | `[r0, r1, LSL #2]`          | Access memory at `r0 + (r1 << 2)` (useful for accessing arrays of 32-bit integers).                        |

#Why Addressing Modes Matter in Embedded Systems:
- These addressing modes allow you to efficiently access memory, peripheral registers, and arrays. Choosing the right addressing mode helps optimize performance and reduce code size, which is important in embedded systems where memory and processing power are limited.

By understanding and leveraging these addressing modes, you can write efficient assembly code for the STM32F429ZI and its Cortex-M4 core, especially when working with real-time data, peripherals, or memory-intensive operations.
```

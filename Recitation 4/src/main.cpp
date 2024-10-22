#include <mbed.h>

// ==================================================================
// * Recitation 4: GPIO | iNPUTS AND oUTPUTS | HAL APIs | PWM *
// ==================================================================

// TODOs:
// [1] Example 1: Digital IO -->> Blinking an LED on the Board!

#define LED1 PG_13

int main(){

    // put your setup code here, to run once:
    // Declarations
    // DigitalOut led(LED1); // equivalent to led(PG_13)
    // DigitalOut led(LED1, 0); // equivalent to led(PG_13, 0)
    DigitalOut led(LED1, 0), led2(LED2, 1); // equivalent to led(PG_13, 0), led2(PG_14, 1)

    // ways to initialize/write to leds
    led.write(1);
    led = 1;

//Blinky --> Blinking leds on the board --> different ways
    while(1){
        // put your main code here, to run repeatedly:
      led = 1;
      thread_sleep_for(500);
      led = 0;
      thread_sleep_for(500);
    }
    // while(1){
    //     // put your main code here, to run repeatedly:
    //     led = !led;
    //     thread_sleep_for(500);
    // }
    // while(1){
    //     // put your main code here, to run repeatedly:
    //     led = !led;
    //     led2 = !led2;
    //     thread_sleep_for(500);
    // }
}

// [2] Example 2: Analog IO -->> How to read data from a PIN on the Board? 
// [3] Example 3: Wave Generation
// [4] Example 4: PWM


// Mbed APIs FULL LIST: https://os.mbed.com/docs/mbed-os/v6.16/apis/index.html
// Mbed OS Github Repo: https://github.com/ARMmbed/mbed-os/tree/master






































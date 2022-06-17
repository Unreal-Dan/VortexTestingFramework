#pragma once

// drop in replacement for the arduino framework

#include <inttypes.h>
#include <string.h>

#define HIGH 1
#define LOW 0

#define INPUT_PULLUP 1
#define OUTPUT 1
#define CHANGE 1

// uncommont this to enable IR comms simulation
//#define ENABLE_IR_COMMS

// init this drop-in framework
void init_arduino();

void delay(size_t amt);
void delayMicroseconds(size_t us);

unsigned long analogRead(uint32_t pin);
unsigned long digitalRead(uint32_t pin);
void digitalWrite(uint32_t pin,  uint32_t val); 
unsigned long millis();
unsigned long micros();
unsigned long nanos();
unsigned long random(uint32_t low = 0, uint32_t high = 0);
void randomSeed(uint32_t seed);
void pinMode(uint32_t pin, uint32_t mode);

void attachInterrupt(int interrupt, void (*func)(), int type);
void detachInterrupt(int interrupt);
int digitalPinToInterrupt(int pin);

#ifdef TEST_FRAMEWORK
// not actually from arduino but we use to simulate ir comms
void test_ir_mark(uint32_t duration);
void test_ir_space(uint32_t duration);

// install the IR callback for test framework
void installIRCallback(void (*func)(uint32_t));
#endif

class SerialClass
{
public:
    void begin(uint32_t i) {}
    void print(uint32_t i) {}
    void print(const char *s) {}
    void println(const char *s) {}
    operator bool() { return true; }
};

extern SerialClass Serial;

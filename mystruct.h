#ifndef MYSTRUCT_H
#define MYSTRUCT_H
#include <stdio.h>

typedef struct {
    int *elements;
    int size;
} MyStruct;

// Function prototypes
int main();
int input(int *choice, int lower, int upper);
MyStruct initialize();
void input_data(MyStruct *s);
void proccess_choice(int choice);
void cleanup(MyStruct *s);
void print_struct(MyStruct s);
void write_to_file(MyStruct s);
void write_to_console(int elements[], int size);
void write(int elements[], int size, FILE *outputFile);
void remove_biggest_element(MyStruct *s);
// void menuPrint();

#endif
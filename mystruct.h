#ifndef MYSTRUCT_H
#define MYSTRUCT_H

typedef struct {
    int *elements;
    int size;
} MyStruct;

// Function prototypes
MyStruct initialize();
void input_data(MyStruct *s);
void proccess_choice(int choice);
void cleanup(MyStruct *s);
void print_struct(MyStruct s);
void menuPrint();

#endif
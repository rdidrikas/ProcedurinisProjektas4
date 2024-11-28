#ifndef MYSTRUCT_H
#define MYSTRUCT_H

typedef struct {
    int *elements;
} MyStruct;

// Function prototypes
void initialize(MyStruct *s);
void inputData(MyStruct *s, int *size);
void processChoice(int choice, MyStruct *s, int *size);
void menuPrint(int *choice);

#endif
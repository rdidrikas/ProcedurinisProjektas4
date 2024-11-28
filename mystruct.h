#ifndef MYSTRUCT_H
#define MYSTRUCT_H

typedef struct {
    int *elements;
    int size;
} MyStruct;

// Function prototypes
void initialize(MyStruct *s);
void inputData(MyStruct *s);
void processChoice(MyStruct *s);
void menuPrint();

#endif
#ifndef Node_H
#define Node_H
#include <stdio.h>
#include <stdbool.h>

extern bool list_initialized;
extern bool list_created;

typedef struct Node{
    int element;
    struct Node *next;
} Node;

typedef struct{
    Node* head;
    int size;
} MyStruct;

// Function prototypes
int main();
int input(int *choice, int lower, int upper);
MyStruct initialize();
void input_data(MyStruct *s);
void proccess_choice(int choice);
void cleanup(MyStruct *s);
void write_to_file(Node *node);
void write_to_console(Node *node);
void write(Node *node, FILE *outputFile);
void remove_biggest_element(MyStruct *s);

#endif
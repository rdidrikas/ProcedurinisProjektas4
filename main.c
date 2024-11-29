#include "mystruct.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(){

    printf("What would you like to do?\n");\
    int choice;
    printf("1. Create a list\n");
    printf("2. Read elements from a file\n");
    printf("3. Write elements to a file\n");
    printf("4. Prints the biggest element in the structure\n");
    printf("5. Deletes the structure\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    proccess_choice(choice);

}
#include "mystruct.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(){

    printf("What would you like to do?\n");\
    int choice;
    char buffer;
    printf("1. Create a list\n");
    printf("2. Read elements from a file\n");
    printf("3. Write elements to a file\n");
    printf("4. Remove the biggest element in the structure\n");
    printf("5. Deletes the structure\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    if(scanf("%d", &choice) == 1){
        if(scanf("%c", &buffer) != 0 && buffer != '\n'){
            printf("Invalid input... Try again.\n");
            while(getchar() != '\n');
            main();
        }
        if(choice < 1 || choice > 6){
            printf("Invalid input... Try again.\n");
            main();
        }
    }
    else{
        printf("Invalid input... Try again.\n");
        while(getchar() != '\n');
        main();
    }
    proccess_choice(choice);

}
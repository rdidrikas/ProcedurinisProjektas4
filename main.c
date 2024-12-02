#include "mystruct.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
        
bool list_created = false;
bool list_initialized = false;

int main(){

    while(1){
        printf("What would you like to do?\n");\
        int choice;
        printf("1. Create a list\n");
        printf("2. Read elements from a file\n");
        printf("3. Write elements to a file\n");
        printf("4. Remove the biggest element in the structure\n");
        printf("5. Deletes the structure\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if(input(&choice, 1, 6) != 0) continue;
        if((choice > 1 && choice < 6) && !list_initialized){
            printf("Error... There is no list!\n");
            continue;
        }
        else if(list_created == true && (choice == 1 || choice == 2)){
            printf("This choice will erase the previous list. Do you want to continue?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your choice: ");
            int copy_choice;
            if(input(&copy_choice, 1, 2) != 0){
                printf("Invalid input...\n");
                continue;
            }
            else if(copy_choice == 0){
                continue;
            }
        }
        
        proccess_choice(choice);
    }

}
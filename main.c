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
        printf("1. Create a structure\n");
        printf("2. Input elements from a file to a structure\n");
        printf("3. Output elements\n");
        printf("4. Remove the biggest element in the structure\n");
        printf("5. Delete the structure\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if(input(&choice, 1, 6) != 0) continue;
        if((choice > 1 && choice < 6) && !list_initialized){
            printf("Error... There is no structure!\n");
            continue;
        }
        else if(list_created == true && choice == 1){
            printf("This choice will erase the previous structure. Do you want to continue?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your choice: ");
            int copy_choice;
            if(input(&copy_choice, 1, 2) != 0){
                printf("Invalid input...\n");
                continue;
            }
            else if(copy_choice == 2){
                continue;
            }
        }
        
        proccess_choice(choice);
    }

}
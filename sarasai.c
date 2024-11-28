#include "mystruct.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#define SIZE 256

void input_filename(char *fileName, char *prompt){

    printf("Enter %s's file name with the data (.txt format): ", prompt);

    if(scanf("%255s", fileName) != 1 || strlen(fileName) < 5 || fileName[strlen(fileName) - 1] != 't' || fileName[strlen(fileName) - 2] != 'x' || fileName[strlen(fileName) - 3] != 't' || fileName[strlen(fileName) - 4] != '.'){
        printf("Invalid input... Try again.\n");
        input_filename(fileName, prompt);
    }

}

void input_data(MyStruct *s){

    char *fileNameInput = malloc(SIZE * sizeof(char));
    input_filename(fileNameInput, "input");
    
    // Error mem allocation
    if (!fileNameInput){
        printf("Memory allocation failed...");
        free(fileNameInput);
        return;
    }

    FILE *inputFile = fopen(fileNameInput, "r");

    // File not found
    if(inputFile == NULL){
        printf("File not found\n");
        free(fileNameInput);
        input_data(s);
    }

    int temp;
    while (fscanf(inputFile, "%d", &temp) == 1) {
        s->size++;
        s->elements = realloc(s->elements, s->size * sizeof(int));
        if (s->elements == NULL) {
            printf("Memory allocation failed\n");
            fclose(inputFile);
            return;
        }
        s->elements[s->size - 1] = temp;
    }
    fclose(inputFile); // Close the file after reading

}

void initialize(){
    MyStruct *s;
    s->elements = NULL;
    s->size = 0;

}

void proccessChoice(int choice, MyStruct *s){
    switch(choice){
        case 1:
            if (s->elements == NULL) {
                initialize(s);           
                printf("List created\n");
                printf("Next?\n");
            } else {
                printf("List already exists. Delete it first (option 5) to create a new one.\n");
            }
            menuPrint(s);
            // break;
        case 2:
            input_data(s);
            break;
        /*
        case 3:
            printf("Enter the name of the file: ");
            char filename2[100];
            scanf("%s", filename2);
            FILE *file2 = fopen(filename2, "w");
            if(file2 == NULL){
                printf("File not found\n");
                return;
            }
            fprintf(file2, "%d\n", s->size);
            for(int i = 0; i < s->size; i++){
                fprintf(file2, "%d ", s->elements[i]);
            }
            fclose(file2);
            break;
        case 4:
            int max = s->elements[0];
            for(int i = 1; i < s->size; i++){
                if(s->elements[i] > max){
                    max = s->elements[i];
                }
            }
            printf("The biggest element is: %d\n", max);
            break;
        case 5:
            free(s->elements);
            s->elements = NULL;
            break;
        case 6:
            exit(0);
            break;
        */
        default:
            printf("Invalid choice\n");
            break;
    }
}

void menuPrint(MyStruct *s){
    int choice;
    printf("1. Create a list\n");
    printf("2. Read elements from a file\n");
    printf("3. Write elements to a file\n");
    printf("4. Prints the biggest element in the structure\n");
    printf("5. Deletes the structure\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    proccessChoice(choice, s);
}

#include "mystruct.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 256

MyStruct s;

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
    free(fileNameInput);

}
void print_struct(MyStruct s){
    for(int i = 0; i < s.size; i++){
        printf("%d ", s.elements[i]);
    }
    printf("\n");
}
void cleanup(MyStruct *s) {
    free(s->elements);
    s->elements = NULL;
    s->size = 0;
    printf("List deleted.\n");
}

MyStruct initialize(){
    MyStruct s;
    s.elements = NULL;
    s.size = 0;
    return s;
}

void proccess_choice(int choice){
    switch(choice){
        case 1:
            s = initialize();
            menuPrint();
            break;
        case 2:
            input_data(&s);
            menuPrint();
            break;
        
        case 3:
            print_struct(s);
            break;
        case 4:
            break;
        case 5:
            cleanup(&s);
            menuPrint();
            break;
        case 6:
            cleanup(&s);
            printf("Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

void menuPrint(){
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

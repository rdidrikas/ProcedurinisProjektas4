#include "mystruct.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define SIZE 256

typedef struct {
    int *elements;
};

void input_filename(char *fileName, char *prompt){

    printf("Enter %s's file name with the data (.txt format): ", prompt);

    if(scanf("%255s", fileName) != 1 || strlen(fileName) < 5 || fileName[strlen(fileName) - 1] != 't' || fileName[strlen(fileName) - 2] != 'x' || fileName[strlen(fileName) - 3] != 't' || fileName[strlen(fileName) - 4] != '.'){
        printf("Invalid input... Try again.\n");
        input_filename(fileName, prompt);
    }

}

void input_data(MyStruct *s, int *size){

    char *fileNameInput = malloc(SIZE * sizeof(char));
    input_filename(fileNameInput, "input");
    
    // Error mem allocation
    if (!fileNameInput){
        printf("Memory allocation failed...");
        free(fileNameInput);
        return;
    }

    FILE *inputFile = fopen(fileNameInput, "r");
    if(inputFile == NULL){
        printf("File not found\n");
        free(fileNameInput);
        input_data(s, size);
    }

    while(!feof(inputFile)){
        int temp;
        if(fscanf(inputFile, "%d", &temp) != 1){
            printf("Invalid input\n");
            return;
        }
        *size++;
        s->elements = realloc(s->elements, *size * sizeof(int));
        s->elements[*size - 1] = temp;
    }

}

void initialize(MyStruct *s){

    s->elements = malloc(0 * sizeof(int));

}

void proccessChoice(int choice, MyStruct *s, int *size){
    switch(choice){
        case 1:
            initialize(s);
            break;
        case 2:
            input_data(s, size);
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

void menuPrint(int *choice){
    printf("1. Create a list\n");
    printf("2. Read elements from a file\n");
    printf("3. Write elements to a file\n");
    printf("4. Prints the biggest element in the structure\n");
    printf("5. Deletes the structure\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
}

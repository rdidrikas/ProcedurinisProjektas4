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

void write_to_file(MyStruct s){
    
    char *fileNameOutput = malloc(SIZE * sizeof(char));
    input_filename(fileNameOutput, "output");

    FILE *outputFile = fopen(fileNameOutput, "w");
    free(fileNameOutput);

    if(outputFile == NULL){
        printf("File could not be created\n");
        write_to_file(s);
    }

    write(s.elements, s.size, outputFile);
    fclose(outputFile);

}

void remove_biggest_element(MyStruct *s){

    if(s->size == 0){
        printf("List is empty\n");
        return;
    }

    int biggest = s->elements[0];
    int index = 0;

    for(int i = 1; i < s->size; i++){
        if(s->elements[i] > biggest){
            biggest = s->elements[i];
            index = i;
        }
    }

    for(int i = index; i < s->size - 1; i++){
        s->elements[i] = s->elements[i + 1];
    }

    s->size--;
    s->elements = realloc(s->elements, s->size * sizeof(int));

    if (s->elements == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Biggest element removed\n");

}


void write(int elements[], int size, FILE *outputFile){

    if (size == 0) {
        return;
    }
    
    fprintf(outputFile, "%d ", elements[0]);
    write(elements + 1, size - 1, outputFile);

}

void write_to_console(int elements[], int size){

    if (size == 0) {
        return;
    }
    
    printf("%d ", elements[0]);
    write_to_console(elements + 1, size - 1);

}
void cleanup(MyStruct *s) {
    free(s->elements);
    printf("List deleted.\n");
}

MyStruct initialize(){

    MyStruct s;
    s.elements = NULL;
    s.size = 0;
    return s;

}

int input(int *choice, int lower, int upper){

    char buffer;
    if(scanf("%d", choice) == 1){
        if(scanf("%c", &buffer) != 0 && buffer != '\n'){
            printf("Invalid input... Try again.\n");
            while(getchar() != '\n');
            return -1;
        }
        if(*choice < lower || *choice > upper){
            printf("Invalid input... Try again.\n");
            return -1;
        }
    }
    else{
        printf("Invalid input... Try again.\n");
        while(getchar() != '\n');
        return -1;
    }
    return 0;

}

void proccess_choice(int choice){

    switch(choice){
        case 1:
            s = initialize();
            main();
            break;
        case 2:
            input_data(&s);
            main();
            break;
        
        case 3:
            printf("1. Write to file\n");
            printf("2. Write to console\n");
            printf("Enter your choice: ");
            if(input(&choice, 1, 2) == -1) main();

            switch(choice){
            case 1:
                write_to_file(s);
                break;
            case 2:
                write_to_console(s.elements, s.size);
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
            main();
            break;
        case 4:
            remove_biggest_element(&s);
            main();
            break;
        case 5:
            cleanup(&s);
            main();
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

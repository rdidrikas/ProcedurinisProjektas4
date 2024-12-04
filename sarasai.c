#include "mystruct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    if(!fileNameInput){
        printf("Memory allocation failed...");
        free(fileNameInput);
        return;
    }

    FILE *inputFile = fopen(fileNameInput, "r");

    if(inputFile == NULL){
        printf("File not found\n");
        free(fileNameInput);
        input_data(s);
    }

    int temp;
    while(fscanf(inputFile, "%d", &temp) == 1){
        Node *newNode = malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Memory allocation failed\n");
            fclose(inputFile);
            return;
        }
        newNode->element = temp;
        newNode->next = NULL;
        
        if(s->head == NULL){
            s->head = newNode; // Pirmas elementas
        } 
        else{
            Node *current = s->head;
            while(current->next != NULL){
                current = current->next; // Iki galo
            }
            current->next = newNode; // Pridedam elementa i gala
        }
        s->size++;
    }

    fclose(inputFile);
    free(fileNameInput);
    list_created = true;
    printf("Data read from file succesfully\n");

}

void write_to_file(Node *node){

    char *fileNameOutput = malloc(SIZE * sizeof(char));
    input_filename(fileNameOutput, "output");

    FILE *outputFile = fopen(fileNameOutput, "w");
    free(fileNameOutput);

    if(outputFile == NULL){
        printf("File could not be created\n");
        write_to_file(node);
    }

    write(node, outputFile);
    fclose(outputFile);
    printf("Data written to file succesfully\n");

}

void remove_biggest_element(MyStruct *s){

    if(s->size == 0){
        printf("Structure is empty\n");
        return;
    }

    Node* current = s->head;
    Node* previous = NULL;
    Node* biggest = s->head;
    Node* previousBiggest = NULL;

    while(current){
        if(current->element > biggest->element){
            biggest = current;
            previousBiggest = previous;
        }
        previous = current;
        current = current->next;
    }
    if(previousBiggest){
        previousBiggest->next = biggest->next;
    }
    else{
        s->head = biggest->next;
    }

    free(biggest);
    s->size--;

    printf("Biggest element removed\n");

}


void write(Node *node, FILE *outputFile){
    
    if(!node){
        return;
    }
    
    fprintf(outputFile, "%d ", node->element);
    write(node->next, outputFile);

}

void write_to_console(Node *node){

    if(!node){
        return;
    }
    
    printf("%d ", node->element);
    write_to_console(node->next);

}
void cleanup(MyStruct *s){

    Node* current = s->head;
    while(current){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    s->head = NULL;
    s->size = 0;
    list_created = false;
    list_initialized = false;
    printf("Structure deleted.\n");

}

MyStruct initialize(){

    MyStruct s;
    s.head = NULL;
    s.size = 0;
    list_initialized = true;
    printf("Structure created!\n");
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
            break;
        case 2:
            input_data(&s);
            break;
        
        case 3:
            if(s.size == 0){
                printf("Structure is empty\n");
                break;
            }
            printf("1. Write to file\n");
            printf("2. Write to console\n");
            printf("Enter your choice: ");
            if(input(&choice, 1, 2) != 0) break;
            switch(choice){
            case 1:
                write_to_file(s.head);
                break;
            case 2:
                write_to_console(s.head);
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
            break;
        case 4:
            remove_biggest_element(&s);
            break;
        case 5:
            cleanup(&s);
            break;
        case 6:
            if(list_initialized) cleanup(&s);
            printf("Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

}

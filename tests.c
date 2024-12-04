#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"


bool list_created = false;
bool list_initialized = false;

void test_initialize(){

    MyStruct s = initialize();
    assert(s.head == NULL); 
    assert(s.size == 0);         
    printf("Test initialize passed.\n");

}

void test_input_data(){

    MyStruct s = initialize();

    FILE *tempFile = fopen("test_data.txt", "w");
    fprintf(tempFile, "1\n2\n3\n4\n5");
    fclose(tempFile);
    int expectedValues[] = {1, 2, 3, 4, 5};

    input_data(&s); // Input file name "test_data.txt"

    assert(s.size == 5);
    assert(s.head != NULL);
    Node *current = s.head;
    for(int i = 0; i < 5; i++){
        assert(current->element == expectedValues[i]);
        current = current->next;
    }

    cleanup(&s);
    printf("Test input_data passed.\n");

}

void test_remove_biggest_element(){

    MyStruct s = initialize();
    
    FILE *tempFile = fopen("test_data.txt", "w");
    fprintf(tempFile, "20\n2\n3\n4\n10");
    fclose(tempFile);
    int expectedValues[] = {2, 3, 4, 10}; 
    input_data(&s); // Input file name "test_data.txt"
    remove_biggest_element(&s);

    assert(s.size == 4);
    assert(s.head != NULL);
    for(int i = 0; i < 4; i++){
        assert(s.head->element == expectedValues[i]);
        s.head = s.head->next;
    }

    cleanup(&s);
    printf("Test test_remove_biggest_element passed.\n");

}

int main(){
    
    test_initialize();
    test_input_data();
    test_remove_biggest_element();

    printf("All tests passed!\n");
    return 0;

}

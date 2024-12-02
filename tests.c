#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"


void test_initialize(){

    MyStruct s = initialize();
    assert(s.elements == NULL); 
    assert(s.size == 0);         
    printf("Test initialize passed.\n");

}

void test_input_data(){

    MyStruct s = initialize();

    FILE *tempFile = fopen("test_data.txt", "w");
    fprintf(tempFile, "1\n2\n3\n4\n5");
    fclose(tempFile);

    input_data(&s); // Input file name "test_data.txt"

    assert(s.size == 5);
    assert(s.elements != NULL);
    assert(s.elements[0] == 1);
    assert(s.elements[4] == 5);

    free(s.elements);
    printf("Test input_data passed.\n");

}

void test_remove_biggest_element(){

    MyStruct s = initialize();
    
    FILE *tempFile = fopen("test_data.txt", "w");
    fprintf(tempFile, "20\n2\n3\n4\n10");
    fclose(tempFile);

    input_data(&s); // Input file name "test_data.txt"
    remove_biggest_element(&s);

    assert(s.size == 4);
    assert(s.elements != NULL);
    assert(s.elements[0] == 2);
    assert(s.elements[1] == 3);

    free(s.elements);
    printf("Test test_remove_biggest_element passed.\n");

}

int main(){
    
    test_initialize();
    test_input_data();
    test_remove_biggest_element();

    printf("All tests passed!\n");
    return 0;

}

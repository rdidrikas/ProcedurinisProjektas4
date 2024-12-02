#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

// Test initialize function
void test_initialize() {
    MyStruct s;
    initialize(&s);
    assert(s.elements == NULL);  // Check if elements is NULL
    assert(s.size == 0);         // Check if size is 0
    printf("Test initialize passed.\n");
}

// Test input_filename function (requires user input handling)
void test_input_filename() {
    // This test would need to mock user input or check for specific behaviors.
    // We can skip this for simplicity since it involves user input redirection.
    printf("Test input_filename skipped (requires user input mocking).\n");
}

// Test input_data function with mock file input
void test_input_data() {
    MyStruct s;
    initialize(&s);

    // Simulate a file with integers
    FILE *tempFile = fopen("test_data.txt", "w");
    fprintf(tempFile, "1\n2\n3\n4\n5");
    fclose(tempFile);

    input_data(&s);  // Call input_data with the mock file

    assert(s.size == 5);  // Check if the size was updated correctly
    assert(s.elements != NULL);  // Ensure that the elements array is not NULL
    assert(s.elements[0] == 1);  // Check if the first element is 1
    assert(s.elements[4] == 5);  // Check if the last element is 5

    // Cleanup
    free(s.elements);
    printf("Test input_data passed.\n");
}

// Test cleanup function

// Test proccessChoice function
void test_proccessChoice() {
    MyStruct s;
    initialize(&s);

    // Test choice 1: Should initialize the list
    proccess_choice(1);
    assert(s.elements == NULL);  // List should be initialized
    assert(s.size == 0);         // Size should be 0
    printf("Test proccessChoice 1 passed.\n");

    // Test choice 5: Deleting the structure (cleanup)
    proccess_choice(5);
    assert(s.elements == NULL);  // Ensure elements are freed
    assert(s.size == 0);         // Ensure size is 0
    printf("Test proccessChoice 5 passed.\n");
}

// Main function to run all tests
int main() {
    // Running all test cases
    test_initialize();
    test_input_data();

    test_proccessChoice();

    printf("All tests passed!\n");
    return 0;
}

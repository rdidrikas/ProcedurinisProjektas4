# Procedūrinis Projektas #4 Code Style
This document describes Rokas Danielius Didrikas' coding style and rules in his project.

## General Rules

- Use `C99` standard
- Use `TABS` instead of spaces for indents
- Use no spaces between keyword and opening brackets
- Use no spaces between opening brackets and curly braces
```c
// Correct
if(condition){}
while(condition){}
for(init; condition; step){}
do{} while(condition)
int main{}

// Incorrect
if (condition) {}
while (condition) {}
for (init;condition;step) {}
do {} while (condition)
int main()
{}
```
## Function and Variable Names
- Function words are all lowercase and are separated by `_`
```c
// Correct
void some_func(){}
int main(){}
char a_b_c_d(){}

// Incorrect
void someFunc(){}
int Main(){}
char ab_C_D(){}
```
- Constants use all-caps naming separated by `_` for multiple word names
- Other variables use camel case
```c
// Correct
const int SIZE;
int number;
char someName;

// Incorrect
const int size;
int Number;
char SOMEname;
```
## Comments
- One line comments are started by `//`
- There has to be one space after `//`
- Multiple line comments start by `/*` and end with `*/`
- Multiple lines comments have to start on the next line after `/*` and on second to last line, right before `*/`
- Multiple line comments have to have an indent before text
```c
// Correct
// Some comment
/*
    Some longer
    Comment
*/

// Incorrect
//Some comment
/* Bad comment */
/*
No NO
*/
/*
    Bad comment again
    Really*/

```
## Spaces, New Lines and Other
- Use single space before and after comparison and assignment operators
- Use single spaces after `;` and `,` in loops, function arguments, etc.
```c
// Correct
int a = 6;
for(int i = 0; i < 1; i++)
a = 1 + 2;
mul(2, 5);

// Incorrect
int a=4;
a= 2+5;
for(int i=0;i<9;i++)
mul(1,2);
```
- Do not use space between function name and opening bracket
```c
int a = sum(b, c);  // Correct
int a = sum (b, c); // Incorrect
```

- There should be an empty line after `{`
- And an empty line before `}`
- This applies only to functions and procedures, which are over 2 lines long
```c
// Correct
int sum(int a, int b){

    int c;
    c = a + b;
    return c;

}
// Correct
int sum(int a, int b){
    return a + b;
}

// Incorrect
int sum(int a, int b){
    int c;
    c = a + b;
    return c;
}
// Incorrect
int some_func(int a, int b){
    // some code...
    // some code...
    // some code...
    // some code...
    return something;

}
// Incorrect
int sum(int a, int b){

    return a + b;

}
```
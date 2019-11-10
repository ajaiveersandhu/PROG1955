#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fail() { 
    printf("Memory could not be allocated");
    exit(EXIT_FAILURE);
}

int main() {
    int maxCharLength = 20;
    char *firstName, *lastName;

    // allocating 20 char memory dynamically
    // sizeof(*firstname) is better optimised code. work similar to sizeof(char).
    firstName = malloc(maxCharLength * sizeof(*firstName));
    // checking if malloc returned NULL (happens in case no memory is left to allocate).
    if (firstName == NULL) fail();
    // allocating 20 char memory dynamically
    lastName = malloc(maxCharLength * sizeof(*lastName));
    // checking if malloc returned NULL (happens in case no memory is left to allocate).
    if (lastName == NULL) fail();  

    // allocating 20 + 20 + 1 chars memory for firstName + " " + lastName
    char *fullName = malloc((maxCharLength + maxCharLength + 1) * sizeof(*fullName));


    int numberOfStudents; // user enters the dynamic size of array.
    printf("\nEnter the numbers of Students Names you want to enter : ");
    scanf("%d", &numberOfStudents);
    getchar();

    // used double pointer because we need to dynamically 
    // allocate memory to each array element of studentNames.
    char **studentNames = malloc(numberOfStudents * sizeof(**studentNames));
    // it will help us to allocate exact amout of memory based on the length of the name.
    int fullNameLength;

    for (int i = 0; i < numberOfStudents; i++) {
        printf("Student %d >", (i + 1));
        printf("\n");
        printf("First Name: ");
        gets(firstName); // fetches the name from user.
        printf("Last Name: ");
        gets(lastName); // fetches the name from user.
        printf("\n");

        fullName = firstName; // storing first name in full name
        strcat(strcat(fullName, " "), lastName); // concatinating the first and last name
        fullNameLength = strlen(fullName);
        // dynamically creating array in array element.
        studentNames[i] = malloc((fullNameLength + 1) * sizeof(*studentNames));
        // copying fullname to dynamically created array
        strcpy(studentNames[i], fullName);  
    }

    printf("\n****************\n");
    printf("List of Student Names : ");
    for (int i = 0; i < numberOfStudents; i++) {
        printf("%d. %s", (i+1), studentNames[i]); // printing the name of students.
    }

    
    return 0;
}

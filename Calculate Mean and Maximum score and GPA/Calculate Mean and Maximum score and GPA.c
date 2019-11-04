// Name :
// Date of Program Creation :
// Purpose of the program :

#include <stdio.h>

float meanAndMaximum(float *marksArray, float *meanOfMarks, float *maximumOfMarks)
// meanAndMaximum function is not calling printf to print to console.
// mean and maximum values are not stored in array to return to function.
{
    float average = 0;
    *maximumOfMarks = marksArray[0]; // to find the largest

    for (int i = 0; i < 5; i++)
    {
        average += marksArray[i];

        if (*maximumOfMarks < marksArray[i])
        {
            *maximumOfMarks = marksArray[i];
        }
    }
    *meanOfMarks = average / 5;
}

float GradePoints(char grade)
{
    switch (grade)
    {
    case 'A':
    case 'a':
        return 4;
        break;
    case 'B':
    case 'b':
        return 3;
        break;
    case 'C':
    case 'c':
        return 2;
        break;
    case 'D':
    case 'd':
        return 1;
        break;
    case 'F':
    case 'f':
        return 0;
        break;
    default:
        break;
    }
}

float Gpa(char *grades, char *hours, int arrLength)
{

    float gpa = 0;
    int sumOfHours = 0;
    float gradePoint;

    for (int i = 0; i < arrLength; i++)
    {
        gradePoint = GradePoints(grades[i]);
        gpa += (gradePoint * hours[i]);
        sumOfHours += hours[i];
    }
    return (gpa / sumOfHours);
}

void main()
{
    float marksArray[5];
    float meanOfMarks, maximumOfMarks;

    for (int i = 0; i < 5; i++)
    {
        printf("Marks for Lab %d : ", (i + 1));
        scanf("%f", &marksArray[i]);
    }

    meanAndMaximum(marksArray, &meanOfMarks, &maximumOfMarks); //giving the reference values of variables,                                                                                //so the values can be updated at the memory location.
    printf("\n");
    printf("********  OUTPUT  ********");
    printf("\n");
    printf("> Mean : %0.2f", meanOfMarks);
    printf("\n");
    printf("> Maximum score : %0.2f", maximumOfMarks);
    printf("\n");
    printf("**************************");

    printf("\n\n\n");

    printf("****  GPA Calculation  **** ");
    int arrLength = 5; //number of courses
    char grades[arrLength];
    char hours[arrLength];

    for (int i = 0; i < arrLength; i++)
    {
        printf("\n");
        printf("Course %d : \n", (i + 1));
        printf("- Grade > ");
        scanf("%c", &grades[i]);
        getchar();
        printf("- Hours  > ");
        scanf("%i", &hours[i]);
        getchar();
    }

    printf("\n");
    printf("********  OUTPUT  ********");
    printf("\n");
    printf("GPA : %0.2f", Gpa(grades, hours, arrLength));
    printf("\n");
    printf("**************************");
}
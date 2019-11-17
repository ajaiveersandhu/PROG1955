#include <stdio.h>
#include <stdlib.h>
int countFuncCalled = 0;

void CountFunction() {
    countFuncCalled++;
    printf("\n******************************* Count Function *******************************\n");
    printf("Count Function has been called : %d times.", countFuncCalled);
    printf("\n");
}

void SwapArrays(int *firstArray, int *secondArray, int len) {
    int tempArray;
    for (int x = 0; x < len; x++) {
        tempArray = *(firstArray + x);
        *(firstArray + x) = *(secondArray + x);
        *(secondArray + x) = tempArray;
    }
}

int main()
{
    int arrayLength;
    printf("\n");
    printf("Length of Array > ");
    scanf("%d", &arrayLength);
    int *firstArray = malloc(arrayLength * sizeof(int));  //allcating array size at run time
    int *secondArray = malloc(arrayLength * sizeof(int)); //allcating array size at run time

    for (int x = 0; x < arrayLength; x++) {
        printf("First Array[%d] > ", (x + 1));
        scanf("%d", &firstArray[x]);
        printf("Second Array[%d] > ", (x + 1));
        scanf("%d", &secondArray[x]);
        printf("\n");
    }

    printf("\n\n");
    printf("************************* Before Array Swap function *************************");
    for (int x = 0; x < arrayLength; x++) {
        printf("\n");
        printf("First Array: (Element %d) > %d \t\t\tSecond Array: (Element %d) > %d", (x + 1), firstArray[x], (x + 1), secondArray[x]);
    }
    SwapArrays(firstArray, secondArray, arrayLength);
    printf("\n");
    printf("\n");
    printf("************************* After Array Swap function **************************");
    for (int x = 0; x < arrayLength; x++) {
        printf("\n");
        printf("First Array: (Element %d) > %d \t\t\tSecond Array: (Element %d) > %d", (x + 1), firstArray[x], (x + 1), secondArray[x]);
    }
    printf("\n");
    CountFunction();

    free(firstArray);
    free(secondArray);
    return 0;
}

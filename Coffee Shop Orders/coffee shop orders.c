// Name :
// Date of Program Creation :
// Purpose of the program :

#include <stdio.h>
#include <stdlib.h>

// structure 
struct CoffeeShop {
    char customerName[50];
    int coffeeCup;
    int teaCup;
};

void printReceipt(struct CoffeeShop *customer) {
    const float COFFEE = 1.75;
    const float TEA = 1.5;
    const int TAX = 13;
    float total;
    total = (customer->coffeeCup * COFFEE) + (customer->teaCup * TEA);
    total += (total * TAX) / 100;
    printf("\n\n");
    printf("%s ordered %d cups of Coffee and %d cups of Tea.", customer->customerName, customer->coffeeCup, customer->teaCup);
    printf("\n");
    printf("\n******************************************\n");
    printf("  COFFEE %d x $%0.2f  -------------  $%0.2f\n", customer->coffeeCup, COFFEE, (customer->coffeeCup * COFFEE));
    printf("  TEA    %d x $%0.2f  -------------  $%0.2f\n", customer->teaCup, TEA, (customer->teaCup * TEA));
    printf("  TAX -----------------------------  %d%%\n", TAX);
    printf("\n ----------------------------------------\n");
    printf("  Total ------------------------  $ %0.2f\n", total);
    printf("******************************************\n");
}

int main()
{
    int numberOfCustomers;
    printf("\n");
    printf("Number of Customers > ");
    scanf("%d", &numberOfCustomers);
    getchar();
    struct CoffeeShop *customerArray = malloc(numberOfCustomers * sizeof(struct CoffeeShop));

    int placeOrder;
    char orderAgain = '1';
    int customerName[50];

    printf("\n");
    for (int x = 0; x < numberOfCustomers; x++)
    {
        struct CoffeeShop customerArray[x];
        printf("Customer Name > ");
        scanf("%s", customerArray[x].customerName);
        printf("\n");
        customerArray[x].coffeeCup = 0;
        customerArray[x].teaCup = 0;
        do
        {
            placeOrder = 0;
            printf("\n");
            printf("What would you like to order ? %s : \n", customerArray[x].customerName);
            printf("(Choose a number)\n");
            printf("1. Coffee\n2. Tea\n> ");
            scanf("%d", &placeOrder);
            switch (placeOrder) {
            case 1:
                printf("Your coffee is on the way.  :)\n");
                customerArray[x].coffeeCup += 1;
                break;

            case 2:
                printf("Your tea is on the way.  :)\n");
                customerArray[x].teaCup += 1;
                break;

            default:
                printf("Please choose the correct option.\n");
                break;
            }
            printf("\nWould you like to order something else ?");
            printf("\nTo order something press 'Y'.\nHit 'Q' for reciept\n> ");
            getchar();
            orderAgain = getchar();

            if (orderAgain == 'Q' || orderAgain == 'q') {
                orderAgain = 'Q';
            }

        } while (orderAgain != 'Q');

        printReceipt(&customerArray[x]);
        getchar();
    }

    return 0;
}

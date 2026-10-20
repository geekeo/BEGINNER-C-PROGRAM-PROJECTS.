#include <stdio.h>

#define LABOR_COST 0.35
#define TAX_RATE 0.085

//functions declarations (must have 6 user-defined functions)
void readData(int *length, int *width, int *discountPercent, float *carpetPrice);
void calculateInstalledPrice(int length, int width, float carpetPrice, float *area, float *carpetCost, float *laborCost, float *installedPrice);
void calculatedSubtotal(float installedPrice, int discountPercent, float *discount, float *subtotal);
void calculatedTotal(float subtotal, float *tax, float *total);
void measurements(int length, int width, float area);
void charges(float carpetPrice, float carpCost, float laborCost, float installedPrice, int discountPercent, float subtotal, float discount, float tax, float total);
int main() {
    //local declarations
    int length, width, discountPercent;
    float carpetPrice;
    float area, carpCost, laborCost, installedPrice;
    float discount, subtotal, tax, total;

    //function calls
    readData(&length, &width, &discountPercent, &carpetPrice);
    calculateInstalledPrice(length, width, carpetPrice, &area, &carpCost, &laborCost, &installedPrice);
    calculatedSubtotal(installedPrice, discountPercent, &discount, &subtotal);
    calculatedTotal(subtotal, &tax, &total);
    measurements(length, width, area);
    charges(carpetPrice, carpCost, laborCost,  installedPrice,  discountPercent, subtotal, discount,  tax, total);

    return 0;
}
//function definitions
void readData(int *length, int *width, int *discountPercent, float *carpetPrice)
{ //This is where we ask the user to put the example
    printf("Length of room (feet)? ");
    scanf("%d",length);
    printf("\nWidth of room(feet)? ");
    scanf("%d",width);
    printf("\nCustomer discount (percent)? ");
    scanf("%d",discountPercent);
    printf("Cost per square foot (xxx.xx)? ");
    scanf("%f",carpetPrice);
}
void calculateInstalledPrice(int length, int width, float carpetPrice, float *area, float *carpetCost, float *laborCost, float *installedPrice)
{   //calculation for the Installed Price.
    *area = length * width;
    *carpetCost = *area * carpetPrice;
    *laborCost = *area * LABOR_COST;
    *installedPrice = *carpetCost + *laborCost;
}
void calculatedSubtotal(float installedPrice, int discountPercent, float *discount, float *subtotal)
{   //calculation for the subtotal
    *discount = installedPrice * discountPercent / 100.00;
    *subtotal = installedPrice - *discount;
}
void calculatedTotal(float subtotal, float *tax, float *total)
{   //calculation for the total
    *tax = subtotal * TAX_RATE;
    *total = subtotal + *tax;
}
void measurements(int length, int width, float area)
{
    printf("\nMEASUREMENTS\n");
    printf("Length: %dft\n", length);
    printf("Width: %dft\n", width);
    printf("Area: %.0f square ft\n", area);
}
void charges(float carpetPrice, float carpCost, float laborCost, float installedPrice, int discountPercent, float subtotal, float discount, float tax, float total)
{
    printf("\nCHARGES\n");
    printf("DESCRIPTION         COST/SQ.FT.       CHARGE");
    printf("\n---------------------------------------------\n");
    printf("Carpet           %10.2f          $%8.2f\n", carpetPrice, carpCost);
    printf("Labor            %10.2f          $%8.2f\n", LABOR_COST, laborCost);
    printf("INSTALLED PRICE                      $%8.2f\n", installedPrice);
    printf("Discount          %7d%%           $%8.2f\n", discountPercent, discount);
    printf("\n---------------------------------------------\n");
    printf("Subtotal                             $%8.2f\n", subtotal);
    printf("Tax                                  $%8.2f\n", tax);
    printf("\n---------------------------------------------\n");
    printf("Total                                $%8.2f\n", total);
}

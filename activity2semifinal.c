/*Create a program that asks the user to enter temperature reading in Centigrade
and then prints out quivalent centigrade value.*/

#include <stdio.h>
//Important because it'll be used for all functions.
/*Why? because if we put it in int main, it'll only stay inside and
cannot be used in the functions globally and will be declared as a local inside.*/
float celcius, fahrenheit;

//Function declarations. Let the machine know in advance.
void getCelcius();
void celciusToFahrenheit();
void printOutFahrenheit();
void getFahrenheit();
void fahrenheitToCelcius();
void printOutCelcius();

int main() {
    //Function calling
    getCelcius(); //call
    celciusToFahrenheit(); //call
    printOutFahrenheit(); //call

    getFahrenheit(); //call
    fahrenheitToCelcius(); //call
    printOutCelcius(); //call

    return 0;
}
//Function definitions.
//here we ask the user to enter a temperature.
void getCelcius()
{
    printf("Please Enter a temperature in Celcius: ");
    scanf("%f", &celcius);
}
void celciusToFahrenheit()
{   //Formula: F = 32 + C * 180 / 100
    //Important: Multiply by 180/100, then add 32.
    fahrenheit = 32 + celcius * 180.0 / 100.0;
}
void printOutFahrenheit()
{   //displays the output
    printf("The Temperature in Celcius to Fahrenheit is: %.2f\n", fahrenheit);
}
void getFahrenheit()
{   //where the user asks to input
    printf("Please Enter a temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
}
void fahrenheitToCelcius()
{   //Formula: C = (F - 32) * 100 / 180
    //Important note: Subtract 32 first, then multiply by 100/180.
    celcius = (fahrenheit - 32) * 100.0 / 180.0;
}
void printOutCelcius()
{   //displays the output.
    printf("The Temperature in Fahrenheit to Celcius is: %.2f\n", celcius);
}

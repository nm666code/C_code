#include <stdio.h>
#include <conio.h>
void displayHexs(unsigned int value); // prototype
void displayOcts(unsigned int value);
void displayOcts1(unsigned int, char *);
int main(void)
{
    char test[13];
    // demonstrate bitwise AND (&)
    unsigned int number1 = 65535;
    unsigned int mask = 1;
    displayHexs(number1);
    displayOcts(number1);
    displayOcts1(number1 ,test);
    printf(" = %s\n", test);
    displayHexs(mask);
    displayOcts(mask);
    displayOcts1(mask, test);
    printf(" = %s\n", test);
    number1 = 15;
    unsigned int setBits = 241;
    displayHexs (number1);
    displayOcts (number1);
    displayOcts1 (number1, test);
    printf(" = %s\n", test);
    displayHexs (setBits);
    displayOcts (setBits);
    displayOcts1 (setBits, test);
    printf(" = %s\n", test);
    number1 = 139;
    unsigned int number2 = 199;
    displayHexs (number1);
    displayOcts (number1);
    displayOcts1 (number1, test);
    printf(" = %s\n", test);
    displayHexs(number2);
    displayOcts(number2);
    displayOcts1 (number2, test);
    printf(" = %s\n", test);
    number1 = 21845;
    displayHexs (number1);
    displayOcts (number1);
    displayOcts1 (number1, test);
    printf(" = %s\n", test);
    number1 <<= 4;
    displayHexs (number1);
    displayOcts (number1);
    displayOcts1 (number1, test);
    printf(" = %s\n", test);
    number1 <<= 4;
    displayHexs (number1);
    displayOcts (number1);
    displayOcts1 (number1, test);
    printf(" = %s\n", test);
    number1 <<= 4;
    displayHexs (number1);
    displayOcts (number1);
    displayOcts1 (number1, test);
    printf(" = %s\n", test);
    number1 <<= 4;
    displayHexs (number1);
    displayOcts (number1);
    displayOcts1 (number1, test);
    printf(" = %s\n", test);
    printf("Please input a number ==>");
    scanf("%d", &number1);
    char ch;
    do {
        displayHexs (number1);
        displayOcts (number1);
        displayOcts1 (number1, test);
        printf(" = %s\n", test);
        while ((ch = _getch()) != -32);
        ch = _getch();
        if (77 == ch) number1 >>= 1;
        if (75 == ch) number1 <<= 1;
        if(72==ch){
                printf("Please input another number ==> ");
                scanf("%d", &number2);
                displayHexs (number2);
                displayOcts (number2);
                displayOcts1 (number2, test);
                printf(" = %s\n", test);
                printf("%10d & %10d = %10d\n", number1, number2, number1 & number2);
                displayHexs (number1 & number2);
                displayOcts (number1 & number2);
                displayOcts1 (number1 & number2, test);
                printf(" = %s\n", test);
                printf("%10d | %10d = %10d\n", number1, number2, number1 | number2);
                displayHexs (number1 | number2);
                displayOcts (number1 | number2);
                displayOcts1 (number1 | number2, test);
                printf(" = %s\n", test);
                printf("%10d ^ %10d = %10d\n", number1, number2, number1 ^ number2);
                displayHexs (number1 ^ number2);
                displayOcts (number1 ^ number2);
                displayOcts1 (number1 ^ number2, test);
                printf(" = %s\n", test);
                break;
        }
    } while (ch != 80);
}
// display bits of an unsigned int value

void displayHexs (unsigned int value)
{
    // declare displayMask and left shift 31 bits
    unsigned int displayMask = 15 << 28;
    printf("%10u = Ox",value);
    // loop through bits
    unsigned int temp;
    for (unsigned int c = 1; c <= 8; ++c) {
        temp = (value & displayMask) >> 28;
        if (temp < 10)
            putchar(temp + 48);
        else{
            putchar(temp + 55);
        }
        value <<= 4; // shift value left by 1
    }
}
void displayOcts (unsigned int value)
{
    unsigned int displayMask = 3 << 30;
    printf(" = 0H");
    // loop through bits
    unsigned int temp;
    temp = (value & displayMask) >> 30;
    putchar(temp + 48);
    displayMask = 7 << 29;
    value <<= 2;
    for (unsigned int c = 1; c <= 10; ++c) {
        temp = (value & displayMask) >> 29;
        putchar(temp + 48);
        value <<= 3; // shift value left by 1
    }
}
void displayOcts1 (unsigned int value, char *tempptr)
{
    unsigned int displayMask = 3 << 30;
    *tempptr = 'O';
    tempptr++;
    // loop through bits
    unsigned int temp;
    temp = (value & displayMask) >> 30;
    *tempptr = (temp + 48);
    tempptr++;
    displayMask = 7 << 29;
    value <<= 2;
    for (unsigned int c = 1; c <= 10; ++c) {
        temp = (value & displayMask) >> 29;
        *tempptr = (temp + 48);
        tempptr++;
        value <<= 3; // shift value left by 1
    }
    *tempptr = '\0';
}

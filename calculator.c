#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_HISTORY 100
#define PI 3.14159265358979323846

char history[MAX_HISTORY][200];
int historyCount = 0;

/* ---------- HISTORY FUNCTIONS ---------- */

void addHistory(const char *text)
{
    if (historyCount < MAX_HISTORY)
    {
        strcpy(history[historyCount], text);
        historyCount++;
    }
    else
    {
        int i;

        for (i = 0; i < MAX_HISTORY - 1; i++)
        {
            strcpy(history[i], history[i + 1]);
        }

        strcpy(history[MAX_HISTORY - 1], text);
    }
}

void showHistory()
{
    int i;

    printf("\n====================================\n");
    printf("          CALCULATION HISTORY       \n");
    printf("====================================\n");

    if (historyCount == 0)
    {
        printf("No calculations available.\n");
        return;
    }

    for (i = 0; i < historyCount; i++)
    {
        printf("%d. %s\n", i + 1, history[i]);
    }
}

void saveHistory()
{
    FILE *file;
    int i;

    file = fopen("history.txt", "w");

    if (file == NULL)
    {
        printf("Unable to save history.\n");
        return;
    }

    for (i = 0; i < historyCount; i++)
    {
        fprintf(file, "%d. %s\n", i + 1, history[i]);
    }

    fclose(file);

    printf("History saved to history.txt successfully.\n");
}

void loadHistory()
{
    FILE *file;
    char line[200];

    file = fopen("history.txt", "r");

    if (file == NULL)
    {
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';

        if (historyCount < MAX_HISTORY)
        {
            strcpy(history[historyCount], line);
            historyCount++;
        }
    }

    fclose(file);
}

void clearHistory()
{
    historyCount = 0;

    printf("\nHistory cleared successfully.\n");
}

/* ---------- BASIC CALCULATIONS ---------- */

void addition()
{
    double a, b, result;
    char text[200];

    printf("\nEnter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    result = a + b;

    printf("Result = %.2lf\n", result);

    sprintf(text, "%.2lf + %.2lf = %.2lf", a, b, result);
    addHistory(text);
}

void subtraction()
{
    double a, b, result;
    char text[200];

    printf("\nEnter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    result = a - b;

    printf("Result = %.2lf\n", result);

    sprintf(text, "%.2lf - %.2lf = %.2lf", a, b, result);
    addHistory(text);
}

void multiplication()
{
    double a, b, result;
    char text[200];

    printf("\nEnter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    result = a * b;

    printf("Result = %.2lf\n", result);

    sprintf(text, "%.2lf * %.2lf = %.2lf", a, b, result);
    addHistory(text);
}

void division()
{
    double a, b, result;
    char text[200];

    printf("\nEnter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    if (b == 0)
    {
        printf("Error: Cannot divide by zero!\n");
        return;
    }

    result = a / b;

    printf("Result = %.2lf\n", result);

    sprintf(text, "%.2lf / %.2lf = %.2lf", a, b, result);
    addHistory(text);
}

/* ---------- ADVANCED MATH ---------- */

void percentage()
{
    double number, percent, result;
    char text[200];

    printf("\nEnter number: ");
    scanf("%lf", &number);

    printf("Enter percentage: ");
    scanf("%lf", &percent);

    result = (number * percent) / 100;

    printf("%.2lf%% of %.2lf = %.2lf\n",
           percent, number, result);

    sprintf(text, "%.2lf%% of %.2lf = %.2lf",
            percent, number, result);

    addHistory(text);
}

void powerCalculation()
{
    double base, exponent, result;
    char text[200];

    printf("\nEnter base: ");
    scanf("%lf", &base);

    printf("Enter exponent: ");
    scanf("%lf", &exponent);

    result = pow(base, exponent);

    printf("Result = %.4lf\n", result);

    sprintf(text, "%.2lf ^ %.2lf = %.4lf",
            base, exponent, result);

    addHistory(text);
}

void squareRoot()
{
    double number, result;
    char text[200];

    printf("\nEnter number: ");
    scanf("%lf", &number);

    if (number < 0)
    {
        printf("Error: Square root of a negative number is not real.\n");
        return;
    }

    result = sqrt(number);

    printf("Square root = %.4lf\n", result);

    sprintf(text, "sqrt(%.2lf) = %.4lf",
            number, result);

    addHistory(text);
}

void factorial()
{
    int n;
    unsigned long long result = 1;
    int i;
    char text[200];

    printf("\nEnter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
        return;
    }

    if (n > 20)
    {
        printf("Please enter a number from 0 to 20.\n");
        return;
    }

    for (i = 1; i <= n; i++)
    {
        result *= i;
    }

    printf("%d! =%I64u\n", n, result);

    sprintf(text, "%d! = %I64u", n, result);
    addHistory(text);
}

/* ---------- TRIGONOMETRY ---------- */

void trigonometry()
{
    int choice;
    double degree;
    double radians;
    double result;
    char text[200];

    printf("\n====================================\n");
    printf("          TRIGONOMETRY              \n");
    printf("====================================\n");

    printf("1. sin\n");
    printf("2. cos\n");
    printf("3. tan\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter angle in degrees: ");
    scanf("%lf", &degree);

    radians = degree * PI / 180.0;

    switch (choice)
    {
        case 1:
            result = sin(radians);

            printf("sin(%.2lf) = %.4lf\n",
                   degree, result);

            sprintf(text, "sin(%.2lf) = %.4lf",
                    degree, result);

            addHistory(text);
            break;

        case 2:
            result = cos(radians);

            printf("cos(%.2lf) = %.4lf\n",
                   degree, result);

            sprintf(text, "cos(%.2lf) = %.4lf",
                    degree, result);

            addHistory(text);
            break;

        case 3:
            result = tan(radians);

            printf("tan(%.2lf) = %.4lf\n",
                   degree, result);

            sprintf(text, "tan(%.2lf) = %.4lf",
                    degree, result);

            addHistory(text);
            break;

        default:
            printf("Invalid choice.\n");
    }
}

/* ---------- LOGARITHMS ---------- */

void logarithm()
{
    int choice;
    double number;
    double result;
    char text[200];

    printf("\n====================================\n");
    printf("             LOGARITHMS             \n");
    printf("====================================\n");

    printf("1. Natural Log (ln)\n");
    printf("2. Log base 10\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter number: ");
    scanf("%lf", &number);

    if (number <= 0)
    {
        printf("Error: Number must be greater than zero.\n");
        return;
    }

    if (choice == 1)
    {
        result = log(number);

        printf("ln(%.2lf) = %.4lf\n",
               number, result);

        sprintf(text, "ln(%.2lf) = %.4lf",
                number, result);

        addHistory(text);
    }
    else if (choice == 2)
    {
        result = log10(number);

        printf("log10(%.2lf) = %.4lf\n",
               number, result);

        sprintf(text, "log10(%.2lf) = %.4lf",
                number, result);

        addHistory(text);
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

/* ---------- NUMBER OPERATIONS ---------- */

void absoluteValue()
{
    double number;
    double result;
    char text[200];

    printf("\nEnter number: ");
    scanf("%lf", &number);

    result = fabs(number);

    printf("|%.2lf| = %.2lf\n",
           number, result);

    sprintf(text, "|%.2lf| = %.2lf",
            number, result);

    addHistory(text);
}

void evenOdd()
{
    int number;

    printf("\nEnter integer: ");
    scanf("%d", &number);

    if (number % 2 == 0)
        printf("%d is EVEN.\n", number);
    else
        printf("%d is ODD.\n", number);
}

void primeCheck()
{
    int number;
    int i;
    int isPrime = 1;

    printf("\nEnter integer: ");
    scanf("%d", &number);

    if (number <= 1)
    {
        isPrime = 0;
    }

    for (i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            isPrime = 0;
            break;
        }
    }

    if (isPrime)
        printf("%d is a PRIME number.\n", number);
    else
        printf("%d is NOT a prime number.\n", number);
}

/* ---------- MAIN MENU ---------- */

void displayMenu()
{
    printf("\n");
    printf("============================================\n");
    printf("             ADVANCED C CALCULATOR          \n");
    printf("============================================\n");

    printf(" 1.  Addition\n");
    printf(" 2.  Subtraction\n");
    printf(" 3.  Multiplication\n");
    printf(" 4.  Division\n");
    printf(" 5.  Percentage\n");
    printf(" 6.  Power\n");
    printf(" 7.  Square Root\n");
    printf(" 8.  Factorial\n");
    printf(" 9.  Trigonometry\n");
    printf("10.  Logarithm\n");
    printf("11.  Absolute Value\n");
    printf("12.  Even / Odd\n");
    printf("13.  Prime Check\n");
    printf("14.  Show History\n");
    printf("15.  Save History\n");
    printf("16.  Clear History\n");
    printf("17.  Exit\n");

    printf("============================================\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;

    loadHistory();

    printf("============================================\n");
    printf("        WELCOME TO ADVANCED CALCULATOR     \n");
    printf("============================================\n");

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addition();
                break;

            case 2:
                subtraction();
                break;

            case 3:
                multiplication();
                break;

            case 4:
                division();
                break;

            case 5:
                percentage();
                break;

            case 6:
                powerCalculation();
                break;

            case 7:
                squareRoot();
                break;

            case 8:
                factorial();
                break;

            case 9:
                trigonometry();
                break;

            case 10:
                logarithm();
                break;

            case 11:
                absoluteValue();
                break;

            case 12:
                evenOdd();
                break;

            case 13:
                primeCheck();
                break;

            case 14:
                showHistory();
                break;

            case 15:
                saveHistory();
                break;

            case 16:
                clearHistory();
                break;

            case 17:
                saveHistory();

                printf("\nThank you for using Advanced Calculator!\n");
                printf("Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1-17.\n");
        }

    } while (choice != 17);

    return 0;
}
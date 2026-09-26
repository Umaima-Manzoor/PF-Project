#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SearchByNumber(char name[1000][100], char email[1000][100], char number[1000][100], int *position)
{
    char num[100];
    int validPhone, i;
    int flag = 0;
    int count = 0;
    char temp;

    do
    {
        printf("Enter the phone number of the contact you want to search: ");
        scanf(" %[^\n]", num);
        // while((temp = getchar()) != '\n' && temp != EOF);

        validPhone = 1;
        for (i = 0; num[i] != '\0'; i++)
        {
            if (!((num[i] >= '0' && num[i] <= '9') || num[i] == '+' || num[i] == '-'))
            {
                validPhone = 0;
                break;
            }
        }

        if (!validPhone)
        {
            printf("Error: Invalid phone number! Only digits, '+' and '-' are allowed.\n\n");
        }

    } while (!validPhone);

    for (i = 0; i < 1000; i++)
    {
        if (strstr(number[i], num) != NULL && strcmp(number[i], " ") != 0)
        {
            position[count] = i;
            printf("\nContact %d:\n", count + 1);
            count++;
            printf("Name: %s\nEmail: %s\nPhone Number: %s\n\n", name[i], email[i], number[i]);
            flag = 1;
        }
    }

    if (!flag)
    {
        printf("\nSorry, but no contact was found in the database with the phone number '%s'\n", num);
    }

    return count;
}

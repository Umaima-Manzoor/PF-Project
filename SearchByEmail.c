#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SearchByEmail(char name[1000][100], char email[1000][100], char number[1000][100], int *position)
{
    char search[100];
    int i, flag = 0;
    int count = 0;
    char temp;

    printf("\nEnter the email you would like to search the contacts by: ");
    scanf(" %[^\n]", search);
    // while((temp = getchar()) != '\n' && temp != EOF);

    for (i = 0; i < 1000; i++)
    {
        if (strstr(email[i], search) != NULL && strcmp(email[i], " ") != 0)
        {
            position[count] = i;
            printf("\nContact %d:\n", count + 1);
            count++;
            printf("Name: %s\nEmail Address: %s\nPhone Number: %s\n\n", name[i], email[i], number[i]);
            flag = 1;
        }
    }

    if (!flag)
    {
        printf("\nSorry, but no contact was found in the database with the email address '%s'\n", search);
    }

    return count;
}

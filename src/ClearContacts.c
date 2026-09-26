#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ClearContact(char (*name)[1000][100], char (*email)[1000][100], char (*number)[1000][100])
{
    int i;
    char clear;
    char temp;

    do
    {
        printf("Are you sure you want to clear all contacts (Y/N): ");
        scanf(" %c", &clear);
        while((temp = getchar()) != '\n' && temp != EOF);

        if (clear != 'Y' && clear != 'N')
        {
            printf("\nPlease enter 'Y' or 'N'");
            sleep(2);
            system("cls");
        }
    } while (clear != 'Y' && clear != 'N');

    if (clear == 'Y')
    {
        for (i = 0; i < 1000; i++)
        {
            strcpy((*name)[i], " ");
            strcpy((*email)[i], " ");
            strcpy((*number)[i], " ");
        }
        printf("\nAll Contacts cleared successfully");
    }
    else
    {
        printf("\nContact clearing cancelled. No changes were made to the contacts.\n");
    }
}

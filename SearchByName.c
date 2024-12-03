#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SearchByName(char name[1000][100], char email[1000][100], char number[1000][100], int *position)
{
    char SearchName[100];
    int flag = 0, i;
    char temp;
    int validName;
    int count = 0;

    do
    {
        printf("\nEnter the name of the contact you want to search: ");
        scanf(" %[^\n]", SearchName);
        // while((temp = getchar()) != '\n' && temp != EOF);

        validName = 1;
        for (i = 0; SearchName[i] != '\0'; i++)
        {
            if (!((SearchName[i] >= 'a' && SearchName[i] <= 'z') || 
                  (SearchName[i] >= 'A' && SearchName[i] <= 'Z') || 
                  SearchName[i] == ' '))
            {
                validName = 0;
                break;
            }
        }

        if (!validName)   
        {
            printf("Error: Invalid name! Only alphabets (both upper and lower cases) are allowed.\n\n");
        }

    } while (!validName);

    for (i = 0; i < 1000; i++)
    {
        if (strstr(name[i], SearchName) != NULL && strcmp(name[i], " ") != 0)
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
        printf("\nSorry, but no contact was found in the database with the name '%s'\n", SearchName);
    }
    return count;
}

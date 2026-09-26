#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DisplayContacts(char name[1000][100], char email[1000][100], char number[1000][100])
{
    int i, flag = 0;

    for (i = 0; i < 1000; i++)
    {
        if (strcmp(name[i], " ") != 0)
        {
            flag = 1;
            printf("Contact %d:\n", i + 1);
            printf("Name: ");
            puts(name[i]);
            printf("Email: ");
            puts(email[i]);
            printf("Phone Number: ");
            puts(number[i]);
            printf("\n");
        }
    }
    if (flag == 0)
    {
        printf("No contacts found");
    }
}

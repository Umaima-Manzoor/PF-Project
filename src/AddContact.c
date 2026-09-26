#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void AddContact(char (*name)[1000][100], char (*email)[1000][100], char (*number)[1000][100])
{
    int i, flag = 0;
    char n[100], e[100], num[100];
    int validName;

    do
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", n);

        validName = 1;

        for (i = 0; n[i] != '\0'; i++)
        {
            if (!((n[i] >= 'a' && n[i] <= 'z') || (n[i] >'A' && n[i] <= 'Z')|| n[i]==' '))
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

    printf("Enter Email: ");
    scanf(" %[^\n]", e);

    int validPhone;

    do
    {
        printf("Enter Phone Number: ");
        scanf(" %[^\n]", num);

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
        if (strcmp((*name)[i], n) == 0 && strcmp((*email)[i], e) == 0 && strcmp((*number)[i], num) == 0)
        {
            flag = -1;
            puts("\nContact is already stored in the database");
            break;
        }
    }
    if (flag != -1)
    {
        for (i = 0; i < 1000; i++)
        {
            if (strcmp((*name)[i], " ") == 0)
            {
                strcpy((*name)[i], n);
                strcpy((*email)[i], e);
                strcpy((*number)[i], num);
                puts("\nContact Was Added Successfully!");
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0)
    {
        puts("Sorry, the contact list is full");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void DeleteContact(char (*name)[1000][100], char (*email)[1000][100], char (*num)[1000][100])
{
    int i, count = 0, pos;
    char choice, delete;
    char temp;
    int validPhone;
    int position[1000];
    char search[100];

    for (i = 0; i < 1000; i++)
    {
        position[i] = -1;
    }

    do
    {
        printf("Would you like to search the contact you would like to delete, by name (N), phone number (P), or email address (E): ");
        scanf(" %c", &choice);
        while((temp = getchar()) != '\n' && temp != EOF);

        if (choice != 'N' && choice != 'P' && choice != 'E')
        {
            printf("\nInvalid choice, please try again\n\n");
            sleep(2);
            system("cls");
        }
    } while (choice != 'N' && choice != 'P' && choice != 'E');

    switch (choice)
    {
    case 'N':
        count = SearchByName(*name, *email, *num, position);
        break;
    case 'P':
        count = SearchByNumber(*name, *email, *num, position);
        break;
    case 'E':
        count = SearchByEmail(*name, *email, *num, position);
        break;
    }

    if (count == 0)
    {
        return;  
    }

    do
    {
        printf("\nWhich contact would you like to delete (1 to %d): ", count);
    

        if (scanf(" %d", &pos) != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
        }

        else {


        if (pos < 1 || pos > count)
        {
            printf("\nPlease enter a valid contact number\n");
        }
        }

    } while (pos < 1 || pos > count);

    pos = position[pos - 1];

    sleep(1);
    system("cls");

    do
    {
        printf("Are you sure you want to delete this contact (Y/N): ");
        scanf(" %c", &delete);
        while((temp = getchar()) != '\n' && temp != EOF);

        if (delete != 'Y' && delete != 'N')
        {
            printf("\nPlease enter 'Y' or 'N'\n");
            sleep(2);
            system("cls");
        }
    } while (delete != 'Y' && delete != 'N');

    if (delete == 'Y')
    {

        for (i = (pos + 1); i < 1000; i++)
        {
            strcpy((*name)[i - 1], (*name)[i]);
            strcpy((*email)[i - 1], (*email)[i]);
            strcpy((*num)[i - 1], (*num)[i]);
        }

        strcpy((*name)[999], " ");
        strcpy((*email)[999], " ");
        strcpy((*num)[999], " ");

        printf("\nContact deleted successfully\n");
    }

    else
    {
        printf("\nContact deletion cancelled. The contact remains in the database.\n");
    }
}

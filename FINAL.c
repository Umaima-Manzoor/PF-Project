#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ClearContact(char (*name)[1000][100], char (*email)[1000][100], char (*number)[1000][100])
{

    int i;
    char clear;
    do {
        printf("Are you sure you want to clear all contacts (Y/N): ");
        scanf(" %c", &clear);

        if (clear!='Y' && clear!='N') {
            printf("\nPlease enter 'Y' or 'N'");
            sleep(2);
            system("cls");
        }
 
    } while (clear!='Y' && clear!='N');

    if (clear=='Y') {
        for (i = 0; i < 1000; i++)
        {
            strcpy((*name)[i], " ");
            strcpy((*email)[i], " ");
            strcpy((*number)[i], " ");
        }
        printf("\nAll Contacts cleared");

    }

    else {
        printf("\nContact clearing cancelled. No changes were made to the contacts.\n");
    }

}

void AddContact(char (*name)[1000][100], char (*email)[1000][100], char (*number)[1000][100])
{
    int i, flag = 0;
    char n[100], e[100], num[100];

    printf("Enter Name: ");
    scanf(" %[^\n]", n);

    printf("Enter Email: ");
    scanf(" %[^\n]", e);

    printf("Enter Phone Number: ");
    scanf(" %[^\n]", num);

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

void SearchByNumber(char name[1000][100], char email[1000][100], char number[1000][100])
{

    char num[100];
    printf("\nEnter the phone number you would like to search your contact by: ");
    scanf("%s", num);

    int flag = 0, i;

    for (i = 0; i < 1000; i++)
    {

        if (strcmp(num, number[i]) == 0)
        {
            flag = 1;
            printf("\nName: %s\nEmail: %s\nPhone Number: %s\n", name[i], email[i], number[i]);
        }
    }

    if (!flag)
    {

        printf("\nSorry, but no contact was found in the database with the phone number '%s'\n", num);
    }
}

void SearchByName(char name[1000][100], char email[1000][100], char number[1000][100])
{
    char SearchName[100];
    int flag = 0;

    printf("\nEnter the name of the contact you want to search: ");
    scanf(" %[^\n]", SearchName);

    int i;
    for (i = 0; i < 1000; i++)
    {
        if (strcmp(SearchName, name[i]) == 0)
        {
            printf("\nName: ");
            puts(name[i]);
            printf("Email: ");
            puts(email[i]);
            printf("Phone Number: ");
            puts(number[i]);
            printf("\n");
            flag = 1;
        }
    }

    if (!flag)
    {
        printf("\nSorry, but no contact was found in the database with the name '%s'\n", SearchName);
    }
}

void SearchByEmail(char name[1000][100], char email[1000][100], char num[1000][100])
{
    int i, flag = 0;
    char search[100];
    printf("\nEnter the email you would like to search the contacts by: ");
    scanf(" %s", search);

    for (i = 0; i < 1000; i++)
    {
        if (strcmp(email[i], search) == 0)
        {
            printf("\nName: %s\nEmail Address: %s\nPhone Number: %s\n", name[i], email[i], num[i]);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("\nSorry, but no contact was found in the database with the email address '%s'\n", search);
    }
}

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

void DeleteContact(char (*name)[1000][100], char (*email)[1000][100], char (*num)[1000][100])
{

    int position[1000], i, count=0, pos, flag=0;
    char choice, search[100], delete;

    for (i=0; i<1000; i++) {
        position[i] = -1;
    }

    do
    {
        printf("Would you like to search the contact you would like to delete, by name (N), phone number (P), or email address (E): ");
        scanf(" %c", &choice);

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
        printf("\nEnter the name of the contact you would like to delete: ");
        scanf(" %[^\n]", search);
        for (i = 0; i < 1000; i++)
        {
            if (strcmp(search, (*name)[i]) == 0)
            {
                position[count] = i;
                printf("\nContact %d:\n", count + 1);
                count++;
                printf("Name: %s\nEmail Address: %s\nPhone Number: %s\n\n", (*name)[i], (*email)[i], (*num)[i]);
                flag=1;

            }
        }
        break;

    case 'P':
        printf("\nEnter the phone number of the contact you would like to delete: ");
        scanf(" %[^\n]", search);
        for (i = 0; i < 1000; i++)
        {
            if (strcmp(search, (*num)[i]) == 0)
            {
                position[count] = i;
                printf("\nContact %d:\n", count + 1);
                count++;
                printf("Name: %s\nEmail Address: %s\nPhone Number: %s\n\n", (*name)[i], (*email)[i], (*num)[i]);
                flag=1;
            }
        }
        break;

    case 'E':
        printf("\nEnter the email address of the contact you would like to delete: ");
        scanf(" %[^\n]", search);
        for (i = 0; i < 1000; i++)
        {
            if (strcmp(search, (*email)[i]) == 0)
            {
                position[count] = i;
                printf("\nContact %d:\n", count + 1);
                count++;
                printf("Name: %s\nEmail Address: %s\nPhone Number: %s\n\n", (*name)[i], (*email)[i], (*num)[i]);
                flag=1;
            }
        }
        break;
    }

    if (flag == 0)
    {
        printf("\nSorry, but no such contact exists in the database\n");
    }
    else
    {

         do
        {
            printf("\nWhich contact would you like to delete (1 to %d): ", count);
            scanf("%d", &pos);

            if (pos < 1 || pos > count)
            {
                printf("\nPlease enter a valid contact number\n");

            }

        } while (pos < 1 || pos > count);

        pos = position[pos-1];

        sleep(1);
        system("cls");

        do {
            printf("Are you sure you want to delete this contact (Y/N): ");
            scanf(" %c", &delete);

            if (delete!='Y' && delete!='N') {
                printf("\nPlease enter 'Y' or 'N'\n");
                sleep(2);
                system("cls");
            }

        } while (delete!='Y' && delete!='N');


        if (delete == 'Y') {

            for (i = (pos+1); i < 1000; i++)
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

        else {
            printf("\nContact deletion cancelled. The contact remains in the database.\n");
        }
    }
}

void UpdateContact(char (*name)[1000][100], char (*email)[1000][100], char (*num)[1000][100])
{
    int i, position[1000], choose, pos, count = 0, flag = 0;
    char choice, again = 'Y';
    char search[100];

    for (i = 0; i < 1000; i++)
    {
        position[i] = -1;
    }

    do
    {
        printf("Would you like to search the contact you would like to update, by name (N), phone number (P), or email address (E): ");
        scanf(" %c", &choice);

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
        printf("\nEnter the name of the contact you would like to update: ");
        scanf(" %[^\n]", search);
        for (i = 0; i < 1000; i++)
        {
            if (strcmp(search, (*name)[i]) == 0)
            {
                position[count] = i;
                printf("\nContact %d:\n", count + 1);
                count++;
                printf("Name: %s\nEmail Address: %s\nPhone Number: %s\n\n", (*name)[i], (*email)[i], (*num)[i]);
                flag = 1;
            }
        }
        break;

    case 'P':
        printf("\nEnter the phone number of the contact you would like to update: ");
        scanf(" %[^\n]", search);
        for (i = 0; i < 1000; i++)
        {
            if (strcmp(search, (*num)[i]) == 0)
            {
                position[count] = i;
                printf("\nContact %d:\n", count + 1);
                count++;
                printf("Name: %s\nEmail Address: %s\nPhone Number: %s\n\n", (*name)[i], (*email)[i], (*num)[i]);
                flag = 1;
            }
        }
        break;

    case 'E':
        printf("\nEnter the email address of the contact you would like to update: ");
        scanf(" %[^\n]", search);
        for (i = 0; i < 1000; i++)
        {
            if (strcmp(search, (*email)[i]) == 0)
            {
                position[count] = i;
                printf("\nContact %d:\n", count + 1);
                count++;
                printf("Name: %s\nEmail Address: %s\nPhone Number: %s\n\n", (*name)[i], (*email)[i], (*num)[i]);
                flag = 1;
            }
        }
        break;
    }

    if (flag == 0)
    {
        printf("\nSorry, but no contact was found matching your search criteria\n");
    }
    else
    {
        do
        {
            printf("\nWhich contact would you like to update (1 to %d): ", count);
            scanf("%d", &pos);

            if (pos < 1 || pos > count)
            {
                printf("\nPlease enter a valid contact number\n");

            }

        } while (pos < 1 || pos > count);

        pos = position[pos - 1];

        do
        {

            sleep(1);
            system("cls");

            do
            {
            printf("What would you like to update in this contact:\n1 . Name\n2 . Phone Number\n3 . Email Address\nChoose one of the options ( 1 | 2 | 3 ):\n\n> ");
            scanf("%d", &choose);


                switch (choose)
                {
                case 1:
                    printf("\nEnter the new name you would like to update this to: ");
                    scanf(" %[^\n]", (*name)[pos]);
                    printf("\nContact updated successfully\n");
                    break;

                case 2:
                    printf("\nEnter the new phone number you would like to update this to: ");
                    scanf(" %s", (*num)[pos]);
                    printf("\nContact updated successfully\n");
                    break;

                case 3:
                    printf("\nEnter the new email address you would like to update this to: ");
                    scanf(" %s", (*email)[pos]);
                    printf("\nContact updated successfully\n");
                    break;

                default:
                    printf("\nInvalid choice, please try again\n\n");
                    sleep(2);
                    system("cls");
                }
            } while (choose < 1 || choose > 3);

            sleep(2);
            system("cls");

            do
            {
                printf("Do you want to update anything else (Y/N): ");
                scanf(" %c", &again);
                if (again != 'Y' && again != 'N')
                {
                    printf("\nPlease choose one from the two options given: 'Y' or 'N'\n\n");
                    sleep(2);
                    system("cls");
                }
            } while (again != 'Y' && again != 'N');

            if (again=='N') {
                printf("\nNo further changes will be made.\n");
            }
            else {
                printf("\nYou may proceed to update any other details of this contact as necessary.\n");
            }
            sleep(2);
            system("cls");

        } while (again == 'Y');
    }
}

int main()
{
    char name[1000][100], email[1000][100], number[1000][100];
    char S;
    char exit;

    int i;

    for (i = 0; i < 1000; i++)
    {
        strcpy(name[i], " ");
        strcpy(email[i], " ");
        strcpy(number[i], " ");
    }

    int choice;

    do
    {

        do
        {
            printf("Phonebook Management System:\n");
            printf(" 1 . Add contact\n");
            printf(" 2 . DeleteContact\n");
            printf(" 3 . UpdateContact\n");
            printf(" 4 . Search Contact\n");
            printf(" 5 . Clear Contacts\n");
            printf(" 6 . Display Contacts\n");
            printf(" 7 . Exit\n");


            printf("Enter option ( 1 | 2 | 3 | 4 | 5 | 6 | 7 ): ");
            scanf("%d", &choice);

            if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
            {
                printf("\nInvalid option\n");
                sleep(2);
                system("cls");
              
            }
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice !=7);


        sleep(1);
        system("cls");

        switch (choice)
        {
        case 1:
            AddContact(&name, &email, &number);
            break;

        case 2:
            DeleteContact(&name, &email, &number);
            break;

        case 3:
            UpdateContact(&name, &email, &number);
            break;

        case 4:

            do
            {
                printf("Would you like to search by name (N), email (E), or phone number (P): ");
                scanf(" %c", &S);
                switch (S)
                {
                case 'N':

                    SearchByName(name, email, number);
                    sleep(3);
                    break;
                case 'P':
                    SearchByNumber(name, email, number);
                    sleep(3);
                    break;
                case 'E':
                    SearchByEmail(name, email, number);
                    sleep(3);
                    break;
                default:
                    printf("\nInvalid choice, try again\n\n");
                    sleep(2);
                    system("cls");
                }

            } while (S != 'N' && S != 'P' && S != 'E');
            break;

        case 5:
            ClearContact(&name, &email, &number);
            break;

        case 6:
            DisplayContacts(name, email, number);
            sleep(5);
            break;

        case 7: 
            do {

                printf("Are you sure you want to exit the system (Y/N): ");
                scanf(" %c", &exit);

                if (exit!='Y' && exit!='N') {
                    printf("\nPlease enter 'Y' or 'N'\n");
                    sleep(2);
                    system("cls");
                }

            } while (exit!='Y' && exit!='N');

            if (exit=='Y') {
                printf("\nYou have exited the phonebook management system");
            }
            else {
                printf("\nYou chose not to exit. The system will continue running.");
            }
            

            break;

        }

        sleep(3);
        system("cls");

    } while (choice!=7 || exit!='Y');

    return 0;
}

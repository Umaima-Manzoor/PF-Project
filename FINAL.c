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
        while((temp = getchar()) != '\n' && temp != EOF);

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
        while((temp = getchar()) != '\n' && temp != EOF);

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

int SearchByEmail(char name[1000][100], char email[1000][100], char number[1000][100], int *position)
{
    char search[100];
    int i, flag = 0;
    int count = 0;
    char temp;

    printf("\nEnter the email you would like to search the contacts by: ");
    scanf(" %[^\n]", search);
    while((temp = getchar()) != '\n' && temp != EOF);

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

void UpdateContact(char (*name)[1000][100], char (*email)[1000][100], char (*num)[1000][100])
{
    int i, count = 0, pos, choose;
    char choice, again;
    char temp;
    char search[100];
    int validName, validPhone;
    int position[1000];

    do
    {
        printf("Would you like to search the contact you would like to update, by name (N), phone number (P), or email address (E): ");
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
        return;  // Search functions already print error message
    }

    int loop;
    do
    {
        loop=0;
        printf("\nWhich contact would you like to update (1 to %d): ", count);
        if (scanf(" %d", &pos) != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
            loop=1;
        }
        else if (pos < 1 || pos > count)
        {
            printf("\nPlease enter a valid contact number\n");
        }

    } while ((pos < 1 || pos > count)|| (loop==1));

    for (i = 0; i < 1000; i++)
    {
        if (strstr((*name)[i], search) != NULL && strcmp((*name)[i], " ") != 0)
        {
            position[count] = i;
            count++;
        }
    }
    pos = position[pos - 1];

    do
    {
        sleep(1);
        system("cls");

        do
        {
            printf("What would you like to update in this contact:\n1 . Name\n2 . Phone Number\n3 . Email Address\nChoose one of the options ( 1 | 2 | 3 ):\n\n> ");
            if (scanf(" %d", &choose)!= 1) {
                printf("Invalid input, please enter a valid number.\n");
                while (getchar()!= '\n');
            }

            else if (choose < 1 || choose > 3)
            {
                printf("\nInvalid choice, please try again\n\n");
                
            }
            sleep(2);
            system("cls");
        } while (choose < 1 || choose > 3);

        switch (choose)
        {
        case 1:
            do
            {
                printf("\nEnter the new name you would like to update this to: ");
                scanf(" %[^\n]", (*name)[pos]);
                while((temp = getchar()) != '\n' && temp != EOF);

                validName = 1;
                for (i = 0; (*name)[pos][i] != '\0'; i++)
                {
                    if (!(((*name)[pos][i] >= 'a' && (*name)[pos][i] <= 'z') || 
                          ((*name)[pos][i] >= 'A' && (*name)[pos][i] <= 'Z') || 
                          (*name)[pos][i] == ' '))
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
            printf("\nContact updated successfully\n");
            break;

        case 2:
            do
            {
                printf("\nEnter the new phone number you would like to update this to: ");
                scanf(" %[^\n]", (*num)[pos]);
                while((temp = getchar()) != '\n' && temp != EOF);

                validPhone = 1;
                for (i = 0; (*num)[pos][i] != '\0'; i++)
                {
                    if (!(((*num)[pos][i] >= '0' && (*num)[pos][i] <= '9') || 
                          (*num)[pos][i] == '+' || (*num)[pos][i] == '-'))
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
            printf("\nContact updated successfully\n");
            break;

        case 3:
            printf("\nEnter the new email address you would like to update this to: ");
            scanf(" %[^\n]", (*email)[pos]);
            while((temp = getchar()) != '\n' && temp != EOF);
            printf("\nContact updated successfully\n");
            break;
        }

        sleep(2);
        system("cls");

        do
        {
            printf("Do you want to update anything else (Y/N): ");
            scanf(" %c", &again);
            while((temp = getchar()) != '\n' && temp != EOF);

            if (again != 'Y' && again != 'N')
            {
                printf("\nPlease choose one from the two options given: 'Y' or 'N'\n\n");
                sleep(2);
                system("cls");
            }
        } while (again != 'Y' && again != 'N');

        if (again == 'N')
        {
            printf("\nNo further changes will be made.\n");
        }
        else
        {
            printf("\nYou may proceed to update any other details of this contact as necessary.\n");
        }
        sleep(2);
        system("cls");

    } while (again == 'Y');
}

int main()
{
    char name[1000][100], email[1000][100], number[1000][100];
    char S;
    char exit;
    char temp;
    int i;
    int choice;
    int positions[1000];

    for (i = 0; i < 1000; i++)
    {
        strcpy(name[i], " ");
        strcpy(email[i], " ");
        strcpy(number[i], " ");
    }

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
        if (scanf(" %d", &choice) != 1)
        {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
        }
        else
        {
            if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
            {
                printf("\nInvalid option. Please enter a number from options listed above.\n");
            }
        }

        sleep(2);
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
                while((temp = getchar()) != '\n' && temp != EOF);

                if (S != 'N' && S != 'P' && S != 'E')
                {
                    printf("\nInvalid choice, try again\n\n");
                    sleep(2);
                    system("cls");
                }
            } while (S != 'N' && S != 'P' && S != 'E');

            switch (S)
            {
            case 'N':
                SearchByName(name, email, number, positions);
                sleep(3);
                break;
            case 'P':
                SearchByNumber(name, email, number, positions);
                sleep(3);
                break;
            case 'E':
                SearchByEmail(name, email, number, positions);
                sleep(3);
                break;
            default:
                printf("\nInvalid choice, try again\n\n");
                sleep(2);
                system("cls");
            }
            break;

        case 5:
            ClearContact(&name, &email, &number);
            break;

        case 6:
            DisplayContacts(name, email, number);
            sleep(5);
            break;

        case 7:
            do
            {
                printf("Are you sure you want to exit the system (Y/N): ");
                scanf(" %c", &exit);
                while((temp = getchar()) != '\n' && temp != EOF);

                if (exit != 'Y' && exit != 'N')
                {
                    printf("\nPlease enter 'Y' or 'N'\n");
                    sleep(2);
                    system("cls");
                }
            } while (exit != 'Y' && exit != 'N');

            if (exit == 'Y')
            {
                printf("\nYou have exited the phonebook management system");
            }
            else
            {
                printf("\nYou chose not to exit. The system will continue running.");
            }

            break;
        }

        sleep(3);
        system("cls");

    } while (choice != 7 && exit != 'Y');

    return 0;
}



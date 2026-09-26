#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



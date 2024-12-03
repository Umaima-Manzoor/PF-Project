#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                // while((temp = getchar()) != '\n' && temp != EOF);

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
                // while((temp = getchar()) != '\n' && temp != EOF);

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
            // while((temp = getchar()) != '\n' && temp != EOF);
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

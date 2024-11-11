#include <stdio.h>
#include <string.h>

void UpdateContact(char (*name)[1000][100], char (*email)[1000][100], char (*num)[1000][100]) { 
    int i, position = -1, choose;
    char choice, again = 'Y';
    char search[100];


    do {
        printf("Would you like to search the contact you would like to update, by name (N), phone number (P), or email address (E): ");
        scanf(" %c", &choice);

        if (choice != 'N' && choice != 'P' && choice != 'E') {
            printf("Invalid choice, please try again\n\n");
        }
    } while (choice != 'N' && choice != 'P' && choice != 'E');
    
    switch (choice) {
        case 'N': 
            printf("Enter the name of the contact you would like to update: ");
            scanf(" %[^\n]", search);
            for (i = 0; i < 1000; i++) {
                if (strcmp(search, (*name)[i]) == 0) {  
                    position = i;
                    break;
                }
            }
            break;

        case 'P': 
            printf("Enter the phone number of the contact you would like to update: ");
            scanf(" %[^\n]", search);
            for (i = 0; i < 1000; i++) {
                if (strcmp(search, (*num)[i]) == 0) {  
                    position = i;
                    break;
                }
            }
            break;

        case 'E': 
            printf("Enter the email address of the contact you would like to update: ");
            scanf(" %[^\n]", search);
            for (i = 0; i < 1000; i++) {
                if (strcmp(search, (*email)[i]) == 0) { 
                    position = i;
                    break;
                }
            }
            break;
    }

  
    if (position == -1) {
        printf("Sorry, but no such contact exists in the database\n");
    } else {
        do {  
            printf("What would you like to update in this contact:\n1. Name\n2. Phone Number\n3. Email Address\n> ");
            scanf("%d", &choose);

            switch (choose) {
                case 1: 
                    printf("Enter the new name you would like to update this to: ");
                    scanf(" %[^\n]", (*name)[position]);  
                    printf("Contact updated successfully\n");
                    break;

                case 2: 
                    printf("Enter the new phone number you would like to update this to: ");
                    scanf(" %s", (*num)[position]); 
                    printf("Contact updated successfully\n");
                    break;
                    
                case 3: 
                    printf("Enter the new email address you would like to update this to: ");
                    scanf(" %s", (*email)[position]); 
                    printf("Contact updated successfully\n");
                    break;

                default: 
                    printf("Invalid choice, please try again\n\n");
            }

            do {
                printf("Do you want to update anything else (Y/N): ");
                scanf(" %c", &again);  
                if (again != 'Y' && again != 'N') {
                    printf("Please choose one from the two options given: 'Y' or 'N'\n\n");
                }
            } while (again != 'Y' && again != 'N');

        } while (again == 'Y'); 
    }
}

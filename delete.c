#include <stdio.h>
#include <string.h>

void DeleteContact(char (*name)[1000][100], char (*email)[1000][100], char (*num)[1000][100]) {

    int position=-1, i;
    char choice, search[100];

    do {
        printf("Would you like to search the contact you would like to delete, by name (N), phone number (P), or email address (E): ");
        scanf(" %c", &choice);

        if (choice != 'N' && choice != 'P' && choice != 'E') {
            printf("Invalid choice, please try again\n\n");
        }
    } while (choice != 'N' && choice != 'P' && choice != 'E');

    switch (choice) {
        case 'N': 
            printf("Enter the name of the contact you would like to delete: ");
            scanf(" %[^\n]", search);
            for (i = 0; i < 1000; i++) {
                if (strcmp(search, (*name)[i]) == 0) {  
                    position = i;
                    break;
                }
            }
            break;

        case 'P': 
            printf("Enter the phone number of the contact you would like to delete: ");
            scanf(" %[^\n]", search);
            for (i = 0; i < 1000; i++) {
                if (strcmp(search, (*num)[i]) == 0) {  
                    position = i;
                    break;
                }
            }
            break;

        case 'E': 
            printf("Enter the email address of the contact you would like to delete: ");
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
    }
    else {
        
        for (i=(position+1); i<1000; i++) {
            strcpy((*name)[i-1], (*name)[i]);
            strcpy((*email)[i-1], (*email)[i]);
            strcpy((*num)[i-1], (*num)[i]);
        }

        strcpy((*name)[999], " ");
        strcpy((*email)[999], " ");
        strcpy((*num)[999], " ");

        printf("Contact deleted successfully\n");
    }
}
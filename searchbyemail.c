#include <stdio.h>
#include <string.h>

void SearchByEmail(char name[1000][100], char email[1000][100], char num[1000][100]) {
    int i,flag=0;
    char search[100];
    printf("Enter the email you would like to search the contacts by: ");
    scanf(" %s", search);

    for (i=0; i<1000; i++) {
        if (strcmp(email[i], " ") != 0) {
            if (strcmp(email[i], search) == 0) {
                printf("Name: %s\nEmail Address: %s\nPhone Number: %s\n\n", name[i], email[i], num[i]);
                flag=1;
            }

        }
    }

    if (flag==0) {
        printf("Sorry, but no contact was found in the database with the email address '%s'\n", search);
    }
    

}
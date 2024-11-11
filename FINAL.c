#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void ClearContact(char (*name)[1000][100],char (*email)[1000][100], char (*number)[1000][100]){
	
	int i;
	
	for(i=0 ;i<1000 ;i++){
		strcpy((*name)[i], " ");
        strcpy((*email)[i], " ");
        strcpy((*number)[i], " ");
	}
	
}

void SearchByNumber(char name[1000][100],char email[1000][100],char number[1000][100]){

    char num[100];
	printf("Enter the phone number you would like to search your contact by: ");
	scanf("%s", num);

	int flag = 0, index, i;
	
	for(i=0 ;i<1000;i++){
	
        if(strcmp(num, number[i])==0) {
            flag = 1;	
            index=i; 
            break; 
        }
	 }
	 
	 if (flag){
	 	printf("Name: %s\nEmail: %s\nPhone Number: %s\n",name[index],email[index],number[index]);
	 	
	 }
	 else 
	 printf("Contact is not in the list");
}




void AddContact(char (*name)[1000][100], char (*email)[1000][100], char (*number)[1000][100]){
    int i, flag=0;;
    for (i=0; i<1000; i++) {
        if (strcmp((*name)[i], " ") == 0) {
            flag=1;
            printf("Enter Name: ");
            scanf(" %[^\n]", (*name)[i]);

            printf("Enter Email: ");
            scanf(" %[^\n]", (*email)[i]);

            printf("Enter Phone Number: ");
            scanf(" %[^\n]", (*number)[i]);

            puts("\nContact Was Added Successfully!");
            break;
        }
    }

    if (flag==0) {
        puts("Sorry, the contact list is full");
    }
}

void SearchByName(char name[1000][100], char email[1000][100], char number[1000][100])
{
    char SearchName[100];
    int flag=0;

    printf("Enter the name of the contact you want to search: ");
    fgets(SearchName, 100, stdin);
    SearchName[strcspn(SearchName, "\n")] = '\0';
    int i;
    for(i=0;i<1000;i++) 
	{
        if(strcmp(SearchName,name[i])==0) 
		{
            printf("Name: ");
            puts(name[i]);
            printf("Email: ");
            puts(email[i]);
            printf("Phone Number: ");
            puts(number[i]);
            printf("\n");
            flag = 1;

        }
    }

    if(!flag) 
	{
        puts("Contact Not Found");
    }
}

void DisplayContacts(char name[1000][100], char email[1000][100], char number[1000][100]) 
{
    int i, flag=0;;
    for(i=0;i<1000;i++) 
	{
        if (strcmp(name[i], " ")!=0) {
            flag=1;
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
    if (flag==0) {
        printf("No contacts found");
    }
}


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

int main(){
char name[1000][100], email[1000][100], number[1000][100];
char S;

int i;

for(i=0;i<1000;i++){
    strcpy(name[i], " ");
    strcpy(email[i], " ");
    strcpy(number[i], " ");
}

int choice;

do{

printf(" 1 . Add contact\n");
printf(" 2 . DeleteContact\n");
printf(" 3 . UpdateContact\n");
printf(" 4 . Search Contact\n"); 
printf(" 5 . Clear Contacts\n");
printf(" 6 . Display Contacts:\n");
printf(" 7 . Exit\n");

printf("Enter option ( 1 | 2 | 3 | 4 | 5 | 6 | 7 ): ");

scanf("%d",&choice);

if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5  && choice!=6 && choice!=7) {
	printf("\nInvalid option\n");
}

if (choice==7) {
	printf("\nYou have exited the phonebook management system");
}

sleep(1);
system("cls");

switch(choice){
	case 1:
		AddContact(&name , &email, &number);
		break;
		
	case 2:
		DeleteContact(&name, &email, &number);
		break;
		
	case 3:
		UpdateContact(&name, &email, &number);
		break;
		
	case 4:
        
        do {
        printf("Would you like to search by name (N), email (E), or phone number (P): ");
        scanf("%c", &S);
        switch (S) {
            case 'N': SearchByName(name, email, number);
            break;
            case 'P': SearchByNumber(name, email, number);
            break;
            case 'E': SearchByEmail(name, email, number);
            break;
            default: printf("Invalid choice, try again\n\n");

        } 

        } while (S !='N' && S !='P' && S!='E');
        break;
		
	case 5:
		ClearContact(&name, &email, &number);
		break;

	case 6:
		DisplayContacts(name,email,number);
		break;
		

}

sleep(3);
system("cls");

} while (choice!=7);

return 0;

}

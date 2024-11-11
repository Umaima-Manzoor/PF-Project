void AddContact(char (*name)[1000][100], char (*email)[1000][100], char (*number)[1000][100])
{
    int i, flag=0;;
    for (i=0; i<1000; i++) {
        if (strcmp((*name)[i], " ") == 0) {
            flag=1;
            printf("Enter Name: ");
            fgets((*name)[i], 100, stdin);
            (*name)[i][strcspn((*name)[i], "\n")] = '\0';

            printf("Enter Email: ");
            fgets((*email)[i], 100, stdin);
            (*email)[i][strcspn((*email)[i], "\n")] = '\0';

            printf("Enter Phone Number: ");
            fgets(number[i], 100, stdin);
            (*number)[i][strcspn((*number)[i], "\n")] = '\0';

            puts("Contact Was Added Successfully!");
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

void SearchByName(char name[1000][100], char email[1000][100], char number[1000][100])
{
    char SearchName[100];
    int flag=0;

    printf("Enter the name of the contact you want to search: ");
    fgets(SearchName, 100, stdin);
    SearchName[strcspn(SearchName, "\n")] = '\0';
    int i;
    for(i=0;i<count;i++) 
	{
        if(strcmp(SearchName,name[i])==0) 
		{
            puts("Contact Found:");
            printf("Name: ");
            puts(name[i]);
            printf("Email: ");
            puts(email[i]);
            printf("Phone Number: ");
            puts(number[i]);
            flag = 1;
            break;
        }
    }

    if (!flag) 
	{
        puts("Contact Not Found");
    }
}


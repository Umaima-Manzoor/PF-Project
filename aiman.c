int count=0;

void AddContact(char name[1000][100], char email[1000][100], char number[1000][100])
{
    printf("Enter Name: ");
    fgets(name[count], 100, stdin);
    name[count][strcspn(name[count], "\n")] = '\0';

    printf("Enter Email: ");
    fgets(email[count], 100, stdin);
    email[count][strcspn(email[count], "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(number[count], 100, stdin);
    number[count][strcspn(number[count], "\n")] = '\0';

    count++;
    puts("Contact Was Added Successfully!");
}

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

void DisplayContacts(char name[1000][100], char email[1000][100], char number[1000][100]) 
{
    if(count==0)
	{
        puts("No Contacts Present");
        return;
    }
    int i;
    for (i=0;i<count; i++) 
	{
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


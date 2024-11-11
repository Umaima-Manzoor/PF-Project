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


void SearchByName(char name[1000][100], char email[1000][100], char number[1000][100])
{
    char SearchName[100];
    int flag = 0;

    printf("\nEnter the name of the contact you want to search: ");
    scanf(" %[^\n]", SearchName);

    int i;
    for (i = 0; i < 1000; i++)
    {
        if (strcmp(SearchName, name[i]) == 0)
        {
            printf("\nName: ");
            puts(name[i]);
            printf("Email: ");
            puts(email[i]);
            printf("Phone Number: ");
            puts(number[i]);
            printf("\n");
            flag = 1;
        }
    }

    if (!flag)
    {
        printf("\nSorry, but no contact was found in the database with the name '%s'\n", SearchName);
    }
}

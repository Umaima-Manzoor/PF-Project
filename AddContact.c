void AddContact(char (*name)[1000][100], char (*email)[1000][100], char (*number)[1000][100])
{
    int i, flag = 0;
    char n[100], e[100], num[100];

    printf("Enter Name: ");
    scanf(" %[^\n]", n);

    printf("Enter Email: ");
    scanf(" %[^\n]", e);

    printf("Enter Phone Number: ");
    scanf(" %[^\n]", num);

    for (i = 0; i < 1000; i++)
    {
        if (strcmp((*name)[i], n) == 0 && strcmp((*email)[i], e) == 0 && strcmp((*number)[i], num) == 0)
        {
            flag = -1;
            puts("\nContact is already stored in the database");
            break;
        }
    }
    if (flag != -1)
    {
        for (i = 0; i < 1000; i++)
        {
            if (strcmp((*name)[i], " ") == 0)
            {
                strcpy((*name)[i], n);
                strcpy((*email)[i], e);
                strcpy((*number)[i], num);
                puts("\nContact Was Added Successfully!");
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0)
    {
        puts("Sorry, the contact list is full");
    }
}

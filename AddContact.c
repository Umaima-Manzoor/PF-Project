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


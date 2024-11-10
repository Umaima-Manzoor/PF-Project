#include<stdio.h>

int main(){


int name[1000][100] ,email[1000][100],number[1000][100];

for(int i=0;i<1000;i++){
	name[1000][100]=0;
	email[1000][100]=0;
	number[1000][100]=0;
}

int choice;

printf(" 1 . Add contact\n");
printf(" 2 . DeleteContact\n");
printf(" 3 . UpdateContact\n");
printf(" 4 . Search Contact By Name\n"); 
printf(" 5 . Search Contact By Email\n");
printf(" 6 . Search Contact By Number\n");
printf(" 7 . Clear Contacts\n");
printf(" 8 . Display Contacts:\n");
printf(" 9 . Exit\n");

printf("Enter option (1.2.3.4.5.6.)\n");

scanf("%d",&choice);

while(1){

switch(choice){
	case 1:
		AddContact(name , email,number);
		break;
		
	case 2:
		DeleteContact(name,email,number);
		break;
		
	case 3:
		UpdateContact(name,email,number);
		break;
		
	case 4:
		SearchByName(name,email,number);
		break;
		
	case 5:
		SearchByEmail(name,email,number);
		break;
		
	case 6:
		SearchByNumber(name,email,number);
		break;
		
	case 7:
		DisplayContact(name,email,number);
		break;
		
	case 8:
		ClearContact(name,email,number);
		break;
		
	case 9:
		printf("Exit\n");
		break;
		
	default:
		printf("Invalid option\n");
		break;
}
}

}
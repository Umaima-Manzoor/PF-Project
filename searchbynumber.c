#include <stdio.h>
#include <string.h>

void SearchByNumber(char name[1000][100],char email[1000][100],char number[1000][100]){

    char num[100];
	printf("Enter the phone number you would like to search your contact by: ");
	scanf("%s", num);

	int flag = 0, index;
	
	for(int i=0 ;i<1000;i++){
	
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






#include <stdio.h>
#include <string.h>

void SearchByNumber(char name[][],char email[][],char number[][],char num[]){

	printf("Enter the phone number you would like to search your contact by: ");
	scanf("%s", num);

	int flag = 0;
	
	for(int i=0 ;i<1000;i++){
	
	 if(strcmp(num, number[i])) {
	 	flag = 1;	
	    index=i;  
	 }
	 }
	 
	 if (flag){
	 	printf(" %s %s %s",name[index],email[index],number[index]);
	 	
	 }
	 else 
	 printf("Contact is not in the list");
}




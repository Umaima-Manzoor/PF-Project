#include<stdio.h>

void ClearContact(name[][],email[][],number[][]){
	int n1,n2;
	printf("Enter from which contact you want you delete till the last contact: ");
	scanf("%d %d",&n1,&n2);
	
	for(int i=n1 ;i<n2 ;i++){
		strcpy(name[i], "");
        strcpy(email[i], "");
        strcpy(number[i], "");
	}
	
}
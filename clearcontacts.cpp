#include<stdio.h>

void ClearContact(name[][],email[][],number[][]){
	
	for(int i=0 ;i<1000 ;i++){
		strcpy(name[i], " ");
        strcpy(email[i], " ");
        strcpy(number[i], " ");
	}
	
}

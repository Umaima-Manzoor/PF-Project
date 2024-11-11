#include<stdio.h>


void ClearContact(char (*name)[1000][100],char (*email)[1000][100], char (*number)[1000][100]){
	
	for(int i=0 ;i<1000 ;i++){
		strcpy((*name)[i], " ");
        strcpy((*email)[i], " ");
        strcpy((*number)[i], " ");
	}
	
}

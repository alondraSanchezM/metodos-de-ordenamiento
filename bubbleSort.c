
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
	FILE *fp;
	int ayuda,n, i,j;
	n=atoi(argv[1]);
	int A[n];
	fp=fopen("datos.txt","r");
	for(i=0; i<n; i++)
		fscanf(fp, "%d", &A[i]);
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(A[i]>A[j]){
				ayuda=A[i];
				A[i]=A[j];
				A[j]=ayuda;
			}
	for(i=0; i<n; i++)
		printf("%d  ",A[i]);
	printf("\n");
}

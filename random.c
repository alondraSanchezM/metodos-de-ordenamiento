//10       1 000       1 000 000     1 000 000 000
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
//#define n 10

int main(int argc, char *argv[]){
	int n;
	n=atoi(argv[1]);
	FILE *fp;
	int num,i,A[n];
	fp=fopen("datos.txt","w");
	srand(time(NULL));

	for(i=0; i<n; i++){
		num=rand() % 3000000000+1;
		fprintf(fp, "%d ", num);
	}
	fclose(fp);
	
	
	fp=fopen("datos.txt","r");
	/*for(i=0; i<n; i++){
		fscanf(fp, "%d", &A[i]);
		printf("%d  ",A[i]);
	}*/
	printf("\n");
}

//Iterative comb Sort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<stdbool.h>

int main(int argc, char *argv[]){
	
	int j, ayuda, n;
	n=atoi(argv[1]);
	int A[n];
	
	float fd = n;	
	bool cambio = true;
	FILE *fp, *fs;

	fp=fopen("datos.txt","r");
	for(int i=0; i<n; i++)
		fscanf(fp, "%d", &A[i]);
	
	do{
		if((fd/1.3)>1)
			fd=(int)(fd/1.3);
		else
			fd=1;
		cambio=false;	
		for(int i=0;i<n-fd;i++){
			j=i+fd;
			if(A[i]>A[j]){
				ayuda=A[i];
				A[i]=A[j];
				A[j]=ayuda;
				cambio = true;
			}
		}
	}while((fd!=1)||(cambio));
	
	
	fs=fopen("resultado.txt","wt");
	for(int i=0;i<n;i++)
		fprintf(fs,"%d ",A[i]);
	fclose(fs);

	fclose(fp);

}

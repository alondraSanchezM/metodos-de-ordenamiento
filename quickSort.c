#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void swap(int* a, int* b);
int partition(int arr[], int l, int h);
void quickSortIterative(int arr[], int l, int h);
void printArr(int arr[], int n);

int main(int argc, char *argv[]){
	FILE *fp;
	int tam;
	tam=atoi(argv[1]);
	int ayuda, i,j, num, A[tam];
	
	fp=fopen("datos.txt","r");
	for(i=0; i<tam; i++)
		fscanf(fp, "%d", &A[i]);
	
	int n = sizeof(A) / sizeof(*A); 
	quickSortIterative(A, 0, n - 1); 
	
	for(i=0; i<tam; i++)
		printf("%d ",A[i]);
	printf("\n");
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int l, int h) 
{ 
    int x = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++) { 
        if (arr[j] <= x) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 

void quickSortIterative(int arr[], int l, int h) 
{ 
    // Create an auxiliary stack 
    int stack[h - l + 1]; 
  
    // initialize top of stack 
    int top = -1; 
  
    // push initial values of l and h to stack 
    stack[++top] = l; 
    stack[++top] = h; 
  
    // Keep popping from stack while is not empty 
    while (top >= 0) { 
        // Pop h and l 
        h = stack[top--]; 
        l = stack[top--]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        int p = partition(arr, l, h); 
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (p - 1 > l) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (p + 1 < h) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    } 
} 


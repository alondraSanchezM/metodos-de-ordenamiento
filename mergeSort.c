//Iterative Merge Sort

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Utility function to find minimum of two numbers
int min(int x, int y)
{
	return (x < y) ? x : y;
}

// Merge two sorted subarrays A[from .. mid] and A[mid + 1 .. to]
void merge(int A[], int temp[], int from, int mid, int to, int N)
{
	int k = from, i = from, j = mid + 1;

	// loop till there are elements in the left and right runs
	while (i <= mid && j <= to)
	{
		if (A[i] < A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	// Copy remaining elements
	while (i < N && i <= mid)
		temp[k++] = A[i++];

	// copy back to the original array to reflect sorted order
	for (int i = from; i <= to; i++)
		A[i] = temp[i];
}

// Iteratively sort array A[low..high] using temporary array
void mergesort(int A[], int temp[], int low, int high)
{
	for (int m = 1; m <= high - low; m = 2*m)
	{
		for (int i = low; i < high; i += 2*m)
		{
			int from = i;
			int mid = i + m - 1;
			int to = min(i + 2*m - 1, high);

			merge(A, temp, from, mid, to, high+1);
		}
	}
}


// Implement Iterative Merge Sort
int main(int argc, char *argv[])
{
	int N=atoi(argv[1]);
	int A[N], temp[N];
	FILE *fp, *fs;

	fp=fopen("datos.txt","r");
	for(int i=0; i<N; i++){
		fscanf(fp, "%d", &A[i]);
		temp[i] = A[i];
	}

	// sort array A[0..N-1] using temporary array temp
	mergesort(A, temp, 0, N - 1);
	
	fs=fopen("resultado.txt","wt");
	for(int i=0;i<N;i++)
		fprintf(fs,"%d ",A[i]);
	fclose(fs);

	fclose(fp);

}

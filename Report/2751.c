#include <stdio.h>

void merge(int a[], int low, int mid, int height)  
{
	int b[1000000];
	int i = low;       
	int j = mid + 1;    
	int k = 0;        
	
	while(i <= mid && j <= height)
	{
		if(a[i] <= a[j])      
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i <= mid) 
		b[k++] = a[i++];
	while(j <= height)         
		b[k++] = a[j++];
	k--;
    
	while(k >= 0)           
	{
		a[low + k] = b[k];
		k--;
	}
}
void mergeSort(int a[], int low, int height) 
{
	
	int mid;
	if(low < height)
	{
		mid = (low + height) / 2;
		mergeSort(a, low, mid);            
		mergeSort(a, mid + 1, height);    
		merge(a, low, mid, height);       
	}
}

int main()
{
	int arr[1000000];
	int i, cnt;  
	
	scanf("%d", &cnt);
	
	for(i = 0 ; i < cnt; i++)
		scanf("%d", &arr[i]);
    
	mergeSort(arr, 0, cnt - 1);  
	
    for(i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
}


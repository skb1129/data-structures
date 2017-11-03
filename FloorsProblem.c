#include <stdio.h>

void swap(int *arr,int n1,int n2){
    int temp=arr[n1];
    arr[n1]=arr[n2];
    arr[n2]=temp;
}

int partition(int *arr,int l,int r){
    int j=l;
    for(int i=l;i<r;i++){
        if(arr[i]<arr[r]){
            swap(arr,i,j);
            j++;
        }
    }
    swap(arr,j,r);
    return j;
}

void quickSort(int *arr,int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

void main() {
	int i, j, n, x, res, arr[100], min[100];
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
		min[i] = 1000000000;
	}
	quickSort(arr,0,n-1);
	for(x=0;x<n-1;x++){
		res = 0;
		for(i=x+1;i<n;i++){
			res += (arr[i] - arr[i-1]) * (i - x);
			if(min[i-1-x]>res)
				min[i-1-x] = res;
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d\t", min[i]);
	}
}

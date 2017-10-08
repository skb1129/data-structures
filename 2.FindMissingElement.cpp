#include<iostream>
using namespace std;
int main(){
	int arr[100],i,n,sum=0,n_sum,min=INT_MAX,max=0;
	cout<<"Size : ";
	cin>>n;
	cout<<"Elements :\n";
	for(i=0;i<n;i++){
		cin>>arr[i];
		if(min>arr[i])
			min=arr[i];
		if(max<arr[i])
			max=arr[i];
		sum+=arr[i];
	}
	n_sum=(max*(max+1)/2)-((min-1)*(min)/2);
	cout<<"Missing Number : "<<n_sum-sum;
}

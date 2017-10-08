#include<iostream>
using namespace std;
int main(){
	int arr[100],n,i,j,k,p,v;
	cout<<"Size : ";
	cin>>n;
	cout<<"Elements :\n";
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	while(1){
		cout<<"\nSelect :\n1.Insertion\n2.Deletion\n";
		cout<<"3.Searching\n4.Display array\n5.Exit\n";
		cout<<"Your Input : ";
		cin>>k;
		if(k==5){
			break;
		}
		else if(k==1){
			cout<<"Index : ";
			cin>>p;
			cout<<"Value : ";
			cin>>v;
			for(i=n;i>p;i--)
				arr[i]=arr[i-1];
			arr[p]=v;
			n++;
			cout<<"Element Inserted";
		}
		else if(k==2){
			cout<<"Select:\n1.Value\n2.Index\nYour Input : ";
			cin>>j;
			if(j==1){
				cout<<"Value : ";
				cin>>v;
				for(i=0;i<n;i++)
					if(arr[i]==v){
						n--;
						for(j=i;j<n;j++)
							arr[j]=arr[j+1];
						i--;
					}
			}
			else if(j==2){
				cout<<"Index : ";
				cin>>p;
				n--;
				for(i=p;i<n;i++)
					arr[i]=arr[i+1];
			}
			cout<<"Deleted";
		}
		else if(k==3){
			cout<<"Value : ";
			cin>>v;
			for(i=0;i<n;i++)
				if(arr[i]==v)
					break;
			if(i==n)
				cout<<"Not Found !";
			else
				cout<<"Found at index "<<i;
		}
		else if(k==4){
			for(i=0;i<n;i++)
				cout<<arr[i]<<"\t";
		}
	}
	cout<<"Thanks";
}

#include<iostream>
using namespace std;

struct Student{
    int rollno;
    string name;
};
void quickSort(Student *,int,int);
int partition(Student *,int,int);
void swap(Student *,int,int);
void quickSort(Student *arr,int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
int partition(Student *arr,int l,int r){
    int j=l;
    for(int i=l;i<r;i++){
        if(arr[i].rollno<arr[r].rollno){
            swap(arr,i,j);
            j++;
        }
    }
    swap(arr,j,r);
    return j;
}
void swap(Student *arr,int n1,int n2){
    Student temp=arr[n1];
    arr[n1]=arr[n2];
    arr[n2]=temp;
}

int main(){
    int i,n;
    struct Student arr[100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i].rollno;
        cin.ignore();
        cin>>arr[i].name;
    }
    quickSort(arr,0,n-1);
    for(i=0;i<n;i++)
        cout<<arr[i].rollno<<"\t"<<arr[i].name<<endl;
}

#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
void insert_beg(int value){
	struct node *temp=head;
	struct node *node1;
	node1=new(struct node);
	node1->data=value;
	node1->next=head;
	node1->prev=NULL;
	if(head==NULL){
		tail=node1;
	}
	else{
		temp->prev=node1;
	}
	head=node1;
	cout<<"Inserted!\n";
}
void insert_end(int value){
	struct node *temp=tail;
	struct node *node2;
	node2=new(struct node);
	node2->data=value;
	node2->next=NULL;
	if(tail==NULL){
		head=node2;
		node2->prev=NULL;
	}
	else{
		temp->next=node2;
		node2->prev=temp;
	}
	tail=node2;
	cout<<"Inserted!\n";
}
void display(){
	struct node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}
void display_rev(){
	struct node *temp=tail;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->prev;
	}
	cout<<endl;
}
int main(){
	int n,val;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>val;
		insert_beg(val);
	}
	display_rev();
	display();
}

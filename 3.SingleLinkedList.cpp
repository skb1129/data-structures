#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert_beg(int value){
	struct node *node1;
	node1=new(struct node);
	node1->data=value;
	node1->next=head;
	head=node1;
	cout<<"Inserted!\n";
}
void insert_end(int value){
	struct node *temp=head;
	if(head!=NULL){
		while(temp->next!=NULL){
			temp=temp->next;
		}
	}
	struct node *node2;
	node2=new(struct node);
	node2->data=value;
	node2->next=NULL;
	if(head==NULL){
		head=node2;
	}
	else{
		temp->next=node2;
	}
	cout<<"Inserted!\n";
}
void insert_after(int after, int value){
	struct node *temp=head;
	while(temp->data!=after && temp->next!=NULL){
		temp=temp->next;
	}
	if(temp->data!=after){
		cout<<"Not Found!\n";
	}
	else{
		struct node *node3;
		node3=new(struct node);
		node3->data=value;
		node3->next=temp->next;
		temp->next=node3;
		cout<<"Inserted!\n";
	}
}
void insert_before(int before, int value){
	struct node *temp=head;
	struct node *prev;
	while(temp->data!=before && temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	if(temp->data!=before){
		cout<<"Not Found!\n";
	}
	else{
		struct node *node3;
		node3=new(struct node);
		node3->data=value;
		node3->next=prev->next;
		prev->next=node3;
		cout<<"Inserted!\n";
	}
}
void delete_beg(){
	struct node *temp=head;
	head=temp->next;
	delete temp;
	cout<<"Deleted!\n";
}
void delete_end(){
	struct node *temp=head;
	struct node *prev;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	delete temp;
	cout<<"Deleted!\n";
}
void delete_value(int value){
	struct node *prev;
	struct node *temp=head;
	while(temp->data!=value && temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	if(temp->data!=value){
		cout<<"Not Found!\n";
	}
	else{
		prev->next=temp->next;
		delete temp;
		cout<<"Deleted!\n";
	}
}
void delete_odd(){
	struct node *temp=head;
	struct node *prev=head;
	struct node *del;
	while(temp!=NULL){
		if(temp->data%2!=0){
			if(temp!=head)
				prev->next=temp->next;
			else
				head=temp->next;
			del=temp;
			prev=temp;
			temp=temp->next;
			delete del;
		}
		else{
			prev=temp;
			temp=temp->next;
		}

	}
	cout<<"Deleted!\n";
}
void search_index(int value){
	struct node *temp=head;
	int i=0;
	while(temp->data!=value && temp->next!=NULL){
		temp=temp->next;
		i++;
	}
	if(temp->data!=value){
		cout<<"Not Found!\n";
	}
	else{
		cout<<"Found at index : "<<i<<endl;
	}
}
void search_value(int index){
	struct node *temp=head;
	for(int i=0;i<index;i++){
		temp=temp->next;
	}
	cout<<"Value at index "<<index<<": "<<temp->data<<endl;
}
void reverse(){
	struct node *begin=head;
	struct node *end=head;
	int temp;
	int n=1;
	while(end->next!=NULL){
		end=end->next;
		n++;
	}
	for(int i=0;i<n/2;i++){
		temp=begin->data;
		begin->data=end->data;
		end->data=temp;
		end=head;
		begin=begin->next;
		for(int j=0;j<n-i-2;j++){
			end=end->next;
		}
	}
	cout<<"List is Reversed!\n";
}
void swap_nodes(int x, int y){
	struct node *t1=head;
	struct node *t2=head;
	int temp;
	for(int i=0;i<x;i++){
		t1=t1->next;
	}
	for(int i=0;i<y;i++){
		t2=t2->next;
	}
	temp=t1->data;
	t1->data=t2->data;
	t2->data=temp;
	cout<<"Swapped!\n";
}
void display(){
	struct node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	int i,n,value,j,after,before,index;
	cout<<"Size: ";
	cin>>n;
	cout<<"Values:\n";
	for(i=0;i<n;i++){
		cin>>value;
		insert_end(value);
	}
	while(1){
		cout<<"Select:\n1.Insert\n2.Delete\n3.Search\n4.Reverse\n5.Swap Nodes\n6.Display\n7.Exit\n";
		cin>>i;
		if(i==1){
			cout<<"1.Begin\n2.End\n3.After\n4.Before\n5.Return to Main\n";
			cin>>j;
			if(j==1){
				cout<<"Enter Value: ";
				cin>>value;
				insert_beg(value);
				n++;
			}
			else if(j==2){
				cout<<"Enter Value: ";
				cin>>value;
				insert_end(value);
				n++;
			}
			else if(j==3){
				cout<<"Enter Value: ";
				cin>>value;
				cout<<"After: ";
				cin>>after;
				insert_after(after,value);
				n++;
			}
			else if(j==4){
				cout<<"Enter Value: ";
				cin>>value;
				cout<<"Before: ";
				cin>>before;
				insert_before(before,value);
				n++;
			}
			else if(j==5){
				continue;
			}
		}
		else if(i==2){
			cout<<"1.Begin\n2.End\n3.Value\n4.Odd\n5.Return to Main\n";
			cin>>j;
			if(j==1){
				delete_beg();
				n--;
			}
			else if(j==2){
				delete_end();
				n--;
			}
			else if(j==3){
				cout<<"Enter Value: ";
				cin>>value;
				delete_value(value);
				n--;
			}
			else if(j==4){
				delete_odd();
			}
			else if(j==5){
				continue;
			}
		}
		else if(i==3){
			cout<<"1.Index of Value\n2.Value at Index\n3.Return to main\n";
			cin>>j;
			if(j==1){
				cout<<"Enter Value: ";
				cin>>value;
				search_index(value);
			}
			else if(j==2){
				do{
					cout<<"Enter Index: ";
					cin>>index;
				}while(index>=n);
				search_value(index);
			}
			else if(j==3){
				continue;
			}
		}
		else if(i==4){
			reverse();
		}
		else if(i==5){
			int i1,i2;
			cout<<"Index 1: ";
			cin>>i1;
			cout<<"Index 2: ";
			cin>>i2;
			swap_nodes(i1,i2);
		}
		else if(i==6){
			display();
		}
		else if(i==7){
			break;
		}
	}
}

#include<stdio.h>
struct node{
	int data;
	struct node* next;
};
struct queue{
	struct node* front;
	struct node* rear;
};
void enqueue(struct queue* q, int data){
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	if(q->front == NULL){
		q->front=new_node;
		new_node->next=NULL;
	}
	else{
		struct node* temp=q->front;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new_node;
		new_node->next=NULL;
	}
	q->rear=new_node;
}
int dequeue(struct queue* q){
	struct node* temp=q->front;
	int res=temp->data;
	q->front=q->front->next;
	free(temp);
	return res;
}
void display(struct queue* q){
	struct node* temp=q->front;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	struct queue q;
	enqueue(&q,4);
	enqueue(&q,5);
	enqueue(&q,6);
	enqueue(&q,8);
	enqueue(&q,9);
	display(&q);
	printf("%d\n",dequeue(&q));
	display(&q);
}

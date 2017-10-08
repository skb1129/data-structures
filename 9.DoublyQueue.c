#include <stdio.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct queue{
	struct node *front;
	struct node *rear;
};
void enqueue_front(struct queue *q, int data){
	struct node *nnode=(struct node*)malloc(sizeof(struct node));
	nnode->data=data;
	if(q->front==NULL){
		q->rear=nnode;
		q->front=nnode;
		nnode->next=NULL;
		nnode->prev=NULL;
	}
	else{
		nnode->next=q->front;
		q->front=nnode;
		nnode->prev=NULL;
	}
}
void enqueue_rear(struct queue *q, int data){
	struct node *nnode=(struct node*)malloc(sizeof(struct node));
	nnode->data=data;
	if(q->front==NULL){
		q->rear=nnode;
		q->front=nnode;
		nnode->next=NULL;
		nnode->prev=NULL;
	}
	else{
		nnode->next=NULL;
		nnode->prev=q->rear;
		q->rear->next=nnode;
		q->rear=nnode;
	}
}
int dequeue_front(struct queue *q){
	struct node* temp=q->front;
	int res=temp->data;
	q->front=q->front->next;
	q->front->prev=NULL;
	free(temp);
	return res;
}
int dequeue_rear(struct queue *q){
	struct node* temp=q->rear;
	int res=temp->data;
	q->rear=q->rear->prev;
	q->rear->next=NULL;
	free(temp);
	return res;
}
void display(struct queue *q){
	struct node *temp=q->front;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void display_rev(struct queue *q){
	struct node *temp=q->rear;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
int main() {
	struct queue q;
	enqueue_rear(&q,4);
	enqueue_rear(&q,5);
	enqueue_rear(&q,6);
	enqueue_rear(&q,7);
	enqueue_rear(&q,8);
	enqueue_rear(&q,9);
	display(&q);
	display_rev(&q);
	printf("%d\n",dequeue_rear(&q));
	display(&q);
	printf("%d\n",dequeue_front(&q));
	display(&q);
	display_rev(&q);
}

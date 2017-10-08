#include<stdio.h>
struct queue{
	int arr[5];
	int front;
	int rear;
};
void enqueue(struct queue *q, int data){
	q->arr[++q->rear]=data;
}
int dequeue(struct queue *q){
	return q->arr[q->front++];
}
void display(struct queue *q){
	int i;
	for(i=q->front;i<=q->rear;i++){
		printf("%d\t",q->arr[i]);
	}
	printf("\n");
}
int main(){
	struct queue q;
	q.front=0;
	q.rear=-1;
	enqueue(&q,4);
	enqueue(&q,6);
	enqueue(&q,8);
	enqueue(&q,10);
	int x=dequeue(&q);
	display(&q);
	printf("%d",x);
}

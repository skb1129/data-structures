#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
  int data;
  int priority;
  int reached;
  struct node *left,*right;
};

struct node *bst(struct node *root,int d,int p,int *m){
  struct node *n=(struct node *)malloc(sizeof(struct node));
  if(root==NULL){
    n->left=NULL;
    n->right=NULL;
    n->priority=p;
    n->data=d;
    return n;
  }
  if(root->data>d){
    if(*m<abs(p-1))
      *m=abs(p-1);
    root->left=bst(root->left,d,p-1,m);
  }
  else if(root->data<d){
    if(*m<abs(p+1))
      *m=p+1;
    root->right=bst(root->right,d,p+1,m);
  }
return root;
}

void inorder(struct node *n){
  if(n==NULL)
    return;
  inorder(n->left);
  printf("%d %d\n",n->data,n->priority);
  inorder(n->right);
}

int maxHeight(struct node *root){
  int l=0,r=0,h;
  if(root==NULL)
    return 0;
  l=maxHeight(root->left);
  r=maxHeight(root->right);
  h=l>r?l:r;
  return ++h;
}

int diameter(struct node *temp){
  int hl,hr;
  if(temp==NULL)
    return 1;
  hl=diameter(temp->left)+1;
  hr=diameter(temp->right)+1;
  if(hr>hl)
    return hr;
  else
    return hl;
}

void topview(int max,int arr[],struct node *temp){
  int i=0;
  if(temp==NULL)
    return;
  if(arr[max+temp->priority]==0){
    arr[max+temp->priority]=temp->data;
    printf("%d ",temp->data);
  }
  topview(max,arr,temp->left);
  topview(max,arr,temp->right);
}

void paths(struct node *temp,int arr[],int l){
  int i,flag=0;
  if(temp->left==NULL&&temp->right==NULL){
    for(i=0;i<l;i++)
      printf("%d ",arr[i]);
    printf("%d\n",temp->data);
    return;
  }
  if(temp->left!=NULL){
    arr[l++]=temp->data;
    paths(temp->left,arr,l);
    flag=1;
  }
  if(temp->right!=NULL){
      arr[l]=temp->data;
      if(flag==0)
        l++;
      paths(temp->right,arr,l);
  }
}

int main(){
  int i,max=0;
  int arr[100]={0};
  struct node *root=NULL;
  int n,temp,hright,hleft;
  printf("enter elements : ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter %d : ",i+1);
    scanf("%d",&temp);
    root=bst(root,temp,0,&max);
  }
  int h=maxHeight(root);
  printf("Max height is %d\n",h);
  hleft=diameter(root->left);
  hright=diameter(root->right);
  printf("diameter : %d\n",hleft+hright-1);
  topview(max,arr,root);
  inorder(root);
  paths(root,arr,0);
  return 0;
}

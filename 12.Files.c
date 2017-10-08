#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char data[100];
    struct node *left;
    struct node *right;
    int count;
};
struct node * insert(struct node *root,char data[100])
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->left=nn->right=NULL,nn->count=0;
    strcpy(nn->data,data);
    if(root==NULL)
        return nn;
    if(strcmp(root->data,data)==0)
        root->count+=1;
     if(strcmp(root->data,data)>0)
        root->left=insert(root->left,data);
    else if(strcmp(root->data,data)<0)
        root->right=insert(root->right,data);
   // else root->count++;
    return root;
}
int max=0;
char d[100];
void  inorder(struct node *root)
{
    if(root==NULL)
        return ;
    if(max<root->count)
    {

        max=root->count;
        strcpy(d,root->data);
    }
  //   printf("%s",root->data);
    inorder(root->left);
    inorder(root->right);
}
void main()
{
    struct node *root=NULL;
    FILE *fptr;
    char str[100];
    fptr=fopen("hello.txt","r");
    if(fptr==NULL)
        printf("File is empty");

    while(fscanf(fptr,"%s",&str)!=EOF)
    {
        root=insert(root,str);
    	//printf("%s ",root->data);
    }
    inorder(root);
    printf("%s",d);
    fclose(fptr);
}

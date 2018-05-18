#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node *newnode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node,int n)
{
if(node==NULL)
   return newnode(n);
if(node->data < n)
    node->right=insert(node->right,n);
else if(node->data > n)
    node->left=insert(node->left,n);
return node;
}


int height(struct node* root)
{
 if(root==NULL)
 {
   return 0;

 }
 else{
  int a=height(root->right) ;
  int b=height(root->left);

if(a>b)
 return a+1;
 else
  return b+1;
 }
}


void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}

int main()
{
  struct node* root=NULL;
 root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root,65);
    insert(root,45);
  printLevelOrder(root);

}

//EXPERIMENT NO 12
//Write a program to construct an AVL tree for the given set of keys.
// Also write function for deleting a key from the given AVL tree

#include<stdio.h>
#include<conio.h>
struct node
{
   int data;
   struct node *left;
   struct node *right;
   int ht;
};
struct node *root = NULL;
struct node *create(int);
struct node *insert(struct node*, int);
struct node *delete(struct node*, int);
struct node *search(struct node*, int);
struct node *rotate_left(struct node*);
struct node *rotate_right(struct node*);
int balance_factor(struct node*);
int height(struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void main()
{
   int ch,data,i,n;
   struct node* result = NULL;
   clrscr();
   while (ch!=7)
   {
      printf("\n---------------------------MENU-----------------------------");
  	printf("\n1.Insert \t2.Delete \t3.Search \t4.Inorder");
  	printf("\n5.Preorder \t6.Postorder \t7.Exit");
      printf("\n------------------------------------------------------------");
  	printf("\nEnter your choice:");
  	scanf("%d",&ch);
  	switch(ch)
  	{
        	 case 1:printf("Enter how many elements you want to insert:");
                    	scanf("%d",&n);
                    	for(i=0;i<n;i++)
                    	{
                    	   printf("Enter value:");
                    	   scanf("%d",&data);
                    	   root=insert(root,data);
                    	}
                    	break;
        	 case 2:printf("Enter data:");
                    	scanf("%d",&data);
                    	root=delete(root,data);
                    	printf("Key deleted..");
                    	break;
        	 case 3:printf("Enter data:");
                    	scanf("%d",&data);
                    	result=search(root,data);
                    	if(result==NULL)
                    		printf("Node not found!");
                    	else
                    		printf("Node found");
                    	break;
        	 case 4:printf("Inorder traversal:");
                    	inorder(root);
                    	break;
        	 case 5:printf("Preorder tracersal:");
                    	preorder(root);
                    	break;
        	 case 6:printf("Postorder traversal:");
                    	postorder(root);
                    	break;
        	 case 7:exit(0);
        	 default:printf("Invalid Choice..");
  	}
   }
   getch();
}
struct node *create(int data)
{
   struct node *new_node=(struct node *)malloc(sizeof(struct node));
   if (new_node==NULL)
   {
  	printf("Memory can't be allocated..");
        	 return NULL;
   }
   new_node->data=data;
   new_node->left=NULL;
   new_node->right=NULL;
   return new_node;
}
struct node *rotate_left(struct node *root)
{
   struct node *right_child=root->right;
   root->right=right_child->left;
   right_child->left=root;
   root->ht=height(root);
   right_child->ht=height(right_child);
   return right_child;
}
struct node *rotate_right(struct node *root)
{
   struct node *left_child=root->left;
   root->left=left_child->right;
   left_child->right=root;
   root->ht=height(root);
   left_child->ht=height(left_child);
   return left_child;
}
int balance_factor(struct node *root)
{
   int lh,rh;
   if(root==NULL)
   	return 0;
   if(root->left==NULL)
   	lh=0;
   else
   	lh=1+root->left->ht;
   if(root->right==NULL)
   	rh=0;
   else
   	rh=1+root->right->ht;
   return lh-rh;
}
int height(struct node *root)
{
   int lh,rh;
   if(root==NULL)
  	return 0;
   if(root->left==NULL)
  	lh=0;
   else
  	lh=1+root->left->ht;
   if(root->right==NULL)
  	rh=0;
   else
  	rh=1+root->right->ht;
   if(lh>rh)
  	return (lh);
   return (rh);
}
struct node *insert(struct node *root,int data)
{
   if(root==NULL)
   {
  	struct node *new_node=create(data);
  	if(new_node==NULL)
        	  return NULL;
  	root=new_node;
   }
   else if(data>root->data)
   {
       root->right=insert(root->right,data);
   	if(balance_factor(root)==-2)
   	{
        	  if(data>root->right->data)
                    	root=rotate_left(root);
        	  else
        	  {
        	     root->right=rotate_right(root->right);
        	     root=rotate_left(root);
        	  }
   	}
   }
   else
   {
   	root->left=insert(root->left, data);
       if(balance_factor(root)==2)
   	{
        	  if(data<root->left->data)
        	     root=rotate_right(root);
        	  else
        	  {
        	     root->left=rotate_left(root->left);
        	     root=rotate_right(root);
        	  }
   	}
   }
   root->ht=height(root);
   return root;
}
struct node *delete(struct node *root,int x)
{
   struct node *temp=NULL;
   if(root==NULL)
   	return NULL;
   if(x>root->data)
   {
  	root->right=delete(root->right,x);
  	if(balance_factor(root)==2)
  	{
        	 if(balance_factor(root->left)>=0)
        	      root=rotate_right(root);
        	 else
        	 {
        	     root->left=rotate_left(root->left);
        	     root=rotate_right(root);
        	 }
  	}
   }
   else if(x<root->data)
   {
   	root->left=delete(root->left,x);
   	if(balance_factor(root)==-2)
   	{
        	  if(balance_factor(root->right)<=0)
        	      root=rotate_left(root);
        	  else
        	  {
        	      root->right=rotate_right(root->right);
        	      root=rotate_left(root);
        	  }
   	}
   }
   else
   {
  	if(root->right!=NULL)
      {
        	  temp=root->right;
        	  while(temp->left!=NULL)
        	     temp=temp->left;
        	  root->data=temp->data;
        	  root->right=delete(root->right,temp->data);
        	  if(balance_factor(root)==2)
        	  {
        	     if(balance_factor(root->left)>=0)
                    	root = rotate_right(root);
        	     else
        	     {
                    	root->left=rotate_left(root->left);
                    	root=rotate_right(root);
        	     }
        	  }
  	}
  	else
        	 return (root->left);
   }
   root->ht=height(root);
   return (root);
}
struct node *search(struct node *root,int key)
{
   if(root==NULL)
   	return NULL;
   if(root->data==key)
   	return root;
   if(key>root->data)
   	search(root->right,key);
   else
   	search(root->left,key);
}
void inorder(struct node *root)
{
   if(root==NULL)
  	return;
   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);
}
void preorder(struct node *root)
{
   if(root==NULL)
  	return;
   printf("%d ",root->data);
   preorder(root->left);
   preorder(root->right);
}
void postorder(struct node *root)
{
   if(root==NULL)
  	return;
   postorder(root->left);
   postorder(root->right);
   printf("%d ",root->data);
}


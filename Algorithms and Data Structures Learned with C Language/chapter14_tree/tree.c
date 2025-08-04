#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* new_node(int x)
{
   Node* p;
   p=(Node*)malloc(sizeof(Node));
   p->data = x;
   p->left = NULL;
   p->right=NULL;
   return p;
}

Node* insert_tree(int x, Node* root){
    if(root==NULL) return new_node(x);
    if(x < root->data) root->left = insert_tree(x, root->left);
    else root->right = insert_tree(x, root->right);
    return root;
}

Node* search_tree(int x, Node* root){
	if(root==NULL) return NULL;
    if(x==root->data) return root;
    if(x < root->data) return search_tree(x, root->left);
    else return search_tree(x, root->right);	
}

void traverse_pre_order(Node* root)
{
    if(root ==NULL)return;
    printf("%d\t",root->data);
    traverse_pre_order(root->left);
    traverse_pre_order(root->right);
}

void traverse_in_order(Node* root)
{
    if(root ==NULL)return;
    traverse_in_order(root->left);
    printf("%d\t",root->data);
    traverse_in_order(root->right);
}

void traverse_post_order(Node* root)
{
    if(root ==NULL)return;
    traverse_post_order(root->left);
    traverse_post_order(root->right);
    printf("%d\t",root->data);
}

void free_tree(Node* root)
{
    if(root ==NULL)return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void enqueue(Node*);
Node* dequeue(void);

void traverse_level_order(Node* root)
{
    int x;
    Node* p;
    enqueue(root);
    while(1){
        p=dequeue();
        if(p==NULL)return;
        printf("%d\t",p->data);
        if(p->left != NULL) enqueue(p->left);
        if(p->right != NULL) enqueue(p->right);
    }
}
#include<stdio.h>
#include<stdlib.h>
#include"dll_func.h"

struct Node* createnode(int data){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->prev=NULL;
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}


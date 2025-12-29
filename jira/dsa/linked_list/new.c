#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}
void insertbegin(struct Node** headref,struct Node** tailref,int data){
	struct Node* newNode=createNode(data);
	newNode->next=*headref;
	*headref=newNode;
	if(*tailref==NULL){
		*tailref=newNode;
	}
}
void insertend(struct Node** headref,struct Node** tailref,int data){
        struct Node* newNode=createNode(data);
        if(*headref==NULL){
                *headref=*tailref=newNode;
        }
	else{
		(*tailref)->next=newNode;
		*tailref=newNode;
	}
}
void freelist(struct Node* head){
	struct Node* temp;
	while(head!=NULL){
		temp=head;
		head=head->next;
		free(temp);
	}
}
void printlist(struct Node* head){
	struct Node* temp;
	while(head!=NULL){
		temp=head;
		printf("%d->",temp->data);
		head=head->next;
	}
	printf("NULL\n");
}
int main(){
	struct Node* head=NULL;
	struct Node* tail=NULL;

	insertbegin(&head,&tail,10);
	insertend(&head,&tail,20);
	insertend(&head,&tail,30);
	printlist(head);
	insertbegin(&head,&tail,5);
        printlist(head);
        freelist(head);
	return 0;
}

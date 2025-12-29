#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}node;

node* createnode(int data){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void deletenode(node** headref,node** tailref,int key){
	node* temp=*headref;
	node* prev=NULL;

	while(temp!=NULL && temp->data!=key){
		prev=temp;
		temp=temp->next;
	}

	if(prev==NULL){
		*headref=temp->next;
		free(temp);
	}
	else if(*tailref==temp){
		*tailref=prev;
		free(temp);
	}
	else{
		prev->next=temp->next;
		free(temp);
	}
}

void displaylist(node* head){
	node* temp =NULL;
	temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

void freelist(node* head){
	node* temp=NULL;
	while(head!=NULL){
		temp=head;
		head=head->next;
		free(temp);
	}
}

int main(){
	node* head=NULL;
	node* tail=NULL;
	node* node=NULL;
	int data,n;
	printf("Enter no.of nodes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("enter the data in node%d:",i+1);
		scanf("%d",&data);
		node=createnode(data);
		if(head==NULL){
			head=tail=node;
		}
		else{
			tail->next=node;
			tail=node;
		}
	}
	displaylist(head);
	printf("enter the data you want to delete:");
	scanf("%d",&data);
	deletenode(&head,&tail,data);
	displaylist(head);
	return 0;
}
	




















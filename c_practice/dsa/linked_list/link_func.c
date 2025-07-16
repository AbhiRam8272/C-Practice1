#include<stdio.h>
#include<stdlib.h>
#include "link_func.h"
/*struct Node {
	int data;
	struct Node* next;
};*/
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
        while(temp!=NULL){
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

void deletenode(struct Node** headref,struct Node** tailref,int key){
        struct Node* temp=*headref;
        struct Node* prev=NULL;

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

struct Node* midnode(struct Node** headref){
        struct Node* slow=NULL;
        struct Node* fast=NULL;

        fast=slow=*headref;
        if(*headref==NULL){
                printf("List is Empty\n");
                return NULL;
        }
	else if ((*headref)->next != NULL && (*headref)->next->next == NULL) {
		printf("The list contains 2 elements only.Can't have a middle node.\n");
		return NULL;
	}

        while(fast!=NULL && (fast->next)!=NULL){
                slow=slow->next;
                fast=fast->next->next;
        }
	
	//printf("The middle node the list is %d\n",slow->data);
        
        return slow;
}

int delmidnode(struct Node** headref,struct Node** tailref){
        struct Node* delnode=midnode(headref);
	if(delnode==NULL){
		printf("The list is either empty or only contains 2 nodes(middle can't deleted)\n");
		return 0;
	}
        deletenode(headref,tailref,delnode->data);
	return 1;
}


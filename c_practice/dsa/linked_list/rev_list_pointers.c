#include<stdio.h>
#include<stdlib.h>
#include"link_func.h"

void revlist(struct Node** headref, struct Node** tailref) {
    struct Node* prev = NULL;
    struct Node* curr = *headref;
    struct Node* next = NULL;

    *tailref = *headref; // Tail becomes the old head

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    *headref = prev; // New head
}

int main(){
	struct Node* head=NULL;
	struct Node* tail=NULL;
	int n,data;
	printf("Enter no.of nodes:");
        scanf("%d",&n);
	struct Node* node;
        for(int i=0;i<n;i++){
                printf("enter the data in node%d:",i+1);
                scanf("%d",&data);
                node=createNode(data);
                if(head==NULL){
                        head=tail=node;
                }
                else{
                        tail->next=node;
                        tail=node;
                }
        }
        printlist(head);
	revlist(&head,&tail);
	printlist(head);
	return 0;
}

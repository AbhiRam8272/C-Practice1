#include<stdio.h>
#include<stdlib.h>
#include"link_func.h"

void revlist(struct Node** headref,struct Node** tailref){
	struct Node* start= *headref;
	struct Node* end= *tailref;
	//struct Node* temp= *headref;
	struct Node* prev= NULL;
	struct Node* temp= createNode(0);

	while(start!=NULL){
		prev=*headref;
		temp->data=start->data;
		start->data=end->data;
		end->data=temp->data;
		start=start->next;
		while(prev!=NULL && prev->next!=end){
			prev=prev->next;
		}
		end=prev;
		if(start==end){
			break;
		}
		else if(start==end->next){
			break;
		}
	}
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

#include<stdio.h>
#include<stdlib.h>
#include"dll_func.h"

int main(){
	struct Node* head=NULL;
	struct Node* tail=NULL;
        struct Node* temp=NULL;
        struct Node* node=NULL;
	int n,data;
	printf("Enter no.of nodes:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("Enter the data to node%d:",i);
		scanf("%d",&data);
		node=createnode(data);
		if(head==NULL){
			head=tail=node;
		}
		else{
			tail->next=node;
			tail=node;
			tail->prev=temp;
		}
		temp=node;
	}
	temp=head;
	 while(temp!=NULL){
                printf("(%p,%d,%p)->",(void*)temp->prev,temp->data,(void*)temp->next);
                temp=temp->next;
        }
        printf("NULL\n");

	while(head!=NULL){
                temp=head;
                head=head->next;
                free(temp);
        }

	return 0;
}











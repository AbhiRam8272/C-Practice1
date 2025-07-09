#include<stdio.h>
#include<stdlib.h>
#include"link_func.h"

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
	dispmidnode(&head);
	return 0;
}


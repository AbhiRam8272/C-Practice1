#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}



setenv bootcmd 'fatload mmc 1:1 0x21000000 zImage; fatload mmc 1:1 0x22000000 a5d2x-rugged_board.dtb; bootz 0x21000000 - 0x22000000'

int main() {
    int n;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    struct Node* node1=createNode(10);
    struct Node* node2=createNode(20);
    node1->next=node2;
    
    struct Node* temp = node1;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    return 0;
}


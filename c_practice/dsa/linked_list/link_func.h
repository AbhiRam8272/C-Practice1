#ifndef FUNC_H
#define FUNC_H
struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data);
void insertbegin(struct Node** headref,struct Node** tailref,int data);
void insertend(struct Node** headref,struct Node** tailref,int data);
void freelist(struct Node* head);
void printlist(struct Node* head);
void deletenode(struct Node** headref,struct Node** tailref,int key);
void dispmidnode(struct Node** headref);




#endif


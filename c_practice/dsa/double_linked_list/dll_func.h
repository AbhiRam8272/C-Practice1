#ifndef DLL_FUNC_H
#define DLL_FUNC_H
struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
};

struct Node* createnode(int data);





#endif

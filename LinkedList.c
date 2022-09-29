#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    
}Node;


Node *head;
Node *tail;
int size = 100;
Node *node[100];


Node *createList(){
    Node *tmpNode = NULL;
    tmpNode = malloc(sizeof(Node));
    tmpNode ->next = NULL;
    head = NULL;
    tail = NULL;
    tmpNode->data = 0;
    return tmpNode;
}
Node *createNode(){
    Node *tmpNode = NULL;
    tmpNode = malloc(sizeof(Node));
    tmpNode->next = NULL;
    return tmpNode;
}


Node *insert(Node *tmpNode, int x){
    if(head == NULL){
        head = createNode();
        tail = createNode();
        head ->data = x;
        return head;
    }else{
        tail ->next = createNode();
        
        tail = createNode();
        tail ->data = x;
        return tail;
    }
}
int addList(int x, Node *n){
    for(int i = x; i < x+1; i++){
        node[i] = n;
    }
    
}

void printList(int x){
    Node *tmp;
    for(int i = 0; i <x; i++){
        tmp = node[i];
        printf("| %d", tmp->data);
    }
}

int main(){
    
   int aCount = 0;
    Node *newList = createList();
    Node *n1 = insert(newList, 5);
    
    addList(aCount, n1);
    aCount ++;
    Node *n2 = insert(n1, 10);
    addList(aCount, n2);
    aCount ++;
    Node *n3 = insert(n2, 12);
     
    addList(aCount, n3);
    aCount ++;
    Node *n4 = insert(n3, 100);
    addList(aCount, n4);
    aCount ++;
    Node *n5 = insert(n4, 60);
    addList(aCount, n5);
    aCount ++;
    Node *n6 = insert(n5, 1);
    addList(aCount, n6);
    aCount ++;
    Node *n7 = insert(n6, 80);
    addList(aCount, n7);
    aCount ++;
    Node *n8 = insert(n7, 7);
    addList(aCount, n8);
    aCount ++;
    printList(aCount);


}
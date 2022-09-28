#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
   
}Node;
Node *createTree(int x){
    Node *tmpNode;
    tmpNode = malloc(sizeof(Node));
    tmpNode ->data = x;
    tmpNode ->left = NULL;
    tmpNode ->right = NULL;
    return tmpNode;
}

Node *createNode(int x){
    Node *tmpNode;
    tmpNode = malloc(sizeof(Node));
    tmpNode ->data = x;
    tmpNode->left= NULL;
    tmpNode ->right = NULL;
    return tmpNode;
}
Node *insert(Node *tmpNode, int x){
    if(x > tmpNode->data){
        if(tmpNode->right ==NULL){
           tmpNode = tmpNode ->right = createNode(x);
           return tmpNode;
        }else if(tmpNode->right != NULL){
            insert(tmpNode->right, x);

        }
    }if(x < tmpNode->data){
        if(tmpNode->left == NULL){
         tmpNode = tmpNode ->left = createNode(x);
         return tmpNode;
        }else if(tmpNode->left != NULL){
            insert(tmpNode->left, x);
        }
    }
    return tmpNode;
}
Node printTree(Node *tmpNode){
    if(tmpNode==NULL){
        return;
    }
    printTree(tmpNode->left);
    printf("| %d ", tmpNode->data); 
    printTree(tmpNode->right);
}

int factorial(int x){
    if(x <=1){
        return x;
    }else{
        return factorial(x-1) * x; 
    }
}

int numOfBST(int key){
    int catalanNumber = factorial(2*key)/(factorial(key+1)*factorial(key));
    return catalanNumber;
}
int main(){
    printf("The binary search tree for this 5 node tree is: \n");
    Node *root = createTree(5);
    Node *n1 = insert(root, 2);
    Node *n2 = insert(n1, 4);
    Node *n3 = insert(n2, 10);
    Node *n4 = insert(n3, 1);
    printTree(root);
    printf("\n");
    
    int catalN = numOfBST(5);
    printf("Number of binary search trees with the key of 5 is %d", catalN);


   
    


}

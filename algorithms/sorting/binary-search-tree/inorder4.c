#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

struct Node {
       int val;
       struct Node *left;
       struct Node *right;
};

typedef struct Node node;

void insert(node **bt, node *Node) {

     if( *bt == NULL) {

         *bt = Node;
     
     } else {

            if( Node->val < (*bt)->val )

                insert(&((*bt)->left), Node);

            else

                insert(&((*bt)->right), Node);
     }
}

void printout(struct Node *node) {

     if(node->left) printout(node->left); 

     printf("%d ", node->val);  

     if(node->right) printout(node->right);
}

void postorder(struct Node *node) {

     if(node->left) printout(node->right); 

     printf("%d ", node->val);  

     if(node->right) printout(node->right);
}

int main(){

    int i, n, elem;    

    node *curr; 
 
    freopen(FIN, "r", stdin);

    freopen(FOUT, "w", stdout);

    node *bt = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; ++i) {

         scanf("%d", &elem); 

         curr = malloc( sizeof(struct Node) );

         curr->val = elem;

         curr->left = NULL;

         curr->right = NULL;

         insert(&bt, curr );
    }

    printout( bt ); 

    return(0);
}
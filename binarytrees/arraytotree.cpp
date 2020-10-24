#include <iostream>

using namespace std;

struct node {
    int info;
    node* left,* right;

    node() : left(NULL), right(NULL) {}
    node(int _info) : info(_info), left(NULL), right(NULL) {}
};

void insertInTree(int info, node** tree) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->info)
            insertInTree(info, &(*tree)->left);
        else
            insertInTree(info, &(*tree)->right);
    }
}

void arrayToTree(int a[], node** tree, int n){  
    for(int i=0; i<n; i++) insertInTree(a[i], tree);
    return;
}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->info << endl;
        inOrder(tree->right);
    }
}

int counter = 0;


int treeHeight(node* tree) {
    if(tree) {
        int left = treeHeight(tree->left);
        int right = treeHeight(tree->right);

        return (left < right) ? right + 1 : left + 1;
    }
}

void printLevel(node* tree, int level) {
    if (tree) {
        if (level == 1)  
            cout << tree->info << "\t";  
        else if (level > 1) {  
            printLevel(tree->left, level - 1);  
            printLevel(tree->right, level - 1);  
        }  
    }
}

void levelOrder(node* tree) {
    int height = treeHeight(tree);

    for(int i = 0; i < height; i++) {
        printLevel(tree, i);
        cout << endl;
    }
}


int main(void){
    int a[] = {10, 7, 12, 5, 8, 11, 16};
    node *tree = NULL;
    int n = sizeof(a)/sizeof(a[0]); 
    arrayToTree(a, &tree, n);
    cout<<treeHeight(tree)<<endl;
    inOrder(tree);
    cout<<endl;
    levelOrder(tree);
}


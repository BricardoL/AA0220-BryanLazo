#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct node {
    int info;
    node* left,* right;

    node() : left(NULL), right(NULL) {}
    node(int _info) : info(_info), left(NULL), right(NULL) {}
};

void inOrder(node* tree);
void preOrder(node* tree);
void postOrder(node* tree);
void removeData(int e, node** tree);
int inOrderSuccesor(node* rightTree);
void insertInTree(int info, node** tree);
int summatory(node* tree);
bool areTheyEquals(node* mangle, node* conan);
bool searchElement(node* tree, int k);
int maximun(node*);
int minimun(node*);
int deepest(node* tree, int k);
void deleteLeaf(node**);

int main(void) {
    node* tree = NULL;
    node* conan = NULL;

    insertInTree(0, &tree);
    insertInTree(9, &tree);
    insertInTree(5, &tree);
    insertInTree(3, &tree);
    insertInTree(6, &tree);
    insertInTree(90, &tree);
    insertInTree(0, &conan);
    insertInTree(9, &conan);
    insertInTree(933, &conan);
    insertInTree(31, &conan);
    insertInTree(6, &conan);
    insertInTree(12, &conan);


    cout << "******************** InOrder traversal ********************" << endl;
    inOrder(tree);
    cout << endl << endl;

    cout << "******************** PreOrder traversal ********************" << endl;
    preOrder(tree);
    cout << endl << endl;

    cout << "******************** PostOrder traversal ********************" << endl;
    postOrder(tree);
    cout << endl << endl;

    cout<<"Funcion nueva   "<<endl;
    cout<<summatory(tree);
    cout<<endl;

    cout<<"Second funct new  \n";
    if (areTheyEquals(tree, conan))
    {
        cout<<"Son iguales!!\n";
    }
    else cout<<"No son iguales F!\n";

    cout<<"Searching...\n";
    if (searchElement(conan, 31)) cout<<"Si esta e elemento1\n";
    else cout<<"No esta el elem:(\n";

    cout<<"Maximum....\n";
    cout<<maximun(conan)<<endl;
    cout<<"Minimun....\n";
    cout<<minimun(conan)<<endl;
    
    

    cout << "******************** InOrder traversal after remove ********************" << endl;
    removeData(3, &tree);
    inOrder(tree);

    int arr[] = {55,43,2,0,75,43,33,50,60};
    int arrSize = sizeof(arr)/sizeof(arr[0]); 
    node *manzano = NULL;
    for(int i = 0; i<arrSize; i++){
        insertInTree(arr[i], &manzano);
    }
    cout<<"\n\nDeepest of...\n";
    cout<<deepest(manzano, 2);
    cout<<"\nIn order...\n";
    inOrder(manzano);
    deleteLeaf(&manzano);
   /* cout<<"In Orden luego de borrar hojaas...\n";
    inOrder(manzano);*/

    return 0;
}

/*
    Works for insertion in BST
    Receives T info to insert and double pointer node of root
    When tree is empty a node is created, otherwise searchs for 
    a correct insertion place depending of alphabetical order
*/
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

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->info << endl;
        inOrder(tree->right);
    }
}

void postOrder(node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->info << endl;
    }
}

void preOrder(node* tree) {
    if(tree) {
        cout << tree->info << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}


int summatory(node* tree){
    if (tree)
    {   
        int center = tree->info;
        int left = summatory(tree->left);
        int right = summatory(tree->right);
        return center + left + right;
}
}

bool areTheyEquals(node* mangle, node* conan)
{
     if (mangle == conan)  return true;

     // Gone past leaf on one side check
     if ((mangle == NULL) || (conan == NULL))  return false;

     // Do data checks and recursion of tree
     return ((mangle->info == conan->info) && areTheyEquals(mangle->left,  conan->left )
                                    && areTheyEquals(mangle->right, conan->right));
}

/*
    InOrder succesor is the element most at to the left of right
    subtree, if left subtree of right subtree is empty then
    succesor is rightsubtree.info
*/
int inOrderSuccesor(node* rightTree) {
    node* aux = rightTree;

    while(aux->left != NULL) {
        aux = aux->left;
    }

    return aux->info;
}

void removeData(int e, node** tree) {
    if(*tree) {
        if(e < (*tree)->info) {
            removeData(e, &(*tree)->left);
        }
        else if (e > (*tree)->info) {
            removeData(e, &(*tree)->right);
        }
        else {
            // If node to be deleted is leaf
            if(!(*tree)->left && !(*tree)->right) {
                node* auxDelete = *tree;
                *tree = NULL;
                delete auxDelete;
            }
            // If tree only has right side
            else if(!(*tree)->left && (*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->right;
                delete root;
            }
            // If tree only has left side
            else if((*tree)->left && !(*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->left;
                delete root;
            }
            // If tree is root
            else {
                // Find inorder succesor
                (*tree)->info = inOrderSuccesor((*tree)->right);
                // Delete inorder succesor
                removeData((*tree)->info, &(*tree)->right);
            }
        }
    }
}

bool searchElement(node* tree, int k)
{
    if(tree){
    if(tree->info == k) return true;
    if(k<tree->info) searchElement(tree->left, k);
    else searchElement(tree->right, k);
    } else return false;
}

int counter = -1;
int deepest(node* tree, int k)
{
    if(tree){
    counter++;
    if(tree->info == k) return counter;
    if(k<tree->info) deepest(tree->left, k);
    else deepest(tree->right, k);
    } else return false;
}
/*
void deleteLeaf(node **tree)
{
    if (!tree)
    {
        delete tree;
    } else {
        deleteLeaf(&(*tree)->left);
        deleteLeaf(&(*tree)->right);
    }
    
}
*/
int minimun(node* tree)
{
    while(tree->left)
    {
        tree = tree->left;
    }
    return tree->info;
}

int maximun(node* tree)
{
    while(tree->right)
    {
        tree = tree->right;
    }
    return tree->info;
}

/*void deletingData(node **tree, int d){
    if ((*tree)->info == d){
        if(!(*tree)->left && !(*tree)->right){
            delete *tree;
        }
        else if(!(*tree)->left || !(*tree)->right){
            node **copy = tree;
            node *child = (!(*tree)->left)?(*tree)->right : (*tree)->left;
            *tree = child;
            delete copy;
        }
        else{
            int m = minimun((*tree)->right);
            (*tree)->info = m;
        }
    }
}*/
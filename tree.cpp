#include <iostream>

using namespace std;

struct Tree{
    int data;
    Tree *left;
    Tree *right;
};

Tree *leaf, *leaf2, *leaf3, *leaf4, *leaf5, *leaf6, *nodeBaru, *root = NULL;



void preOrder(Tree *current){
    if(current!=NULL){
        cout << " " << current->data;
        preOrder(current->left);
        preOrder(current->right);
    }
}

void inOrder(Tree *current){
    if(current!=NULL){
        inOrder(current->left);
        cout << " " << current->data;
        inOrder(current->right);
    }
}

void postOrder(Tree *current){
    if(current!=NULL){
        postOrder(current->left);
        postOrder(current->right);
        cout << " " << current->data;
    }
}

void addLeft(Tree *current, int data){
    if(current->left==NULL){
    nodeBaru = new Tree();
    nodeBaru->data = data;
    nodeBaru->left = NULL;
    nodeBaru->right= NULL;
    current->left = nodeBaru;
    }else{
    nodeBaru = new Tree();
    nodeBaru->data = data;
    nodeBaru->left = NULL;
    nodeBaru->right= NULL;
    current->right = nodeBaru;
    }
}

void addRight(Tree *current, int data){
    if(current->right==NULL){
    nodeBaru = new Tree();
    nodeBaru->data = data;
    nodeBaru->left = NULL;
    nodeBaru->right= NULL;
    current->right = nodeBaru;
    }else{
    nodeBaru = new Tree();
    nodeBaru->data = data;
    nodeBaru->left = NULL;
    nodeBaru->right= NULL;
    current->left = nodeBaru;
    }
}

int main()
{
    leaf = new Tree();
    leaf->data = 5;
    leaf->left = NULL;
    leaf->right= NULL;

    leaf2 = new Tree();
    leaf2->data = 3;
    leaf2->left = NULL;
    leaf2->right= NULL;

    leaf3 = new Tree();
    leaf3->data = 10;
    leaf3->left = NULL;
    leaf3->right= NULL;

    leaf4 = new Tree();
    leaf4->data =11;
    leaf4->left = NULL;
    leaf4->right= NULL;

    leaf->left = leaf2;
    leaf->right = leaf3;
    leaf3->right = leaf4;

    addLeft(leaf2, 20);
    addLeft(leaf2, 23);

    cout << sizeof(Tree) << "\n";
    cout << "Preorder : ";preOrder(leaf);cout <<"\n";
    cout << "Inorder : ";inOrder(leaf);cout <<"\n";
    cout << "Postorder : ";postOrder(leaf);cout << "\n";
    return 0;
}

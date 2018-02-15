#include<iostream>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;
    int height;
};

int height(Node *N)
{
    if(N==NULL)
        return 0;
    return N->height;
}
Node *newNode(int k)
{
    Node *newN=new Node;

    newN->data=k;
    newN->left=NULL;
    newN->right=NULL;
    newN->height=1;

    return newN;
}
Node *rightroatate(Node *y)
{
    Node *x=y->left;
    Node *T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(y->right))+1;

    return x;
}
Node *leftroatate(Node *y)
{
    Node *x=y->right;
    Node *T2=x->left;

    x->left=y;
    y->right=T2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(y->right))+1;

    return x;
}
int getBalance(Node *n)
{
    if(n==NULL)
        return 0;
    return (height(n->left)-height(n->right));
}
Node *_insert(Node *nN,int key)
{
        if(nN==NULL)
            return newNode(key);

        if(key < nN->data)
        {
            nN->left=_insert(nN->left,key);
        }
        else if(key>nN->data)
        {
            nN->right=_insert(nN->right,key);
        }
        else
          return nN;



        nN->height=1+max(height(nN->right),height(nN->left));

        int balance=getBalance(nN);

        if(balance > 1 && key < nN->left->data)
            return rightroatate(nN);

        if(balance < -1 && key > nN->right->data)
            return leftroatate(nN);

        if(balance > 1 && key > nN->left->data)
        {
            nN->left=leftroatate(nN->left);
            return rightroatate(nN);
        }

        if(balance < -1 && key < nN->right->data)
        {
            nN->right=rightroatate(nN->right);
            return leftroatate(nN);
        }

        return nN;
}
void preOrder(Node *n)
{
    if(n!=NULL)
    {
     cout<<n->data<<" ";
     //cout<<"hello";
     preOrder(n->left);
     preOrder(n->right);
    }

}

int main()
{
  struct Node *root = NULL;

  /* Constructing tree given in the above figure */
  root = _insert(root, 10);
  root = _insert(root, 20);
  //cout<<"hello";
  root = _insert(root, 30);
  //cout<<"hello5";
  root = _insert(root, 40);
  //cout<<"hello";
  root = _insert(root, 50);
  root = _insert(root, 25);


  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);

  return 0;
}

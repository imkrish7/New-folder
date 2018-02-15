#include<iostream>
using namespace std;

struct Trie{
            bool isend;
            Trie child[2];
};

Trie *newNode()
{
    Trie *temp=(Trie*)malloc(sizeof(Trie));

    temp->isend=0;
    temp->child[0]=temp->child[1]=0;
    return temp;
}

bool insert(Trie **root,int *M[Col],int r,int c)
{
    if(*root==NULL)
        root=newNode();
    if(c<Col){
            return insert(&(*root)->child[M[r][c]],r,c+1);

    }
    esle
    {
        if(!*root->isend)
            return(*root)->isend=1;
            else
            return 0;
    }
}

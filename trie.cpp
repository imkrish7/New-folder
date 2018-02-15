#include<iostream>
using namespace std;

struct node{

        node *children[26];

        bool isEndofword;
};

node *getnode()
{
            node *pnode =new node;

            pnode->isEndofword=false;

            for(int i=0;i<26;i++)
            {
                pnode->children[i]=NULL;
            }
return pnode;
}

void insert(node *root,string key)
{
            int n=key.length();
            node *pcrawl=root;

            for(int i=0;i<n;i++)
            {
                int t=key[i]-'a';
                if(!pcrawl->children[t])
                {
                    pcrawl->children[t]=getnode();
                }
            pcrawl=pcrawl->children[t];
            }
        pcrawl->isEndofword=true;
}

bool _search(node *root,string key)
{
            int n=key.length();
            node *pcrawl=root;

            for(int i=0;i<n;i++)
            {
                int t=key[i]-'a';
                if(!pcrawl->children[t])
                {
                    return false;
                }
                pcrawl=pcrawl->children[t];
            }
            return (pcrawl !=NULL && pcrawl->isEndofword);
}

int main()
{

    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct node *root = getnode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    _search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    _search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;

}

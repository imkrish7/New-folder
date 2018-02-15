#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INDEX(c) ((int)c-(int)'a')
#define FREE(p)
    free(p);\
    p=NULL;\

struct trieNode{

    int value;
    struct trieNode *children[26];
};

struct trie{
        struct trieNode *root;
        int _count;
};

struct trieNode *getNode()
{
                struct trieNode *pnode=(struct trieNode *)malloc(sizeof(trieNode));

                for(int i=0;i<26;i++)
                {
                    pnode->value=0;

                    pnode->children[i]=NULL;
                }
return pnode;
}

void initialize(struct trie *pnode)
{
    pnode->root=getNode();
    pnode->_count=0;

}

void _insert(struct trie *pnode,char key[])
{
            int n=strlen(key);
            int level;
            int t;
            struct trieNode *pcrawl;

            pnode->_count++;
            pcrawl=pnode->root;

            for(level=0;level<n;level++)
            {
                t=INDEX(key[level]);

                if(!pcrawl->children[t])
                {
                    pcrawl->children[t]=getNode();
                }
                pcrawl=pcrawl->children[t];
            }
            pcrawl->value=pndoe->_count;

}
int _search(struct trie *pnode,char key[])
{

            int n=strlen(key);

            struct trieNode *pcrawl=pnode->root;

            for(int i=0;i<n;i++)
            {
                int t=INDEX(key[i]);

                if(!pcrawl->children[t])
                {
                    return 0;
                }
                pcrawl=pcrawl->children[t];
            }

            return (0!=pcrawl && pcrawl->value);
}
int isleafNode(struct trieNode *pcrawl)
{
    return (pcrawl->value!=0);
}

int isItFreeNode(struct trieNode *pcrawl)
{
        int i;
        for(i=0;i<26;i++)
        {
            if(pcrawl->children[i])
                return 0;
        }
        return 1;
}

bool deleteNode(trieNode *pnode ,char key[],int level,int len)
{
            if(pnode)
            {

                    if(level=len)
                    {
                        if(pnode->value)
                        {
                            if(isItFreeNode(pnode))
                            {
                                return true;
                            }
                            return false;

                        }

                    }
                    else
                    {
                        int t=INDEX(key[level]);
                        if(deleteNode(pnode,key,level+1,len)
                        {
                            FREE(pnode->children[level]);

                            return (!isleafNode(pnode) && isItFreeNode(pnode));
                        }
                    }
            }
            return false;

}
void deleteKey(struct trie *pnode,char key[])
{
        int n=strlen(key);
        if(n>0)
        {
            deleteNode(pnode->root,key,0,n);
        }
}

int main()
{
     char keys[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    struct trie trie_t;

    initialize(&trie_t);

    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        _insert(&trie_t, keys[i]);
    }

    deleteKey(&trie_t, keys[0]);

    printf("%s %s\n", "she", search(&trie_t, "she") ? "Present in trie" : "Not present in trie");

    return 0;
}

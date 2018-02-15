#include<stdio>
#include<stdlib>
#include<string>
#define INDEX(c) ((int)c-(int)'a')
#define FREE(p)
        free(p);
        p=NULL;
struct trieNode{

    int value;
    struct trieNode *children[26];
};

struct trie{
        struct trieNode *root;
        int count;
}

struct trieNode *getNode()
{
                struct trieNode *pnode=(trieNode *)malloc(sizeof(trieNode));

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
    pnode->count=0;

}

void insert(struct trie *pnode,char key[])
{
            int n=strlen(key);
            int level;
            int t;
            trieNode *pcrawl;

            pnode->count++;
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
            pcrawl->value=pndoe->count;

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

int isItFreeNode(struct trie *pcrawl)
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
    trie_t trie;

    initialize(&trie);

    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&trie, keys[i]);
    }

    deleteKey(&trie, keys[0]);

    printf("%s %s\n", "she", search(&trie, "she") ? "Present in trie" : "Not present in trie");

    return 0;
}

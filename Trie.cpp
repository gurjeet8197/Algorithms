#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
#const int a_size = 26

struct trieNode
{
	trieNode *child[a_size]; //map can also be used
	bool eow;
};

trieNode* getNode()
{
	trieNode *node = new trieNode;
	node->eow = false;

	for(int i=0; i<a_size; i++)
		node->child[i] = NULL;

	return node;

}

void insert(trieNode *root, string key)
{
	trieNode *curr = root;
	for(int i=0; i<key.length*(); i++)
	{
		int j = key[i]-'a';
		curr = curr->child[j];
		if(curr == NULL)
			curr = getNode();

	}

	curr->eow = true;
}

bool search(trieNode *root, string key)
{
	
	trieNode *curr = root;
	for(int i=0; i<key.length(); i++)
		{
			int j = key[i]-'a';
			curr = curr->child[j]
			if(curr==NULL)
				return false;

		}

		return curr->eow;

}

bool remove(trieNode *root, string key)
{
	if(root==NULL)
		return false;

}

int main()
{
	
}
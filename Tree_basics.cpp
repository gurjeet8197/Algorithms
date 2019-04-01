# include <bits/stdc++.h>
using namespace std;

struct node
{
	struct node* left;
	struct node* right;
	int key;
};

struct node* newnode(int key)
{
	struct node* temp = new node();
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* insert(node* node, int key)
{
	if(node==NULL)
		return newnode(key);

	if(key<node->key)
		node->left = insert(node->left, key);
	else if(key>node->key)
		node->right=insert(node->right, key);

	return node;
}

struct node* insert_iterative(node* node, int key)
{
	if(node==NULL)
		return newnode(key);

	struct node* temp = node;
	struct node* prev;

	while(temp!=NULL)
	{
		if(key < temp->key){
			prev = temp;
			temp = temp->left;
		}
		else{
			prev = temp;
			temp = temp->right;

		}
	}

	if(key < prev->key)
		prev->left = newnode(key);
	else 
		prev->right = newnode(key);

	return node;
}

void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

void preorder(struct node* root)
{
	if(root!=NULL)
	{
		cout << root->key << " ";
		inorder(root->left);
		inorder(root->right);
	}
}

void postorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorder(root->right);
		cout << root->key << " ";
	}
}

void levelorder(node* root)
{
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		node* curr = q.front();
		cout << curr->key << " ";
		q.pop();

		if(curr->left!=NULL)
			q.push(curr->left);
		if(curr->left!=NULL)
			q.push(curr->right);
	}

}

int minHeight(struct node* root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return 1+min(minHeight(root->left), minHeight(root->right));
}



int main()
{
    // Let us create binary tree shown in above diagram
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    levelorder(root);
    return 0;
}

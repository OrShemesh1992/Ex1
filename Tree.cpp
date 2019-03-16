#include "Tree.hpp"
#include <iostream>
#include <string.h>
using namespace std;
using namespace ariel;

Tree::Tree()
{
        treeroot=NULL;
}
Tree::Tree(node * tree)
{
        treeroot=tree;
}
Tree::~Tree()
{
        remove();
}
//foun insert
Tree Tree::insert(int key)
{

        if(treeroot!=NULL)
        {
                insert(key, treeroot);
        }else{
                treeroot=new node;
                treeroot->key_value=key;
                treeroot->left=NULL;
                treeroot->right=NULL;
        }
        return treeroot;
}

void Tree::insert(int key, node *leaf)
{
        if(key< leaf->key_value)
        {
                if(leaf->left!=NULL)
                        insert(key, leaf->left);
                else
                {
                        leaf->left=new node;
                        leaf->left->key_value=key;
                        leaf->left->left=NULL; //Sets the left child of the child node to null
                        leaf->left->right=NULL; //Sets the right child of the child node to null
                }
        }
        else if(key>=leaf->key_value)
        {
                if(leaf->right!=NULL)
                        insert(key, leaf->right);
                else
                {
                        leaf->right=new node;
                        leaf->right->key_value=key;
                        leaf->right->left=NULL; //Sets the left child of the child node to null
                        leaf->right->right=NULL; //Sets the right child of the child node to null
                }
        }
}
// foun remove

void Tree::remove()
{
        remove(treeroot);
}

void Tree::remove(node *leaf)
{
        if(leaf!=NULL)
        {
                remove(leaf->left);
                remove(leaf->right);
                delete leaf;
        }
}

// foun size

int Tree::size()
{
  return size(treeroot);
}
int Tree::size(node* node)
{
    if (node == NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}

// foun root
int Tree::root()
{
  return treeroot->key_value;
};
// foun parent
int Tree::parent(int key)
{
  return searchfather(key,treeroot)->key_value;
};
// foun left
int Tree::left(int key)
{
  return search(key)->left->key_value;
};
// foun right
int Tree::right(int key)
{
  return search(key)->right->key_value;
};
// foun help search
node * Tree::search(int Key)
{
    int   ValueInTree = false;
    node *temp;

    temp = treeroot;
    while((temp != NULL) && (temp->key_value != Key))
    {
        if(Key < temp->key_value)
            temp = temp->left;  // Search key comes before this node.
        else
            temp = temp->right; // Search key comes after this node
    }
    if(temp == NULL) return temp;    // Search key not found
    else
        return(temp);    // Found it so return a duplicate
};
// foun help parent
node * Tree::searchfather(int key, node *leaf)
{
        if(leaf!=NULL)
        {
                if((key==leaf->left->key_value)||(key==leaf->right->key_value))
                        return leaf;
                if(key<leaf->key_value)
                        return searchfather(key, leaf->left);
                else
                        return searchfather(key, leaf->right);
        }
        else return NULL;
}
//foun print
void Tree::print(){
		print(treeroot);
}
void Tree::print(node *leaf){
	if(leaf != NULL){
		print(leaf->left);
		cout << leaf->key_value << ",";
		print(leaf->right);
	}
}

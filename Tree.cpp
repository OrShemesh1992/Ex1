#include "Tree.hpp"
#include <iostream>
#include <string.h>
#include <iomanip>
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
void Tree::insert(int x){
		treeroot = Tree::insert(x,treeroot);
	}
node* Tree::insert(int x, node* p){

	if(p == NULL){
		p = new node;
    p->parent=p;
		p->key_value = x;
		p->left = p->right = NULL;
	}
	else if (p->key_value == x){
	throw invalid_argument("This numer is allready in the Tree");

	}
	else if(x < p->key_value){
    p->parent=p;
		p->left = Tree::insert(x, p->left);
	}
	if(x > p->key_value){
    p->parent=p;
		p->right = Tree::insert(x, p->right);
}
		return p;
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
  return search(key)->parent->key_value;
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
node * Tree::search(int Key){
  return search(treeroot,Key);
}
node* Tree::search(node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key_value == key)
    root->parent=root;
       return root;

    // Key is greater than root's key
    if (root->key_value < key)
    root->parent=root;
       return search(root->right, key);

    // Key is smaller than root's key
    root->parent=root;
    return search(root->left, key);
}
void Tree::print(){
		print(treeroot,10);
}
void Tree::print(node* p, int indent) {

 if (p != NULL) {
 if (p->right) {
   Tree::print(p->right, indent + 4);
 }
 if (indent) {
   cout << setw(indent) << ' ';
 }
 if (p->right) cout << " /\n" << setw(indent) << ' ';
 cout << p->key_value << "\n ";
 if (p->left) {
   cout << setw(indent) << ' ' << " \\\n";
   Tree::print(p->left, indent + 4);
 }
}
}
// bool contain(int key) {
//   node * temp =search(key);
//   if (temp==NULL) {returnz/* code */
//   }

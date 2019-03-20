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
        Tree::del(treeroot);
}
void Tree::del(node *leaf)
{
        if(leaf!=NULL)
        {
                Tree::del(leaf->left);
                Tree::del(leaf->right);
                delete leaf;
        }
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

void Tree::remove(int x)
{
  if((contains(x) == false) || (treeroot==NULL)){
  throw::invalid_argument("Is Not GOOD");
}else{
 Tree::remove(treeroot,x);
}
}
node* Tree::remove(node* root,int data)
{
    if(root==NULL) return root;
    else if(data<=root->key_value)
        root->left = remove(root->left, data);
    else if (data> root->key_value)
        root->right = remove(root->right, data);
    else
    {
        //No child
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            root = NULL;
        }
        //One child
        else if(root->right == NULL)
        {
            node* temp = root;
            root= root->left;
            delete temp;
        }
        else if(root->left == NULL)
        {
            node* temp = root;
            root= root->right;
            delete temp;
        }
    }
    return root;
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
  node* temp =search(key);
if (temp==NULL) {
  throw::invalid_argument("No Parent found");
  return -1;
}
else return temp->parent->key_value;
};
// foun left
int Tree::left(int key)
{
  node* temp =search(key);
if (temp==NULL) {
  throw::invalid_argument("No left found");
  return -1;
}
else return temp->left->key_value;
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
 bool Tree::contains(int key) {
   node * temp =search(key);
   if (temp==NULL) {
     return false;
   }else{
     return true;
   }
 }

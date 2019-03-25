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
node* minValueNode(node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
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
node* Tree::remove(node* root,int key)
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key_value) 
        root->left = Tree::remove(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key_value) 
        root->right = Tree::remove(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            node *temp = root->right; 
            delete(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            node *temp = root->left; 
            delete(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key_value = temp->key_value; 
  
        // Delete the inorder successor 
        root->right = Tree::remove(root->right, temp->key_value); 
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
  //throw::invalid_argument("not found");
     return false;
   }else{
     return true;
   }
}

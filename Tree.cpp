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
Tree::~Tree()
{
        Tree::del(treeroot);
}

//foun delete
void Tree::del(node * root)
{
        if(root!=NULL)
        {
                Tree::del(root->left);
                Tree::del(root->right);
                delete root;
        }
}
node* Tree::newNode(int x)
{
        node* root = new node();
        root->x = x;
        root->left = root->right = NULL;
        return root;
}
//foun insert
void Tree::insert(int x){
        bool cheack=Tree::contains(x);
        if(cheack==true) {
                __throw_invalid_argument("The data in the try!!");
        }else if(cheack==false) {
                treeroot = Tree::insert(x,treeroot);
        }
}
//foun help insert
node* Tree::insert(int x, node* root){

        if(root == NULL)
                root = newNode(x);
        else if(x <= root->x)
                root->left = insert(x,root->left);
        else if(x > root->x)
                root->right = insert(x,root->right);
        return root;
}
// foun remove
void Tree::remove(int x)
{
        node *removeNode = search(treeroot, x);

        if (removeNode == NULL)
        {
                throw std::invalid_argument("the number isn't exist ");
        }

        node *temp = remove(treeroot,x);

        if (removeNode == treeroot)
        {
                treeroot = temp;
        }
        if (temp == NULL)
        {
                treeroot = NULL;
        }
}


//foun help remove
node * Tree::remove(node* root, int x){
        if(root==NULL) {
                return root;
        }
        if (root->x > x) {
                root->left = remove(root->left, x);
        } else if (root->x < x) {
                root->right = remove(root->right, x);
        } else {
                if (root->left == NULL)
                {
                        node *temp = root->right;
                        delete root;
                        return temp;
                }
                else if (root->right== NULL)
                {
                        node *temp = root->left;
                        delete root;
                        return temp;
                }
                node *temp = minimumElement(root->right);
                root->x=(temp->x);
                root->right=remove(root->right, temp->x);
        }
        return root;
}
node * Tree::minimumElement(node *root)
{
        if(root == NULL)
                return NULL;
        else if(root->left == NULL)
                return root;
        else
                return minimumElement(root->left);
}
// foun size
int Tree::size()
{
        return size(treeroot);
}
// foun help size
int Tree::size(node* root)
{
        if (root == NULL)
                return 0;
        else
                return(size(root->left) + 1 + size(root->right));
}
// foun root
int Tree::root()
{
        if(treeroot==NULL) {
                __throw_invalid_argument("The data is not in the tree!!");
        }else{
                return treeroot->x;
        }
};
// foun parent
int Tree::parent(int x)
{

        node * cheack=Tree::search(treeroot,x);
        if(cheack==NULL||treeroot->x==x) {
                __throw_invalid_argument("The data is not in the tree!! or dats is the root");
        }else {
                return findParent(treeroot,x);
        }
}
// foun help parent
int Tree::findParent(node* root,int x) {
        if (x < root->x) {
                if (root->left->x == x) {
                        return root->x;
                }
                else {
                        return Tree::findParent(root->left,x);
                }
        }else if (root->right->x ==x) {
                return root->x;
        }else {
                return Tree::findParent(root->right,x);
        }
}
// foun left
int Tree::left(int x)
{
        node * cheack=Tree::search(treeroot,x);
        if(cheack==NULL||cheack->left==NULL) {
                __throw_invalid_argument("The data is not in the tree!!");
        }else {
                return cheack->left->x;
        }
}
// foun right
int Tree::right(int x)
{
        node * cheack=Tree::search(treeroot,x);
        if(cheack==NULL||cheack->right==NULL) {
                __throw_invalid_argument("The data is not in the tree!!");
        }else {
                return cheack->right->x;
        }
}
//foun search
node * Tree::search(node* root, int x)
{
        if(root == NULL)
                return NULL;
        else if(x < root->x)
                return search(root->left, x);
        else if(x > root->x)
                return search(root->right, x);
        else
                return root;
}
//foun print
void Tree::print(){
        print(treeroot,10);
}
//foun help print
void Tree::print(node* p, int indent) {

        if (p != NULL) {
                if (p->right) {
                        Tree::print(p->right, indent + 4);
                }
                if (indent) {
                        cout << setw(indent) << ' ';
                }
                if (p->right) cout << " /\n" << setw(indent) << ' ';
                cout << p->x << "\n ";
                if (p->left) {
                        cout << setw(indent) << ' ' << " \\\n";
                        Tree::print(p->left, indent + 4);
                }
        }
}
//foun contains
bool Tree::contains(int x) {
        node * temp = search(treeroot,x);
        if(temp==NULL) return false;
        else return true;
}

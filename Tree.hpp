#include "iostream"
using namespace std;
namespace ariel {
struct node
{
        int x;
        node *left;
        node *right;
};
class Tree
{
private:
node * treeroot;
public:
Tree();
~Tree();
void del(node *root);
void insert(int x);
void print();
bool contains(int x);
int size();
int root();
int left(int x);
int right(int x);
int parent(int x);
void remove(int x);
private:
node* insert(int x, node* root);
node* newNode(int x);
node* minimumElement(node* root);
node* remove(node* root, int x);
int size(node* node);
int findParent(node* root,int x);
node * search(node* root, int x);
void print(node *root,int x);
};
}

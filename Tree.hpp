
#include "iostream"
using namespace std;
namespace ariel {
struct node
{
        int key_value;
        node *left;
        node *right;
        node *parent;
};

class Tree
{
private:
  node * treeroot;
public:
  Tree();
  ~Tree();
void del(node *leaf);
Tree(node * tree);
void insert(int key);
node* insert(int x, node* p);
node* remove(node* root, int key);
void remove(int x);
int size();
int size(node* node);
int root();
int parent(int key);
node* search(node* root, int key);
node * search(int Key);
int left(int key);
int right(int key);
void print();
void print(node *leaf,int x);
bool contains(int key);
};
}


#include "iostream"
using namespace std;
namespace ariel {
struct node
{
        int key_value;
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
Tree(node * tree);
Tree insert(int key);
void insert(int key, node *leaf);
void remove();
void remove(node *leaf);
int size();
int size(node* node);
int root();
int parent(int key);
node * search(int Key);
node *searchfather(int key, node *leaf);
int left(int key);
int right(int key);
void print();
void print(node *leaf);
};
}

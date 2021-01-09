#include "TreeNode.h"


using namespace std;

template<typename T>
class RBTree {
private:
    enum NodeColor {
        Red,
        Black
    };
    
    struct TreeNode {
        T val;
        TreeNode *p;
        TreeNode *left;
        TreeNode *right;

        NodeColor color;

        /* constructors */
        TreeNode(T val, TreeNode* left = nil, TreeNode* right = nil) : val(val), p(nil), left(nil), right(nil), color(Black) {}
        TreeNode() : color(Black) {}
    };

private:
    TreeNode* root;
    int _size; 
    const static TreeNode * const nil = new TreeNode(); //always point to the same thing, that thing never changes, so two consts

public:
    RBTree() :  root(nil), _size(0) {}
    
    void insert(T key) {
        TreeNode* x = root;
        TreeNode* y = nil;
        TreeNode* z = new TreeNode(key);

        while (x != nil) { 
            y = x;
            if (z->val < x->val)
                x = x->left;
            else
                x = x->right;
        }
        z->p = y;

        if (y == nil) // empty case
            root = z;
        else if (key < y->val)
            y->left = z;
        else y->right = z;

        z->color = Red; // currently black by default
        ++_size;
        RBInsertFixup(z);
    }

    void RBInsertFixup(TreeNode* z) {
        while (z->p->color == Red) { // while nodes parent is red
            if (z->p == z->p->p->left) {
                y = z->p->p->right;
                
            }
        }
        root->color = Black;
    }
};
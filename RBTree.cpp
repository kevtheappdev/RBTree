#include <vector>
#include "RBTree.h"

using namespace std;

TreeNode* RBTree::NIL = new TreeNode();
void RBTree::insertMany(const vector<int>& keys) {
    for(auto it : keys) {
        insert(it);
    }
}

void RBTree::insert(int k) {
    TreeNode* z = new TreeNode(k, NIL);

    TreeNode* y = NIL;
    TreeNode* current = root;

    while(current != NIL) {
        y = current;
        if(k < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    z->parent = y;
    if(y == NIL) {
        root = z;
    }
    else if(z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }

    RBInsertFixup(z);

}

RBTree::RBTree() : size(0) {
    NIL = new TreeNode();
    root = NIL;
}

RBTree::RBTree(int k) : size(1) {
    NIL = new TreeNode();
    root = new TreeNode(k, NIL);
}

void RBTree::RBInsertFixup(TreeNode *z) {
    while(z->parent->color == TreeNode::Color::RED) {
        if(z->parent == z->parent->parent->left) {
            TreeNode* uncle = z->parent->parent->right;
            if(uncle->color == TreeNode::Color::RED) {//case 1
                z->parent->color = TreeNode::Color::BLACK;
                uncle->color = TreeNode::Color::BLACK;
                z->parent->parent->color = TreeNode::Color::RED;
                z = z->parent->parent;
            }
            else {
                if(z == z->parent->right) { //case 2
                    z = z->parent;
                    leftRotation(z);
                }
                //fall through to case 3
                z->parent->color = TreeNode::Color::BLACK;
                z->parent->parent->color = TreeNode::Color::RED;
                rightRotation(z->parent->parent);
            }
        }
        else {
            TreeNode* uncle = z->parent->parent->left;
            if(uncle->color == TreeNode::Color::RED) {//case 1
                z->parent->color = TreeNode::Color::BLACK;
                uncle->color = TreeNode::Color::BLACK;
                z->parent->parent->color = TreeNode::Color::RED;
                z = z->parent->parent;
            }
            else {
                if(z == z->parent->left) { //case 2
                    z = z->parent;
                    rightRotation(z);
                }
                //fall through to case 3
                z->parent->color = TreeNode::Color::BLACK;
                z->parent->parent->color = TreeNode::Color::RED;
                leftRotation(z->parent->parent);
            }
        }
    }
    root->color = TreeNode::Color::BLACK;

}

vector<int> RBTree::inorderTraversal() {
    vector<int> res;
    inorderTraversal(root, res);

    return res;
}

void RBTree::inorderTraversal(TreeNode *current, vector<int> &res) {
    if(current != NIL) {
        inorderTraversal(current->left, res);
        res.push_back(current->key);
        inorderTraversal(current->right, res);
    }
}

void RBTree::leftRotation(TreeNode *x) {
    TreeNode* y = x->right;
    x->right = y->left;
    if(y->left != NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NIL) {
        root = y;
    }
    else if(x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBTree::rightRotation(TreeNode *y) {
    TreeNode* x = y->left;
    y->left = x->right;
    if(x->right != NIL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if(y->parent == NIL) {
        root = x;
    }
    else if(y == y->parent->right) {
        y->parent->right = x;
    }
    else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}


TreeNode::TreeNode(int k, TreeNode *nilRef) :
    key(k), color(RED), left(nilRef), right(nilRef), parent(nilRef)
{

}

//this assumes rhs will never be NIL, since it is only called in RBTree which already checks for that
TreeNode::TreeNode(const TreeNode& rhs) {
    const TreeNode* rhs_ptr = &rhs;

    key = rhs.key;

    if(rhs_ptr->left != RBTree::NIL) {
        left = new TreeNode(*rhs_ptr->left);
        left->parent = this;
    }
    else {
        left = RBTree::NIL;
    }
    if(rhs_ptr->right != RBTree::NIL) {
        right = new TreeNode(*rhs_ptr->right);
        right->parent = this;
    }
    else {
        right = RBTree::NIL;
    }


}

RBTree::RBTree(const RBTree& rhs) {
    if(rhs.root == RBTree::NIL) {
        root = RBTree::NIL;
    }
    else {
        root = new TreeNode(*rhs.root);
        root->parent = RBTree::NIL;
    }
}

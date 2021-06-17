#include <iostream>
#include <stack>
#include <unordered_map>
#include <algorithm>

#ifndef RBTREE_H
#define RBTREE_H

using namespace std;

class RBTree;


class TreeNode {
public:
    enum Color {
        BLACK, RED
    };

    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    Color color;

    TreeNode(int k, TreeNode* nilPtr);

    TreeNode(const TreeNode& rhs);

    //constructor for NIL
    TreeNode() : color(BLACK), left(nullptr), right(nullptr), parent(nullptr) {}
private:

};

class RBTree {
    int size;

public:
    //constructor for empty tree
    RBTree();

    //copy constructor
    RBTree(const RBTree& rhs);

    //constructor for tree with 1 node
    RBTree(int k);

    void insert(int k);
    void insertMany(const vector<int>& keys);

    void leftRotation(TreeNode* x);
    void rightRotation(TreeNode* y);

    vector<int> inorderTraversal();

    TreeNode* root;
    static TreeNode* NIL;
private:
    void inorderTraversal(TreeNode* current, vector<int>& res);
    void RBInsertFixup(TreeNode* z);
};
#endif //RBTREE_H

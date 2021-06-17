#include "gtest/gtest.h"
#include "RBTree.h"

using namespace std;
TEST(RBTrees, inorderTraversal) {
    RBTree tree;
    vector<int> keys{100, 50, 150, 75, 125, 74, 76, 124, 130, 73, 131};

    tree.insertMany(keys);

    sort(keys.begin(), keys.end());
    vector<int> res = tree.inorderTraversal();

    ASSERT_EQ(keys, res);
}

TEST(RBTrees, rotationInverses) {
    RBTree tree;
    vector<int> keys{100, 50, 150, 75, 125, 74, 76, 124, 130, 73, 131};

    tree.insertMany(keys);

    vector<int> original = tree.inorderTraversal();
    tree.rightRotation(tree.root);
    tree.leftRotation(tree.root);
    vector<int> res = tree.inorderTraversal();

    ASSERT_EQ(original, res);
}

TEST(RBTrees, rotationInversesCopyCtr) {
    RBTree tree;
    vector<int> keys{100, 50, 150, 75, 125, 74, 76, 124, 130, 73, 131};

    tree.insertMany(keys);

    RBTree tree_copy = tree;

    tree.leftRotation(tree.root);
    tree.rightRotation(tree.root);

    ASSERT_EQ(tree_copy.inorderTraversal(), tree.inorderTraversal());
}

TEST(RBTrees, copyConstructor) {
    RBTree tree;
    vector<int> keys{100, 50, 150, 75, 125, 74, 76, 124, 130, 73, 131};

    tree.insertMany(keys);

    RBTree tree2 = tree;

    ASSERT_EQ(tree.inorderTraversal(), tree2.inorderTraversal());
}

TEST(RBTrees, exercise13_3_2) {
    RBTree tree;
    vector<int> keys{41, 38, 31, 12, 19, 8};

    tree.insertMany(keys);

    sort(keys.begin(), keys.end());

    ASSERT_EQ(keys, tree.inorderTraversal());
}

TEST(RBTrees, randomKeys100) {
    RBTree tree;

    int NUM_KEYS = 100;
    vector<int> keys;

    for(int i = 0; i < NUM_KEYS; i++) {
        srand(time(nullptr));
        keys.push_back(rand());
    }

    tree.insertMany(keys);

    sort(keys.begin(), keys.end());

    ASSERT_EQ(keys, tree.inorderTraversal());
}
#include <iostream>
#include <algorithm>

class BSTNode
{
public:
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

BSTNode *root;

class BinarySearchTree
{
public:
    BSTNode *insert(BSTNode *root, int data)
    {
        if (root == nullptr)
        {
            root = new BSTNode{data};
        }
        else if (data <= root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }

    bool search(BSTNode *root, int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (root->data == data)
        {
            return true;
        }
        else if (data <= root->data)
        {
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }

    int findMin(BSTNode *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        if (root->left == nullptr)
        {
            return root->data;
        }
        return findMin(root->left);
    }

    int findMax(BSTNode *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        if (root->right == nullptr)
        {
            return root->data;
        }
        return findMax(root->right);
    }

    int height(BSTNode *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        return std::max(height(root->left), height(root->right)) + 1;
    }
};

int main()
{
    BinarySearchTree *binarySearchTree = new BinarySearchTree;
    root = nullptr;

    root = binarySearchTree->insert(root, 10);
    root = binarySearchTree->insert(root, 15);
    root = binarySearchTree->insert(root, 5);
    root = binarySearchTree->insert(root, 25);
    root = binarySearchTree->insert(root, 8);
    root = binarySearchTree->insert(root, 4);
    root = binarySearchTree->insert(root, 31);
    root = binarySearchTree->insert(root, 28);
    root = binarySearchTree->insert(root, 12);

    std::cout << binarySearchTree->search(root, 25) << "\n";
    std::cout << binarySearchTree->search(root, 30) << "\n";
    std::cout << binarySearchTree->search(root, 5) << "\n";
    std::cout << binarySearchTree->search(root, 21) << "\n";

    std::cout << "minimum value in tree: " << binarySearchTree->findMin(root) << "\n";
    std::cout << "maximum value in tree: " << binarySearchTree->findMax(root) << "\n";

    std::cout << "height of the tree is: " << binarySearchTree->height(root);
}

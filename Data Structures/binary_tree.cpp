#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode()
    {
        val = -1;
        right = left = NULL;
    }

    TreeNode(int value)
    {
        val = value;
        right = left = NULL;
    }
};

int totalNodes(TreeNode *node)
{
    if (!node) // null node or leaf node
        return 0;

    return 1 + totalNodes(node->left) + totalNodes(node->right);
}

// DFS (Depth First Search), Time Complexity: O(n), Space Complexity: O(h = height of tree)
void inOrderTraversal(TreeNode *node)
{
    if (node == NULL)
        return;

    inOrderTraversal(node->left);
    cout << node->val << " ";
    inOrderTraversal(node->right);
}

// DFS (Depth First Search), Time Complexity: O(n), Space Complexity: O(h = height of tree)
void preOrderTraversal(TreeNode *node)
{
    if (node == NULL)
        return;

    cout << node->val << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

// DFS (Depth First Search), Time Complexity: O(n), Space Complexity: O(h = height of tree)
void postOrderTraversal(TreeNode *node)
{
    if (node == NULL)
        return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->val << " ";
}

// BFS (Breath First Search), Time Complexity: O(n), Space Complexity: O(w = width of tree)
void levelOrderTraversal(TreeNode *node)
{
    if (node == NULL)
        return;

    queue<TreeNode *> queue;
    queue.push(node);
    queue.push(NULL);

    while (!queue.empty())
    {
        if (queue.front() != NULL)
        {
            cout << queue.front()->val << " ";

            if (queue.front()->left != NULL)
                queue.push(queue.front()->left);

            if (queue.front()->right != NULL)
                queue.push(queue.front()->right);

            queue.pop();
        }
        else
        {
            queue.pop();
            if (!queue.empty())
                queue.push(NULL);
        }
    }
}

// max Distance between root node and leaf node
int heightOfTree(TreeNode *node)
{
    if (node == NULL)
        return 0;

    return 1 + max(heightOfTree(node->left), heightOfTree(node->right));
}

// Max Distance between two nodes, Time Complexity: O(n^2)
int diameterOfTreeBrute(TreeNode *node)
{
    if (node == NULL)
        return 0;

    int lh = heightOfTree(node->left); 
    int rh = heightOfTree(node->right);
    int currDiameter = 1 + lh+ rh;

    int lDiameter = diameterOfTreeBrute(node->left);
    int rDiameter = diameterOfTreeBrute(node->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}

// Time Complexity; O(n)
int diameterOfTree(TreeNode *node, int *height)
{
    if (node == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0; 
    int rh = 0;

    int lDiameter = diameterOfTree(node->left, &lh);
    int rDiameter = diameterOfTree(node->right, &rh);

    int currDiameter = 1 + lh + rh;

    // store the height of current node in 'height' pointer
    *height = 1 + max(lh, rh);

    return max(currDiameter, max(lDiameter, rDiameter));
}

void nodesInLevel(TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->val << " ";
    else if (level > 1)
    {
        nodesInLevel(root->left, level - 1);
        nodesInLevel(root->right, level - 1);
    }
}

// BFS (Breath First Search), Time Complexity: O(n^2), Space Complexity: O(1)
void levelOrderTraversalNaive(TreeNode *node)
{
    int height = heightOfTree(node);

    for (int level = 1; level <= height; level++)
        nodesInLevel(node, level);
}

int main()
{
    int h = 0;

    TreeNode *root = new TreeNode(1);
    /*

            1
          /   \
        2       3
       / \     / \
      4   5   6   7
         / \   \
        8   9   10

    */

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->left->right = new TreeNode(10);

    cout << "Height of Tree: " << heightOfTree(root) << endl;
    cout << "Diameter of Tree: " << diameterOfTree(root, &h) << endl;
    cout << "Total Nodes of Tree: " << totalNodes(root) << endl;

    cout << "\nDepths First Search:-" << endl;

    cout << "In Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "\nBreadth First Search:-" << endl;

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}

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

void printVectorInt(vector<int> vec)
{
    for (auto val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}

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
    int currDiameter = 1 + lh + rh;

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

// Time Complexity: O(n^2)
bool isBalanced(TreeNode *node, int *height)
{
    if (!node)
        return true;

    int lh = 0, rh = 0;
    if (!isBalanced(node->left, &lh) || !isBalanced(node->right, &rh))
        return false;

    *height = 1 + max(lh, rh);

    if (abs(lh - rh) <= 1)
        return true;

    return false;
}

bool isComplete(TreeNode *node)
{
    if (!node)
        return true;
}

bool isPerfect(TreeNode *node)
{
    if ((node->left == NULL) != (node->right == NULL))
        return false;
    if (node->left == NULL)
        return true;
    if ((node->left->left == NULL) != (node->right->left == NULL))
        return false;
    if (!isPerfect(node->left) || !isPerfect(node->right))
        return false;
    return true;
}

vector<int> rightView(TreeNode *node)
{
    if (!node)
        return {-1};

    vector<int> result;

    queue<TreeNode *> queue;
    queue.push(node);

    while (!queue.empty())
    {
        int n = queue.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *curr_node = queue.front();
            queue.pop();
            if (i == n - 1)
                result.push_back(curr_node->val);

            if (curr_node->left)
                queue.push(curr_node->left);
            if (curr_node->right)
                queue.push(curr_node->right);
        }
    }

    return result;
}

vector<int> leftView(TreeNode *node)
{
    if (!node)
        return {-1};

    vector<int> result;

    queue<TreeNode *> queue;
    queue.push(node);

    while (!queue.empty())
    {
        int n = queue.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *curr_node = queue.front();
            queue.pop();
            if (i == 0)
                result.push_back(curr_node->val);

            if (curr_node->left)
                queue.push(curr_node->left);
            if (curr_node->right)
                queue.push(curr_node->right);
        }
    }

    return result;
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
                  \
                   11

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
    root->right->left->right->right = new TreeNode(11);

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

    h = 0;
    cout << "\nIs The Tree Balanced: " << boolalpha << isBalanced(root, &h) << endl;
    cout << "Is The Tree Complete: " << boolalpha << isComplete(root) << endl;
    cout << "Is The Tree Perfect: " << boolalpha << isPerfect(root) << endl;

    cout << "Right View: ";
    printVectorInt(rightView(root));

    cout << "Left View: ";
    printVectorInt(leftView(root));

    return 0;
}

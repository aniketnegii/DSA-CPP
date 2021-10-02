#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node *CreateNode(int data)
{
    node *newNode = new node();
    if (!newNode)
    {
        cout << "Memory Error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *InsertNode(node *root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

void DeleteDeepest(node *root, node *dNode)
{
    queue<node *> q;
    q.push(root);

    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == dNode)
        {
            temp = NULL;
            delete (dNode);
            return;
        }

        if (temp->right)
        {
            if (temp->right == dNode)
            {
                temp->right = NULL;
                delete (dNode);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }

        if (temp->left)
        {
            if (temp->left == dNode)
            {
                temp->left = NULL;
                delete (dNode);
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}

node *DeleteNode(node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL and root->right == NULL)
    {
        if (root->data == key)
        {
            delete (root);
            return NULL;
        }
        return root;
    }

    queue<node *> q;
    q.push(root);

    node *temp;
    node *keyNode = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
        {
            keyNode = temp;
        }

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    if (keyNode != NULL)
    {
        int x = temp->data;
        DeleteDeepest(root, temp);
        keyNode->data = x;
    }

    return root;
}

int sizeOfTree(node *root)
{
    if (root == NULL)
        return 0;
    else
        return (sizeOfTree(root->left) + 1 + sizeOfTree(root->right));
}

int maxOfTree(node *root)
{
    if (root == NULL)
        return -1;
    int temp = root->data;
    int ltemp = maxOfTree(root->left);
    int rtemp = maxOfTree(root->right);

    if (temp < ltemp)
        temp = ltemp;
    if (temp < rtemp)
        temp = rtemp;

    return temp;
}

int minOfTree(node *root)
{
    if (root == NULL)
        return INT_MAX;
    int temp = root->data;
    int ltemp = minOfTree(root->left);
    int rtemp = minOfTree(root->right);

    if (temp > ltemp)
        temp = ltemp;
    if (temp > rtemp)
        temp = rtemp;

    return temp;
}

void leftViewOfTree(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);

    node *temp;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            temp = q.front();
            q.pop();
            if (i == 1)
                cout << temp->data << " ";

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void rightViewOfTree(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);

    node *temp;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            temp = q.front();
            q.pop();
            if (i == n)
                cout << temp->data << " ";

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int heightOfTree(node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        if (root->left == NULL and root->right == NULL)
            return 0;
        else
            return (1 + max(heightOfTree(root->left), heightOfTree(root->right)));
    }
}

node *mirrorTree(node *root)
{
    if (root == NULL)
        return root;
    node *temp = root->right;
    root->right = root->left;
    root->left = temp;

    if (root->left)
    {
        mirrorTree(root->left);
    }

    if (root->right)
    {
        mirrorTree(root->right);
    }

    return root;
}

node *LCA(node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 or root->data == n2)
    {
        return root;
    }

    node *l = LCA(root->left, n1, n2);
    node *r = LCA(root->right, n1, n2);

    if (l and r)
        return root;
    if (l)
        return l;
    else
        return r;
}

int findSumTree(node *root)
{
    if (root == NULL)
        return 0;
    int ls = findSumTree(root->left);
    int rs = findSumTree(root->right);
    int val = root->data;
    int newVal = ls + rs;
    root->data = newVal;
    return ls + rs + val;
}

void convertSumTree(node *root)
{
    findSumTree(root);
}

void toDLL(node *root, node *&head, node *&prev, int &flag)
{
    if (!root)
        return;
    toDLL(root->left, head, prev, flag);
    if (flag == 0)
    {
        flag = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    toDLL(root->right, head, prev, flag);
}

node *convertToDLL(node *root)
{
    int flag = 0;
    node *head = NULL;
    node *prev = NULL;
    toDLL(root, head, prev, flag);
    return head;
}

void preOrderit(node *root)
{

    if (root == NULL)
        return;

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *t = s.top();
        cout << t->data << " ";
        s.pop();

        if (t->right)
            s.push(t->right);
        if (t->left)
            s.push(t->left);
    }
}

// void postOrderit(node* root){
//     if(root == NULL) return ;
//     stack<node*>s;
//     s.push(root);

//     while(!s.empty())
//     {
//         node *t = s.top();
//         if(t->right) s.push(t->right);
//         if(t->left) s.push(t->left)
//     }
// }

void inOrder(node *temp)
{
    if (temp == NULL)
        return;

    inOrder(temp->left);
    cout << temp->data << " ";
    inOrder(temp->right);
}

int main()
{
    struct node *root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->left->right = CreateNode(12);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    /*         10    */
    /*    11         9 */
    /* 7     12  15      8 */

    cout << "Inorder traversal before deletion : ";
    inOrder(root);

    cout << "Preorder traversal before deletion : ";
    preOrderit(root);

    cout << "\nSize of tree is : " << sizeOfTree(root);

    int key = 11;
    root = DeleteNode(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inOrder(root);

    cout << "Preorder traversal after deletion : ";
    preOrderit(root);

    /*         10    */
    /*    8         9 */
    /* 7     12  15       */

    cout << "\nSize of tree is : " << sizeOfTree(root);
    cout << "\nHeight of tree is : " << heightOfTree(root);
    cout << "\nMax of tree is : " << maxOfTree(root);
    cout << "\nMin of tree is : " << minOfTree(root);
    cout << "\nLeft view of tree is : ";
    leftViewOfTree(root);
    cout << "\nRight view of tree is : ";
    rightViewOfTree(root);

    // cout << "\nMirrored tree inorder traversal: ";
    // mirrorTree(root);
    // inOrder(root);

    cout << "\nLCA of 7 and 12 is: " << (LCA(root, 11, 9))->data;

    // convertSumTree(root);
    // cout << "\nSum tree is :";
    // preOrderit(root);

    //node *dllHead = convertToDLL(root);

    return 0;
}
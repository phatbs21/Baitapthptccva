#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

float density(Node *root)
{
    queue<Node *> q;

    q.push(root);

    q.push(NULL);
    int height = 1, size = 0;
    while (!q.empty())
    {
        Node *t = q.front();
        q.pop();
        if (t)
            size++;
        else
        {
            if (q.empty())
                break;
            q.push(NULL);
            height++;
            continue;
        }
        if (t->left)
        {
            q.push(t->left);
        }
        if (t->right)
        {
            q.push(t->right);
        }
    }
    return (float)size / height;
}
int main()
{
    freopen("PAIRING.INP", "r", stdin);
    freopen("PAIRING.OUT", "w", stdout);
    int a, b, c;
    cin >> a >> b >> c;
    Node *root = newNode(a);
    root->left = newNode(b);
    root->right = newNode(c);
    cout << (int)(density(root) * 2);
    return 0;
}
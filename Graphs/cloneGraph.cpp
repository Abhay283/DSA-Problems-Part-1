#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
};

class solution
{
public:
    unordered_map<Node *, Node *> mp;
    void dfs(Node *node, Node *clone_node)
    {
        for (Node *n : node->neighbors)
        {
            if (mp.find(n) == mp.end())
            {
                Node *clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(n, clone);
            }
            else
            {
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return node;
        }
        Node *clone_node = new Node(node->val);
        mp[node] = clone_node;
        dfs(node, clone_node);
        return clone_node;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Node *> adj(n, NULL);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        if (adj[u] == NULL)
        {
            adj[u] = new Node(u);
        }
        if (adj[v] == NULL)
        {
            adj[v] = new Node(v);
        }
        adj[u]->neighbors.push_back(adj[v]);
        adj[v]->neighbors.push_back(adj[u]);
    }
        solution obj;
        Node *clone = obj.cloneGraph(adj[0]);
        cout<<"Cloned graph created successfully."<<endl;
        return 0;
}
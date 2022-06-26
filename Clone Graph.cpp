// https://leetcode.com/problems/clone-graph/
// 133. Clone Graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * bfs(Node * node, map<Node *, Node *> & visited)
    {
        // visited[node] = true;
        Node * temp = new Node(node->val);
        visited[node] = temp;
        vector<Node *> neighbors;
        
        for(int i=0;i<node->neighbors.size();i++)
        {
            Node * temp = node->neighbors[i];
            if(visited.find(temp) == visited.end())
                bfs(temp, visited);
            neighbors.push_back(visited[temp]);
        }
        
        temp->neighbors = neighbors;
        return temp;
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;      
        
        Node* temp;
        map<Node *,Node *> visited;
        temp = bfs(node, visited);
        return temp;
    }
};

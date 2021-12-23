class Solution {
public:
    int V;

    bool isCyclicUtil(vector<int> adj[], int v, bool visited[], bool *recStack) {
        if (visited[v] == false) {
            // Mark the current node as visited and part of recursion stack
            visited[v] = true;
            recStack[v] = true;

            // Recur for all the vertices adjacent to this vertex
            // list<int>::iterator i;
            for (auto i:adj[v]) {
                if (!visited[i] && isCyclicUtil(adj, i, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }

        }
        recStack[v] = false;  // remove the vertex from recursion stack
        return false;
    }

    bool isCyclic(vector<int> adj[]) {
        // Mark all the vertices as not visited and not part of recursion
        // stack
        bool *visited = new bool[V];
        bool *recStack = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
            recStack[i] = false;
        }

        // Call the recursive helper function to detect cycle in different
        // DFS trees
        for (int i = 0; i < V; i++)
            if (isCyclicUtil(adj, i, visited, recStack))
                return true;

        return false;
    }

//     void bfs(vector<int> adj[],int start, int n,vector<bool> &visited,vector<int> & ans)
//     {
//         queue<int> q;
//         q.push(start);

//         while(!q.empty())
//         {
//             int index = q.front();
//             if(!visited[index])
//                 ans.push_back(index);
//             visited[index] = true;
//             q.pop();

//             // travers all nodes            
//             for(int i=0;i<adj[index].size();i++)
//             {
//                 int in = adj[index][i];
//                 if(!visited[in]){
//                     visited[in]=true;
//                     ans.push_back(in);
//                     q.push(in);
//                 }                   
//             }

//         }
//     }
    int visit_node_size = 0;

    void topo(int V, vector<int> adj[], int index, vector<bool> &visited, vector<int> &ans, stack<int> &st) {
        if (visited[index] == false) {
            visited[index] = true;
            st.push(index);
            for (int i = 0; i < adj[index].size(); i++) {
                topo(V, adj, adj[index][i], visited, ans, st);
            }
            // visit_node_size++;
            ans.push_back(index);
            st.pop();
        }
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        // code here
        // int ind[V] = {0};
        vector<int> ind(V, 0);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                ind[adj[i][j]]++;
            }
        }


        // bool visited[V] = {false};
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (ind[i] == 0)
                topo(V, adj, i, visited, ans, st);
        }

        for (int i = 0, j = ans.size() - 1; i < j; i++, j--) {
            int temp = ans[i];
            ans[i] = ans[j];
            ans[j] = temp;
        }
        return ans;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // vector<int> ans;
        vector<int> adj[numCourses];
        // vector<int> adjRev[numCourses];
        // vector<int> points;
        V = numCourses;
        int n = prerequisites.size();
        bool isValid = true;
        for (int i = 0; i < n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            // adjRev[u].push_back(u);
            // adj[u].push_back(v);
        }


//         for(int i=0;i<numCourses && isValid;i++){
//             for(int j=0;j<adj[i].size() && isValid;j++)
//             {
//                 int u = i;
//                 int v = adj[i][j];

//                 //check
//                 for(int k=0;k<adj[v].size() && isValid;k++)
//                 {
//                     int v1 = adj[v][k];
//                     if(v1==u){
//                         isValid = false;
//                             break;
//                         }
//                 }
//             }
//         }
        vector<int> res;

        bool isC = false;
        isC = isCyclic(adj);


        if (!isC)
            res = topoSort(numCourses, adj);


//         int endIndex = 0;
//         int startIndex = 0;
//         bool startFind = false;
//          vector<bool> visited(numCourses,false);

//         //startIndex 
//         for(int i=0;i<numCourses;i++)
//         {
//             if(adjRev[i].size()==0){
//                 ans.push_back(i);
//                 visited[i]=true;
//                 startIndex = i;
//                 startFind=true;
//             }
//         }

//        points = ans;
//         // cout<<startIndex<<endl; 
//         if(startFind && isValid) {
//             // cout<<"i";
//         for(auto &in:points){
//             cout<<in;
//         bfs(adj,in,numCourses,visited,ans);
//         }


//         //      0
//         //    1   2
//         //    3   4
//         //    5
//         //    6

//         // add remaining nodes
//         // for(int i=0;i<numCourses;i++)
//         // {
//         //     if(!visited[i]){
//         //         ans.push_back(i);
//         //         visited[i] = true;
//         //     }
//         // }

//         }

//         // any course left
//         vector<int> empty;
//         if(!isValid)
//         {
//             ans = empty;
//         }

//         // if empty edges
//         if(n==0)
//         {
//             for(int i=0;i<numCourses;i++)
//             {
//                 if(!visited[i]){
//                     ans.push_back(i);
//                     visited[i] = true;
//                 }
//             }
//         }

        return res;
    }
};

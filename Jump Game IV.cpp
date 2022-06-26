// Needs to improve and try again
// https://leetcode.com/problems/jump-game-iv/
// 1345. Jump Game IV


// class Solution {
// public:
        
//     int minJumps(vector<int>& arr) {
        
//         // return 0;
//         int n = arr.size();
        
//         if(n==1)
//             return 0;
        
//         // int mx = pow(10,8)+1;
//         // vector<int> index[mx];
//         map<int,vector<int>> mp;
        
//         for(int i=0;i<n;i++)
//         {
//             int index = arr[i];
//             mp[index].push_back(i);  
//         }
        
//         //bfs
        
//         queue<pair<int,int>> q;
//         vector<bool> visited(n,false);
        
//         q.push({0,0});
//         int ans = n;
        
//         while(!q.empty())
//         {
//             int index = q.front().first;
//             int dis = q.front().second;
//             visited[index] = true;
//             // cout<<index<<" ";
            
//             q.pop();
            
//             if(index == n-1)
//             {
//                 ans = min(ans,dis);
//                 // break;
//             }
            
            
//             if(index-1>=0 && !visited[index-1])
//                 q.push({index-1,dis+1}); 
            
//             if(index+1<n && !visited[index+1])
//                 q.push({index+1,dis+1});
            
            
//             vector<int> temp = mp[arr[index]];
//             int sz = temp.size();
//             for(int i=0;i<sz;i++)
//             {
//                 int tindex = temp[i];
//                 if(tindex<=index)
//                     continue;
                
//                 if(!visited[tindex]){
//                     q.push({tindex,dis+1});
//                     // visited[tindex] = true;
//                 }
//             }
            
            
//         }
        
//         return ans;
//     }
// };


class Solution {
	unordered_map<int, vector<size_t>> indices;
    unordered_map<int, bool> vis;
public:
	int minJumps(vector<int>& arr)
	{
		const size_t n = arr.size();
		for (int i = 0; i < n; ++i)
			indices[arr[i]].push_back(i);

		// bfs
		vector<int> jumps(n, -1);
		queue<size_t> q;
		q.push(0);
		jumps[0] = 0;

		while(!q.empty())
		{
			int node = q.front();
			q.pop();

			// all neighbors
			if (!vis[arr[node]])
			{
				for (const auto& idx: indices[arr[node]])
				{
					if (jumps[idx] != -1)
						continue;

					jumps[idx] = jumps[node] + 1;
					q.push(idx);
				}
			}
			vis[arr[node]] = true;

			if (node + 1 < n && jumps[node + 1] == -1)
			{
				jumps[node + 1] = jumps[node] + 1;
				q.push(node + 1);
			}

			if (node - 1 >= 0 && jumps[node - 1] == -1)
			{
				jumps[node - 1] = jumps[node] + 1;
				q.push(node - 1);
			}
		}

		return jumps[n-1];
	}
};

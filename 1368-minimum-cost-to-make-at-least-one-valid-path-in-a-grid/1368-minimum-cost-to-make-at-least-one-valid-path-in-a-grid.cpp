class compare
{
    public:
    bool operator()(pair<int,pair<int,int>>&a, pair<int,pair<int,int>>&b)
    {
        return (a.first > b.first);
    }
};
class Solution {
public:
    int minCost(vector<vector<int>>&A) {
        int m = A.size();
        int n = A[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,compare >pq;
        vector<vector<int>>D(m,vector<int>(n,INT_MAX));
        D[m - 1][n - 1] = 0;
        pq.push({0,{m - 1,n - 1}});
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        while(!pq.empty())
        {
            pair<int,pair<int,int>>node = pq.top();
            pq.pop();
            int x = node.second.first;
            int y = node.second.second;
            int dis = node.first;
            if(x == 0 and y == 0)
                return dis;
            if(dis > D[x][y])
                continue;
            int dir = 1;
            for(int k = 0; k < 4; k++)
            {
                int i = x + dx[k];
                int j = y + dy[k];
                int change = 0;
                if(i >= 0 and i < m and j >= 0 and j < n)
                {
                    change = (A[i][j] == dir) ? 0 : 1;
                    if(dis + change < D[i][j])
                    {
                        D[i][j] = dis + change;
                        pq.push({D[i][j],{i,j}});
                    }
                }
                dir++;
            }
            
        }
        return INT_MAX;
        
    }
};

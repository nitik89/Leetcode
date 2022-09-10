class Solution {
public:
    int check(vector<vector<int>>&mat){
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]){
                    return 0;
                }
            }
        }
        return 1;
    }
    int minFlips(vector<vector<int>>& mat) {
        map<vector<vector<int>>,int>mp;
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        queue<vector<vector<int>>>q;
        q.push(mat);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
            auto x=q.front();
                q.pop();
            if(mp.count(x)){
                continue;
            }
            if(check(x)){
                return ans;
            }
                mp[x]=1;
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    vector<vector<int>>vec=x;
                    vec[i][j]=vec[i][j]?0:1;
                    for(int k=0;k<dir.size();k++){
                        int nx=i+dir[k][0];
                        int ny=j+dir[k][1];
                        
                        if(nx>=0&&nx<mat.size()&&ny>=0&&ny<mat[0].size()){
                            vec[nx][ny]=vec[nx][ny]?0:1;
                        }
                    }
                    q.push(vec);
                }
            }
            }
            ans++;
        }
        
        return -1;
    }
};









class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        vector<bool>vis(1001,false);
        queue<int>q;
        q.push(start);
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                int x=q.front();
                q.pop();
                if(x==goal) return cnt;
                if(x>1000||x<0||vis[x]) continue;
                vis[x]=true;
                
                for(int i=0;i<nums.size();i++){
                    int a=nums[i]+x;
                    int b=x-nums[i];
                    int c=nums[i]^x;
                   
                        q.push(a);
                    
                    
                        q.push(b);
                    
            
                        q.push(c);
                    
                }
            }
            cnt++;
        }
        return -1;
    }
};
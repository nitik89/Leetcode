class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        priority_queue<long long>pq;
        vector<long long>vec(n,0);
        for(auto x:roads){
            vec[x[0]]++;
            vec[x[1]]++;
        }
        for(auto x:vec){
            pq.push(x);
        }
        long long sum=0;
        
        while(!pq.empty()){
            sum+=pq.top()*n;
            n--;
            pq.pop();
        }
        return sum;
        
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x:stones){
            pq.push(x);
        }
        if(pq.size()==2){
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            return f-s;
        }
        while(pq.size()>1){
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            if(f!=s){
                if(f>s){
                    pq.push(f-s);
                }
                
            }
            else if(f==s){
                if(pq.size()==0){
                    return f-s;
                }
            }
        }
        return pq.top();
    }
};
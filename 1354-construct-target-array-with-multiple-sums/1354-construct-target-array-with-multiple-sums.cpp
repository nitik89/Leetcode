class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        long long sum=0;
        for(auto x:target){
            sum+=x;
            pq.push(x);
        }
        while(pq.top()!=1){
            int t=pq.top();
            pq.pop();
            int save=sum;
            sum-=t;//curr val to which t has been added
            if(sum<=0||sum>=t){
                return false;
            }
           t = t % sum; // to directly go to where it came from , without following all steps one by one
			sum += t;
			int tbp = t > 0 ? t : sum;
			pq.push(tbp);
          
           
        }
        return true;
        
    }
};
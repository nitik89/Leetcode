class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a){
            pq.push({a,'a'});
        }
        if(b){
            pq.push({b,'b'});
        }
        if(c){
            pq.push({c,'c'});
        }
        string ans="";
        while(pq.size()>1){
            pair<int,char>f=pq.top();pq.pop();
            pair<int,char>s=pq.top();pq.pop();
            if(f.first>=2){
                ans+=f.second;
                ans+=f.second;
                f.first-=2;
            }
            else{
                ans+=f.second;
                f.first--;
            }
            
            if(s.first>=2&&s.first>=f.first){
                ans+=s.second;
                ans+=s.second;
                s.first-=2;
            }
            else{
                ans+=s.second;
                s.first--;
            }
            if(f.first>0){
                pq.push(f);
            }
            if(s.first>0){
                pq.push(s);
            }
        }
        if(pq.empty()) return ans;
        if(pq.top().first>=2){
        ans+=pq.top().second;
        ans+=pq.top().second;
        }
        else{
            ans+=pq.top().second;
        }
        return ans;
        
        
    }
};









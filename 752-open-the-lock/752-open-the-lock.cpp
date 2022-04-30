class Solution {
public:
    int openLock(vector<string>& deads, string target) {
        queue<pair<string,int>>q;
        q.push({"0000",0});
        unordered_set<string>dead;
        for(auto x:deads){
            dead.insert(x);
        }
        unordered_set<string>vis;
        // vis.insert("0000");
        while(!q.empty()){
            pair<string,int>x=q.front();
            q.pop();
            // cout<<x.first<<" ";
            if(dead.find(x.first)!=dead.end()){
                continue;
            }
            if(x.first==target){
                return x.second;
            }
            
            if(vis.find(x.first)!=vis.end()){
                // cout<<x.first<<" ";
                continue;
            }
            vis.insert(x.first);
            string temp=x.first;
            string str=x.first;
            for(int i=0;i<str.size();i++){
                int m=str[i] - '0';
                char my=(char)(((m+1)%10) + '0');
                str[i]=my;
                // cout<<str<<" ";
                // cout<<(dead.find(str)!=dead.end())<<" "<<str<<"\n";
                if(vis.find(str)==vis.end()&&dead.find(str)==dead.end()){
                    // cout<<str<<" ";
                    q.push({str,x.second+1});
                }
                
                str=temp;
                 m=str[i] - '0';
                my=(char)(((10+(m-1)%10)%10) + '0');
            
                str[i]=my;
                
                if(vis.find(str)==vis.end()&&dead.find(str)==dead.end()){
                    q.push({str,x.second+1});
                }
                str=temp;
            }
        }
        return -1;
    }
};
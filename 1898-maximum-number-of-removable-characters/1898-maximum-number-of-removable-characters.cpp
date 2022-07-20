class Solution {
public:
    bool isPos(vector<int>&rem,string s,string p,int mid){
        string temp=s;
        for(int i=0;i<=mid;i++){
            int idx=rem[i];
            temp[idx]='-';
        }
        int i=0,j=0;
        while(i<temp.size()&&j<p.size()){
            if(temp[i]==p[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int st=0,e=rem.size()-1;
        int ans=-1;
        while(st<=e){
            int mid=(st+e)/2;
            if(isPos(rem,s,p,mid)){
                ans=mid;
                st=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans+1;
    }
};
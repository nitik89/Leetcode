class Solution {
public:
    vector<long long>seg;
    
    void update(int pos,int s,int e,int v){
        if(v>e||v<s){
            return;
        }
        if(s==e){
            seg[pos]++;
            return;
        }
        int mid=(s+e)/2;
        update(2*pos+1,s,mid,v);
        update(2*pos+2,mid+1,e,v);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
    int getAns(int s,int e,int ql,int qr,int pos){
        if(qr<s||e<ql){
            return 0;
        }
        if(ql<=s&&e<=qr){
            // cout<<seg[pos]<<" ";
            return seg[pos];
        }
        int mid=(s+e)/2;
        return getAns(s,mid,ql,qr,2*pos+1)+getAns(mid+1,e,ql,qr,2*pos+2);
    }
    int createSortedArray(vector<int>& in) {
        int s=0,e=*max_element(in.begin(),in.end());
        seg.resize(4*e,0);
        int mod=1e9+7;
        int ans=0;
        for(int i=0;i<in.size();i++){
            int v=in[i];
            int mn=getAns(s,e,s,v-1,0);
            int mx=getAns(s,e,v+1,e,0);
            ans=ans%mod+min(mn,mx);
            update(0,s,e,v);
        }
        return ans%mod;
    }
};






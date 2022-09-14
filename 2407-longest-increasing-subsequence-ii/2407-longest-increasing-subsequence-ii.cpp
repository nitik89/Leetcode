class Solution {
public:
    vector<int>seg;
    int query(int pos,int s,int e,int l,int r){
        if(r<s||e<l){
            return 0; 
        }
        if(l<=s&&r>=e){
            return seg[pos];
        }
        int mid=(s+e)/2;
        return max(query(2*pos+1,s,mid,l,r),query(2*pos+2,mid+1,e,l,r));
    }
    void update(int pos,int s,int e,int i,int v){
        if(i<s||i>e){
            return;
        }
        if(s==e){
            seg[pos]=max(seg[pos],v);
            return;
        }
        int mid=(s+e)/2;
        update(2*pos+1,s,mid,i,v);
        update(2*pos+2,mid+1,e,i,v);
        seg[pos]=max(seg[2*pos+1],seg[2*pos+2]);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=1e5+1;
        int size = (int)(ceil(log2(n)));
    size = (2 * pow(2, size)) - 1;
        seg.resize(size,0);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int no=nums[i];
            int cur=query(0,0,n-1,max(no-k,0),no-1)+1;
            ans=max(ans,cur);
            update(0,0,n-1,no,cur);
            
        }
        return ans;
    }
};
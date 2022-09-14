class Solution {
public:
    vector<long long>seg;
    void update(int s,int e ,int pos,int v)
    {
        if(s>v||v>e){
            return ;
        }
        
        if(s==v&&e==v){
            seg[pos]=1;
            return;
        }
        int mid=(s+e)/2;
        update(s,mid,2*pos+1,v);
        update(mid+1,e,2*pos+2,v);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
    int query(int s,int e,int low,int high,int pos){
        if(e<low||s>high){
            return 0;
        }
        if(s>=low&&e<=high){
            return seg[pos];
        }
        int mid=(s+e)/2;
        return query(s,mid,low,high,2*pos+1)+query(mid+1,e,low,high,2*pos+2);
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        seg.resize(400004);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums1[i]]=i;
        }
        for(int i=0;i<n;i++){
            nums2[i]=mp[nums2[i]];
        }
        //now baari aai tree ki 
        update(0,n-1,0,nums2[0]);
        long long ans=0;
        for(int i=1;i<n-1;i++){
            long long cntonlf=query(0,n-1,0,nums2[i]-1,0);
            //calculate the ones on the right
            long long notinc=(i-cntonlf);
            long long rgt=((n-1)-nums2[i]-notinc);
            ans+=cntonlf*rgt;
            update(0,n-1,0,nums2[i]);
        }
        return ans;
        
    }
};






/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int search(int i,int j,int tar,MountainArray &mount){
        while(i<=j){
            int mid=(i+j)>>1;
            if(mount.get(mid)==tar){
                return mid;
            }
            else if(mount.get(mid)>tar){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return -1;
    }
    int search1(int i,int j,int tar,MountainArray &mount){
        while(i<=j){
            int mid=(i+j)>>1;
            if(mount.get(mid)==tar){
                return mid;
            }
            else if(mount.get(mid)>tar){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mount) {
        int i=0,j=mount.length()-1;
        // cout<<mount.length()<<" ";
        int idx=-1;
        while(i<=j){
            int mid=(i+j)>>1;
            
            if(mount.get(mid)>mount.get(mid+1)){
                
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
         // cout<<idx<<"\n";
        // return 1;
        idx=i;
        i=0;
        j=mount.length()-1;
    
        int ans=search(i,idx,target,mount);
        if(ans!=-1){
            // cout<<ans<<"\n";
            return ans;
        }
        
        return search1(idx+1,j,target,mount);
    }
};
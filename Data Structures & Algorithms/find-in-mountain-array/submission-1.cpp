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
    int binarySearchAsc(MountainArray &arr, int target, int l, int r){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr.get(mid) == target){
                return mid;
            }else if(arr.get(mid) > target){
                r = mid-1;
            }else{
                l= mid+1;
            }
        }
        return -1;
    }

    int binarySearchDsc(MountainArray &arr, int target, int l, int r){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr.get(mid) == target){
                return mid;
            }else if(arr.get(mid) > target){
                l = mid+1;
            }else{
                r= mid-1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();;
        int low=0,high=n-1;
        while(low < high){
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        int peak = low;
        int left = binarySearchAsc(mountainArr,target,0,peak);
        if(left != -1){
            return left;
        }
        return binarySearchDsc(mountainArr,target,peak+1,n-1);
    }
};
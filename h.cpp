#include<bits/stdc++.h>
using namespace std;
    bool check(vector<int> &nums,int val,vector<int> &nums2,int k){
        if(k-val>nums2.size()) return true;
        return false;
    }
    int maxc(vector<int> &nums1,vector<int> &nums2,int numsf,int numss){
        if(numsf==-1) return nums2[numss];
        if(numss==-1) return nums1[numsf];
        else{
            return max(nums1[numsf],nums2[numss]);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2,int k) {
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int low = 0,high;
        if(nums1.size()>k) high = k;
        else high = nums1.size();
        int l1,l2,r1,r2;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(nums1,mid,nums2,k)){
                low = mid+1;
                continue;
            }
            l1 = mid-1,l2 = mid;
            r1 = k-mid-1,r2 = k-mid;
            if(l1!=-1 && r2<nums2.size() && nums1[l1]>nums2[r2]){
                high = mid-1;
            }
            else if(r1!=-1 && l2<nums1.size() && nums1[l2]<nums2[r1]){
                low = mid+1;
            }
            else{
                break;
            }
        }
        return (double)maxc(nums1,nums2,l1,r1);
    }
    int main(){
        vector<int> nums1 = {1};
        vector<int> nums2 = {2,3,4,5,6};
        int k = 6;
        cout<<findMedianSortedArrays(nums1,nums2,k);
    }
/*Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.*/


class Solution {
public:
   
    int valid(vector<int> &nums,int m,int mid)
    {
       int cuts=0,sum=0;
       for(int i=0;i<nums.size();i++)
       {
           sum+=nums[i];
           if(sum>mid)
           {
               ++cuts;
               sum=nums[i];
           }
       }
        cuts++;
        return cuts<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int high=0;
        int low=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            high+=nums[i];
            low=max(nums[i],low);
        }
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(valid(nums,m,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
      
        
    }
};

/*Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer*/


class Solution {
public:
     bool possible(vector<int> &nums,int &t,int div)
    {
        int cnt=0;
        int number=0;
        for(int w:nums)
        {
           number+=ceil((double)w/(double)div);
        }
        if(number<=t)
            return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int t) {
         int low=1,high=1e6,mid;
        int ans=1e6;
        int n=nums.size();
    
        while(low<=high)
        {
            mid=(low+high)/2;
            if(possible(nums,t,mid))
            {
                high=mid-1;
                ans=min(mid,ans);
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};

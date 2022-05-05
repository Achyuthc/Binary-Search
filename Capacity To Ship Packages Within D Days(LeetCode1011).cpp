/*A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.*/


class Solution {
public:
    bool possible(vector<int> &weights,int days,int c)
    {
        int sum=0;
        int number=1;
        for(int w:weights )
        {
            sum+=w;
            if(w>c)
                return false;
            if(sum>c)
            {
                sum=w;
                number++;
            }
        }
        if(number<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1,high=25000000,mid;
        int ans=25000000;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(possible(weights,days,mid))
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

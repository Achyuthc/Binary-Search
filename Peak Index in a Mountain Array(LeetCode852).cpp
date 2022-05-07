/*Let's call an array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].*/


class Solution {
public:
        int peak(vector<int> &arr,int low,int high)
        {
            int mid=(low+high)/2;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(mid==0)
                    low=mid+1;
                else if(mid==arr.size()-1)
                    high=mid-1;
                else if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1])
                    return mid;
                else if(arr[mid-1]<arr[mid])
                    low=mid+1;
                else
                    high=mid-1;
            }
            return low;   
        }

        
    int peakIndexInMountainArray(vector<int>& arr) {
          return peak(arr,0,arr.size()-1);
           
        
    }
};

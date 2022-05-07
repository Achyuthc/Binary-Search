/*Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0,high=letters.size()-1;
        int mid,n=letters.size();
        while(low<=high)
        {
            mid=(low+high)/2;
            if(letters[mid]<=target)
                low=mid+1;
            else
                high=mid-1;
        }
        //cout<<low<<" "<<high<<" ";
        return letters[low%n];
    }
};

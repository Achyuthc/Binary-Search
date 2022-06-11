/*You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

 */

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        int m=potions.size();
        
        for(int i=0;i<spells.size();i++)
        {
            long need=(success+spells[i]-1)/spells[i];
            
            ans.push_back(m-(lower_bound(potions.begin(),potions.end(),need)-potions.begin()));
        }
        return ans;
        
    }
};

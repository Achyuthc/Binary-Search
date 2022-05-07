/*Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.

*/


int Solution::findMedian(vector<vector<int> > &A) {
int low=1,high=1e9;
int indx=0,cnt=0;
int m=A[0].size();
int mid;
bool found=false;
int left=m*A.size()/2;
while(low<=high)
{
    mid=(low+high)/2;
    cnt=0;
    found=false;
    for(int i=0;i<A.size();i++)
    {
        indx=prev(upper_bound(A[i].begin(),A[i].end(),mid))-A[i].begin();
        if(A[i][indx]==mid)
            found=true;
        cnt+=indx+1;
    }
    if(cnt==left+1&&found)
        return mid;
    else if(cnt<left+1)
    {
        low=mid+1;
    }
    else
    {
        high=mid-1;
    }
        
}
return low;
}

//[1,3,4]

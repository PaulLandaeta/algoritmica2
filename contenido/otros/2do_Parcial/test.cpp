#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_N 100000
using namespace std;

vector<int> vec;

void binSearch(int target)
{
    sort(vec.begin(), vec.end());
    int left = 0, right = vec.size() - 1, mid = left + ((right - left) / 2);
    int ans = 0;
    while (left < right)
    {
        if (vec[mid] <= target)
        {
            
            if (vec[mid+1] > target)
            {
                ans = vec[mid+1];
                break;
            } else {
                left=mid+1;
            }
        } else if (vec[mid]>target){
            if (vec[mid-1]>target)
            {
                if (vec[mid-2]<vec[mid-1])
                {
                    ans=vec[mid-2];
                break;
                } else{ 
                     ans=vec[mid-1];
                     break;
                }
                
               
            } else if (vec[mid]>target )
            {
                ans=vec[mid];
                break;
            } else {
                right=mid-1;
            }
        }
        mid = left + ((right - left) / 2);
        
    }
    cout<<ans<<endl;
}

int main()
{
    input;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int numb;
        cin >> numb;
        vec.push_back(numb);
    }
    int k;
    cin >> k;
    binSearch(k);
}

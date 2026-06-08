#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>> t;
    int n;
    while(t--)
    {
        cin>> n;
        vector<int> a(n+1);
        vector<int> prefix(n+1,0);
        int ans=0;
        for(int i =1; i<=n; i++)
        {
            cin>> a[i];
            // prefix[i] = max(prefix[i], a[i]);
            if(i+a[i]<= n){
                prefix[i+a[i]] = max(prefix[i]+a[i], prefix[i+a[i]]);
            }
            else{
                ans = max(ans,prefix[i]+a[i]);
            }
            // cout<< prefix[i]<< " ";
        }
        cout<< ans<< endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>> n;
    string s;
    int cost;
    int dp[2][2][2];
    fill(&dp[0][0][0], &dp[0][0][0] + 2 * 2 * 2, 300001);
    for(int i =1; i<=n; i++)
    {
        cin>> cost >> s;
        int a=0, b=0, c=0;
        for(int j =0; j< s.size(); j++)
        {
            if(s[j] == 'A') a=1;
            else if(s[j]== 'B') b=1;
                else c=1;
        }
        dp[a][b][c] = min(cost, dp[a][b][c]);
    }

    int ans = dp[1][1][1];
    ans = min(ans, dp[1][0][0]+dp[0][1][1]);
    ans = min(ans, dp[0][1][0] + dp[1][0][1]);
    ans = min(ans, dp[0][0][1] + dp[1][1][0]);

    ans = min(ans, dp[1][1][0] + dp[0][1][1]);
    ans = min(ans, dp[1][0][1] + dp[0][1][1]);
    ans = min(ans, dp[1][0][1] + dp[1][1][0]);

    ans = min(ans, dp[1][0][0] + dp[0][1][0] + dp[0][0][1]);
     // ! a b c ab ac bc abc

     if(ans == 300001) cout<<-1;
     else
     cout<< ans;
}
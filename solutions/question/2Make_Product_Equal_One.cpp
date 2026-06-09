#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>> n;
    long long int ans =0;
    int check=1;
    int temp;
    int countzero=0;
    for(int i=0; i<n; i++)
    {
        cin>> temp;

        if(temp != 0)
        ans += abs(1 - abs(temp));
        else
        {
            ans += 1;
            countzero++;
        }
        // cout<< temp << " " << abs(1 - abs(temp))<< endl;
        if(temp<0){
            check *= -1;
        }
    }

    if (check == -1)
    {
        if(countzero ==0)
        cout<< ans+2;
        else{
            cout<< ans;
        }
    }
    else
    cout<< ans;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>> n >>m;
    int a[n];
    a[0]= 0;
    cin>> a[1];
    for(int i =2; i<= n; i++)
    {
        cin>> a[i];
        a[i]+= a[i-1];
    }

    int m1,m2;
    long long int ans=0;
    for(int i =0; i< m; i++)
    {
        cin>> m1 >> m2;
        int temp = a[m2] - a[m1-1];

        if(temp >0)
        {
            ans+= temp;
        }
    }
    cout<< ans;
}
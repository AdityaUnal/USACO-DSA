#include<bits/stdc++.h>
using namespace std;

int MOD = 998244353;

int main()
{
    int T;
    T = 1;
    while(T){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> rem(n, -1);
        int currSum = 0;
        rem[0] = 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            currSum += arr[i];
            rem[currSum%n] = i;
            ans += rem[currSum%n];
        }
        T--;
    }
    return 0;
}
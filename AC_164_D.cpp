#include<bits/stdc++.h>
using namespace std;

int MOD = 998244353;

int main()
{
    int T;
    T = 1;
    while(T){
        string s;
        cin>>s;
        int n = s.length();
        int N = 2019;
        vector<long long> prev(N,0);
        int currNum = 0;
        int res = 0;
        prev[0] = 1;
        long long pow = 1;
        for(int i = n-1;i >= 0; i--){
            int curr = s[i] - '0';
            // cout<<curr<<"Brooo"<<endl;
            currNum = (pow*curr + currNum)%N;
            // cout<<i<<" "<<pow<<" "<<currNum<<endl;
            // cout<<currNum<<endl;
            // if(prev[currNum] != 0){
            //     cout<<i<<" "<<prev[currNum]<<endl;
            // }
            pow = pow*10%N;
            prev[currNum] += 1;
            // cout<<prev[currNum]<<endl;
            // vector<int> temp = prev;
            // for(int idx = 1;idx < 2019;idx +=1){
            //     temp[(idx*10)%N] += prev[idx];
            //     // cout<<idx<<" "<<temp[(idx*10)%N]<<endl;
            // }
            // break;
            // prev = temp;
        }
        // cout<<res<<endl;
        for(int i = 0;i < 2019;i +=1){
            res += (prev[i]*(prev[i] - 1))/2;
        }
        cout<<res<<endl;
        T--;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int MOD = 998244353;

int main()
{
    int T = 1;
    // cin>>T;
    while(T){
        int n;
        int x = 0;    
        cin>>n;
        cin>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int> prefixSum(n + 1, 0);
        map<long long, int> mp;
        long long ans = 0;
        long long currSum = 0;
        // mp[0] = 1;
        for(int i = 0;i < n;i +=1){
            mp[currSum] += 1;
            currSum += arr[i];
            prefixSum[i + 1] = currSum;
            long long currSumMinusX = currSum - x;
            if(mp.find(currSumMinusX) != mp.end()){
                ans += mp[currSumMinusX];
            }

            // if(mp.find(-(currSum%n)) != mp.end() ){
            //     ans += mp[-(currSum%n)];
            // }
            // if(mp.find(-(currSum%n)) != mp.end() and (currSum%n) != 0){
            //     ans += mp[-(currSum%n)];
            // }
            // cout<<i<<" : ";
            // for(auto j:mp){
            //     cout<<j.first<<" "<<j.second<<" ; ";
            // }
            // cout<<endl;
            // cout<<"ans : "<<ans<<endl;
        }
        
        cout<<ans<<endl;
        T--;
    }
    return 0;
}
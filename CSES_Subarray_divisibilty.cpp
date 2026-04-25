#include<bits/stdc++.h>
using namespace std;

int MOD = 998244353;

int main()
{
    int T = 1;
    // cin>>T;
    while(T){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i] = arr[i]%n;
        }

        vector<int> prefixSum(n + 1, 0);
        unordered_map<long long, int> mp;
        long long ans = 0;
        // mp[0] = 1;
        for(int i = 0;i < n;i +=1){
            mp[(prefixSum[i]%n)] += 1;
            prefixSum[i + 1] = (prefixSum[i] + arr[i])%n;
            int currSum = prefixSum[i] + arr[i];
            int currSumMod = currSum%n;
            if(mp.find(currSumMod) != mp.end()){
                ans += mp[currSumMod];
            }
            else if(currSumMod != 0 and mp.find((n - currSumMod)%n) != mp.end() ){
                ans += mp[(n - currSumMod)%n];
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
#include<bits/stdc++.h>
using namespace std;

int MOD = 998244353;

int main()
{
    int T;
    cin>>T;
    while(T){
        int n;
        cin>>n;
        string s;
        cin >>s;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = s[i] - '0';
        }
        int currSum = 0;
        vector<int> prefixSum(n + 1, 0);
        unordered_map<long long, int> mp;
        long long ans = 0;
        // mp[0] = 1;
        for(int i = 0;i < n;i +=1){
            mp[prefixSum[i] - i] += 1;
            prefixSum[i + 1] = prefixSum[i] + arr[i];
            int currSum = prefixSum[i] + arr[i];
            if(mp.find(currSum - i - 1) != mp.end()){
                ans += mp[currSum - i - 1];
            }
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
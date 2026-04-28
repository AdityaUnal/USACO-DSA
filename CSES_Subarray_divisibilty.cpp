#include<bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

int main()
{
    long long T = 1;
    // cin>>T;
    while(T){
        long long n;
        cin>>n;

        vector<long long> arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
            // arr[i] = arr[i]%n;
        }
        vector<long long> mods(n,0);
        mods[0] = 1;
        long long ans = 0;
        long long sum = 0;
        for(long long i = 0;i < n;i +=1){
            sum = (sum + arr[i])%n;
            sum = ((sum)%n + n)%n;
            mods[sum] +=1;
        }
        for(long long i:mods){
            ans += (i*(i - 1))/2;
        }
        cout<<ans<<endl;
        T--;
    }
    return 0;
}
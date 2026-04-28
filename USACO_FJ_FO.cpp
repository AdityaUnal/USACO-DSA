#include<bits/stdc++.h>
// using namespace std;

int MOD = 998244353;

int main()
{
    int T;
    cin>>T;
    while(T){
        int n,m;
        std::cin>>n>>m;
        std::vector<int> a(n);
        std::for(int i = 0;i < n;i +=1){
            std::cin(a[i]);
        }
        int res = INT_MAX;
        std::for(int i = -8;i <= 8;i +=1 ){
            std::vector<int> temp(a);
            std::for(int i = 0;i < n;i +=1){
                temp[i] = a[i] - x;
                temp[i] = (temp[i])%9;
            }
            int sum = 0;
            std::for(int i : temp){
                sum += min(i,n - i);
            }
            res = min(res,sum);
        }
        T--;
    }
    return 0;
}
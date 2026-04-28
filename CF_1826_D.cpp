#include<bits/stdc++.h>
// using namespace std;

int MOD = 998244353;


int main()
{
    int T;
    std::cin>>T;
    while(T){
        int n(0);
        std::cin>>n;
        std::vector<int> b(n,0);
        for(int i = 0;i < n;i +=1){
            std::cin>>b[i];
        }
        std::vector<int> greatest(3,0);
        std::vector<int> start(n);
        std::vector<int> end(n);
        int res = INT_MAX;
        for(int i = 0;i < n;i +=1){
            if(i > 1){
                greatest[2] = std::max(greatest[2],greatest[1] + b[i] - i);
            }
            if(i > 0){
                greatest[1] = std::max(greatest[1], greatest[0] + b[i]);
            }
            greatest[0] = std::max(greatest[0],b[i] + i);
        }
        std::cout<<greatest[2]<<std::endl;
        T--;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int MOD = 998244353;

int findmin(vector<int> arr){
    // for(int i = 0;i < 26;i +=1){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int maxFreq = 0;
    int maxChar = 0;
    for(int i = 0;i < 26;i +=1){
        maxChar = (maxFreq < arr[i]) ? i:maxChar;
        maxFreq = max(arr[i],maxFreq);
    }
    int res = 0;
    for(int i = 0;i < 26;i +=1){
        if(i != maxChar){
            res +=arr[i]; 
        }
    }
    // cout<<"res : "<<res<<endl;
    return res;
}

vector<int> addArray(vector<int> arr1, vector<int> arr2){
    vector<int> res(26,0);
    for(int i = 0;i < 26;i +=1){
        res[i] = arr1[i] + arr2[i];
    }
    return res;
}

int main()
{
    int T;
    cin>>T;
    // vector<int> results;
    while(T){
        int n;
        string s;
        cin>>n;
        cin>>s;
        if(n%2){
            vector<int> preOdd(26,0);
            vector<int> preEven(26,0);
            vector<vector<int>> postOdd(n,vector<int>(26,0));
            vector<vector<int>> postEven(n,vector<int>(26,0));
            // vector<int> postEven(26,0);
            int res = INT_MAX;
            for(int i = n - 1;i > 0;i--){
                postOdd[i-1] = postOdd[i];
                postEven[i-1] = postEven[i];
                if(i%2){
                    postOdd[i - 1][s[i] - 'a'] +=1;
                }
                else{
                    postEven[i - 1][s[i]-'a'] +=1;
                }
            }
            for(int i = 0;i < n;i +=1){
                // cout<<i<<" : "<<findmin(preOdd)+findmin(preEven)+findmin(postOdd[i])+findmin(postEven[i]) + 1<<endl;
                // cout<<i<<" : "<<findmin(preOdd)<<" "<<findmin(preEven)<<" "<<findmin(postOdd[i])<<" "<<findmin(postEven[i])<<endl;
                // cout<<i<<" : "<<printArray(preOdd)<<printArray(preEven)<<printArray(postOdd[i])<<printArray(postEven[i])<<endl;
                // cout<<i<<" : ";
                res = min(res,findmin(addArray(preOdd,postEven[i]))+findmin(addArray(preEven, postOdd[i])) + 1);
                if(i%2){
                    preOdd[s[i] - 'a'] +=1;
                }
                else{
                    preEven[s[i]-'a'] +=1;
                }
            }
            
            // results.push_back(res);
            cout<<res<<endl;
        }
        else{
            vector<int> odd(26,0);
            vector<int> even(26,0);
            for(int i = 0;i < n;i +=1){
                if(i%2){
                    odd[s[i] - 'a'] +=1;
                }
                else{
                    even[s[i]-'a'] +=1;
                }
            }
            // results.push_back(findmin(odd) + findmin(even));
            cout<<findmin(odd) + findmin(even)<<endl;
        }
        T--;
    }
    // cout<<"Results :"<<endl;
    // for(int i:results){
    //     cout<<i<<endl;
    // }
    return 0;
}
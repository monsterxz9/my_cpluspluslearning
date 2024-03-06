#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,x;
    cin>>n>>x;
    vector<string> s;
    int count=0;
    for(int i=0;i<=n;i++){
        while(i%10){
            int a=i%10;
            if(a==x)count++;
            i=i%10;
        }
    }
    cout<<count;
}
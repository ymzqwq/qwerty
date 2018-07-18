#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,a[N],b[N],k,mx,ans;
 
void read(LL &x){
    char ch=getchar();x=0;int w=1;
    for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=w;
}
 
int check(LL x){
    LL ans=0;
    for(int i=1;i<=n;i++) ans+=max(1LL*0,a[i]*x-b[i]);
    return ans<=k;
}
 
int main(){
    read(n);read(k);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++){
        read(b[i]);
        mx=max(mx,(b[i]+k)/a[i]);
    }
    LL L=0,r=mx;
    while(L<=r){
        LL mid=(L+r)/2;
        if (check(mid)) ans=mid,L=mid+1;
         else r=mid-1;
    }
    cout<<ans;
    return 0;
}

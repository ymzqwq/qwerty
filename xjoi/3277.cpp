#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,a[N],f[N],ans=-2e9;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) f[i]=max(0,f[i-1])+a[i],ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}

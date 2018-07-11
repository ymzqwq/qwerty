#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=51;
int n,a[N],ans;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	ans=max(a[2]-a[1],a[n]-a[n-1]);
	for(int i=3;i<=n;i+=2) ans=max(ans,a[i]-a[i-2]);
	for(int i=4;i<=n;i+=2) ans=max(ans,a[i]-a[i-2]);
	cout<<ans;
	return 0;
}

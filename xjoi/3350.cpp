#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,a[N],f[N][2],mx;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++){
		LL x;read(x);
		mx=max(mx,x);
		a[x]+=x;
	}
	for(int i=1;i<=mx;i++){
		f[i][0]=max(f[i-1][1],f[i-1][0]);
		f[i][1]=f[i-1][0]+a[i];
	}
	cout<<max(f[mx][0],f[mx][1]);
	return 0;
}

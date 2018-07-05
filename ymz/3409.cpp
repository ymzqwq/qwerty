#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=101;

LL n,k,c[31][31],ans=1;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(k);
	if (k>n) {
		cout<<'0';
		return 0;
	}
	for(int i=n;i>n-k;i--) ans*=i;
	c[0][0]=1;
	for(int i=1;i<=n+1;i++)
	 for(int j=1;j<=n+1;j++)
	  c[i][j]=c[i-1][j]+c[i-1][j-1];
	cout<<ans*c[n+1][k+1];
	return 0;
}

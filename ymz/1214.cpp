#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=201;
int n,m,a[N][N],f[N],sum,ans=-2e9;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++) 
	 for(int j=1;j<=m;j++)
	  read(a[i][j]);
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++){
			sum=-2e9;
			for(int k=1;k<=m;k++) f[k]+=a[j][k];
			for(int k=1;k<=m;k++) sum=max(0,sum)+f[k],ans=max(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}

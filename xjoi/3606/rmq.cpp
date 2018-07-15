#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,a[N],f[N][20],log_2[N];
LL ans;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int getmin(int L,int r){
	int Lg=log_2[r-L+1];
	if (a[f[r][Lg]]<a[f[L+(1<<Lg)-1][Lg]]) return f[r][Lg];
	 else return f[L+(1<<Lg)-1][Lg];
}

void getans(int L,int r){
	if (L>r) return;
	int x=getmin(L,r);
	ans=max(ans,1LL*a[x]*(r-L+1));
	if (L==r) return;
	getans(L,x-1);getans(x+1,r);
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++) log_2[i]=log_2[i>>1]+1;
	for(int i=1;i<=n;i++) f[i][0]=i;
	for(int i=1;i<=log_2[n];i++)
	 for(int j=1<<i;j<=n;j++)
	  if (a[f[j][i-1]]<a[f[j-(1<<i>>1)][i-1]]) f[j][i]=f[j][i-1];
	   else f[j][i]=f[j-(1<<i>>1)][i-1];
	getans(1,n);
	cout<<ans;
	return 0;
}

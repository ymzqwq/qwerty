#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
const int M=13;
int n,mt;
LL f[N][M];
struct data{
	int x,t;
}a[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int cmp(const data q,const data w){
	if (q.t==w.t) return q.x<w.x;
	return q.t<w.t;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i].x),read(a[i].t),f[a[i].t][a[i].x+1]++,mt=max(mt,a[i].t);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=11;i++) if (i!=6) f[0][i]=-n-1;
	for(int i=1;i<=mt;i++)
	 for(int j=1;j<=11;j++)
	  f[i][j]+=max(f[i-1][j],max(f[i-1][j-1],f[i-1][j+1]));
	LL ans=0;
	for(int i=1;i<=11;i++) ans=max(ans,f[mt][i]);
	cout<<ans;
	return 0;
}

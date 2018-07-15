#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
LL n,m,a[N][N],k,p,sr[N*N],sc[N*N],ans;
priority_queue<LL> row,col;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(m);read(k);read(p);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  read(a[i][j]);
	for(int i=1;i<=n;i++){
		LL sum=0;
		for(int j=1;j<=m;j++) sum+=a[i][j];
		row.push(sum);
	}
	for(int j=1;j<=m;j++){
		LL sum=0;
		for(int i=1;i<=n;i++) sum+=a[i][j];
		col.push(sum);
	}
	for(int i=1;i<=k;i++){
		LL r=row.top(),c=col.top();
		sr[i]=sr[i-1]+r;sc[i]=sc[i-1]+c;
		r-=p*m;c-=p*n;
		row.pop();col.pop();
		row.push(r);col.push(c);
	}
	ans=-1e18;
	for(int i=0;i<=k;i++){
		int j=k-i;
		ans=max(ans,sr[i]+sc[j]-i*j*p);
	}
	cout<<ans;
	return 0;
}

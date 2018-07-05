#include<bits/stdc++.h>
using namespace std;
const int N=7;
int n,m,a[N][N],s[N],ans,sum;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void dfs(int k){
	if (k>m) { ans=max(ans,sum);return; }
	dfs(k+1);
	for(int i=1;i<=n;i++)
	 if (s[i]<2){
	 	sum+=a[i][k];
	 	s[i]++;
	 	dfs(k+1);
	 	s[i]--;
	 	sum-=a[i][k];
	 }
	for(int i=1;i<n;i++)
	 for(int j=i+1;j<=n;j++)
	  if (s[i]<2&&s[j]<2){
	  	sum+=a[i][k]+a[j][k];
	  	s[i]++;s[j]++;
	  	dfs(k+1);
	  	s[i]--;s[j]--;
	  	sum-=a[i][k]+a[j][k];
	  }
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  read(a[i][j]);
	dfs(1);
	cout<<ans;
	return 0;
}

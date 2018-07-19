#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=21;
int n,a[N],b[N],f[N][N][N][N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int i,int j,int k,int l){
	if (j<i&&l<k) return;
	if (f[i][j][k][l]!=0) return;
	if ((j-i+1+l-k+1)%2==0){
		if (i<=j){
			dfs(i+1,j,k,l);
			f[i][j][k][l]=max(f[i][j][k][l],f[i+1][j][k][l]+a[i]);
			dfs(i,j-1,k,l);
			f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+a[j]);
		}
		if (k<=l){
			dfs(i,j,k+1,l);
			f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k+1][l]+b[k]);
			dfs(i,j,k,l-1);
			f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+b[l]);
		}
	} else{
		f[i][j][k][l]=2e9;
		if (i<=j){
			dfs(i+1,j,k,l);dfs(i,j-1,k,l);
			f[i][j][k][l]=min(f[i+1][j][k][l],f[i][j-1][k][l]);
		}
		if (k<=l){
			dfs(i,j,k+1,l);dfs(i,j,k,l-1);
			f[i][j][k][l]=min(f[i][j][k][l],f[i][j][k+1][l]);
			f[i][j][k][l]=min(f[i][j][k][l],f[i][j][k][l-1]);
		}
	}
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	dfs(1,n,1,n);
	/*for(int o=1;o<=2*n;o++)
	 for(int i=1;i<=max(1,n-o+1);i++)
	  for(int j=0;j<=o;j++)
	   for(int k=1;k<=max(1,n-(o-j)+1)*/
	printf("%d",f[1][n][1][n]);
	return 0;
}

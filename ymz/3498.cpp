#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=21;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int n,m,sum,a[N][N],f[N*N][N][N],ans;
char c[N][N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  if (c[i][j]=='#') sum++;
	   else a[i][j]=1;
	if (sum<n+m-1){
		cout<<"-1";
		return 0;
	}
	memset(f,0x3f,sizeof f);
	f[0][1][1]=a[1][1];
	ans=n*m;
	for(int o=1;o<=sum-(!a[1][1]);o++){
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=m;j++)
		  for(int k=0;k<4;k++){
		  	int x=i+dx[k],y=j+dy[k];
		  	if (x>0&&x<=n&&y>0&&y<=m)
		  	 f[o][i][j]=min(f[o][i][j],f[o-1][x][y]+a[i][j]);
		  }
		ans=min(ans,f[o][n][m]);
	}
	cout<<ans;
	return 0;
}

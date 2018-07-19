#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=11;
const int M=60000;
int n,m,f[M][N],a[N][N],po[N];

void read(int &x){//scanf("%d",&x);
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

inline int pd(int i,int j){
	i/=po[j];
	return i%3;
}

int qs1(int i){
	for(int j=0;j<n;j++)
	 if (!pd(i,j)) return 0;
	return 1;
}

int main(){
	po[0]=1;
	for(int i=1;i<N;i++) po[i]=po[i-1]*3;
	while(scanf("%d%d",&n,&m)>0){
		memset(a,0x3f,sizeof a);
		for(int i=1;i<=m;i++){
			int x,y,z;
			read(x);read(y);read(z);
			x--;y--;
			if (z<a[x][y]) a[x][y]=a[y][x]=z;
		}
		memset(f,0x3f,sizeof f);
		for(int i=0;i<n;i++) f[po[i]][i]=0;
		for(int i=1;i<po[n]-1;i++)
		 for(int j=0;j<n;j++)
		  if (pd(i,j))
		   for(int k=0;k<n;k++)
		    if (pd(i,k)&&j!=k)
		     f[i][j]=min(f[i][j],f[i-po[j]][k]+a[k][j]);
		int ans=2e9;
		for(int i=1;i<po[n]-1;i++)
		 if (qs1(i))
		  for(int j=0;j<n;j++)
		   ans=min(ans,f[i][j]);
		if (ans>1e9) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}

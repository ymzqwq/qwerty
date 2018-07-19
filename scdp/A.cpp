#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=11;
int n,a[N][N],f[1<<N][N],d[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	while(1){
		read(n);
		if (n==0) break;
		for(int i=0;i<=n;i++)
		 for(int j=0;j<=n;j++)
		  read(a[i][j]);
		for(int i=0;i<=n;i++)
		 for(int j=0;j<=n;j++)
		  for(int k=0;k<=n;k++)
		   a[k][j]=min(a[k][j],a[k][i]+a[i][j]);
		memset(f,0x3f,sizeof f);
		f[1][0]=0;
		for(int i=1;i<(1<<n+1);i++)
		 for(int j=0;j<=n;j++)
		  if (i&(1<<j)){
		 	for(int k=0;k<=n;k++)
		 	 //if ((i&(1<<k))==0)
		 	  f[i|(1<<k)][k]=min(f[i|(1<<k)][k],f[i][j]+a[j][k]);
		  }
		memset(d,0x3f,sizeof d);
		d[0]=0;
		for(int i=1;i<=n;i++)
		 for(int j=0;j<i;j++)
		  d[i]=min(d[i],d[j]+f[((1<<i+1)-(1<<j+1))|1][0]);
		printf("%d\n",d[n]);
	}
	return 0;
}

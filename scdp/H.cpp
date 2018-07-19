#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=4;
const int M=60000;
int T,n,f[1<<N][N],Nex[1<<N][N],a[N][N];
string c[N];

void read(int &x){//scanf("%d",&x);
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void match(int x,int y){
	a[x][y]=max(strlen(c[x]+1),strlen(c[y]+1));
	for(int i=1;i<=strlen(c[x]+1);i++)
	 for(int j=i;j<=strlen(c[x]+1)+1;j++){
	 	if (j==strlen(c[x]+1)+1){
	 		a[x][y]=i-1;
	 		return;
	 	}
	 	if (j-i+1>strlen(c[y]+1)) break;
	 	if (c[x][j]!=c[y][j-i+1]) break;
	 }
}

int main(){
	read(T);
	while(T--){
		read(n);
		for(int i=0;i<n;i++) cin>>c[i];
		sort(c,c+n);
		for(int i=0;i<n;i++)
		 for(int j=0;j<n;j++)
		  match(i,j);
		memset(f,0x3f,sizeof f);
		for(int i=0;i<n;i++) f[1<<i][i]=c[i].size();
		for(int i=1;i<(1<<n);i++)
		 for(int j=0;j<n;j++)
		  if (i&(1<<j))
		   for(int k=0;k<n;k++)
		    if ((i&(1<<k))&&k!=j)
		     if (f[i^(1<<j)][k]+a[j][k]<f[i][j]){   //!!恶心的细节等下再搞
		     	f[i][j]=f[i^(1<<j)][k]+a[j][k];
		     	Nex[i][j]=k;
		     }
		int x=0;
		for(int i=0;i<n;i++)
		 if (f[(1<<n)-1][i]<f[(1<<n)-1][x]) x=i;
		int i=(1<<n)-1;
		cout<<f[i][x]<<endl<<c[x]);
		while(Nex[i][x]){
			for(int j=0;j<a[x][Nex[i][x]];j++)
			 printf("%c",c[Nex[i][x]][j]);
			i^=1<<x;
			x=Nex[i^(1<<x)][x];
		}
	}
	return 0;
}

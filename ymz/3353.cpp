#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,a[N],f[N][2],be[N];
char c[N];

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int ppd(int Lx,int rx,int q,int Ly,int ry,int w){
	int p1=Lx,p2=Ly;
	while(p1!=rx&&p2!=ry){
		if (c[p1]<c[p2]) return 1;
		if (c[p1]>c[p2]) return 0;
		p1+=q;p2+=w;
	}
	if (c[p1]<c[p2]) return 1;
	if (c[p1]>c[p2]) return 0;
	return abs(Lx-rx)<=abs(Ly-ry);
}

int pd(int x,int bx,int y,int by){
	int Lx=be[x],rx=be[x+1]-1,Ly=be[y],ry=be[y+1]-1,q=1,w=1;
	if (bx) Lx^=rx^=Lx^=rx,q=-1;
	if (by) Ly^=ry^=Ly^=ry,w=-1;
	return ppd(Lx,rx,q,Ly,ry,w);
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++){
		be[i]=strlen(c);
		gets(c+strlen(c));
	}
	be[n+1]=strlen(c);
	memset(f,0x7f/2,sizeof f);
	f[1][1]=a[1];f[1][0]=0;
	for(int i=2;i<=n;i++)
	 for(int j=0;j<2;j++)
	  for(int k=0;k<2;k++)
	   if (pd(i-1,k,i,j)) f[i][j]=min(f[i][j],f[i-1][k]+(j?a[i]:0));
	int ans=min(f[n][0],f[n][1]);
/*	if (ans>1e15) cout<<"-1"<<endl;
	 else cout<<ans<<endl;*/
	int a,b,c,d;while(scanf("%d%d%d%d",&a,&b,&c,&d)==4) printf("%d\n",pd(a,b,c,d));
	return 0;
}

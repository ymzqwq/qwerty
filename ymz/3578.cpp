#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,m,f[N],a[N],ans;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int gf(int x){ return f[x]==x?x:f[x]=gf(f[x]); }

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i]),f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,fy,fx;
		read(x);read(y);
		fx=gf(x);fy=gf(y);
		f[fx]=fy;
	}
	for(int i=1;i<=n;i++){
		int fx=gf(i),fy=gf(a[i]);
		if (fx==fy) ans++;
	}
	cout<<ans;
	return 0;
}

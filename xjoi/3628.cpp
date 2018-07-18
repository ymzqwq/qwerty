#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n,m,f[N],mn,mx;
struct data{
	int u,v,w;
}a[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int cmp(const data &q,const data &w){
	return q.w<w.w;
}

int gf(int x) { return f[x]==x?x:f[x]=gf(f[x]); }

int main(){
	read(n);read(m);
	for(int i=1;i<=m;i++){
		read(a[i].u);read(a[i].v);read(a[i].w);
	}
	sort(a+1,a+1+m,cmp);
	
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int fx=gf(a[i].u),fy=gf(a[i].v);
		if (fx!=fy){
			f[fx]=fy;
			mn+=a[i].w;
		}
	}
	
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=m;i;i--){
		int fx=gf(a[i].u),fy=gf(a[i].v);
		if (fx!=fy){
			f[fx]=fy;
			mx+=a[i].w;
		}
	}
	
	f[0]=0;f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
		if (f[i]>=mn&&f[i]<=mx){
			printf("Yes");
			return 0;
		}
		if (f[i]>mx) break;
	}
	printf("No");
	return 0;
}

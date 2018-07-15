#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=10;
int n,m,a[N],b[N],f[1<<N];
queue<int> h;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int bfs(){
	h.push(0);
	while(!h.empty()){
		int st=h.front();
		h.pop();
		if (f[st]>=m){
			int sum=0;
			for(int i=0;i<n;i++)
			 if (st&(1<<i)) sum++;
			return sum;
		}
		for(int i=1;i<=n;i++)
		 if ((st&(1<<i-1))==0){
		 	int x=st|(1<<i-1),w=0;
		 	if (m-f[st]<=b[i]) w=f[st]+2*a[i];
		 	 else w=f[st]+a[i];
		 	if (!f[x]) h.push(x);
		 	f[x]=max(f[x],w);
		 }
	}
	return -1;
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i]),read(b[i]);
	cout<<bfs();
	return 0;
}

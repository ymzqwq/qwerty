#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,T,f[N*10],v[N],w[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(T);read(n);
	for(int i=1;i<=n;i++) read(v[i]),read(w[i]);
	for(int i=1;i<=n;i++)
	 for(int j=T;j>=v[i];j--)
	  f[j]=max(f[j],f[j-v[i]]+w[i]);
	cout<<f[T];
	return 0;
}

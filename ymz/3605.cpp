#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,a[N],f[N],sum;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int x){
	if (f[x]) return;
	if (a[x-1]<a[x]&&x>1) dfs(x-1),f[x]=max(f[x],f[x-1]+1);
	if (a[x+1]<a[x]&&x<n) dfs(x+1),f[x]=max(f[x],f[x+1]+1);
	if (!f[x]) f[x]=1;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	 if (!f[i]) dfs(i);
	for(int i=1;i<=n;i++) if (!f[i]) sum++;else sum+=f[i];
	cout<<sum;
	return 0;
}

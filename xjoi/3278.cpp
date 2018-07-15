#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=101;
const int M=10000001;
int n,a[N],f[M],s,ans;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]),s+=a[i];
	f[0]=1;
	for(int i=1;i<=n;i++)
	 for(int j=s;j>=a[i];j--) if (f[j-a[i]]) f[j]=1;
	ans=s;
	for(int i=0;i<=s/2;i++) if (f[i]&&s-i-i<ans) ans=s-i-i;
	cout<<ans;
	return 0;
}

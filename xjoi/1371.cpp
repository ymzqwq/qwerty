#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,a[N],f[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	for(int i=2;i<=n;i++)
	 for(int j=1;j<i;j++)
	  if (i%j==0) a[i]+=j;
	for(int i=2;i<=n;i++)
	 for(int j=n;j>=i;j--)
	  f[j]=max(f[j],f[j-i]+a[i]);
	cout<<f[n];
	return 0;
}

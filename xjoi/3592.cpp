#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int n,a[N],f[N],nex[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]),f[i]=1;
	f[0]=1;
	for(int i=n-1;i>=0;i--)
	 for(int j=i+1;j<=n;j++)
	  if (a[i]<a[j]){
	  	if (f[j]+1>f[i]){
	  		f[i]=f[j]+1;
	  		nex[i]=j;
	  	} else if (f[j]+1==f[i]&&a[j]<a[nex[i]]) nex[i]=j;
	  }
	for(int i=0;nex[i]!=0;i=nex[i]) printf("%d ",a[nex[i]]);
	return 0;
}

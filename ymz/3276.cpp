#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int n,a[N],f[N];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=1e5;
	for(int i=1;i<=n+1;i++)
	 for(int j=0;j<i;j++)
	  if (a[j]<a[i]) f[i]=max(f[i],f[j]+1);
	cout<<f[n+1]-1;
	return 0;
}

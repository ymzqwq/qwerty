#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int n,a[N],f[N][2];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	f[1][1]=a[1];
	for(int i=2;i<=n;i++){
		f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
		f[i][0]=min(f[i-1][1],f[i-2][1]);
	}
	cout<<min(f[n][0],f[n][1]);
	return 0;
}

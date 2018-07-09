#include<bits/stdc++.h>
using namespace std;
const int N=367;
int n,ans,a[N],mo[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	for(int i=1;i<=12;i++) mo[i]+=mo[i-1];
	for(int i=1;i<=n;i++){
		int mon,da;
		read(mon);read(da);
		a[i]=mo[mon-1]+da;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) ans=max(ans,a[i]-a[i-1]-1);
	ans=max(ans,366-a[n]);
	printf("%d",int(ans*86400/366.0+0.5));
	return 0;
}

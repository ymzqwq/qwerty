#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=10000001;
int n,sqr,ans;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	cin>>n;
	sqr=int(sqrt(n));
	ans=n;
	for(int i=2;i<=sqr;i++)
	 if (n%i==0){
	 	while(n%i==0) n/=i;
	 	ans=ans/i*(i-1);
	 }
	if (n>1) ans=ans/n*(n-1);
	cout<<ans;
	return 0;
}

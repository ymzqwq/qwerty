#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
const int p=1e9+7;
LL n,m,k;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

LL power(LL a,LL n){
	LL sum=a,ans=1;
	while(n){
		if (n&1) ans=ans*sum%p;
		n>>=1;
		sum=sum*sum%p;
	}
	return ans;
}

int main(){
	cin>>n>>m>>k;
	if (n>m) n^=m^=n^=m;
	if (k==-1&&(n%2!=m%2)){
		printf("0");
		return 0;
	}
	n=(n-1)%(p-1);m=(m-1)%(p-1);
	cout<<power(2,n*m%(p-1));
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,ans,sum=1;

void read(LL &x){
	char ch=getchar();x=0;int flag=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())
	 if (flag) x=(x<<3)+(x<<1)+1;
	  else if (ch<'2') x=(x<<3)+(x<<1)+ch-'0';
	   else{
	   	  flag=1;
	   	  x=(x<<3)+(x<<1)+1;
	   }
}

int main(){
	read(n);
	while(n){
		if (n&1) ans+=sum;
		sum<<=1;
		n/=10;
	}
	cout<<ans;
	return 0;
}

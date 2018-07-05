#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5001;
int n,m,h[N],L;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++){
		int x,j;read(x);
		if (x>=h[L]) h[++L]=x;
		 else{
		 	for(j=L;j;j--) if (x>=h[j]) break;
		 	h[j+1]=x;
		 }
	}
	cout<<n-L;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int a,b,x,y,g;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void exgcd(int a,int b,int &g,int &x,int &y){
	if (b==0) { g=a;x=1;y=0;return; }
	exgcd(b,a%b,g,y,x);
	y-=a/b*x;
}

int main(){
	read(a);read(b);
	exgcd(a,b,g,x,y);
	if (g!=1) printf("-1");
	 else printf("%d",(x+b)%b);
	return 0;
}

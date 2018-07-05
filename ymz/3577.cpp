#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2001;
int n,L,r;
char c[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int pd(int L,int r){
	for(;L<r;L++,r--){
		if (c[L]<c[r]) return 1;
		if (c[L]>c[r]) return 0;
	}
	return 1;
}

int main(){
	read(n);
	scanf("%s",c);
	L=0;r=strlen(c)-1;
	while(L<=r)
	 if (pd(L,r)) printf("%c",c[L]),L++;
		else printf("%c",c[r]),r--;
	return 0;
}

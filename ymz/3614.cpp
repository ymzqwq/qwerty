#include<bits/stdc++.h>
using namespace std;
const int p1=5000007;
const int p2=1e7+13;
int n,x;
bool b1[p1],b2[p2];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(x);
		if (b1[x%p1]&&b2[x%p2]) printf("ignored\n");
		 else{
		 	b1[x%p1]=1;
		 	b2[x%p2]=1;
		 	printf("accepted\n");
		 }
	}
	return 0;
}

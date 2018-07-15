#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,ans,s[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int work(){
	int x,ch=getchar();
	while(ch>0&&ch!='\n'){
		if (ch=='<') x=0;if (ch=='>') x=1;
		if (ch=='{') x=2;if (ch=='}') x=3;
		if (ch=='[') x=4;if (ch==']') x=5;
		if (ch=='(') x=6;if (ch==')') x=7;
		if (x&1){
			if (n==0) return -1;
			if (x-1!=s[n]) ans++;
			n--;
		} else s[++n]=x;
		ch=getchar();
	}
	if (n!=0) return -1;
	return ans;
}

int main(){
	int ans=work();
	if (ans==-1) printf("Impossible");
	 else cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
int n,a[N][N],f[N][N];
char c[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void getnum(int L,int r){
	for(int i=L;i<=r;i++) a[L][r]=a[L][r]*10+c[i]-'0';
}

void cal(int L,int r){
	int sum=0,w=1;
	if (c[L]=='('){
		for(int i=L;i<=r;i++)
		 if (c[i]=='(') sum++;
		  else if (c[i]==')'){
		  	sum--;
		  	if (sum==0&&i!=r) w=0;
		  }
		if (w){
			cal(L+1,r-1);
			f[L][r]=f[L+1][r-1];
			a[L][r]=a[L+1][r-1];
			return;
		}
	}
	sum=0;w=L-1;
	for(int i=L;i<=r;i++)
	 if (c[i]=='(') sum++;
	  else if (c[i]==')') sum--;
	   else if (c[i]=='+'&&sum==0)
	    { w=i;break; }
	if (w>=L){
		cal(L,w-1);cal(w+1,r);
		a[L][r]=a[L][w-1]+a[w+1][r];
		f[L][r]=f[L][w-1]+f[w+1][r]+1;
		return;
	}
	if (c[L]!='M'){
		getnum(L,r);
		return;
	}
	sum=0;w=L-1;
	for(int i=L;i<=r;i++)
	 if (c[i]=='(') sum++;
	  else if (c[i]==')') sum--;
	   else if (c[i]==','&&sum==1)
	    { w=i;break; }
	cal(L+4,w-1);cal(w+1,r-1);
	a[L][r]=max(a[L+4][w-1],a[w+1][r-1]);
	f[L][r]=(f[L+4][w-1]+f[w+1][r-1])*2;
}

int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	cal(1,n);
	printf("%d %d",a[1][n],f[1][n]);
	return 0;
}

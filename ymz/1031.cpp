#include<bits/stdc++.h>
using namespace std;
const int N=101;
char c[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int isc(int x){ return c[x]=='+'||c[x]=='-'||c[x]=='*'||c[x]=='/'||c[x]=='^'; }

double js(double a,double b,char x){
	if (x=='+') return a+b;
	if (x=='-') return a-b;
	if (x=='*') return a*b;
	if (x=='/') return a/b;
	if (x=='^') return pow(a,b);
}

int prio(char x){
	if (x=='+'||x=='-') return 1;
	if (x=='*'||x=='/') return 2;
	if (x=='^') return 3;
	return 4;
}

double cnum(int L,int r){
	double x=0.0,num=1.0;int i;
	for(i=L;c[i]>='0'&&c[i]<='9'&&i<=r;i++)
	 x=x*10.0+c[i]-'0';
	for(i++;i<=r;i++){
		num/=10.0;
		x+=num*(c[i]-'0');
	}
	return x;
}

double cal(int L,int r){
	int mid=L,cnt=0,flag=0;
	if (c[L]=='('){
		int i,cnt=1;
		for(i=L+1;i<=r;i++){
			if (cnt==0) break;
			if (c[i]=='(') cnt++;
			if (c[i]==')') cnt--;
		}
		if (i>r) return cal(L+1,r-1);
	}
	for(int i=L;i<=r;i++){
		if (c[i]=='(') cnt++;
		if (c[i]==')') cnt--;
		if (isc(i)){
			flag=1;
			if (cnt==0&&prio(c[i])<=prio(c[mid])) mid=i;
		}
	}
	if (!flag) return cnum(L,r);
	return js(cal(L,mid-1),cal(mid+1,r),c[mid]);
}

int main(){
	scanf("%s",c);
	printf("%.3lf",cal(0,strlen(c)-1));
	return 0;
}

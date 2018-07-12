#include<bits/stdc++.h>
using namespace std;
const int N=1001;
char c[N];
int s[N],b[N],len;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int isc(int x){ return c[x]=='+'||c[x]=='-'||c[x]=='*'||c[x]=='/'||c[x]=='^'; }

int js(int a,int b,char x){
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

int cnum(int L){
	return c[L]-'0';
}

void cal(int L,int r){
	int mid=L,cnt=0,flag=0;
	if (c[L]=='('){
		int i,cnt=1;
		for(i=L+1;i<=r;i++){
			if (cnt==0) break;
			if (c[i]=='(') cnt++;
			if (c[i]==')') cnt--;
		}
		if (i>r) { cal(L+1,r-1);return; }
	}
	for(int i=L;i<=r;i++){
		if (c[i]=='(') cnt++;
		if (c[i]==')') cnt--;
		if (isc(i)){
			flag=1;
			if (cnt==0&&prio(c[i])<=prio(c[mid])) mid=i;
		}
	}
	if (!flag){
		s[++len]=cnum(L);
		return;
	}
	cal(L,mid-1);cal(mid+1,r);
	s[++len]=c[mid];b[len]=1;
}

void print(){
	while(len>1){
		for(int i=1;i<=len;i++)
		 if (b[i]) printf("%c ",s[i]);
		  else printf("%d ",s[i]);
		int mid;
		for(mid=1;mid<=len;mid++)
		 if (b[mid]) break;
		s[mid-2]=js(s[mid-2],s[mid-1],s[mid]);
		for(int i=mid-1;i<=len-2;i++) s[i]=s[i+2],b[i]=b[i+2];
		len-=2;
		printf("\n");
	}
	printf("%d",s[1]);
}

int main(){
	scanf("%s",c);
	int n=strlen(c);
	cal(0,n-1);
	print();
	return 0;
}

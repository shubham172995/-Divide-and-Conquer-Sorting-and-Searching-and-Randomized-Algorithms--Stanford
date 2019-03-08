#include<bits/stdc++.h>
using namespace std;

int equate(string& a, string& b){
	int n1=a.length();
	int n2=b.length();
	if(n1==n2)
		return n1;
	else if(n1<n2){
		int l=n2-n1;
		string temp="";
		for(int i=0;i<l;i++)
			temp+=to_string(0);
		a=temp+a;
		return n2;
	}
	else{
		int l=n1-n2;
		string temp="";
		for(int i=0;i<l;i++)
			temp+=to_string(0);
		b=temp+b;
		return n1;
	}
}

int single(vector<int> x, vector<int> y){
	return x[0]*y[0];
}

vector<int> sum(vector<int> a, vector<int> b){
	int l1=a.size();
	int l2=b.size();
	vector<int> res;
	int carry=0;
	if(l1>l2)
		res.resize(l1+1);
	else if(l2>l1)
		res.resize(l2+1);
	else res.resize(l1+1);
	if(l1>l2){
		for(int i=l2-1;i>=0;i--){
			res[l1-(l2-i)]=a[l1-(l2-i)]+b[i];
			if(res[l1-(l2-i)]<=9)continue;
			else{
				carry=res[l1-(l2-i)]/10;
				res[l1-(l2-i)]=res[l1-(l2-i)]%10;
			}
		}
		for(int i=l1-l2-1; i>0;i--)
			res[i]=a[i];
	}
	else{
		for(int i=l1-1;i>=0;i--){
			res[l2-(l1-i)]=b[l2-(l1-i)]+a[i];
			if(res[l2-(l1-i)]<=9)continue;
			else{
				carry=res[l2-(l1-i)]/10;
				res[l2-(l1-i)]=res[l2-(l1-i)]%10;
			}
		}
		for(int i=l2-l1-1; i>0;i--)
			res[i]=b[i];
	}
	if(carry==0)return res;
	else res[0]=carry;
	return res;
}

vector<int> diff(vector<int> a, vector<int> b){
	int l1=a.size();
	int l2=b.size();
	vector<int> res;
	int carry=0;
	if(l1>l2)
		res.resize(l1+1);
	else if(l2>l1)
		res.resize(l2+1);
	else res.resize(l1+1);
	if(l1==l2){
		if(a[0]>b[0]){
			int carry=0;
			for(int i=l1-1;i>=0;i--){
				res[i]=a[i]-b[i];
				if(carry==0)continue;
				else res[i]-=1;
				if(res[i]<0){
					res[i]+=10;
					carry=1;
				}
				else if(res[i]>=0)carry=0;
			}
		}
		if(a[0]<=b[0]){
			int carry=0;
			for(int i=l1-1;i>=0;i--){
				res[i]=b[i]-a[i];
				if(carry==0)continue;
				else res[i]-=1;
				if(res[i]<0){
					res[i]+=10;
					carry=1;
				}
				else if(res[i]>=0)carry=0;
			}
		}
	}
	else if(l1<l2){
		int carry=0;
		for(int i=l1-1;i>=0;i--){
			res[l2-(l1-i)]=b[l2-(l1-i)]-a[i]-carry;
			if(res[l2-(l1-i)]<0){
				res[l2-(l1-i)]+=10;
				carry=1;
			}
			else carry=0;
		}
		for(int i=l2-l1-1; i>=0; i--){
			if(carry==0)res[i]=b[i];
			else{
				res[i]=b[i]-1;
				carry=0;
				if(res[i]<0){
					res[i]+=10;
					carry=1;
				}
			}
		}
	}
	else if(l2<l1){
		int carry=0;
		for(int i=l2-1;i>=0;i--){
			res[l1-(l2-i)]=a[l1-(l2-i)]-b[i]-carry;
			if(res[l1-(l2-i)]<0){
				res[l1-(l2-i)]+=10;
				carry=1;
			}
			else carry=0;
		}
		for(int i=l1-l2-1; i>=0; i--){
			if(carry==0)res[i]=a[i];
			else{
				res[i]=a[i]-1;
				carry=0;
				if(res[i]<0){
					res[i]+=10;
					carry=1;
				}
			}
		}
	}
}

vector<int> product(vector<int> x, vector<int> y){
	int first, second;
	int l=x.size();
	if(l==1){int p=single(x, y);vector<int> g(1);g[0]=p;return g;}
	first=l/2;
	second=l-first;
	vector<int> xl(first), xh(second), yl(first), yh(second);
	for(int i=0;i<first;i++){
		xl[i]=x[i];
		yl[i]=y[i];
	}
	for(int i=first;i<second;i++){
		xh[i-first]=x[i];
		yh[i-first]=y[i];
	}
	vector<int> p1, p2, p3;
	p1=product(xl, yl);
	p2=product(xh, yh);
	p3=product(sum(xl, xh), sum(yl, yh));
	p2.resize(l*2);
	p3=diff(p3, p2);
	p3=diff(p3, p1);
	p3.resize(l*2);
	p3=sum(p3, p2);
	p3=sum(p3, p1);
	return p3;
}

int main(){
	string a, b;
	cin>>a>>b;
	int l=equate(a, b);
	vector<int> x(l), y(l);
	for(int i=0;i<l;i++){
		x[i]=a[i]-'0';
		y[i]=b[i]-'0';
	}
	vector<int> res=product(x, y);
	for(int i=0;i<res.size(); i++)
	cout<<res[i]<<endl;
	return 0;
}

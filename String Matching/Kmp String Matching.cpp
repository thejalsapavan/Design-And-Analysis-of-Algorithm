#include<iostream>
using namespace std;
class StringMatching{
	public:
		int *Prefix_caluclate(string P){
			int m=P.length();
			int k=0;
			int count=0;
			int *pi=new int [m];
			pi[0]=0;
			for(int i=0;i<m-1;i++){
				count++;
				while(k>0 && P[k]!=P[i+1]){
					k=pi[k-1];
					count++;
				}
				if(P[k]==P[i+1]){
					k=k+1;
				}
				pi[i+1]=k;
			}
			for(int i=0;i<m;i++){
				cout<<pi[i]<<"\t";
			}
			cout<<"\nCount for creating Pi(π) table : "<<count;
			return pi;
		}
		void Kmp_StringMatching(string S,string P,int *pi,int &count){
			int m,n;
			n=S.length();
			m=P.length();
			int q=0;
			for(int i=0;i<n;i++){
				count++;
				while(q>0 && P[q]!=S[i]){
					q=pi[q-1];
					count++;
				}
				if(P[q]==S[i]){
					q++;
					if(q==m){
						cout<<"\nPattern occuring with valid shift : "<<i-(m-1)<<endl;
						q=pi[q-1];
					}
				}
			}
		}
};
int main(){
	string s="ABARBDDWEDECRWSEDFKADEQ";
	string p="DWED";
	StringMatching f;
	int c;
	int * pi=f.Prefix_caluclate(p);
	c=0;
	f.Kmp_StringMatching(s,p,pi,c);
	cout<<"Count value : "<<c;
}
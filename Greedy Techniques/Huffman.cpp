#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct charnode{
	char c;
	int freq;
	int codelen;
	string code;
	charnode*parent;
	charnode*left;
	charnode*right;
};
class Priority_Queue{
	private:
		charnode**Q;
		int heapsize;
		int n;
	public:
		void create(charnode*C[],int len){
			heapsize=len-1;
			Q = new charnode*[len];
			for(int i=0;i<=heapsize;i++){
				Q[i]=C[i];
			}
			for(int i=(heapsize+1)/2 ; i>=0;i--){
				Min_Heapify(i);
			}
		}
		void Min_Heapify(int i){
			int l=2*i + 1;
			int r=2*i + 2;
			int s;
			if(l<=heapsize && Q[l]->freq<Q[i]->freq){
				s=l;
			}
			else{
				s=i;
			}
			if(r<=heapsize && Q[r]->freq<Q[s]->freq){
				s=r;
			}
			if(s!=i){
				charnode*temp;
				temp=Q[i];
				Q[i]=Q[s];
				Q[s]=temp;
				Min_Heapify(s);
			}
		}
		void insert(charnode *z){
			heapsize=heapsize+1;
			int i=heapsize;
			while(i>0 && Q[i/2]->freq>z->freq){
				Q[i]=Q[i/2];
				i=i/2;
			}
			Q[i]=z;
		}
		charnode*Extract_Min(){
			charnode*temp;
			temp=Q[0];
			Q[0]=Q[heapsize];
			heapsize=heapsize-1;
			Min_Heapify(0);
			return temp;
		}
};
class Huffman{
	private:
		charnode**C;
		int n;
	public:
		Huffman(char ch[],int freq[],int len){
			n= len;
			C=new charnode*[len];
			for(int i=0;i<n;i++){
				C[i] = new charnode();
				C[i]->c=ch[i];
				C[i]->freq=freq[i];
				C[i]->codelen=0;
				C[i]->code="";
				C[i]->left=C[i]->right=C[i]->parent=NULL;
			}
		}
		void display(){
			for(int i=0;i<n;i++){
				findcode(C[i]);
				cout<<C[i]->freq<<"\t";
				cout<<C[i]->codelen<<"\t";
				cout<<C[i]->code<<"\t";
				cout<<endl;
			}
		}
		int filesize(){
			int fs=0;
			for(int i=0;i<n;i++)
			 fs+=C[i]->freq * C[i]->codelen; 
			return fs;
		}
		charnode*BuildTree(){
			Priority_Queue q;
			q.create(C,n);
			for(int i=1;i<=n-1;i++){
				charnode*x,*y,*z;
				z= new charnode;
				z->codelen=0;
				z->code="";
				z->parent=NULL;
				x=q.Extract_Min();
				y=q.Extract_Min();
				z->left=x;
				z->right=y;
				y->parent=x->parent=z;
				z->freq=x->freq+y->freq;
				q.insert(z);
			}
			return q.Extract_Min();
		}
		void findcode(charnode*t){
			if(t->parent==NULL){
					t->code="";
					t->codelen=0;
			}
			else{
				findcode(t->parent);
				t->codelen=t->parent->codelen+1;
				if(t->parent->left==t){
					t->code = t->parent->code + "0";
				}
				else{
					 t->code = t->parent->code + "1";
				}
			}
		}
};
int main(){
	int n;
	char a[100];
	int freq[100];
	cout<<"Enter the No of charcters : "<<endl;
	cin>>n;
	cout<<"Enter the character and frequency : "<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i]>>freq[i];
	}
	Huffman H(a,freq,n);
	H.display();
	cout<<"\n";
	charnode*head=H.BuildTree();
	H.display();
	charnode*t;
	int fixedlen;
	int variablelen;
	int tfreq;
	int ratio;
	tfreq = 0;
	for(int i=0;i<n;i++){
		tfreq+=freq[i];
	}
	fixedlen=tfreq*(int)(log2(n)+1);
	variablelen=H.filesize();
	cout<<"File size in variable length : "<<variablelen<<endl;
	cout<<"File size in Fixed length : "<<fixedlen<<"\n";
	ratio=100-(double)variablelen/fixedlen *100;
	cout<<"Compression Ratio : "<<ratio<<endl;
	return 0;
}
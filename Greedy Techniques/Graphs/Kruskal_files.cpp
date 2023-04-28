#include<iostream>
#include<fstream>
using namespace std;
struct node{
	int from ;
	int to;
	int weight;
	bool status;
	node *next;
};
class graph{
	int n,m;
	string vertex[10];
	int par[20],rank[20];
	node *elist;
	public:
		void creategraph(){
			fstream in("input.txt");
			in>>n;
			for(int i=0;i<n;i++){
				in>>vertex[i];
			}
			in>>m;
			elist=NULL;
				for(int j=0;j<m;j++){
					node *newnode=new node;
					in>>newnode->from;
					in>>newnode->to;
					in>>newnode->weight;
					newnode->status=false;
					newnode->next=NULL;
					if(elist==NULL || elist->weight==newnode->weight){
						newnode->next=elist;
						elist=newnode;
					}
					else{
						node*t=elist;
						while(t->next!=NULL && t->next->weight<=newnode->weight){
							t=t->next;
						}
						newnode->next=t->next;
						t->next=newnode;
					}
				}
		}
		void Setintialize(int v){
			par[v]=v;
			rank[v]=0;
		}
		int FindSet(int v){
			while(par[v]!=v){
				v=par[v];
			}
			return v;
		}
		void Union(int i,int j){
			if(rank[i]>rank[j]){
				par[j]=i;
			}
			else{
				par[i]=j;
				if(rank[i]==rank[j]){
					rank[j]++;
				}
			}
		}
		void FindSpanningTree(){
			for(int i=1;i<=n;i++){
				Setintialize(i);
			}
			int count,tweight;
			count=1;
			tweight=0;
			node *temp=elist;
			cout<<"Edges included in Minimum weight Spanning Tree: \n";
			while(temp!=NULL && count<=n-1){
				int i=FindSet(temp->from);
				int j=FindSet(temp->to);
				if(i!=j){
					temp->status=true;
					count++;
					tweight=tweight+temp->weight;
					cout<<temp->from<<" --> "<<temp->to<<" Weight "<<temp->weight<<endl;
					Union (i,j);
				}
				temp=temp->next;
			}
			cout<<"\nTotal Weight of the MWST is : "<<tweight<<endl;
		}
};
int main(){
	graph G;
	G.creategraph();
	cout<<"\t Kurskal Algorithm "<<endl;
	G.FindSpanningTree();
	return 0;
}
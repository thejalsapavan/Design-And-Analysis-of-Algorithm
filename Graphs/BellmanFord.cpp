#include<iostream>
#include<iomanip>

using namespace std;
struct node{
    int from;
    int to;
    int weight;
    node *next;
};
struct vnode{
    string name;
    int d;
    int pi;
   };
class graph{
    int n,m;
    vnode vertex[10];
    node *elist;

  public:
    void createGraph(){
    	cout << "Enter number of vertices: ";
		cin >> n;
		
		for (int i=1; i<=n; i++){
			cout << "Enter name of the vertex - "<< i<< ": ";
	        cin >> vertex[i].name;
	    }
		cout << "Enter number of edges: ";
	    cin >> m;
	    elist=NULL;
		node *last=NULL;
		for (int j=0; j<m; j++){
		  	node *t=new node;
			cout << "Enter index of from vertex: ";
 		    cin >> t->from;
 		    cout << "Enter index of to vertex: ";
		    cin >> t->to;
 		    cout << "Enter edge weight: "; 		    
 		    cin >> t->weight;
  	        t->next=NULL;
	        if (elist==NULL)
	           elist=last=t;
	        else
	           last->next=t;
	        last=t;	
	        
		}	      

	}
    void INITIALIZE_SINGLE_SOURCE(int s){
    	for (int i=1; i<=n; i++){
    		vertex[i].d=9999;
    		vertex[i].pi=-1;
		}
		vertex[s].d=0;
	}
    
	void RELAX(int u,int v,int w){
		if (vertex[v].d>vertex[u].d+w){
			vertex[v].d=vertex[u].d+w;
			vertex[v].pi=u;
		}
	}
	
    bool BELLMAN_FORD(int s){
    	node *t;
    	INITIALIZE_SINGLE_SOURCE(s);
		for (int i=1; i<=n-1; i++){
			t=elist;
	        while (t!=NULL){
	             RELAX(t->from,t->to,t->weight);
	             t=t->next;
			}
		}
		t=elist;
		while (t!=NULL){
 		   	if (vertex[t->to].d>vertex[t->from].d+t->weight)
	            return false;
	    	t=t->next;
	    }
		return true;      
	}
	void Print_ShortestPath(int i,int j)
   {
   	if(i==j)
   	cout<<i;
   	else if(vertex[j].pi==-1)
	cout<<"no path from "<<i <<" to "<<j<<" exists\n";
   	else
	 {
	 	Print_ShortestPath(i,vertex[j].pi);
	 	cout<<"->"<<j;
	 }  	
	   
   }
	void display(){
		
		cout<<setiosflags(ios::right);
		cout<<setw(8)<<"vid"<<setw(8)<<"Name"<<setw(8)<<"Dist"<<setw(8)<<"parent"<<endl;
		for (int i=1; i<=n; i++){
			cout <<setw(8) <<i <<setw(8) << vertex[i].name << setw(8) << vertex[i].d << setw(8)<< vertex[i].pi << endl;
		}
		cout << endl;
		for (int i=2; i<=n; i++){
			cout<<"\nDistance from 1 to"<<i<<" : "<<vertex[i].d<<endl;
			Print_ShortestPath( 1,i);
		}
		
	}
};  

int main(){
	graph g;
	g.createGraph();
	bool res = g.BELLMAN_FORD(1);
	if (res)
		g.display();
	else 
	    cout << "Graph contains negative valued cycle...." << endl;
	return 0;
}


	
	




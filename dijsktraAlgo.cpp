#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int minDistance(int weigh[],bool visited[],int V){
    int min=INT_MAX,min_pos;
    for(int i=0;i<V;i++){
        if(!visited[i] and weigh[i]<=min){
            min=weigh[i];
            min_pos=i;
        }
    }
    return min_pos;
}
void dijikstraAlgo(int adjMat[][100] ,int V, int src,int dest){
    int weigh[V];
    bool visited[V];
    int parent[V];
    for(int i=0;i<V;i++){
        weigh[i]=INT_MAX;
        visited[i]=false;
    }
    weigh[src]=0;
    parent[src]=-1;
    for(int i=0;i<V-1;i++){
        int min = minDistance(weigh,visited,V);
        visited[min]=true;
        for(int j=0;j<V;j++){
            if(!visited[j] and adjMat[min][j] and weigh[min]!=INT_MAX and (weigh[min]+adjMat[min][j]<weigh[j])){
               weigh[j] = weigh[min]+adjMat[min][j]; 
               parent[j]=min;
               
            }
        }
    }
    cout<<"\nDistance from Source =  "<<weigh[dest]<<endl;
    cout<<"Path for Source to Destination : \n";
    int i=dest;
    while(i<=src and visited[i]==true and parent[i]!=-1){
    		cout<<char(parent[i]+65)<<" - "<<char(i+65)<<" \t"<<adjMat[i][parent[i]]<<"\n";
    		i++;
    	}
}
int main() {
	int V,E;
	cout<<"Enter the no. of vertices : ";
	cin>>V;
	cout<<"Enter the no. of edges : ";
	cin>>E;
	int adjMat[100][100];
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			adjMat[i][j]=0;
		}
	}
	
	char key[V];
	cout<<"Enter the key value of nodes :\n";
	for(int i=0;i<V;i++){
		cin>>key[i];
		mp[key[i]]=i;
	}
	cout<<"Enter the vertices pairs having edges and weights :\n";
	for(int i=0;i<E;i++){
		int w;
		char u,v;
		cin>>u>>v>>w;
		adjMat[mp[u]][mp[v]]=w;
		adjMat[mp[v]][mp[u]]=w;
	}
	char s,d;
	cout<<"Enter the source Node : ";
	cin>>s;
	cout<<"Enter the destination Node : ";
	cin>>d;
    dijikstraAlgo(adjMat,V,s-'A',d-'A');
}

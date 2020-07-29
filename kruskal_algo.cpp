#include<bits/stdc++.h>
using namespace std;
int main()
{
	int v,e,i,j;
	map<char,int>mp;
    cout<<"Enter the number of vertexes\n";
	cin>>v;
    cout<<"Enter the number of edges\n";
	cin>>e;
	char a[v];
	cout<<"Enter the vertexes\n";
	for(i=0;i<v;i++)
	{
		cin>>a[i];
		mp[a[i]] = i;
	}
	int gr[v][v];
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			gr[i][j] =0 ;
		}
	}
	cout<<"Enter the edge connectivity\n";
	char x,y;
	int w;
	while(e--)
	{
         cin>>x>>y>>w;
         gr[mp[x]][mp[y]] = w;
	}

cout<<"The Matrix representation of graph is:\n";
cout<<"    ";
for(i=0;i<v;i++)
{
	cout<<a[i]<<"   ";
}
cout<<endl;
	for(i=0;i<v;i++)
	{
			cout<<a[i]<<"   ";
		for(j=0;j<v;j++)
		{
		    	cout<<gr[i][j]<<"   ";

		}
		cout<<endl;
	}
}
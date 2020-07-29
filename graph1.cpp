#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n,i,j,egcnt,x,y;
	map<int,int>mp;
	cout<<"Enter the number of nodes\n";
	cin>>n;
	int gr[n][n],a[n];
	cout<<"Enter the node's value\n";
	for(i=0;i<n;i++)
	{
       cin>>a[i];
       mp[a[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			gr[i][j]=0;
		}
	}
cout<<"Enter the numbers of edges\n";
cin>>egcnt;
    while(egcnt--)
    {
        cout<<"Enter the edge connectivity\n";
        cin>>x>>y;
        gr[mp[x]][mp[y]]=1;
    }
cout<<"The Matrix representation of graph is:\n";
cout<<"  ";
for(i=0;i<n;i++)
{
	if(a[i]>9)
	cout<<a[i]<<"  ";
    else
    cout<<a[i]<<"   ";
}
cout<<endl;
	// for(i=0;i<n;i++)
	// {
	//  gr[i][0]=a[i];
	// }
	for(i=0;i<n;i++)
	{
		if(a[i]>=10)
			cout<<a[i]<<"  ";
		else
			cout<<a[i]<<"   ";
		for(j=0;j<n;j++)
		{
			if(a[j]>9)
			cout<<gr[i][j]<<"  ";
		    else
		    	cout<<gr[i][j]<<"   ";

		}
		cout<<endl;
	}
	int b,c;
cout<<"CHECKING  OF CONNECTIVITY:\n";
cout<<"enter the values to check the connectivity\n";
cin>>b>>c;
if(gr[mp[b]][mp[c]]==1)
	cout<<"CONNECTIVITY EXIST\n";
else
	cout<<"CONNECTIVITY NOT EXIST!\n";
}

#include <iostream>
#include <string>
using namespace std;
// created by Steve 
// this road.h name certain road in edges
void road(int edge[10],string name)
{
	int maxint = 999999;
	cout << "The road start-->";
	for (int i = 0;i < 10;i++)
		if (edge[i] != maxint)
			cout << edge[i] << "-->";
	
	cout << "end is "<< name<<endl;
}

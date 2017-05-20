#include <fstream>
#include <iostream>
// created by Steve 
// this store.h store the map situation into file 
// need the number of map vertex and edge situation

void store(int n,int c[20][20],string filename){
ofstream output(filename);
output << n << endl;
for (int i = 1; i <= n;++i)
{
	for (int j = 1; j <= n; ++j)
	{
		output << c[i][j] << " ";
	}
	output << endl;
}
output.close();
}
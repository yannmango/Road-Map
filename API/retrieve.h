#include <iostream>
#include <fstream>
// created by Steve 
// this retrieve.h retrieve filename and print the map situation
//return path and distance between fromvertx and tovertex

void retrieve(string filename)
{
	int c[20][20];
	int n;
	ifstream input(filename);
	input >> n;
	cout <<"The number of total vertex is  " << n << endl;
	cout << "The map array is like the following " << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			input >> c[i][j];
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	input.close();
}
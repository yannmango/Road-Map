#include <iostream>
#include <fstream>
// created by Steve 
// this vertex.h find vertex besides some interst of point

void vertex(int vertexlabel)
{
	int maxint = 999999;
	const int maxnum = 20;
	int c[maxnum][maxnum];
	int n;
	int vertex[maxnum];
	int count = 1;
	ifstream input("C:\\Users\\sound\\Desktop\\Waterloo\\books\\Software tools and methods\\assginment\\3\\mapinfo.txt");
	input >> n;
	if(vertexlabel>n||vertexlabel<1)
	{
		cout << "there is no vertexlabel in map" << endl;
	}
	else {
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				input >> c[i][j];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (c[vertexlabel][i] != maxint)
			{
				vertex[count] = i;
				count++;
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (c[i][vertexlabel] != maxint)
			{
				vertex[count] = i;
				count++;
			}
		}
		int j, i, temp, a;
		cout << "The asscoited vertex label is ";
		for (i = 1;i < count;i++)
		{
			temp = vertex[i];
			for (j = i + 1;j < count;j++)
			{
				if (temp == vertex[j])
				{
					a = temp;
					cout << temp << " ";
				}
			}
		}
		for (int i = 1;i < count;i++)
		{
			if (vertex[i] != a)
				cout << vertex[i] << " ";
		}
		cout << endl;
	}
	input.close();
}
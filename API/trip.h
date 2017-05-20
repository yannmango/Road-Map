#include <iostream>
#include <fstream>
using namespace std;
// created by Steve 
// this trip.h use fromvertex and to vertex 
//return path and distance between fromvertx and tovertex
//do remember the maxnum is 10 because i use static array
int trip(int fromvertex, int tovertex)
{
	const int maxnum = 20;  // the maxnum number of vertex
	const int maxint = 999999;
	int c[maxnum][maxnum]; // the map array used to store data
	int n; // the number of vertex
	int prev[maxnum];     // store the data of path
	int dist[maxnum];     // store the distance between the original point to target point 
	bool s[maxnum];    // the boolen number to judge wheather point has been checked

		// get the map info in the file including the number of vertex and edges situation
		ifstream input("C:\\Users\\sound\\Desktop\\Waterloo\\books\\Software tools and methods\\assginment\\3\\mapinfo.txt");
		input >> n;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				input >> c[i][j];
		input.close();
	if (fromvertex>n || fromvertex<1 || tovertex>n || tovertex<1)
		{
			cout << "please reenter the vertex label in right range"<< endl;
			return 0;
		}
	else {
		/////Dijkstria Algorithms/////////
		//Step 1: initialize the data in dist and s
		for (int i = 1; i <= n; ++i)
			dist[i] = maxint;
		for (int i = 1; i <= n; ++i)
		{
			dist[i] = c[fromvertex][i];//intialize the distance to fromvertex
			s[i] = 0;
			if (dist[i] == maxint)
				prev[i] = 0;
			else
				prev[i] = fromvertex;
		}
		dist[fromvertex] = 0;
		s[fromvertex] = 1;
		//Step 2: from the rest point select the closest point to fromvertex
		for (int i = 2; i <= n; ++i)
		{
			int tmp = maxint;
			int u = fromvertex;
			// find the cloest data to fromvertex
			for (int j = 1; j <= n; ++j)
				if ((!s[j]) && dist[j] < tmp)
				{
					u = j; // find the point which is closest to fromvertex         
					tmp = dist[j];
				}
			s[u] = 1;

			//Step 3£ºupdate the dist array and prev data 
			for (int j = 1; j <= n; ++j)
				if ((!s[j]) && c[u][j] < maxint)
				{
					int newdist = dist[u] + c[u][j];
					if (newdist < dist[j])
					{
						dist[j] = newdist;
						prev[j] = u;
					}
				}
		}
		if (dist[tovertex] == maxint)
		{
			cout << "there is no road between fromvertex and tovertex" << endl;
			return -1;
		}
		else
		{
			// print the distance from fromvertex to tovertex
			cout << "The distance between fromvertex and tovertex is: " << dist[tovertex] << endl;

			// print the pathe between fromvertex and tovertex
			cout << "The path between fromvertex and tovertex is: ";
			int que[maxnum]; //que store the data of path
			int tot = 1;
			que[tot] = tovertex;
			tot++;
			int tmp = prev[tovertex];
			while (tmp != fromvertex)
			{
				que[tot] = tmp;
				tot++;
				tmp = prev[tmp];
			}
			que[tot] = fromvertex;
			for (int i = tot; i >= 1; --i)
				if (i != 1)
					cout << que[i] << " -> ";
				else
					cout << que[i] << endl;
			return 1;
		}
		
	}
}


#include <iostream>
typedef struct edge //define a struct
{
	int vertex1;
	int vertex2;
	int directional;
	int speed;
	int length;
	struct edge* pNext;
}EDGE, *PEDGE;

using namespace std;

class addEdge
{
private:
	PEDGE pHead;//struct edge* pHead

public:
	addEdge()   //construction
	{
		this->pHead = NULL;
	}

	~addEdge()  //deconstruction
	{
		while (this->pHead != NULL)
		{
			PEDGE pTemp = pHead->pNext;
			delete pHead;
			pHead = pTemp;
		}
	}

	void Add(int vertex1, int vertex2, int directional, int speed, int length) 
	{
		if (pHead == NULL)
		{
			pHead = new EDGE;
			pHead->vertex1 = vertex1;
			pHead->vertex2 = vertex2;
			pHead->directional = directional;
			pHead->speed = speed;
			pHead->length = length;
			pHead->pNext = NULL;
		}
		else
		{
			PEDGE pTemp = pHead;
			while (pTemp->pNext != NULL)
			{
				pTemp = pTemp->pNext;
			}

			PEDGE pNew = new EDGE;
			pNew->vertex1 = vertex1;
			pNew->vertex2 = vertex2;
			pNew->directional = directional;
			pNew->speed = speed;
			pNew->length = length;
			pNew->pNext = NULL;
			pTemp->pNext = pNew;
		}
	}
	int Find(int vertex1,int vertex2)   
		  {
		       int i = 1;
		       PEDGE pTemp = pHead;
		       while (pTemp != NULL)
			       {
			           if ((pTemp->vertex1 == vertex1)&(pTemp->vertex2 == vertex2))
			            {
				               return i;
				            }
		           pTemp = pTemp->pNext;
			            //i++;
			        }
		        return 0;
	   }
	int Getweight(int vertex1, int vertex2)
	{
		int i = 1;
		PEDGE pTemp = pHead;
		while (pTemp != NULL)
		{
			if ((pTemp->vertex1 == vertex1)&(pTemp->vertex2 == vertex2))
			{
				int length = pTemp->length;
				int speed = pTemp->speed;
				return length*speed;
			}
			pTemp = pTemp->pNext;
			//i++;
		}
		return 0;

	}
	int Getdirection(int vertex1, int vertex2)
	{
		PEDGE pTemp = pHead;
		while (pTemp != NULL)
		{
			if ((pTemp->vertex1 == vertex1)&(pTemp->vertex2 == vertex2))
			{
				int direction = pTemp->directional;
				return direction;
			}
			pTemp = pTemp->pNext;
		}
		return -1;

	}
	void Travel()  //look through data in list
	{
		PEDGE pTemp = this->pHead;

		while (pTemp != NULL)
		{
			cout << pTemp->vertex1 << "  ";
			cout << pTemp->vertex2 << "  ";
			cout << pTemp->directional << "  ";
			cout << pTemp->speed << "  ";
			cout << pTemp->length << "  ";
			pTemp = pTemp->pNext;
		}
		cout << endl;
	}
	int GetNodeCnt()  //get the number of list
	{
		int cnt = 0;
		PEDGE pTemp = pHead;

		while (pTemp != NULL)
		{
			cnt++;
			pTemp = pTemp->pNext;
		}

		return cnt;
	}
};

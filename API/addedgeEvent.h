#include <iostream>
typedef struct edgeevent //define a struct
{
	int vertex1;
	int vertex2;
	int eventType;
	struct edgeevent* pNext;
}EDGEEVENT, *PEDGEEVENT;

using namespace std;

class addedgeEvent
{
private:
	PEDGEEVENT pHead;//struct edge* pHead

public:
	addedgeEvent()   //construction
	{
		this->pHead = NULL;
	}

	~addedgeEvent()  //deconstruction
	{
		while (this->pHead != NULL)
		{
			PEDGEEVENT pTemp = pHead->pNext;
			delete pHead;
			pHead = pTemp;
		}
	}

	void Add(int vertex1, int vertex2, int eventType)
	{
		if (pHead == NULL)
		{
			pHead = new EDGEEVENT;
			pHead->vertex1 = vertex1;
			pHead->vertex2 = vertex2;
			pHead->eventType = eventType;
			pHead->pNext = NULL;
		}
		else
		{
			PEDGEEVENT pTemp = pHead;
			while (pTemp->pNext != NULL)
			{
				pTemp = pTemp->pNext;
			}

			PEDGEEVENT pNew = new EDGEEVENT;
			pNew->vertex1 = vertex1;
			pNew->vertex2 = vertex2;
			pNew->eventType = eventType;
			pNew->pNext = NULL;
			pTemp->pNext = pNew;
		}
	}

	void Travel()  //look through data in list
	{
		PEDGEEVENT pTemp = this->pHead;

		while (pTemp != NULL)
		{
			cout << pTemp->vertex1 << "  ";
			cout << pTemp->vertex2 << "  ";
			cout << pTemp->eventType << "  ";
			pTemp = pTemp->pNext;
		}
		cout << endl;
	}
	
	int GeteventType(int vertex1, int vertex2)
	{
		PEDGEEVENT pTemp = pHead;
		while (pTemp != NULL)
		{
			if ((pTemp->vertex1 == vertex1)&(pTemp->vertex2 == vertex2))
			{
				int direction = pTemp->eventType;
				return direction;
			}
			pTemp = pTemp->pNext;
		}
		return -1;

	}
};
#include <iostream>
typedef struct vertex 
{
	int type;   //vertex type 
	int label;  //vertex label
	struct vertex* pNext; 
}VERTEX, *PVERTEX;

using namespace std;
class addVertex
{
private:
	PVERTEX pHead;//struct vertex* pHead

public:
	addVertex()   //construction
	{
		this->pHead = NULL;
	}

	~addVertex()  //deconstruction
	{
		//cout << "deconstruction";
		while (this->pHead != NULL)
		{
			PVERTEX pTemp = pHead->pNext;
			delete pHead;
			pHead = pTemp;
		}
	}
	void Add(int type, int label) 
	{
		if (pHead == NULL)
		{
			pHead = new VERTEX;
			pHead->type = type;
			pHead->label = label;
			pHead->pNext = NULL;
		}
		else
		{
			PVERTEX pTemp = pHead;
			while (pTemp->pNext != NULL)
			{
				pTemp = pTemp->pNext;
			}

			PVERTEX pNew = new VERTEX;
			pNew->type = type;
			pNew->label = label;
			pNew->pNext = NULL;
			pTemp->pNext = pNew;
		}
	}

	int Find(int label)
	{
	int i = 0;
	PVERTEX pTemp = pHead;
	while (pTemp != NULL)
	{
	if (pTemp->label == label)
	{
	return i;
	}
	pTemp = pTemp->pNext;
	i++;
	}
	return -1;
	}
	void Travel()  //look through data in list
	{
		PVERTEX pTemp = this->pHead;

		while (pTemp != NULL)
		{
			cout << pTemp->type << "  ";
			cout << pTemp->label << "  ";
			pTemp = pTemp->pNext;
		}
		cout << endl;
	}
	int GetNodeCnt()  //get the number of list 
	    {
	       int cnt = 0;
		      PVERTEX pTemp = pHead;
		
		       while (pTemp != NULL)
			       {
			            cnt++;
			           pTemp = pTemp->pNext;
			        }
		
			        return cnt;
		    }

};
#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
	vector<int> pq;

	public :

	

	bool isEmpty() {
		return pq.size() == 0;
	}

	// Return the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);
		
		int childIndex = pq.size() - 1;

		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}

	}

	int removeMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
	
		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;



	}
	





};


int main() {
	PriorityQueue p;

	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	cout <<"Size : "<< p.getSize() << endl;
	cout <<"Minimum element in the Priority Queue right now : "<< p.getMin() << endl;

	while(!p.isEmpty()) {
		cout <<"Current Minimum element which is being deleted : "<< p.removeMin() << "  \n" ;

	}
	cout<<"\n";
	cout <<"Size after deleting all elements : "<< p.getSize() << endl;
	return 0;
	
}



/*
Output is as follows of the above code  : 

Size : 7
Minimum element in the Priority Queue right now : 4
Current Minimum element which is being deleted : 4
Current Minimum element which is being deleted : 10
Current Minimum element which is being deleted : 15
Current Minimum element which is being deleted : 17
Current Minimum element which is being deleted : 21
Current Minimum element which is being deleted : 67
Current Minimum element which is being deleted : 100

Size after deleting all elements : 0
*/


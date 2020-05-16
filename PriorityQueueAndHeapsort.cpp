/*
	Heapsort and Priority Queue
	
	Author: Bryant Sirois
	Description: An implementation of Heapsort via construction of an array-based Priority Queue.
	The code was written after a close study of the algorithm from Robert Sedgewick's "Algorithms" 
	Fourth Edition text, David Reed and John Zelle's "Data Structures and Algorithms Using Python and C++"
	text, and a PDF taken from David J. Eck's Data Structures and Algorithms course (http://math.hws.edu/eck/cs327_s04/chapter3.pdf)

*/

#include <iostream>
#include <time.h>

void heapifySwim(int[], int);
void heapifySink(int[], int, int);
void exchange(int[], int, int);
void heapsort(int[], int);

int main()
{
	/*Seeding a random number generator object. User input determines quantity of numbers
	  to set in an array-based priority queue, and its subsequent heapsort.*/
	srand(time(NULL));
	int n;
	std::cout << "How many numbers shall I sort? ";
	std::cin >> n;
	n++;
	int a[n];
	a[0] = 0;
	std::cout << "\n" << n-1 << " Random Numbers: \t";
	
	/*Generation of random numbers between 1 - 200. After each assignment, the array
	is passed into heapifySwim() in order to ensure the binary heap/priority queue structure remains.*/
	for (int i = 1; i <= n-1; ++i)
	{
		a[i] = rand() % 200 + 1;
		std::cout << a[i] << " ";
		heapifySwim(a, i);
	}
	std::cout << "\n\nPriority Queue Form: \t";
	for (int i = 1; i < n; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	
	/*The array is then passed to heapsort(). The sorted output is then displayed.*/
	std::cout << "\nSorted via Heapsort: \t";
	heapsort(a, n-1);
	for (int i = 1; i < n; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	
	return 0;
}

/*heapsort() accepts an array and array-size n as arguments. First item is exchanged with item
from the back. Since the first item in an array-based priority queue is the greatest value, it is
now in its proper position, so we decrement n by one. The new first item is then passed to the 
heapifySink() method, where it is moved in the smaller priority queue to its proper place. This is
repeated until n reaches 1, and the array is now sorted.*/
void heapsort(int a[], int n)
{
	while (n > 1)
	{
		exchange(a, 1, n--);
		heapifySink(a, 1, n);
	}
}

/*heapifySwim() takes an item at position pos and "floats" it to its proper position.
These calculations are simplified in an array with an ignored item at position 0. Therefore, the
first item in the collection is at index 1, the second at index 2, etc. Any parent in this implementation
can be found through integer division of an item at any position (For example: the parent of an item at 
position 5 is 5 / 2 = 2). The left child of an item can be found by multiplying its index by 2, and the
right child can be found by multiplying its index by 2 and then adding 1. These child-finding methods
are more apparent in the next method, heapifySink().*/
void heapifySwim(int heap[], int pos)
{
	while(true)
	{
		int parent = pos / 2;
		if (pos <= 1 || heap[parent] >= heap[pos])
		{
			break;
		}
		else
		{
			exchange(heap, pos, parent);
		}
		pos = parent;
	}
}

/*heapifySink() takes an item at position pos and "sinks" it to its proper position. Here, we
examine the children of a node, determine if any of them are greater than the parent, and then 
swap if necessary. This continues until the item reaches the bottom of the heap, if applicable.*/
void heapifySink(int heap[], int pos, int n)
{	
	while (true)
	{
		int leftChild = pos * 2;
		int rightChild = (pos * 2) + 1;
		if (leftChild > n)
		{
			break;
		}
		int biggerChild = ((rightChild > n) || (heap[leftChild] >= heap[rightChild])) ? leftChild : rightChild;
		
		if (heap[pos] >= heap[biggerChild])
		{
			break;
		}
		exchange(heap, pos, biggerChild);
		pos = biggerChild;
	}
}

/*A helper method that exchanges two elements at positions i and j.*/
void exchange(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
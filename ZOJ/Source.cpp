#include "SortAlgorithm.h"
#include <iostream>
using namespace std;

void main(void)
{
	int arr[] = {4,6,2,8,3,8,1,0,11};
	SortAlgorithm* sa = new SortAlgorithm(arr, 9);
	cout<<"Array befor sort."<<endl;
	sa->Print();
	cout<<endl;
	cout<<"Array after sort."<<endl;
	sa->InsertSort();
	sa->Print();

	delete sa;
}
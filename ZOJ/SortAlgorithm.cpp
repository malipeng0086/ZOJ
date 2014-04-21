#include "SortAlgorithm.h"
#include<assert.h>
#include<iostream>
using namespace std;

SortAlgorithm::SortAlgorithm(int* source, int length)
{
	assert(source);
	this->arrayForSort = new int[length];
	this->length = length;
	int index = 0;
	for(int index = 0; index < length; index++)
	{
		*(this->arrayForSort + index) = *(source + index);
	}
}
/*
≤Â»Î≈≈–Ú
*/
void SortAlgorithm::InsertSort()
{
	for(int i = 1; i < this->length; i++)
	{
		int target = *(this->arrayForSort + i);
		for(int j = 0; j < i; j++)
		{
			if(*(this->arrayForSort + j) > target)
			{
				int temp = target;
				for(int k = i; k > j; k--)
				{
					*(this->arrayForSort + k) = *(this->arrayForSort + k - 1);
				}
				*(this->arrayForSort + j) = target;
				break;
			}
		}
	}
}

void SortAlgorithm::Print()
{
	cout<<"{";
	for(int index = 0; index < this->length; index++)
	{
		if(index != 0)
			cout<<", ";
		cout<<(*(this->arrayForSort + index));
	}
	cout<<"}";
}
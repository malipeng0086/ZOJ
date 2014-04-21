class SortAlgorithm
{
private:
	int *arrayForSort;
	int length;
public:
	SortAlgorithm(int *source, int length);
	void InsertSort();

	void Print();
	~SortAlgorithm()
	{
		length = 0;
		delete[] arrayForSort;

		arrayForSort = 0;
	}
};
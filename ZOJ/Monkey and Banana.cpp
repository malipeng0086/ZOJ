#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class CubeArea
{
private:
	int area;
	int height;
	int width;
	int length;
public:
	CubeArea(int length, int width, int height)
	{
		this->length = length;
		this->width = width;
		this->height = height;

		this->area = length*width;
	}

	int GetHeight()
	{
		return this->height;
	}

	int GetWidth()
	{
		return this->width;
	}

	int GetLength()
	{
		return this->length;
	}

	int GetArea()
	{
		return this->area;
	}
	bool operator<(const CubeArea& other) const
	{
		if(other.area < this->area)
			return true;
		else if(other.area == this->area)
		{
			return other.height > height;
		}

		return false;
	}
};

int main()
{
	int types;
	while(cin>>types && types != 0)
	{
		vector<CubeArea> vec;
		for(int i = 0; i < types; i++)
		{
			int x, y, z;
			cin>>x>>y>>z;
			vec.push_back(CubeArea(x,y,z));
			vec.push_back(CubeArea(x,z,y));
			vec.push_back(CubeArea(z,y,x));
		}
		sort(vec.begin(), vec.end());
		int height = 0;
		CubeArea tempArea = vec[0];
		height = tempArea.GetHeight();
		for(int j = 1; j < vec.size(); j++)
		{
			if((vec[j].GetLength() < tempArea.GetLength() && vec[j].GetWidth() < tempArea.GetWidth())
				|| (vec[j].GetLength() < tempArea.GetWidth() && vec[j].GetWidth() < tempArea.GetLength())
				)
			{
				height = height + vec[j].GetHeight();
				tempArea = vec[j];
			}
			
		}
		cout<<height<<endl;
	}
	return 1;
}
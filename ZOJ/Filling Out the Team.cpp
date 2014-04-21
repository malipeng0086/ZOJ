#include<iostream>
#include<map>
#include<string>

using namespace std;

class Position
{
private:
	string name;
	double lowestSpeed;
	double minWeight;
	double minStrength;
public:
	Position(){}

	string GetName()
	{
		return this->name;
	}
	Position(string name, double lowestSpeed, double minWeight, double minStrength)
	{
		this->name=name;
		this->lowestSpeed = lowestSpeed;
		this->minWeight = minWeight;
		this->minStrength = minStrength;
	}

	bool MathPosition(double speed, double weight, double strength)
	{
		return (weight >= this->minWeight && strength >= this->minStrength && speed <= this->lowestSpeed);
	}
};
int main()
{
	Position **p = new Position*[3];

	*p = new Position("Wide Receiver", 4.5, 150, 200);
	*(p+1) = new Position("Lineman", 6.0, 300, 500);
	*(p+2) = new Position("Quarterback", 5.0, 200, 300);

	double s, w, str;
	while(cin>>s>>w>>str && (s != 0 || w != 0 || str != 0))
	{
		int matchCount = 0;
		if((*p)->MathPosition(s,w,str)){
			cout<<(*p)->GetName();
			matchCount++;
		}
		if((*(p+1))->MathPosition(s,w,str)){
			if(matchCount != 0)
				cout<<" ";
			cout<<(*(p+1))->GetName();
			matchCount++;
		}
		if((*(p+2))->MathPosition(s,w,str)){
			if(matchCount != 0)
				cout<<" ";
			cout<<(*(p+2))->GetName();
			matchCount++;
		}
		if(matchCount == 0)
			cout<<"No positions";
		cout<<endl;
	}

	
	delete[] p;
	p = NULL;

	return 0;
}
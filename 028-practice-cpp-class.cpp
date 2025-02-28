#include <iostream>
using namespace std;

class rectangle
{
private:
	int length;
	int breadth;
public:
	// constructors
	rectangle()
	{
		length = breadth = 1;
	}
	rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	// mutators and accessors
	void setLength(int l)
	{
		length = l;
	}
	void setBreadth(int b)
	{
		breadth = b;
	}
	int getLength()
	{
		return length;
	}
	int getBreadth()
	{
		return breadth;
	}

	// area and perimeter methods
	int area()
	{
		return length * breadth;
	}
	int perimeter()
	{
		return 2 * (length + breadth);
	}

	// destructor
	~rectangle()
	{
		cout << "Rectangle Destroyed" << endl;
	}
};

int main()
{
	rectangle r(10, 5);
	cout << "Area: " << r.area() << endl;
	cout << "Perimeter: " << r.perimeter() << endl;
	return 0;
}
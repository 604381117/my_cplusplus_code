#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class Point;

class Line{
public:
	float dis(const Point &,const Point &);
};

class Point{
public:
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)"<< endl;
	}
	
	void Print()
	{
		cout<<"("<<_ix<<","<<_iy<<")"<<endl;
	}
private:
	friend float Line::dis(const Point &,const Point &);
	int _ix;
	int _iy;
};

float Line::dis(const Point &p1,const Point &p2)
{
	return sqrt((p1._ix-p2._ix)*(p1._ix-p2._ix)+(p1._iy-p2._iy)*(p1._iy-p2._iy));
}

int main(void)
{
	Line l1;
	Point pt1(1,4);
	Point pt2(7,9);
	pt1.Print();
	cout<<"-->";
	pt2.Print();
	cout<<" dis="<< l1.dis(pt1,pt2)<<endl;
	return 0;
}

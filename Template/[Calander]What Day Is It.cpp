#include<iostream>
using namespace std;
#include<string>

int main()
{
	int mdas[]={31,28,31,30,31,30,31,31,30,31,30,31};
	string days[]={"Monday","Tuesday","Wednesday", 
		         "Thursday","Friday","Saturday","Sunday"};
	string mons[]={"January","February","March","April","May","June", 
	             "July","August","September","October","November","December"};
    int m,d,y;
	cin>>m>>d>>y;
	while (m || d || y)
	{
		int day=mdas[(m-1)%12];
		if ((y<=1752) && (m==2) && (y%4==0)) day=29;
		if (((y>1752) && (m==2))
			&& (((y%4==0) && (y%100!=0)) || (y%400==0)))
			day=29;
		if (((y==1752) && (m==9) && (d>2) && (d<14))
			|| ((d<1) || (m<1) || (d>day) || (m>12) || (y<1)))
		{
			cout<<m<<"/"<<d<<"/"<<y<<" is an invalid date."<<endl;
			cin>>m>>d>>y;
			continue;
		}
		int star;
		if (m<3) 
		{
			y--;
			m+=12;
		}
		if (((y==1752) && (m==9) && (d>2))
		   || ((y==1752) && (m>9))
		   || (y>1752))
		   star=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
		if (((y==1752) && (m==9) && (d<=2))
		   || ((y==1752) && (m<9))
		   || (y<1752))
		   star=(d+2*m+3*(m+1)/5+y+y/4+5)%7;
		if (m>12)
		{
			y++;
			m-=12;
		}
		cout<<mons[(m-1)%12]<<" "<<d<<", "<<y<<" is a "<<days[star]<<endl;
		cin>>m>>d>>y;
	}
	return 0;
}
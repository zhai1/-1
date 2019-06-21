#include "point.h" 
void point::setpoint(double a1,double b1,double c1)
{
  cout<<"请输入空间点的坐标："<<endl;
  cin>>a1>>b1>>c1;
  a=a1;b=b1;c=c1;  
}
void point::setvector(double a2,double b2,double c2)
{
   cout<<"请输入直线的空间向量："<<endl;
   cin>>a2>>b2>>c2;
   a=a2,b=b2,c=c2;
}

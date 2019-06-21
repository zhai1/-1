#include "line.h"
void line::setline(double a1,double b1,double c1,double d1)
{
  cout<<"请输入直线方程ax+by+cz+d=0的a、b、c、d："<<endl;
  cin>>a1>>b1>>c1>>d1;
  a=a1;b=b1;c=c1;d=d1;
  cout<<"直线方程为："<<endl;
  cout<<a<<"x+"<<b<<"y+"<<c<<"z+"<<d<<"=0";
}

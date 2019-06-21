#include "plane.h"
void plane::setplane(double a1,double b1,double c1,double d1)
{
   cout<<"请输入一个平面方程:ax+by+cz+d=0,中的a、b、c、d"<<endl;
   cin>>a1>>b1>>c1>>d1;
   a=a1;b=b1;c=c1;d=d1;
   cout<<"所得平面方程为："<<a<<"x+"<<b<<"y+"<<c<<"z+"<<d<<"=0"<<endl;
}

#include "line.h"
void line::setline(double a1,double b1,double c1,double d1)
{
  cout<<"������ֱ�߷���ax+by+cz+d=0��a��b��c��d��"<<endl;
  cin>>a1>>b1>>c1>>d1;
  a=a1;b=b1;c=c1;d=d1;
  cout<<"ֱ�߷���Ϊ��"<<endl;
  cout<<a<<"x+"<<b<<"y+"<<c<<"z+"<<d<<"=0";
}

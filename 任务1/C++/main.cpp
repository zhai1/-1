#include"point.h"
#include"plane.h"
#include"line.h"
#include <cmath>
int main()
{
  point d[100];
  plane m[100];
  plane p[100];
  line z[100];
  while(1)
  {
    int k;
	cout<<"        ��ѡ�������һ������        "<<endl
		<<"             1 ����ֱ��            "<<endl
		<<"             2 ����ƽ��            "<<endl
		<<"             3 �������            "<<endl
		<<"             4 ��������            "<<endl
		<<"             5 �жϹ�ϵ            "<<endl
		<<"             6   �˳�              "<<endl
		<<"              ��ѡ��             "<<endl;
	cin>>k;
	if(k==1)
	{  
	    int a;
	   cout<<"����ȷ��һ��ֱ������1��"<<endl<<"�����ཻƽ��ȷ��һ��ֱ������2��"<<endl<<"�ռ����ߵĵ�бʽ����3��"<<endl;
	   cin>>a;
	   if(a==1)
	   {
		   d[1].setpoint(1.0,2.0,3.0);
		   d[2].setpoint(1.0,2.0,3.0);
		   cout<<"�ռ�ֱ�߷���Ϊ��"<<endl;
		   cout<<"(x-"<<d[1].a<<")/"<<d[2].a-d[1].a<<"="
			   <<"(y-"<<d[1].b<<")/"<<d[2].b-d[1].b<<"="
			   <<"(z-"<<d[1].c<<")/"<<d[2].c-d[1].c<<endl;
	   }
	   else if(a==2)
	   {
		   m[1].setplane(1.0,2.0,3.0,4.0);
		   m[2].setplane(1.0,2.0,3.0,4.0);
		   cout<<"����ƽ���ཻ����ֱ�߷���Ϊ��"<<endl;
		   cout<<m[1].a-m[2].a<<"x+"
			   <<m[1].b-m[2].b<<"y+"
			   <<m[1].c-m[2].c<<"z+"
			   <<m[1].d-m[2].d<<"=0";
	   }
	   else if(a==3)
	   {
		  d[3].setvector(1.0,2.0,3.0);
		  d[4].setpoint(1.0,2.0,3.0);
		  cout<<"ֱ�߷���Ϊ��"<<endl;
		  cout<<"(x-"<<d[4].a<<")/"<<d[3].a<<"="
			  <<"(y-"<<d[4].b<<")/"<<d[3].b<<"="
			  <<"(z-"<<d[4].c<<")/"<<d[3].c<<endl;
	   }
	   else 
		   cout<<"��������";
	}
	  else if(k==2)
	  {
	      int t;
		  cout<<"���������ߵĵ�ȷ��һ��ƽ������1��"<<endl<<"һ�����һ��������ȷ��һ��ƽ������2��"<<endl;
		  cin>>t;
		  if(t==1)
		  { 
			d[1].setpoint(1.0,2.0,3.0);
		    d[2].setpoint(1.0,2.0,3.0);
			d[3].setpoint(1.0,2.0,3.0); 
			cout<<"����ƽ�淽��Ϊ��"<<endl;
			cout<<(d[2].b)*(d[3].c)-(d[2].c)*(d[3].b)<<"(x-"<<d[1].a<<")"<<"+"
				<<(d[2].c)*(d[3].a)-(d[2].a)*(d[3].c)<<"(y-"<<d[1].b<<")"<<"+"
				<<(d[2].a)*(d[3].b)-(d[3].a)*(d[2].b)<<"(z-"<<d[1].c<<")"<<"=0"<<endl;

		  }
		  if(t==2)
		  {
			  d[4].setpoint(1.0,2.0,3.0);
			  d[0].setvector(1.0,2.0,3.0);
			  cout<<"����ƽ�淽��Ϊ��"<<endl;
			  cout<<d[0].a<<"(x-"<<d[4].a<<")"<<"+"
				  <<d[0].b<<"(y-"<<d[4].b<<")"<<"+"
				  <<d[0].c<<"(z-"<<d[4].c<<")"<<"=0"<<endl;
		  }
		  else 
			  cout<<"��������";
	  }
	  else if(k==3)
	  {
	    int g;
		double w;
		double W;
		cout<<"����������������1������㵽ֱ�߾�������2������㵽ƽ���������3��";
			cin>>g;
			if(g==1)
			{
				d[1].setpoint(1.0,2.0,3.0);
		        d[2].setpoint(1.0,2.0,3.0);
				w=(d[1].a-d[2].a)*(d[1].a-d[2].a)+(d[2].b-d[2].b)*(d[2].b-d[2].b)+(d[1].c-d[2].c)*(d[1].c-d[2].c);
				cout<<"��������Ϊ��"<<" "<<sqrt(w)<<endl;
			}
			else if(g==2)
			{
				d[3].setpoint(1.0,2.0,3.0);
				z[1].setline(1.0,2.0,3.0,4.0);
				w=z[1].a*z[1].a+z[1].b*z[1].b+z[1].c*z[1].c;
				W=(d[3].a*z[1].a+d[3].b*z[1].b+d[3].c*z[1].c+z[1].d)/sqrt(w);
				cout<<"�㵽ֱ�ߵľ���Ϊ��"<<W<<endl;
            }
			else if(g==3)
			{
			    d[3].setpoint(1.0,2.0,3.0);
				m[1].setplane(1.0,2.0,3.0,4.0);
				w=m[1].a*m[1].a+m[1].b*m[1].b+m[1].c*m[1].c;
				W=(d[3].a*m[1].a+d[3].b*m[1].b+d[3].c*m[1].c+m[1].d)/sqrt(w);
				cout<<"�㵽ƽ��ľ���Ϊ��"<<W<<endl;
			}
			else
				cout<<"��������"<<endl;
      }
	  else if(k==4)
	  {
	    int h;
		double w;
		cout<<"����ռ�ֱ�ߵ�λ������������1��"<<endl<<"����ռ�ƽ��ĵ�λ����������2��"<<endl;
		cin>>h;
		if (h==1)
		{
		  cout<<"����ֱ���ϵ������㣺"<<endl;
		  d[1].setpoint(1.0,2.0,3.0);
		  d[2].setpoint(1.0,2.0,3.0);
		  d[3].a=d[1].a-d[2].a;d[3].b=d[1].b-d[2].b;d[3].c=d[1].c-d[2].c;
		  w=d[3].a*d[3].a+d[3].b*d[3].b+d[3].c*d[3].c;
		  cout<<"ֱ�ߵ�λ��������Ϊ��"<<endl;
		  cout<<"("<<d[3].a<<"/��"<<w<<","<<d[3].b<<"/��"<<w<<","<<d[3].c<<"/��"<<w<<")"<<endl;
		  
		}
		else if(h==2)
		{
			m[1].setplane(1.0,2.0,3.0,4.0);
			w=m[1].a*m[1].a+m[1].b*m[1].b+m[1].c*m[1].c;
			cout<<"ƽ�浥λ������Ϊ��"<<endl;
			cout<<"("<<m[1].a<<"/��"<<w<<","<<m[1].b<<"/��"<<w<<","<<m[1].c<<"/��"<<w<<")"<<endl;
		}
		else 
			cout<<"��������"<<endl;
	  }
	  else if(k==5)
	  {
	    int h;
		cout<<"�жϵ���ֱ�ߵĹ�ϵ����1��"<<endl;
		cout<<"�ж�ֱ����ֱ�ߵĹ�ϵ����2��"<<endl;
		cout<<"�жϵ�����Ĺ�ϵ����3��"<<endl;
		cout<<"�ж�ֱ����ƽ��Ĺ�ϵ����4;"<<endl;
		cout<<"�ж�ƽ����ƽ��֮��Ĺ�ϵ����5;"<<endl;
		cin>>h;
		if(h==1)
		{
		   d[1].setpoint(1.0,2.0,3.0);
		   z[1].setline(1.0,2.0,3.0,4.0);
		   if(d[1].a*z[1].a+d[1].b*z[1].b+d[1].c*z[1].c+z[1].d==0)
			   cout<<"��������"<<endl;
		   else 
			   cout<<"��������"<<endl;

		}
		else if(h==2)
		{ 
		  double w,q;
		  cout<<"����һ��ֱ���ϵ������㣺"<<endl;
		  d[1].setpoint(1.0,2.0,3.0);
		  d[2].setpoint(1.0,2.0,3.0);
		  d[3].a=d[1].a-d[2].a;d[3].b=d[1].b-d[2].b;d[3].c=d[1].c-d[2].c;
		  w=d[3].a*d[3].a+d[3].b*d[3].b+d[3].c*d[3].c;
		  cout<<"������һ��ֱ���ϵ������㣺"<<endl;
		  d[4].setpoint(1.0,2.0,3.0);
		  d[5].setpoint(1.0,2.0,3.0);
		  d[0].a=d[4].a-d[5].a;d[0].b=d[4].b-d[5].b;d[0].c=d[4].c-d[5].c;
		  q=d[0].a*d[0].a+d[0].b*d[0].b+d[0].c*d[0].c;
		  if((d[3].a*d[3].a)/w==(d[0].a*d[0].a)/q&&(d[3].b*d[3].b)/w==(d[0].b*d[0].b)/q&&(d[3].c*d[3].c)/w==(d[0].c*d[0].c)/q)
			  cout<<"��ֱ��ƽ��"<<endl;
		  else if(d[3].a*d[0].a+d[3].b*d[0].b+d[3].c*d[3].c==0)
			  cout<<"��ֱ�ߴ�ֱ"<<endl;
		  else
			  cout<<"��ֱ������"<<endl;

		}
		else if(h==3)
		{
			d[1].setpoint(1.0,2.0,3.0);
			m[1].setplane(1.0,2.0,3.0,4.0);
			if(d[1].a*m[1].a+d[1].b*m[1].b+d[1].c*m[1].c+m[1].d==0)
				cout<<"��������"<<endl;
			else
				cout<<"��������"<<endl;
		}
		else if(h==4)
		{
		  double w,q;
		  cout<<"����һ��ֱ���ϵ������㣺"<<endl;
		  d[1].setpoint(1.0,2.0,3.0);
		  d[2].setpoint(1.0,2.0,3.0);
		  d[3].a=d[1].a-d[2].a;d[3].b=d[1].b-d[2].b;d[3].c=d[1].c-d[2].c;
		  w=d[3].a*d[3].a+d[3].b*d[3].b+d[3].c*d[3].c;
		  m[1].setplane(1.0,2.0,3.0,4.0);
		  q=m[1].a*m[1].a+m[1].b*m[1].b+m[1].c*m[1].c;
		  if(d[3].a*m[1].a+d[3].b*m[1].b+d[3].c*m[1].c==0)
		  {
		     cout<<"ֱ������ƽ�У�"<<endl;
		  }
		  else if((d[3].a*d[3].a)/w==(m[1].a*m[1].a)/q&&(d[3].b*d[3].b)/w==(m[1].b*m[1].b)/q&&(d[3].c*d[3].c)/w==(m[1].c*m[1].c)/q)
		  {
		     cout<<"ֱ����ƽ�洹ֱ��"<<endl;
		  }
		  else
			  cout<<"ֱ����ƽ���ཻ��"<<endl;

		}
		else if(h==5)
		{
		   double w,q;
			cout<<"�����һ��ƽ�棺"<<endl;
			m[1].setplane(1.0,2.0,3.0,4.0);
			cout<<"����ڶ���ƽ�棺"<<endl;
			m[2].setplane(1.0,2.0,3.0,4.0);
			w=m[1].a*m[1].a+m[1].b*m[1].b+m[1].c*m[1].c;
			q=m[2].a*m[2].a+m[2].b*m[2].b+m[2].c*m[2].c;
			if(m[1].a*m[2].a+m[1].b*m[2].b+m[1].c*m[2].c==0)
		  {
		     cout<<"�����洹ֱ��"<<endl;
		  }
			else if((m[1].a*m[1].a)/w==(m[2].a*m[2].a)/q&&(m[1].b*m[1].b)/w==(m[2].b*m[2].b)/q&&(m[1].c*m[1].c)/w==(m[2].c*m[2].c)/q)
			{
			  cout<<"������ƽ�У�"<<endl;
			}
			else
				cout<<"�������ཻ"<<endl;
		}
		else 
			cout<<"��������"<<endl;

	  }
	  else if(k==6)
		  break;
	  else 
		cout<<"��������!"<<endl;
	}
	return 0;
  }

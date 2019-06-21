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
	cout<<"        请选择下面的一个功能        "<<endl
		<<"             1 创建直线            "<<endl
		<<"             2 创建平面            "<<endl
		<<"             3 计算距离            "<<endl
		<<"             4 计算向量            "<<endl
		<<"             5 判断关系            "<<endl
		<<"             6   退出              "<<endl
		<<"              请选择：             "<<endl;
	cin>>k;
	if(k==1)
	{  
	    int a;
	   cout<<"两点确定一条直线输入1；"<<endl<<"两个相交平面确定一条直线输入2；"<<endl<<"空间曲线的点斜式输入3；"<<endl;
	   cin>>a;
	   if(a==1)
	   {
		   d[1].setpoint(1.0,2.0,3.0);
		   d[2].setpoint(1.0,2.0,3.0);
		   cout<<"空间直线方程为："<<endl;
		   cout<<"(x-"<<d[1].a<<")/"<<d[2].a-d[1].a<<"="
			   <<"(y-"<<d[1].b<<")/"<<d[2].b-d[1].b<<"="
			   <<"(z-"<<d[1].c<<")/"<<d[2].c-d[1].c<<endl;
	   }
	   else if(a==2)
	   {
		   m[1].setplane(1.0,2.0,3.0,4.0);
		   m[2].setplane(1.0,2.0,3.0,4.0);
		   cout<<"由两平面相交所得直线方程为："<<endl;
		   cout<<m[1].a-m[2].a<<"x+"
			   <<m[1].b-m[2].b<<"y+"
			   <<m[1].c-m[2].c<<"z+"
			   <<m[1].d-m[2].d<<"=0";
	   }
	   else if(a==3)
	   {
		  d[3].setvector(1.0,2.0,3.0);
		  d[4].setpoint(1.0,2.0,3.0);
		  cout<<"直线方程为："<<endl;
		  cout<<"(x-"<<d[4].a<<")/"<<d[3].a<<"="
			  <<"(y-"<<d[4].b<<")/"<<d[3].b<<"="
			  <<"(z-"<<d[4].c<<")/"<<d[3].c<<endl;
	   }
	   else 
		   cout<<"输入有误！";
	}
	  else if(k==2)
	  {
	      int t;
		  cout<<"三个不共线的点确定一个平面输入1；"<<endl<<"一个点和一个法向量确定一个平面输入2；"<<endl;
		  cin>>t;
		  if(t==1)
		  { 
			d[1].setpoint(1.0,2.0,3.0);
		    d[2].setpoint(1.0,2.0,3.0);
			d[3].setpoint(1.0,2.0,3.0); 
			cout<<"所得平面方程为："<<endl;
			cout<<(d[2].b)*(d[3].c)-(d[2].c)*(d[3].b)<<"(x-"<<d[1].a<<")"<<"+"
				<<(d[2].c)*(d[3].a)-(d[2].a)*(d[3].c)<<"(y-"<<d[1].b<<")"<<"+"
				<<(d[2].a)*(d[3].b)-(d[3].a)*(d[2].b)<<"(z-"<<d[1].c<<")"<<"=0"<<endl;

		  }
		  if(t==2)
		  {
			  d[4].setpoint(1.0,2.0,3.0);
			  d[0].setvector(1.0,2.0,3.0);
			  cout<<"所得平面方程为："<<endl;
			  cout<<d[0].a<<"(x-"<<d[4].a<<")"<<"+"
				  <<d[0].b<<"(y-"<<d[4].b<<")"<<"+"
				  <<d[0].c<<"(z-"<<d[4].c<<")"<<"=0"<<endl;
		  }
		  else 
			  cout<<"输入有误！";
	  }
	  else if(k==3)
	  {
	    int g;
		double w;
		double W;
		cout<<"计算两点间距离输入1；计算点到直线距离输入2；计算点到平面距离输入3；";
			cin>>g;
			if(g==1)
			{
				d[1].setpoint(1.0,2.0,3.0);
		        d[2].setpoint(1.0,2.0,3.0);
				w=(d[1].a-d[2].a)*(d[1].a-d[2].a)+(d[2].b-d[2].b)*(d[2].b-d[2].b)+(d[1].c-d[2].c)*(d[1].c-d[2].c);
				cout<<"两点间距离为："<<" "<<sqrt(w)<<endl;
			}
			else if(g==2)
			{
				d[3].setpoint(1.0,2.0,3.0);
				z[1].setline(1.0,2.0,3.0,4.0);
				w=z[1].a*z[1].a+z[1].b*z[1].b+z[1].c*z[1].c;
				W=(d[3].a*z[1].a+d[3].b*z[1].b+d[3].c*z[1].c+z[1].d)/sqrt(w);
				cout<<"点到直线的距离为："<<W<<endl;
            }
			else if(g==3)
			{
			    d[3].setpoint(1.0,2.0,3.0);
				m[1].setplane(1.0,2.0,3.0,4.0);
				w=m[1].a*m[1].a+m[1].b*m[1].b+m[1].c*m[1].c;
				W=(d[3].a*m[1].a+d[3].b*m[1].b+d[3].c*m[1].c+m[1].d)/sqrt(w);
				cout<<"点到平面的距离为："<<W<<endl;
			}
			else
				cout<<"输入有误！"<<endl;
      }
	  else if(k==4)
	  {
	    int h;
		double w;
		cout<<"计算空间直线单位方向向量输入1；"<<endl<<"计算空间平面的单位法向量输入2；"<<endl;
		cin>>h;
		if (h==1)
		{
		  cout<<"输入直线上的两个点："<<endl;
		  d[1].setpoint(1.0,2.0,3.0);
		  d[2].setpoint(1.0,2.0,3.0);
		  d[3].a=d[1].a-d[2].a;d[3].b=d[1].b-d[2].b;d[3].c=d[1].c-d[2].c;
		  w=d[3].a*d[3].a+d[3].b*d[3].b+d[3].c*d[3].c;
		  cout<<"直线单位方向向量为："<<endl;
		  cout<<"("<<d[3].a<<"/√"<<w<<","<<d[3].b<<"/√"<<w<<","<<d[3].c<<"/√"<<w<<")"<<endl;
		  
		}
		else if(h==2)
		{
			m[1].setplane(1.0,2.0,3.0,4.0);
			w=m[1].a*m[1].a+m[1].b*m[1].b+m[1].c*m[1].c;
			cout<<"平面单位法向量为："<<endl;
			cout<<"("<<m[1].a<<"/√"<<w<<","<<m[1].b<<"/√"<<w<<","<<m[1].c<<"/√"<<w<<")"<<endl;
		}
		else 
			cout<<"输入有误！"<<endl;
	  }
	  else if(k==5)
	  {
	    int h;
		cout<<"判断点与直线的关系输入1；"<<endl;
		cout<<"判断直线与直线的关系输入2；"<<endl;
		cout<<"判断点与面的关系输入3；"<<endl;
		cout<<"判断直线与平面的关系输入4;"<<endl;
		cout<<"判断平面与平面之间的关系输入5;"<<endl;
		cin>>h;
		if(h==1)
		{
		   d[1].setpoint(1.0,2.0,3.0);
		   z[1].setline(1.0,2.0,3.0,4.0);
		   if(d[1].a*z[1].a+d[1].b*z[1].b+d[1].c*z[1].c+z[1].d==0)
			   cout<<"点在线上"<<endl;
		   else 
			   cout<<"点在线外"<<endl;

		}
		else if(h==2)
		{ 
		  double w,q;
		  cout<<"输入一条直线上的两个点："<<endl;
		  d[1].setpoint(1.0,2.0,3.0);
		  d[2].setpoint(1.0,2.0,3.0);
		  d[3].a=d[1].a-d[2].a;d[3].b=d[1].b-d[2].b;d[3].c=d[1].c-d[2].c;
		  w=d[3].a*d[3].a+d[3].b*d[3].b+d[3].c*d[3].c;
		  cout<<"输入另一条直线上的两个点："<<endl;
		  d[4].setpoint(1.0,2.0,3.0);
		  d[5].setpoint(1.0,2.0,3.0);
		  d[0].a=d[4].a-d[5].a;d[0].b=d[4].b-d[5].b;d[0].c=d[4].c-d[5].c;
		  q=d[0].a*d[0].a+d[0].b*d[0].b+d[0].c*d[0].c;
		  if((d[3].a*d[3].a)/w==(d[0].a*d[0].a)/q&&(d[3].b*d[3].b)/w==(d[0].b*d[0].b)/q&&(d[3].c*d[3].c)/w==(d[0].c*d[0].c)/q)
			  cout<<"两直线平行"<<endl;
		  else if(d[3].a*d[0].a+d[3].b*d[0].b+d[3].c*d[3].c==0)
			  cout<<"两直线垂直"<<endl;
		  else
			  cout<<"两直线异面"<<endl;

		}
		else if(h==3)
		{
			d[1].setpoint(1.0,2.0,3.0);
			m[1].setplane(1.0,2.0,3.0,4.0);
			if(d[1].a*m[1].a+d[1].b*m[1].b+d[1].c*m[1].c+m[1].d==0)
				cout<<"点在面上"<<endl;
			else
				cout<<"点在面外"<<endl;
		}
		else if(h==4)
		{
		  double w,q;
		  cout<<"输入一条直线上的两个点："<<endl;
		  d[1].setpoint(1.0,2.0,3.0);
		  d[2].setpoint(1.0,2.0,3.0);
		  d[3].a=d[1].a-d[2].a;d[3].b=d[1].b-d[2].b;d[3].c=d[1].c-d[2].c;
		  w=d[3].a*d[3].a+d[3].b*d[3].b+d[3].c*d[3].c;
		  m[1].setplane(1.0,2.0,3.0,4.0);
		  q=m[1].a*m[1].a+m[1].b*m[1].b+m[1].c*m[1].c;
		  if(d[3].a*m[1].a+d[3].b*m[1].b+d[3].c*m[1].c==0)
		  {
		     cout<<"直线与面平行！"<<endl;
		  }
		  else if((d[3].a*d[3].a)/w==(m[1].a*m[1].a)/q&&(d[3].b*d[3].b)/w==(m[1].b*m[1].b)/q&&(d[3].c*d[3].c)/w==(m[1].c*m[1].c)/q)
		  {
		     cout<<"直线与平面垂直！"<<endl;
		  }
		  else
			  cout<<"直线与平面相交！"<<endl;

		}
		else if(h==5)
		{
		   double w,q;
			cout<<"输入第一个平面："<<endl;
			m[1].setplane(1.0,2.0,3.0,4.0);
			cout<<"输入第二个平面："<<endl;
			m[2].setplane(1.0,2.0,3.0,4.0);
			w=m[1].a*m[1].a+m[1].b*m[1].b+m[1].c*m[1].c;
			q=m[2].a*m[2].a+m[2].b*m[2].b+m[2].c*m[2].c;
			if(m[1].a*m[2].a+m[1].b*m[2].b+m[1].c*m[2].c==0)
		  {
		     cout<<"面与面垂直！"<<endl;
		  }
			else if((m[1].a*m[1].a)/w==(m[2].a*m[2].a)/q&&(m[1].b*m[1].b)/w==(m[2].b*m[2].b)/q&&(m[1].c*m[1].c)/w==(m[2].c*m[2].c)/q)
			{
			  cout<<"面与面平行！"<<endl;
			}
			else
				cout<<"面与面相交"<<endl;
		}
		else 
			cout<<"输入有误！"<<endl;

	  }
	  else if(k==6)
		  break;
	  else 
		cout<<"输入有误!"<<endl;
	}
	return 0;
  }

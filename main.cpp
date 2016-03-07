#include<iostream>
using namespace std;
#define random()(rand()%100)
class shuzi         //shuzi类的功能是产生随机数
{
public:
	int display()    //调用display产生随机整数
	{
		int num=random();
		cout<<num<<"  ";
		return 0;
	}
	int display1()  //调用display1产生随机真分数
	{
		int num1=random();
	    int num2=random();
		for(;;)
		{	    
			if((num1 <= num2) && (num2 != 0))		//判断分子小于分母，且分母不为0	
			{
				cout<<num1<<"/"<<num2<<"  ";	  
				break;
			}
			if((num2 <= num1) && (num1 != 0))			
			{
				cout<<num2<<"/"<<num1<<"  ";
				break;
			}
		}
		return 0;
	}
};
void main()
{
	char add='+';
	char sec='-';
	char min='*';
	char div='/';
	int i;
	int n;
	cout<<"请输入数量：";
	cin>>n;
	cout<<"请选择打印方式：";
	cout<<"请选择是否有除法：";
	cout<<"请选择是否有括号：";
	cout<<"数值范围：";
	cout<<"";
	cout<<"";
	shuzi x;
    for( i=0;i<n;i++)   //产生10个纯整数四则运算
	{
		cout<<"("<<i+1<<") ";
		x.display();
	    cout<<add;	
	    x.display();
    	cout<<sec;
    	x.display();
    	cout<<min;
    	x.display();
        cout<<div;
	   for(;;)       //判断除数是否为0
	   {
		   int t=random();
	  	   if(t != 0)
		   {		
			   cout<<t;		
			   break;
		   }
	   }
	   cout<<"="<<endl;
	}
	for(i=0;i<n;i++)  //产生10个纯分数四则运算
	{
		cout<<"("<<i+11<<")";
		x.display1();
	    cout<<add<<"  ";	
	    x.display1();
    	cout<<sec<<"  ";
    	x.display1();
    	cout<<min<<"  ";
    	x.display1();
        cout<<div<<"  ";
		x.display1();
	   cout<<"="<<endl;
	}
	for(i=0;i<n;i++)      //输出10个整数和分数混合的四则运算
	{
		cout<<"("<<i+21<<")";
		x.display();
	    cout<<add<<"  ";	
	    x.display1();
    	cout<<sec<<"  ";
    	x.display();
    	cout<<min<<"  ";
    	x.display1();
        cout<<div<<"  ";
		x.display1();
	   cout<<"="<<endl;
	}
}
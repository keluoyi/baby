#include<iostream>
using namespace std;
#define random()(rand()%100)
class shuzi         //shuzi��Ĺ����ǲ��������
{
public:
	int display()    //����display�����������
	{
		int num=random();
		cout<<num<<"  ";
		return 0;
	}
	int display1()  //����display1������������
	{
		int num1=random();
	    int num2=random();
		for(;;)
		{	    
			if((num1 <= num2) && (num2 != 0))		//�жϷ���С�ڷ�ĸ���ҷ�ĸ��Ϊ0	
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
	cout<<"������������";
	cin>>n;
	cout<<"��ѡ���ӡ��ʽ��";
	cout<<"��ѡ���Ƿ��г�����";
	cout<<"��ѡ���Ƿ������ţ�";
	cout<<"��ֵ��Χ��";
	cout<<"";
	cout<<"";
	shuzi x;
    for( i=0;i<n;i++)   //����10����������������
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
	   for(;;)       //�жϳ����Ƿ�Ϊ0
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
	for(i=0;i<n;i++)  //����10����������������
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
	for(i=0;i<n;i++)      //���10�������ͷ�����ϵ���������
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
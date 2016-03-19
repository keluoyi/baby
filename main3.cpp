//���� ��˶  2015.3.19
//��������3
#include<iostream>
#include<fstream> 
#include<iomanip>
#include<cmath>  
#include<vector>
#include<string>  
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define random() (rand()%1000) 
const int MAX=1000;

  /*����ģ��*/
  class Input
  {
  public:
      Input()
      {
          for( int i = 0;i < MAX;i++ )
              Str_input[i] = '\0';
      }
      char Str_input[MAX];
      void inStr()
      {
          cin>>Str_input;
      }
  };

  /*���ģ��*/
  class Output
  {
  public:
      Output()
      {
          result = 0;
      }
      double getRes( double res )
      {
          result = res;		
		  return result;
      }

  private:
      double result;
  };

  /*�����õĴ洢�ṹ*/
  template <class Type>
  class STACK{                 
     private:
         Type base[MAX];
         int Size;
     public:
         STACK()
		 {
			 Size=0;
		 };
         void push(Type a)     
         {
             base[Size]=a;
            Size++;
         }
         Type pop()           
         {
             return base[--Size];
         }
         int size()
        {return Size;}
  };


  /*�����ģ��*/
  class jisuan
  {
  public: 
      bool shuhanshu(char);                 
      bool fuhanshu(char);                 
      int jckh(char);                  
      bool jcxsd(char *);              
      int pdyxj(char);                 
      double ToData(char*);             
      double Call(double,double,char);    
      int ppkh(char* buffer,int pos); 
      void Opr( STACK<char>&, STACK<double>&, int& ); 
      double Calculate(char*, double& );   

  };
  bool jisuan::shuhanshu(char ch)      
  {
      return ((ch>='0'&&ch<='9')||ch=='.')?true:false;
  }
  bool jisuan::fuhanshu(char ch)     
 {
     return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='#')?true:false;
 }
 int jisuan::jckh(char ch)
 {
     if(ch=='(')
        return 1;
     if(ch==')')
        return -1;
     return 0;
 }
 bool jisuan::jcxsd(char *ch)
 {
     int a=0;
     for(int i=0;i<strlen(ch);i++)
         if(ch[i]=='.')          
             a++;
        if(a>1)
             return false;
         return true;
 }
 int jisuan::pdyxj(char ch)          //���ŵ����ȼ���
 {
     switch(ch)
     {
     case '+':
         return 0;
     case '-':
         return 0;
     case '*':
         return 1;
     case '/':
         return 1;
	 case '#':
		 return 0;
     default:
         return -1;
     }
 }
 double jisuan::ToData(char* ch)   //������ת��Ϊ��ֵ
 {
     int i,j,sumn=0;
     double sum=0.0;
     if(!jcxsd(ch)) return 0.0;
     for(i=0;i<strlen(ch);i++)           
     {
         if(ch[i]!='.')
             sumn=sumn*10+(ch[i]-'0');
         else break;
     }
     if(i<strlen(ch))
         for(j=i+1;j<strlen(ch);j++)        
             sum=sum*10+(ch[j]-'0');
     sum /= pow(10.0,(double)(strlen(ch)-1-i));
     return (sum+sumn);                    
 }
 double jisuan::Call(double sum,double data,char ch)
 {
     double ans=0.0;
     switch(ch)
     {
     case '+':
         ans=sum+data;
         break;
     case '-':
         ans=sum-data;
         break;
     case '*':
         ans=sum*data;
         break;
     case '/':
         if( data != 0.0 )
             ans=sum/data;
         else
         {
             cout<<"������ֳ�0������ֹ��\n";
             system("pause");
             exit(1);
         }
         break;
	 case '#':
		 return 0;
     default:ans=0.0;
         break;
     }
     return ans;
 }
 int jisuan::ppkh(char* buffer,int pos)     //����ջ�ҵ�ƥ�������
 {
     STACK<char> Temp;
     int i;
     for(i=pos;i<strlen(buffer);i++)
     {
         if(jckh(buffer[i])==1)
             Temp.push('0');
         if(jckh(buffer[i])==-1)
         {
             Temp.pop();
             if(Temp.size()==0) return i;
         }
     }
     return -1;
 }
 void jisuan::Opr(STACK<char>& symbol,STACK<double>& data,int& mark)
 {
     double sum;
     while(symbol.size()!=0)
     {
         char tem=symbol.pop();
         int temp=pdyxj(tem);
         symbol.push(tem);
         if(temp<mark)
             break;
         else{
             sum=Call(data.pop(),data.pop(),symbol.pop());
             data.push(sum);
         }
     }
 }
 double jisuan::Calculate(char* buffer,double& sum)   //�ַ�������͸�����������
 {
     STACK<double> data;
     STACK<char> symbol;
     double ans;
     char temp[MAX];
     int ct=0,mark=0,tp=0;
     data.push(sum);
     while(ct<=strlen(buffer))
     {
         if(shuhanshu(buffer[ct]))            //��������ֻ�С����
         {
             while( ct < strlen(buffer) && shuhanshu(buffer[ct]) )
                 temp[tp++]=buffer[ct++];
             temp[tp]='\0';
             tp=0;                         //����������Ҳ��С��Ϊֹ
             ans=ToData(temp);             //�Ѷ������ַ���ת��Ϊ��
             data.push(ans);

             if(ct==strlen(buffer))        //�Ѿ������ַ���ĩβ
             {
                 mark=0;
                 Opr(symbol,data,mark);    
                 sum=data.pop();           
                 return sum;               
             }
             else{
                 int mark=pdyxj(buffer[ct]);
                 Opr(symbol,data,mark);     //����
             }
         }
         else if(fuhanshu(buffer[ct]))         //����������
             symbol.push(buffer[ct++]);     //�������symbolջ
         else
         {
             char BF[100];int k=0;          //��������ǣ���ֻ��������
             while( jckh( buffer[ct] ) != 1 && ct <= strlen(buffer) )
                 BF[k++] = buffer[ct++];
             BF[k]='\0';
             if(jckh(buffer[ct])==1)       //һ�����������ţ�Ѱ����ƥ���������
             {
                 int i,j;
                 char Temp[100];
                 for(i=ct+1,j=0;i<ppkh(buffer,ct);i++,j++)
                     Temp[j]=buffer[i];     //����������е��ַ�������Temp
                 Temp[j]='\0';
                 data.push(Calculate(Temp,sum)); 
                           
                 ct+=(strlen(Temp)+1);       
                 if(ct+1==strlen(buffer))   
                 {
                     mark=0;
                     Opr(symbol,data,mark);
                     sum=data.pop();
                     return sum;
                 }
                 else
                 {
                     mark=pdyxj(buffer[ct+1]); //���ǵĻ���������
                     Opr(symbol,data,mark);
                 }
                 ct++;                           //������һ���ַ�
             }
         }
     }
     return 0.;
 }

string  i_s(int shuzi)
{
	int temp=abs(shuzi);
	char str[100];
	itoa(temp,str,10);
	string str1=str;
	return str1;
}

string zuhe (string str1,string str2,char x)
{
	string expression;
	expression=str1+x+str2;
	return expression;
}

 //�Ƿ��г˳���
char operator_random(int c1)
{
    char o;
	int c,c2;
	if(c1==0)
	{
		c2=2;
	}
	if(c1==1)
	{
		c2=4;
	}
    c= (rand() % 100)%c2;
    if (c == 0) o = '+';
    else if (c == 1) o = '-';
    else if (c == 2) o = '*';
    else o = '/';
    return o;
}

void main()
{
    srand((unsigned)time(NULL));//����ʱ������ ����ʹ����ÿ�εõ��Ľ������ͬ 
	int mul_div,number,output_mode,value_range,num_1,num_2,plus_or_minus,jump,yushu,kuohao,score=0;
	double answer=0.0,solution;
	string str_1,str_2,temp;
	char operator_r;
	char storage[100];
	cout<<"    �Ƿ��г˳�����<0>û��   <1>�У�";
	cin>>mul_div;
	cout<<"    �������ţ�    <0>û��   <1>�У�";
	cin>>kuohao;
	cout<<"    �Ӽ����޸�����<0>û��   <1>�У�";
	cin>>plus_or_minus;
	cout<<"    ��������������<0>û��   <1>�У�";
	cin>>yushu;
	cout<<"    ��Ŀ��������<0>���ļ������ ��<1>�ڴ�ֱ�������";
	cin>>output_mode;
	cout<<"    ��������ֵ��Χ��";
	cin>>value_range;
	
	cout<<"    ��������Ŀ��������";
	cin>>number;
	cout<<endl;

	string *expression=new string[number];//string expression[number];
	ofstream fout;
	if(output_mode==0)
	{
		fout.open("yunsuan.txt");
		fout<<number<<"������������㣺"<<endl;
	}
	else
	{
		cout<<number<<"������������㣺"<<endl;
	}

    for (int i = 0; i < number; i++)
    {
       num_1=random()%value_range+1;
	   num_2=random()%value_range+1;
	   int length;//����ʽ�ĳ���   
	   int j=num_1-num_2;
	   int x=num_1%num_2;
	   operator_r=operator_random(mul_div);
	   length=random()%9+2;
	   str_1=i_s(num_1);
	   str_2=i_s(num_2);
	   expression[i]=zuhe(str_1,str_2,operator_r);
	   if(length>2)
	   {
		   for(length;length>2;length --)
		   {
			   operator_r=operator_random(mul_div);
			   str_1=expression[i];
			   if(kuohao==1)
			   {
				   jump=random()%2;
				   if(jump==0)
				   {
					   str_1='('+str_1+')';
				   }
			   }
			   operator_r=operator_random(mul_div);
			   num_2=random()%value_range+1;
			   str_2=i_s(num_2);
		       jump=random()%2;
			   if (jump==0)
			   {
				   temp=str_1;
				   str_1=str_2;
				   str_2=temp;
			   }
			   expression[i]=zuhe(str_1,str_2,operator_r);
			  
		   }   
	   }
	   if(output_mode==1)
	   {
		  
		   strcpy(storage,expression[i].c_str());
		 
            cout.precision(12);			//���þ���Ϊ12

			Input in;
            jisuan cl;
			Output out;
   
			answer=out.getRes( cl.Calculate(storage,answer) ); //����ģ��

			if(plus_or_minus==0 )
			{	
				if(answer>0)
				{				
					cout<<"    ("<<i+1<<")"<<expression[i]<<"="<<endl;    									
					cout<<"    ��������";							
					cin>>solution;							
					cout<<"    ��ȷ�����"<<answer<<endl;							
					if(answer==solution)						
					{							
						score++;								
						cout<<"    ��ȷ������"<<endl;								
						cout<<endl;							
					}						
					else					
					{							
						cout<<"    ���ź�������"<<endl;							
						cout<<endl;							
					}
				}    //������С��0
				else
				{
					i=i-1;
				}
			}
			else  //�����Ҫ��Ӽ��޸���
			{
				cout<<"    ("<<i+1<<")"<<expression[i]<<"="<<endl;    									
					cout<<"    ��������";							
					cin>>solution;							
					cout<<"    ��ȷ�����"<<answer<<endl;							
					if(answer==solution)						
					{							
						score++;								
						cout<<"    ��ȷ������"<<endl;								
						cout<<endl;							
					}						
					else					
					{							
						cout<<"    ���ź�������"<<endl;							
						cout<<endl;							
					}
			}
	   }   
	   else
	   {
		   fout<<expression[i]<<"="<<endl;      
	   }
	}
	if(output_mode==1)
	{
		cout<<"    �÷֣�"<<score<<endl;
		cout<<endl;
	}
	
	if(output_mode==1) 
	{
		fout.close();
	}
} 


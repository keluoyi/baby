#include<iostream>
#include<time.h>
#include<fstream>
#define random() (rand()%100)
using namespace std;

void main()
{
	ofstream outfile;
	outfile.open("a.txt");
	char add='+';
	char sec='-';
	char min='*';
	char div='/';
	int length;
	cout<<"��������Ŀ������";
	cin>>length;
    
	bool printway;
	cout<<"��ѡ���ӡ��ʽ  <1>txt�ĵ�  <0>��Ļ��";
	cin>>printway;
	
	bool divsion;
	cout<<"��ѡ���Ƿ��г���<1>�г���  <0>�޳�����";
	cin>>divsion;
	
	bool bracket;
	cout<<"��ѡ���Ƿ�������<1>������  <0>�����ţ�";
	cin>>bracket;

	bool negative;
	cout<<"�Ӽ����޸���<1>�и���  <0>�޸�����";
	cin>>negative;
	
	bool remainder;
	cout<<"������������<1������>  <0>��������";//�ȼ��������ٸ����������
	cin>>remainder;
	
	int widestart;
	int wideend;
	cout<<"��ֵ��Χ(��ʼ---��ֹ)��";
	cin>>widestart;
	cin>>wideend;

	int i;//ѭ������
	int j;//ѭ������
	int firstnum;
	int secondnum;
	int thirdnum;
	int fourthnum;
	int fifthnum;
	 srand((int)time(NULL));
	
	  
	 for( i=0;i<length;i++)                       //ѭ�����length����ʽ
	 {
		 firstnum=rand()%wideend+widestart;		
	    secondnum=rand()%wideend+widestart;	
        thirdnum=rand()%wideend+widestart;	
	    fourthnum=rand()%wideend+widestart;
	    fifthnum=rand()%wideend+widestart;


		if(negative)/*if negative =1   ���Ӽ����ڸ���ʱ*/   
		{	
			if(printway)           //�������txt
			{
				outfile<<firstnum;
				outfile<<add;
			}
			else
			{
				cout<<firstnum;   
				cout<<add;		
			}        
			if(bracket)		 //��ѡ�����������������
			{
				if(printway)
				{
					outfile<<"(";
				}
				else
				{
					cout<<"(";	
				}
			}                //��������Ž���
			if(printway)
			{
				outfile<<secondnum;
				outfile<<sec;
				outfile<<thirdnum;	
				outfile<<min;
				outfile<<fourthnum;
			}
			else
			{
				cout<<secondnum;	
				cout<<sec;
				cout<<thirdnum;	
				cout<<min;
				cout<<fourthnum;
			}                              //�������֮ǰ����
			if(bracket)		
			{
				if(printway)
				{
					outfile<<")";
				}
				else
				{
					cout<<")";	
				}
			}               //���������


            /*******************************************************************************************�г���������û������**/
			if(divsion)		    //�г��������
			{
					if(bracket)//if have bracket,panduan shifou you yushu
					{
						if (!remainder)           //���û������
						{
							for(i=0;;)
							{
								int result=( secondnum-thirdnum*fourthnum )   /fifthnum;
								if( result==0)    
								{
									if(printway)
									{
										outfile<<div<<fifthnum;
									}
									else
									{
										cout<<div<<fifthnum;
									}
									break;
								}
								else
								{
									fifthnum=rand()%wideend+widestart;
								}
							}
						}
					}


					/**************************************************************************************�г���������������********/
					else//meiyou kuohao panduan shifou you yushu
					{

						if (!remainder)  //û�����������
						{

							for(i=0;;)
							{
								int result1=(thirdnum*fourthnum  )  /   fifthnum;
								if(   result1 ==0)   //�ж��Ƿ�����������û�У������
								{
									if(printway)
									{
										outfile<<div<<fifthnum<<"="<<endl;
									}
									else
									{
										cout<<div<<fifthnum<<"="<<endl;
									}
									break;
								}	
								else
								{
									fifthnum=rand()%wideend+widestart;   //�������������������ɳ���
								}
							}
						}
						
					}			
			}
	
			if(printway)
			{
				outfile<<"="<<endl;
			}
			else
			{
				cout<<"="<<endl;
			}
			
        }



		else/* negative=0               û�и��������*/
		{
			if(printway)
			{
				outfile<<firstnum;    
				outfile<<add;		
			}
			else
			{
				cout<<firstnum;    
				cout<<add;		
			}
			if(bracket)		
			{
				if(printway)
				{
					outfile<<"(";
				}
				else
				{
					cout<<"(";	
				}
			}
			if(printway)
			{
				outfile<<secondnum;	
				outfile<<sec;
				outfile<<thirdnum;	
				outfile<<min;
				outfile<<fourthnum;
			}
			else
			{
				cout<<secondnum;	
				cout<<sec;
				cout<<thirdnum;	
				cout<<min;
				cout<<fourthnum;
			}
			for(j=0;;)       /*  a+b-c*d/e ���ж�b-c*d�����и��� �����и�����ѭ���� û��*/
			{	
				secondnum=rand()%wideend+widestart;
				if(secondnum>(thirdnum*fourthnum))
				{
					if(printway)
					{
						outfile<<firstnum<<add;
					}
					else
					{
						cout<<firstnum<<add;
					}
					if(bracket)
					{
						if(printway)
						{
							outfile<<"(";
						}
						else
						{
							cout<<"(";
						}
					}
					if(printway)
					{
						outfile<<secondnum<<sec<<thirdnum<<min<<fourthnum;
					}
					else
					{
						cout<<secondnum<<sec<<thirdnum<<min<<fourthnum;
					}
				}                    //ѭ������
                			  	  
				if(divsion)
				{
					if(printway)
					{
						outfile<<")"<<div;
					}
					else
					{
						cout<<")"<<div;
					}
					if(bracket)//if have bracket,panduan shifou you yushu
					{
						if (!remainder)
						{
							for(i=0;;)
							{
								int flag=firstnum+( secondnum-thirdnum*fourthnum ) /fifthnum ;//�����ŵ�������ж��Ƿ�������
								if( flag ==0)
								{
									if(printway)
									{
										outfile<<fifthnum;
									}							
									else
									{
										cout<<fifthnum;
									}
									break;
								}
								else
								{
									fifthnum=rand()%wideend+widestart;
								}
							}
						}
						else
						{
							if(printway)
							{
								outfile<<")";
							    outfile<<div<<fifthnum;
							}
							else
							{
								cout<<")";
								cout<<div<<fifthnum;
							}
						}
					}
					else//meiyou kuohao panduan shifou you yushu
					{
						if (!remainder)
						{
							for(i=0;;)
							{
								int flag1= (thirdnum*fourthnum  )/fifthnum;
								if( flag1 ==0)                         //û�����ŵ�������ж������Ƿ�Ϊ0
								{
									if(printway)
									{
										outfile<<div<<fifthnum;
									}
									else
									{
										cout<<div<<fifthnum;
									}
									break;
								}	
								else
								{
									fifthnum=rand()%wideend+widestart;
								}
							}
						}
						else
						{
							if(printway)
							{
								outfile<<")";
							    outfile<<div<<fifthnum;
							}
							else
							{
								cout<<")";
							    cout<<div<<fifthnum;
							}
						
						}
					}
					break;
				}		
				
				if(printway)
		        {
				    outfile<<"="<<endl;
			    }
			    else
			    {
				    cout<<"="<<endl;
			    }				
			}
			
		}
	}
	outfile.close();
}
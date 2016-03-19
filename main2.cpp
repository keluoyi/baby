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
	cout<<"请输入题目数量：";
	cin>>length;
    
	bool printway;
	cout<<"请选择打印方式  <1>txt文档  <0>屏幕：";
	cin>>printway;
	
	bool divsion;
	cout<<"请选择是否有除法<1>有除法  <0>无除法：";
	cin>>divsion;
	
	bool bracket;
	cout<<"请选择是否有括号<1>有括号  <0>无括号：";
	cin>>bracket;

	bool negative;
	cout<<"加减有无负数<1>有负数  <0>无负数：";
	cin>>negative;
	
	bool remainder;
	cout<<"除法有无余数<1有余数>  <0>无余数：";//先计算结果，再根据条件输出
	cin>>remainder;
	
	int widestart;
	int wideend;
	cout<<"数值范围(起始---终止)：";
	cin>>widestart;
	cin>>wideend;

	int i;//循环参数
	int j;//循环参数
	int firstnum;
	int secondnum;
	int thirdnum;
	int fourthnum;
	int fifthnum;
	 srand((int)time(NULL));
	
	  
	 for( i=0;i<length;i++)                       //循环输出length个算式
	 {
		 firstnum=rand()%wideend+widestart;		
	    secondnum=rand()%wideend+widestart;	
        thirdnum=rand()%wideend+widestart;	
	    fourthnum=rand()%wideend+widestart;
	    fifthnum=rand()%wideend+widestart;


		if(negative)/*if negative =1   当加减存在负数时*/   
		{	
			if(printway)           //若输出到txt
			{
				outfile<<firstnum;
				outfile<<add;
			}
			else
			{
				cout<<firstnum;   
				cout<<add;		
			}        
			if(bracket)		 //若选择有括号输出左括号
			{
				if(printway)
				{
					outfile<<"(";
				}
				else
				{
					cout<<"(";	
				}
			}                //输出左括号结束
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
			}                              //输出除法之前的数
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
			}               //输出右括号


            /*******************************************************************************************有除法有括号没有余数**/
			if(divsion)		    //有除法的情况
			{
					if(bracket)//if have bracket,panduan shifou you yushu
					{
						if (!remainder)           //如果没有余数
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


					/**************************************************************************************有除法无括号无余数********/
					else//meiyou kuohao panduan shifou you yushu
					{

						if (!remainder)  //没有余数的情况
						{

							for(i=0;;)
							{
								int result1=(thirdnum*fourthnum  )  /   fifthnum;
								if(   result1 ==0)   //判断是否有余数，若没有，则输出
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
									fifthnum=rand()%wideend+widestart;   //若有余数。则重新生成除数
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



		else/* negative=0               没有负数的情况*/
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
			for(j=0;;)       /*  a+b-c*d/e 则判断b-c*d不能有负数 ，若有负数则循环至 没有*/
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
				}                    //循环结束
                			  	  
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
								int flag=firstnum+( secondnum-thirdnum*fourthnum ) /fifthnum ;//有括号的情况下判断是否有余数
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
								if( flag1 ==0)                         //没有括号的情况下判断余数是否为0
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
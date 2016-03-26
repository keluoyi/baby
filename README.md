# baby
//20133099 王硕 2016.3.24
//一维数组求最大子数组的和
#include <iostream> 
#include <algorithm> 
using namespace std; 
#define MAXN 1003 
int A[MAXN]; 
int Tail[MAXN]; 
 // 动态规划思想，时间复杂度O(n) 
int main() 
{ 
    int length;   //数组长度
	int   i;        //循环变量
	int  tail;     //记录数组结束的位置 
	cout<<"please input the length of array:"<<endl;
    cin >> length; 
	cout<<"please input every number of array:"<<endl;
    for (i=1; i<=length; i++) 
	{
        cin >> A[i]; 
	}                                               // 计算以tail结尾的子数组之和的最大值，即子数组包含第k个数 
    Tail[1] = A[1]; 
    for (tail=2; tail<=length; tail++)                   // tail个阶段 
	{                                 
        Tail[tail] = max(A[tail],Tail[tail-1]+A[tail]); 
	}                                              // 只有两个状态 
                                                   // 因为和最大的子数组肯定以某个数结尾，所以取这length个子数组的最大值
    int All = Tail[1]; 
    for (i=2; i<=length; i++) 
        All = max(All, Tail[i]); 
    cout << "MAX :  "<<All<<"  !"<<endl; 
} 

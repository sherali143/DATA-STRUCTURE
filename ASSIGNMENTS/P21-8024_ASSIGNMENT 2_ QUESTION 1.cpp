#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int postfix_evaluation(string s)
{
	stack<char> st;
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			st.push(s[i]-'0');           // TO CONVERT A CHARACTER IN TO INTEGER I MINUS THE INTEGER WITH THE ASCII VALUE OF 0 ;
		}
		else
		{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			
			switch(s[i])
			{
				case'+':
					st.push(op1+op2);
					break;
					
					
				case'/':
					st.push(op1/op2);
					break;
					
				case'-':
					st.push(op1-op2);
					break;
				
				
				case'*':
					st.push(op1*op2);
					break;
					
				case'^':
					st.push(pow(op1,op2));
					break;
			}
		}
	}
	
	return st.top();
	
}

	int main()
	{
		cout<<"Final Result of post evaluation is :";
		cout<<postfix_evaluation("46+2/5*7+");
		return 0;
	}

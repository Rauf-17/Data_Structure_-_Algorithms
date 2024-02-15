#include<bits/stdc++.h>
#include<stack>
using namespace std;


int precedence(char character)
{

	if (character == '^')
		return 3;

	else if (character == '/' || character == '*')
		return 2;

	else if (character == '+' || character == '-')
		return 1;

	else
		return -1;
}


string inToPost(string str)
    {

	stack<char> st;
	string evaluation = "";

	for (int i = 0; i < str.length(); i++)
	{
		char character = str[i];


		if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')
		|| (character >= '0' && character <= '9'))

			evaluation += character;

		else if (character == '(')
			st.push('(');


		else if (character == ')')
		 {
			while (st.top() != '(')
			{
				evaluation += st.top();
				st.pop();
			}

			st.pop();
		}


		else {

			while (!st.empty() && precedence(str[i]) <= precedence(st.top()))
			{

				evaluation += st.top();

				st.pop();
			}

			st.push(character);
		}
	}


	while (!st.empty())
	{
		evaluation += st.top();
		st.pop();
	}

	return evaluation;
}

int main(){
	string str;
	cout<<"Please Enter an Expression: ";
	cin >> str;
	cout<<endl;
	cout<<"After Converting Infix to Postfix: ";
	cout << inToPost(str);
	return 0;
}

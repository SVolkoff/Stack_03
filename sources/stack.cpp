
#include "stack.hpp"
#include <string>
#include "stack.hpp"

int main()
{
	stack<int> st;
	char ch = ' ';
	while (std::cin >> ch)
	{
		int val = 0;
		switch (ch)
		{

		case'+':
			if (!(std::cin >> val))
			{
				std::cin.clear();
				std::cout << "An error has occurred while reading arguments" << std::endl; 
				while (std::cin.get() != '\n') continue;
			}
			else
				st.push(val);	
				break;

		case'-':
			if (st.count()==0)
			{
				std::cout << "Stack is empty" << std::endl;
			}
			else 
			{
				std::cout << st.pop() << std::endl;
			}
			break;

		case'=':
			if (!st.count()) 
			{
				std::cout << "Stack is empty" << std::endl;
			}
			else 
			{
				st.print();
			}
			break;

		case'?':
			if (st.count()==0) 
			{
				std::cout << "Stack is empty" << std::endl;
			}
			else
			{
				val = st.pop();
				std::cout << val << std::endl;
				st.push(val);
			}
			break;

		case'z':
			std::getchar();
			return 0;
			break;

		default:
			std::cout << "An error has occurred while reading arguments";
		}
	}

	system("pause");
	return 0;
}

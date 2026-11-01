#include <iostream>
#include <ciso646>

char ch = '0';
bool mem_size_unknown = true; 
size_t mem_size = 0;

int main()
{
	while(std::cin.get(ch))
	{
		if(mem_size_unknown and ch >= '0' and ch <= '9')
		{

		}
		else mem_size_unknown = false;

		
	}
}

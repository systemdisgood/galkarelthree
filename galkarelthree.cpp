#include <iostream>
#include <ciso646>


char ch = '\0';
bool mem_size_unknown = true; 
size_t mem_size = 0;
uint64_t octopower = 1;
bool reg = false;
bool not_bypass = false;;
size_t mem_pos = 0;
bool was_m = false;
std::vector<bool> mem;

int main()
{
	while(std::cin.get(ch))
	{
		if(mem_size_unknown and ch >= 'a' and ch <= 'h' and mem_size < SIZE_MAX)
		{
			mem_size += (ch - 'a') * octopower;
			octopower *= 8;
		}
		else 
		{
			if(mem_size_unknown)
			{
				if(mem_size < 2)
				{
					return EXIT_FAILURE;
				}
				mem_size_unknown = false;
				mem.resize(mem_size);
			}
		    switch(ch)
            {
                case 's':
        	        reg = true;
                    break;
                case 't':
                    if(mem[mem_pos]) reg = false;
                    break;
                case 'm':
                    was_m = true;
        	        break;
                case 'n':
                    if(was_m)
                    {
                        if(not_bypass) mem[mem_pos] = reg;
                        if(mem_pos < (mem.size() - 1)) ++mem_pos;
                        else mem_pos = 0;
                        was_m = false;
                    }
                    break;
                case 'p':
                    not_bypass = false;
                    break;
                case 'r':
                    not_bypass = true;
                    break;
                case 'o':
					if(not_bypass) std::cout << reg;
					else std::cout << mem[mem_pos];
                    break;
                case 'l':
                    std::cout << std::endl;
                    break;
            }
		}
	}
}

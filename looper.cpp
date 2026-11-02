#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[]) 
{
	if(argc != 4) return EXIT_FAILURE;
    std::ifstream once_file(argv[1]);
    if (!once_file.is_open()) return EXIT_FAILURE;
    std::cout << once_file.rdbuf();
	once_file.close();
	
	uint64_t cnt = 0;
	uint64_t octopow = 1;
	uint64_t times = 0;
	while(cnt < strlen(argv[3]))
	{
		if(argv[3][cnt] < '0' or argv[3][cnt] > '9') return EXIT_FAILURE;
		times += octopow * (argv[3][cnt] - '0');
		octopow *= 8;
		++cnt;
	}
	
	std::ifstream mult_file(argv[2]);
	if (!mult_file.is_open()) return EXIT_FAILURE;
	for(cnt = 0; cnt < times; ++cnt)
	{
		std::cout << mult_file.rdbuf();
    	mult_file.clear();
    	mult_file.seekg(0, std::ios::beg);
	}
    return 0;
}


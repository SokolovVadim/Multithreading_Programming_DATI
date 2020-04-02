#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
	std::ifstream fin1("report1.txt");
	std::string line1;
	int counter(0);
	std::ofstream fout("data.txt");
	int i(1);

	while (std::getline(fin, line1))
	{
		
		if(counter == 0){
			counter++;
			// std::cout << line << std::endl;
			continue;
		}
		int len1 = line1.length();
		for(int i(0); i < len1; ++i)
		{
			if(line1[i] == ',')
			{
				line1[i] = '.';
				line1[i - 2] = ' ';
				line1[i - 3] = ' ';
				line1[i - 5] = ' ';
				line1[i - 6] = ' ';
				line1[i - 7] = ' ';
				line1[i - 8] = ' ';
				line1[i + 4] = ' ';
			}
		}
		// std::cout << line << std::endl;
		std::stringstream stream(line1);
		float time1(0.0);
		stream >> time1;
		fout << i << " " << time1 << std::endl;
		i += 2;
	}
}
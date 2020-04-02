#include <fstream>
#include <sstream>
#include <iostream>

float get_time(std::string & line)
{
	int len = line.length();
	for(int i(0); i < len; ++i)
	{
		if(line[i] == ',')
		{
			line[i] = '.';
			line[i - 2] = ' ';
			line[i - 3] = ' ';
			line[i - 5] = ' ';
			line[i - 6] = ' ';
			line[i - 7] = ' ';
			line[i - 8] = ' ';
			line[i + 4] = ' ';
		}
	}
	std::stringstream stream(line);
	float time(0.0);
	stream >> time;
	return time;
}

int main()
{
	std::ifstream fin("report.txt");
	std::string line;
	std::ifstream fin1("report1.txt");
	std::string line1;
	std::ifstream fin2("report2.txt");
	std::string line2;
	std::ifstream fin3("report3.txt");
	std::string line3;
	int counter(0);
	std::ofstream fout("data.txt");
	int i(1);

	while (std::getline(fin, line))
	{
		if(counter == 0){
			counter++;
			continue;
		}
		std::getline(fin1, line1);
		std::getline(fin2, line2);
		std::getline(fin3, line3);
		
		float time  = get_time(line);
		float time1 = get_time(line1);
		float time2 = get_time(line2);
		float time3 = get_time(line3);
		fout << i << " " << time << " " << time1 << " " << time2 << " " << time3 << std::endl;
		i += 1;
	}
}
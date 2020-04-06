#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

const double mistake = 0.01;


double get_time(std::string & line)
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
	double time(0.0);
	stream >> time;
	return time;
}

void process_data(std::vector<std::vector<double>> & data)
{
	int counter(0);
	for(int i(1); i < data.size() - 2; ++i)
	{
		// fout << i << " ";
		for(int j(0); j < 4; ++j)
		{
			// std::cout << data.at(i).at(j) << " ";
			if(double(data.at(i).at(j) - data.at(i - 1).at(j)) > mistake){
				data.at(i).at(j) = (data.at(i + 1).at(j) + data.at(i - 1).at(j)) / 2.0;
				counter++;
			}
			//fout << data.at(i).at(j) << " ";
		}

		// std::cout << std::endl;
		//fout << "\n";
	}
	std::cout << "Points to be corrected: " << counter << std::endl;
}

void process_data_and_out(std::vector<std::vector<double>> & data, std::ofstream & fout)
{
	int counter(0);
	for(int i(1); i < data.size() - 2; ++i)
	{
		fout << i << " ";
		for(int j(0); j < 4; ++j)
		{
			// std::cout << data.at(i).at(j) << " ";
			if(double(data.at(i).at(j) - data.at(i - 1).at(j)) > mistake){
				data.at(i).at(j) = (data.at(i + 1).at(j) + data.at(i - 1).at(j)) / 2.0;
				counter++;
			}
			fout << data.at(i).at(j) << " ";
		}

		// std::cout << std::endl;
		fout << "\n";
	}
	std::cout << "Points to be corrected: " << counter << std::endl;
}

void process_data_lvl2(std::vector<std::vector<double>> & data, std::ofstream & fout)
{
	double k_average(0.0);
	for(int i(2); i < data.size() - 2; ++i)
	{
		for(int j(0); j < 4; ++j)
		{
			if(j == 0){
				double k = (data.at(i).at(j); - data.at(0).at(0)) / double(i);
				k_average += k;
			}
		}
	}
	std::cout << "k average: " << k_average / double(data.size()) << std::endl;

	for(int i(2); i < data.size() - 2; ++i)
	{
		// fout << i << " ";
		
		for(int j(0); j < 4; ++j)
		{
			// std::cout << data.at(i).at(j) << " ";
			double p1 = data.at(i - 2).at(j);
			double p2 = data.at(i - 1).at(j);
			double p3 = data.at(i).at(j);
			double p4 = data.at(i + 1).at(j);
			double p5 = data.at(i + 2).at(j);

			if(j == 0){
				double k = (p3 - data.at(0).at(0)) / double(i);
				k_average += k;
			}


			// fout << data.at(i).at(j) << " ";
		}
	}
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


	std::vector<std::vector<double>> data;

	while (std::getline(fin, line))
	{
		if(counter == 0){
			counter++;
			continue;
		}
		std::getline(fin1, line1);
		std::getline(fin2, line2);
		std::getline(fin3, line3);

		std::vector<double> v;

		
		double time  = get_time(line);
		double time1 = get_time(line1);
		double time2 = get_time(line2);
		double time3 = get_time(line3);

		v.push_back(time);
		v.push_back(time1);
		v.push_back(time2);
		v.push_back(time3);

		data.push_back(v);
		v.clear();
		// fout << i << " " << time << " " << time1 << " " << time2 << " " << time3 << std::endl;
		i += 1;
	}

	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data(data);
	process_data_lvl2(data, fout);
	process_data_and_out(data, fout);

	fin.close();
	fin1.close();
	fin2.close();
	fin3.close();
	fout.close();
}
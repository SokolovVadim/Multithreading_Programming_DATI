#include <iostream>
#include <stdexcept>
#include "matrix.hpp"

template<typename T>
void display_matrix(T** matrix, int N);

template<typename T>
void fill_matrix(T** matrix, int N);

template<typename T>
void find_product(T** a, T** b, T** c, int N, int s);

template<typename T>
void find_naive_product(T** a, T** b, T** c, int N);

int main(int argc, char** argv)
{
	try {
		
	if(argc != 3)
	{
		std::cout << "i'm here\n";
		throw std::runtime_error("Invalid number of arguments!");
	}
	long int N = ReadArg(argv[1]);
	long int S = ReadArg(argv[2]);

	// memory allocation for a, b, c

	double** a = new double*[N];
	double** b = new double*[N];
	double** c = new double*[N];

	for(int i(0); i < N; ++i){
		a[i] = new double[N];
		b[i] = new double[N];  
		c[i] = new double[N]; 
	}

	fill_matrix(a, N);
	fill_matrix(b, N);

	/*display_matrix(a, N);
	display_matrix(b, N);*/

	// find_product(a, b, c, N, S);
	find_naive_product(a, b, c, N);
	// display_matrix(c, N);



	// memory free
	
	for(int i = 0; i < N; ++i){
    	delete [] a[i];
    	delete [] b[i];
    	delete [] c[i];
	}
	delete [] a;
	delete [] b;
	delete [] c;



	} catch(std::runtime_error & err){
		std::cout << err.what() << std::endl;
	}

	return 0;
}

inline int my_min(int jj, int s, int N)
{
	return (jj + s) > N ? N:(jj + s);
}


template<typename T>
void find_product(T** a, T** b, T** c, int N, int s)
{
	
	for(int jj(0); jj < N; jj += s){
	    for(int kk(0); kk < N; kk += s){
	        for(int i(0); i < N; i++){
	            for(int j(jj); j < my_min(jj, s, N); j++){
	                T temp(0);
	                for(int k(kk); k < my_min(kk, s, N); k++){
	                    temp += a[i][k] * b[k][j];
	                }
	                c[i][j] += temp;
	            }
	        }
	    }
	}
}


template<typename T>
void find_naive_product(T** a, T** b, T** c, int N)
{
	for(int i(0); i < N; ++i)
	{
		for(int j(0); j < N; ++j)
		{
			for(int k(0); k < N; ++k)
				c[i][j] += a[i][k] * b[k][j];
		}
	}

}

template<typename T>
void display_matrix(T** matrix, int N)
{
	for(int i(0); i < N; ++i)
	{
		for(int j(0); j < N; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


template<typename T>
void fill_matrix(T** matrix, int N)
{
	for(int i(0); i < N; ++i)
	{
		for(int j(0); j < N; ++j)
		{
			matrix[i][j] = T(i) / T((j + 1));
		}
	}
}




#include <iostream>


void find_product(int** a, int** b, int** c, int N, int s)
{
	int temp(0);
	for(int jj=0;jj<N;jj+= s){
	        for(int kk=0;kk<N;kk+= s){
	                for(int i=0;i<N;i++){
	                        for(int j = jj; j<((jj+s)>N?N:(jj+s)); j++){
	                                temp = 0;
	                                for(int k = kk; k<((kk+s)>N?N:(kk+s)); k++){
	                                        temp += a[i][k]*b[k][j];
	                                }
	                                c[i][j] += temp;
	                        }
	                }
	        }
	}
}

int main(int argc, char** argv)
{
	
	return 0;
}
#include <iostream> //std::cout
#include <cmath>
#include <cstdlib> //rand srand
#include <algorithm> //min
#include <cassert>
#include <unistd.h> //sleep
#include <chrono> //time

#define MAX_INT 1000000009

int SIZE = 16;
//int SIZE = 4096;
//int SIZE = 256;
int TEST_SIZE=100000;

int SPARSE_SIZE = SIZE;

int * A;// = {9,4,8,3,7,2,6,1,5,0};

#include "util.cpp"

#include "simple.cpp"

#include "constant.cpp"

#include "sparse.cpp"

#include "optimal.cpp"

void generator(int * R,int size){
	int mode = 10;
	for(int i=1;i<=size;i++){
		R[i]=rand()%mode;
	}
}

void print(int A[]){
	std::cout << "[" << A[1];
	for(int i=2;i<=SIZE;i++){
		std::cout << ", " << A[i];
	}
	std::cout << "]" << std::endl;

}

int main(int argc, char *argv[]){

	//sparse::print();
	for(int i=4;i<30;i+=4){
		SIZE=power2(i);
		A = (int *) malloc((SIZE+1)*sizeof(int));
		srand(42);
		A[0]=MAX_INT;
		generator(A,SIZE);
		auto start = std::chrono::steady_clock::now();
		//constant::preprocess();
		//sparse::preprocess(A);
		optimal::preprocess();
		auto end = std::chrono::steady_clock::now();
		free(A);
		std::cout << "constant on size: " << SIZE << ", time: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
		<< " ns" << std::endl;
	}
	return 0;
	







	int error = 0;
	int counter = 0;
	for(int i=1;i<=SIZE;i++){
		for(int j=i;j<=SIZE; j++){
			//int first = sparse::RMQ(A,i,j);
			int first = optimal::RMQ(i,j);
			int second =  simple::RMQ(i,j);
			if(first != second){
				std::cout << "ERROR! "
				<< "i: " << i << ", j: " << j 
				<< ". optimal: " << first << ", simple: " << second 
				<< "\n";
				error++;
			}
			counter++;
		}
	}
	std::cout << error << std::endl;
	std::cout << counter << std::endl;
	//	 */
	
/*
	int i = 3, j = 7;
	std::cout << "i: " << i << ", j: " << j << std::endl;
	int o = optimal::RMQ(i,j) ;
	std::cout << "optimal: " << o << std::endl; 

	std::cout << "simple: " << simple::RMQ(i,j) << std::endl;
	// */

	return 0;
}

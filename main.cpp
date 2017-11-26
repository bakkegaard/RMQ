#include <iostream> //std::cout
#include <cmath>
#include <stdlib.h> //rand srand
#include <algorithm> //min

#define SIZE 320

#define SPARSE_SIZE SIZE

#define MAX ((int) 0)-1

int A[SIZE+1];// = {9,4,8,3,7,2,6,1,5,0};

#include "util.cpp"

#include "simple.cpp"

#include "constant.cpp"

#include "sparse.cpp"

#include "optimal.cpp"

void generator(int r, int mode){
	srand(r);
	for(int i=1;i<=SIZE;i++){
		A[i]=rand()%mode;
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
	
	int seed = 42;

	generator(seed,37);

	print(A);

	constant::preprocess();
	sparse::preprocess();

	sparse::print();

	int error = 0;
	for(int i=1;i<=SIZE;i++){
		for(int j=i;j<=SIZE; j++){
			int first = constant::RMQ(i,j);
			int second =  sparse::RMQ(i,j);
			if(first != second){
				std::cout << "ERROR! " << std::endl;
				std::cout << "i: " << i << ", j: " << j << ". constant: " << first << ", sparse: " << second << "\n";
				error++;
			}
		}
	}
	std::cout << error << std::endl;

	return 0;
}

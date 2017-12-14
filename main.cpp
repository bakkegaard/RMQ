#include <iostream> //std::cout
#include <cmath>
#include <cstdlib> //rand srand
#include <algorithm> //min
#include <cassert>
#include <unistd.h> //sleep
#include <chrono> //time

#define MAX_INT 1000000009

int SIZE;

int SPARSE_SIZE;

int * A;// = {9,4,8,3,7,2,6,1,5,0};

#include "util.cpp"

#include "simple.cpp"

#include "constant.cpp"

#include "sparse.cpp"

#include "optimal.cpp"

void generator(int * R,int size,int mode){
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

	/*

	std::string s;
	//s = "Constant";
	//s = "Sparse";
	s = "Optimal";

	std::cout << s << std::endl;
	std::cout << "size, time (in ns)" << std::endl;

	for(int i=1;i<10;i++){
		SIZE = power2(4*i);
		SPARSE_SIZE = SIZE;
		A = (int *) malloc((SIZE+1)*sizeof(int));
		srand(42);
		A[0]=MAX_INT;
		generator(A,SIZE);

		//constant::construct();
		//sparse::construct();
		optimal::construct();

		auto start = std::chrono::steady_clock::now();

		//constant::preprocess();

		//sparse::preprocess(A);
		
		optimal::preprocess();
		
		auto end = std::chrono::steady_clock::now();
		std::cout << SIZE << ", "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
			<< std::endl;
		free(A);
		//constant::del();
		//sparse::del();
		optimal::del();
	}
	*/


	std::string s;
	//s = "Simple";
	//s = "Constant";
	//s = "Sparse";
	s = "Optimal";
	std::cout << s << std::endl;
	std::cout << "size, time (in ns)" << std::endl;

	for(int i=1;i<10;i++){
		SIZE = power2(i*4);
		SPARSE_SIZE = SIZE;
		A = (int *) malloc((SIZE+1)*sizeof(int));
		A[0]=MAX_INT;
		generator(A,SIZE,104729);

		srand(42);
		int * test = (int *) malloc((1+200000)*sizeof(int));
		generator(test,200000,SIZE-1);
		
		for(int j=1;j<=200000;j++){
			test[j]+=1;
		}
		for(int j=1;j<=200000;j+=2){
			if(test[j]>test[j+1]){
				int temp = test[j];
				test[j] = test[j+1];
				test[j+1]=temp;
			}
		}
		
		//constant::construct();
		//constant::preprocess();
		
		//sparse::construct();
		//sparse::preprocess(A);

		optimal::construct();
		optimal::preprocess();

		int sum=0;
		auto start = std::chrono::steady_clock::now();
		for(int j=1;j<=200000;j+=2){
			//std::cout << test[j] << " " << test[j+1] << std::endl;
			 sum += optimal::RMQ(test[j],test[j+1]);
		}
		auto end = std::chrono::steady_clock::now();
		std::cout << SIZE << ", "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
			<< ", " << sum
			<< std::endl;
		free(A);
		//constant::del();
		//sparse::del();
		optimal::del();
	}
}

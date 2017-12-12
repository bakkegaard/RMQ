namespace optimal{

	bool DEBUG=false;

	int * A_; 
	int * B_;
	int s;

	int RMQ(int i, int j){

		if(i==j) return i;

		//Calculate the interval for the part outsite the block on the lower part
		int lower_start = i;
		int lower_end = ((i-1)/s)*s+s-1+1;
		int lower = simple::RMQ(lower_start,lower_end);

		if(DEBUG) std::cout << "lower: start=" << lower_start << ", end=" << lower_end << std::endl;

		//Calculate the min element in the block
		//
		int middle=0;

		if(abs((i-1)/s-(j-1)/s)>1){
			int middle_start = (i-1)/s+1+1;
			int middle_end = (j-1)/s+1-1;

			if(DEBUG) std::cout << "middle: start=" << middle_start << ", end=" << middle_end << std::endl;

			middle = B_[sparse::RMQ(A_,middle_start,middle_end)];
		}


		//Calculate the interval for the part outsite the block on the upper part
		int upper_start = ((j-1)/s)*s+1;
		int upper_end = j;
		if(DEBUG) std::cout << "upper: start=" << upper_start << ", end=" << upper_end << std::endl;
		int upper = simple::RMQ(upper_start,upper_end);

		if(DEBUG) std::cout << "lower: " << lower << ", middle: " << middle << ", upper: " << upper << std::endl;

		//Return the minimum
		int current_best;
		if(A[lower]<=A[middle]){
			current_best=lower;
		}
		else{
			current_best=middle;
		}
		if(A[upper]<A[current_best]) current_best = upper;
		return current_best;
	}

	void preprocess(){
		//Calculate s, the block size
		s = log2(SIZE)/4;

		//Initialize arrays A_ and B_ with the number of blocks
		A_ = (int *) malloc((SIZE/s+1)*sizeof(int));
		B_ = (int *) malloc((SIZE/s+1)*sizeof(int));
		
		//Go through each block
		for(int i=1;i<=SIZE/s;i++){

			int minSoFar = MAX_INT;
			int minIndex = -1;

			//For each block find the minimum element in the block
			for(int j=0;j<s;j++){

				int index = ((i-1)*s)+1+j;

				if(A[index]<minSoFar){
					minSoFar = A[index];
					minIndex = index;
				}

				A_[i] = minSoFar;
				B_[i] = minIndex;
			}
		}
		SPARSE_SIZE=SIZE/s+1;
		//std::cout << "A_=[";
		//for(int i=1;i<=SIZE/s;i++){
			//std::cout << ", " << A_[i];
		//}
		//std::cout << std::endl << "B_=[";
		//for(int i=1;i<=SIZE/s;i++){
			//std::cout << ", " << B_[i];
		//}
		std::cout << std::endl;
		sparse::preprocess(A_);
	}

	void del(){
		free(A_);
		free(B_);
	}
}

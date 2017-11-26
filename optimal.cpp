namespace optimal{
	int A_[SIZE+1]; //TODO: should be size n/s
	int B_[SIZE+1]; //TODO: should be size n/s
	int RMQ(int i, int j){
		return 0;
	}

	void preprocess(){
		int s = log2(n)/4;
		
		for(int i=0;i<n/s;i++){

			int minSoFar = MAX;
			int minIndex = -1;

			for(int j=0;j<s;j++){
				int index = i*s+j;
				if(A[index]<minSoFar){
					minSoFar = A[index];
					minIndex = index;
				}
				A_[j] = minSoFar;
				B_[j] = minIndex;
			}

			//TODO: do sparse algorithm on A_
		}
	}
}

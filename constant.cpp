namespace constant{
	int B[SIZE+1][SIZE+1];

	void m(){}

	void preprocess(){
		for(int i=1;i<=SIZE;i++){
			for(int j=i;j<=SIZE;j++){
				if(i==j) B[i][j]=A[i];
				else B[i][j] = std::min(B[i][j-1],A[j]);
			}
		}
	}

	int RMQ(int i, int j){
		return B[i][j];
	}
}

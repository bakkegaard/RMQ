namespace sparse{

	int M[SIZE+1][SIZE+1]; //TODO: Second one should be log_2(SIZE)+1

	void print(){
		for(int i=1;i<=SIZE;i++){
			for(int j=0;j<=SIZE;j++){
				std::cout << M[i][j] <<", ";
			}
			std::cout << "\n";
		}
	}

	int RMQ(int i, int j){
		if(i==j) return A[i];
		int l = log2(j-i+1);

		int r1 = A[M[i][l]];
		int temp = j-power2(l)+1;
		int r2 = A[M[temp][l]];
		if(r1 <= r2){
			return A[M[i][l]];
		}
		else{
			return A[M[j-power2(l)+1][l]];
		}
	}

	void preprocess(){
		for(int j=0;j<=log2(SIZE);j++){
			for(int i=1;i<=SIZE;i++){
				if(j==0) M[i][j] = i;
				else if(i+power2(j)-1>SIZE) continue;
				else{
					int temp1 = M[i][j-1];
					int temp2 = M[i+power2(j-1)][j-1];
					if(A[temp1]<=A[temp2]){
						M[i][j] = temp1;
					}
					else{
						M[i][j] = temp2;
					}
				}
			}
		}
	}
}

namespace constant{
	int * B;

	int B_offset=SIZE;

	int get(int i, int j){
		return B[i*B_offset+j];

	}

	void set(int i, int j, int element){
		B[i*B_offset+j] = element;
	}

	void construct(){
		B = (int *) malloc((SIZE+1)*(SIZE+1)*sizeof(int));
	} 
	void m(){}

	void preprocess(){
		
		construct();

		for(int i=1;i<=SIZE;i++){
			for(int j=i;j<=SIZE;j++){
				if(i==j) set(i,j,i);
				else{
					if(A[get(i,j-1)]<=A[j]){
						set(i,j,get(i,j-1));
					}
					else{
						set(i,j,j);
					}
				}
			}
		}
	}

	int RMQ(int i, int j){
		return get(i,j);
	}

	void del(){
		free(B);
	}
}

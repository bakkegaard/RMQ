namespace sparse{

	int * M; 
	int M_offset;

	int get(int i, int j){
		return M[i*M_offset+j];
	}

	void set(int i, int j, int element){
		M[i*M_offset+j]=element;
	}

	void print(){
		for(int i=1;i<=SPARSE_SIZE;i++){
			for(int j=0;j<=log2(SPARSE_SIZE)+1;j++){
				std::cout << get(i,j) <<", ";
			}
			std::cout << "\n";
		}
	}

	int RMQ(int * A, int i, int j){
		if(i==j) return i;
		int l = log2(j-i+1);

		int r1 = A[get(i,l)];
		int temp = j-power2(l)+1;
		int r2 = A[get(temp,l)];
		if(r1 <= r2){
			return get(i,l);
		}
		else{
			return get(j-power2(l)+1,l);
		}
	}

	void preprocess(int * A){
		M_offset = log2(SPARSE_SIZE)+1;
		M = (int *) malloc((SPARSE_SIZE+1)*(log2(SPARSE_SIZE)+1)*sizeof(int));

		for(int j=0;j<=log2(SPARSE_SIZE);j++){
			for(int i=1;i<=SPARSE_SIZE;i++){
				if(j==0) set(i,j,i);
				else if(i+power2(j)-1>SPARSE_SIZE) continue;
				else{
					int temp1 = get(i,j-1);
					int temp2 = get(i+power2(j-1),j-1);
					if(A[temp1]<=A[temp2]){
						set(i,j,temp1);
					}
					else{
						set(i,j,temp2);
					}
				}
			}
		}
	}
	void del(){
		free(M);
	}
}

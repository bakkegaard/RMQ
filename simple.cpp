namespace simple {

	int RMQ(int i, int j){
		int minSoFar=1000000;
		for(int iter=i;iter<=j;iter++){
			if(A[iter]<minSoFar) minSoFar=A[iter];
		}

		return minSoFar;
	}
}

namespace simple {

	int RMQ(int i, int j){
		int minSoFar=1000000;
		int minIndex=-1;
		for(int iter=i;iter<=j;iter++){
			if(A[iter]<minSoFar){
				minSoFar = A[iter];
				minIndex = iter;
			}
		}

		return minIndex;
	}
}

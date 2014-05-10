// Given a 2D array of 1s and 0s, count the number of "islands of 1s" 
// (e.g. groups of connecting 1s)

unsigned int islands( int** world, unsigned int rows, unsigned int cols ){
	unsigned int island_count = 0;

	for ( unsigned int i=0; i<rows; i++ ){
		for ( unsigned int j=0; i<cols; i++ ){
			if (world[i][j]){
				if (!( ( j>0 && world[i][j-1] ) || // left
						 	 ( j>0 && i>0 && world[i-1][j-1] ) || // left and up
						 	 ( i>0 && world[i-1][j] ) || // up
						 	 ( i>0 && j!=cols && world[i-1][j+1] ))) { // up and right
					island_count++;
				}
			}
		}
	}

	return island_count;
}
// Given 2 integer arrays, determine of the 2nd array is a rotated version of the 1st 
// array. Ex. Original Array A={1,2,3,5,6,7,8} Rotated Array B={5,6,7,8,1,2,3}

bool rotated(int* arr1, unsigned int arr1_len, int* arr2, unsigned int arr2_len){
	if ( arr1_len != arr2_len ) return false;

	for ( unsigned int i=0; i< arr1_len; i++ ){
		if ( arr1[i] == arr2[0] ) {
			unsigned int tmp = i;
			for (unsigned int j=1; j<arr2_len; j++){
				i = (i+1) % arr1_len;
				if ( arr1[i] != arr2[j] ) break;
				else if ( j == arr2_len-1 ) return true;
			}
			i = tmp;
		}
	}

	return false;
}
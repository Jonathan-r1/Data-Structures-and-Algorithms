void mySort(int d[], unsigned int n)
{

int j,number ;
for(int i = 0; i < n; i++){
	number = d[i];
	j = i-1;

	while(j >= 0 && d[j] > number){
		d[j+1] = d[j];
		j--;
	}
		d[j+1] = number;

	}
}

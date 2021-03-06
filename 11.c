/*Using OpenMP, Design, develop and run a multi-threaded program 
to generate and print Fibonacci Series. One thread has to generate 
the numbers up to the specified limit and another thread has to print 
them. Ensure proper synchronization. */
#include<stdio.h>
#include<omp.h>

int fib(int n){
	int i,j;
	if(n<2)
		return n;
	#pragma omp task shared(i) firstprivate(n)
	i=fib(n-1);
	#pragma omp task shared(j) firstprivate(n)
	j=fib(n-2);
	#pragma omp taskwait 
	return(i+j);
}
int main(){
	int fibn[100];int n, i;
	printf("Enter the limit\n");
	scanf("%d",&n);
	#pragma omp parallel num_threads(2)
	{
		#pragma omp critical
		
		if(omp_get_thread_num()==0){
			printf("\nThere are %d threads",omp_get_num_threads());
			printf("\nThread %d generating numbers ",omp_get_thread_num());
			for(i =0 ;i<n;i++)
				fibn[i]=fib(i);
		}
		else{
			printf("\nThere are %d threads",omp_get_num_threads());
			printf("\nThread %d printing numbers ",omp_get_thread_num());
			for(i =0 ;i<n;i++)
				printf("%d  ",fibn[i]);
		}
	}
}
			
		

//Design, develop and run a program to implement the Banker’s Algorithm. Demonstrate its working with different data values. 
#include<stdio.h>

int max[10][10],alloc[10][10],need[10][10],av[10],np=0,nr=0,i,j,l;

void bankers(){

	int flag=1,done=0,k=0,b=0,f[10],p[10];

	for(i=0;i<10;i++){
		f[i]=0;
		p[i]=0;
		}

	while(flag){
		
		flag=0;
		
		for(i=0;i<np;i++) {
			
			k=0;
			for(j=0;j<nr;j++) {
				
				if(need[i][j]<=av[j])
					k++;

				if(k==nr && f[i]==0){
										
					done++;
					flag=1;
					p[b++]=i;
					f[i]=1;

					for(l=0;l<nr;l++)
						av[l]+=alloc[i][l];
				}
			}
		}
	}
	
	if(done==np) {
		printf("\nSafe sequence is : \n\n\n");
		for(l=0;l<np;l++)
			printf("[%d]\t",p[l]);
		
	}
	else {
		printf("\nUnsafe\n");
	}
}
		
int main() {

	for(i=0;i<np;i++){
		for(j=0;j<nr;j++){
			max[i][j]=0;
			alloc[i][j]=0;
			need[i][j]=0;
		}
		av[i]=0;
	
	}
	
	printf("Enter the number of processess\n");
	scanf("%d",&np);
	
	printf("Enter the number of resources\n");
	scanf("%d",&nr);
	
	printf("Enter the max resources needed\n");
	for(i=0;i<np;i++)
		for(j=0;j<nr;j++)
			scanf("%d",&max[i][j]);
	 
	printf("Enter the allocated resources\n");
        for(i=0;i<np;i++)
		for(j=0;j<nr;j++){
			scanf("%d",&alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
		
	 printf("The need matrix is \n");		
	 for(i=0;i<np;i++){
	 	printf("\n");
		for(j=0;j<nr;j++){
			printf("%d ",need[i][j]);
		}
	}
	 printf("\n\nEnter the available resources\n");
	 for(i=0;i<nr;i++)
	 	scanf("%d",&av[i]);
	 
	 bankers();
	 
	 return -1;
}
		
/*
Enter the number of processess
5
Enter the number of resources
3
Enter the max resources needed
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter the allocated resources
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
The need matrix is 

7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 

Enter the available resources
3 3 2

Safe sequence is : 


[1]	[3]	[4]	[0]	[2]	

*/		
		

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main(){
    int process = 3;
    int resource = 3;
    int i,j;
    int allocation[3][3] = { { 0, 0, 1 }, // P0    
                        { 3, 2, 0 }, // P1 
                        { 2, 1, 1 }, // P2 
                    };
    int maximum[3][3] = { { 8, 4, 3 }, // P0
                      { 6, 2, 0 }, // P1 
                      { 3, 3, 3 }, // P2 
                };
    int available[3] = {3,2,2};
  
    
    findSafeState(process,resource,available,allocation,maximum);

}

int findSafeState(int process,int resource,int *available,int allocation[3][3],int maximum[3][3])
{
        int i=0,j=0,k=0;
        int finish[process];
        int need[process][resource];
        int safeSequence[process];
        int isFound = 0;
        int work[resource];
        for (i = 0; i <resource ; i++)
		work[i] = available[i];
		int completed=0;
		
		
        
        printf("Need Matrix is : \n");
        for(i=0;i<process;i++)
        {
            finish[i]=0;
            for(j=0;j<resource;j++)
            {
                need[i][j] = maximum[i][j]-allocation[i][j];
                printf("\t%d",need[i][j]);
            }
            printf("\n");

        }
        printf("Enter the requesting process  : P");
        int pr;
        scanf("%d",&pr);
        int request[resource];
        for(i=0;i<resource;i++)
        {
            printf("R%d : ",i);scanf("%d",&request[i]);
        }
        int allowed = 0;
            for(i=0;i<resource;i++)
            {
                if(request[i]<=available[i])
                {allowed=1;}
                else
                {allowed=0;break;}
            }
            if(allowed==1)
            {
                
                for(i=0;i<resource;i++)
                {
                    allocation[pr][i]+=request[i];
                    need[pr][i]-=request[i];
                    available[i]-=request[i];
                  
                }
            }
            else{
                printf("Could not find safe sequence...");
                exit(1);
            }
            
            
            
        /*Calculation for need completed*/
        printf("\n\n\t\t\t\t\tFinding Safe sequence ....\n\n\n\t\t");
        while(completed<process)
        {
        for(i=0;i<process;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<resource;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        break;
                    }
                }
                if(j==resource)
                {
                    for(k=0;k<resource;k++)
                    {
                        work[k]+=allocation[i][k];
                    }
                    Sleep(800);
                    completed++;
                    isFound = 1;
                    finish[i]=1;
                    safeSequence[completed-1] = i;
                    printf("\tP%d\t",safeSequence[completed-1]);
                }
            }
        }
        if (isFound == 0)
		{
			printf(" Could not get safe Sequence");
			return -1;
		}
        }
         printf("\n\n\t\t ! ..... Safe Sequence found .....!");
        
		sleep(3);
      	system("CLS");
	    
		printf("\n\n\t\t\tSafe Sequence is :\n\n\t\t----------------------------------------------\n\t\t");
        for(i=0;i<3;i++)
        {
            printf(" P%d | ",safeSequence[i]);Sleep(400);
        }
        Sleep(500);}

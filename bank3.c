        #include <stdio.h>
            void main()
            {
                int p,r,i,j,k,count=0,x,l;
                int avail[20],alloc[20][20],max[20][20],need[20][20];
                printf("Enter no. of process:");
                scanf("%d",&p);
                printf("Enter no. of resource:");
                scanf("%d",&r);
                for ( i = 0; i < r; i++)
                {
                    done[i]=0;
                }
                printf("Enter available resource: ");
                for ( i = 0; i < r; i++)
                {
                    scanf("%d",&avail[i]);
                }
                printf("Enter allocated table:\n");
                for ( i = 0; i < p; i++)
                {
                    for ( j = 0; j < r; j++)
                    {
                        scanf("%d",&alloc[i][j]);
                    }
                    
                }
                printf("Enter max table\n");
                for ( i = 0; i < p; i++)
                {
                    for ( j = 0; j < r; j++)
                    {
                        scanf("%d",&max[i][j]);
                    }
                    
                }
                
                printf("\nMaking need matrix\n");
                for ( i = 0; i < p; i++)
                {
                    for ( j = 0; j < r; j++)
                    {
                        need[i][j]=max[i][j]-alloc[i][j];
                    }
                    
                }
                printf("\nNeed matrix made\n");
                int check(int a)
                {
                    int c_flag;
                    for ( l = 0; l < r; l++)
                    {
                        if(need[a][l]<=avail[l])
                            c_flag=1;
                        else
                        {
                            c_flag=0;break;
                        }
                        
                    }
                    return c_flag;
                }
                void new_avail(int a)
                {
                    int u;
                    for ( u = 0; u < r; u++)
                    {
                        avail[u]+=alloc[a][u];
                    }
                    
                }
                while(count!=p)
                {
                    for ( i = 0; i < p; i++)
                    {
                        if(done[i]!=1)
                        {
                            x=check(i);
                            if (x==1)
                            {
                                printf("Process%d is executing\n",i+1);
                                new_avail(i);//new avail creation
                                count++;
                                done[i]=1;
                            }
                        }
                    
                    }
                }
                printf("\nSystem is in safe state");
            }
    
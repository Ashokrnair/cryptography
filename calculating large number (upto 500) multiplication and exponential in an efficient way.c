#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{

    int x[500]={0},n=0,n1=0,result[5000]={0},i,j,k,p,binary[9]={0},big[500]={0};
    int xcopy[5000]={0},temp=0,pos=0,c=0,xcopy2[5000]={0},x1[500]={0},result2[5000]={0},y[500]={0};
    int d=0,substract[500]={0};
    double time;
    printf("enter the number of digits requird\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        x[i]=rand()%10;
    printf("the number is \n");
    for(i=0;i<n;i++)
        printf("%d",x[i]);
        printf("\n the second number is \n");
        for(i=0;i<n;i++)
      {
          y[i]=rand()%10;
           printf("%d",y[i]);
      }
        //finding largest
       i=0;
      one:
          if(x[i]==y[i])
          {
            goto one;
            i++;
          }
          else if (x[i]!=y[i])
          goto two;
      two:
      if(y[i]>x[i])
      {
          for(k=0;k<n;k++)
          {
            big[k]=y[k];
            y[k]=x[k];
            x[k]=big[k];
          }
      }
      printf(" \n after greater \n");
      for(i=0;i<n;i++)
      {
         printf("%d",x[i]);
      }
      printf("\n");
      for(i=0;i<n;i++)
      {
         printf("%d",y[i]);
      }
        //substraction
      c=0;
      for(i=(n-1),c=499;i>=0;i--,c--)
      {
          substract[c]=x[i]-y[i];
          if(substract[c]<0 && i!=0)
          {
              substract[c]+=10;
              x[i-1]=(x[i-1]-1);
          }
      }
      d=n+1;
      if(d>499)
      {
          d=500;
      }
      printf("\n\n\n the substraction is \n");
      for(i=(500-d);i<=499;i++)
      {
      printf("%d",substract[i]);
      }
      printf("\n enter the length of base value");
      n=0;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
          x[i]=0;
          scanf("%d",&x[i]);
      }
      printf("\n the base value is \n");
      for(i=0;i<n;i++)
      {
          printf("%d",x[i]);
      }
      for(i=(n-1),j=499;i>=0;i--,j--)
      {
          x1[j]=x[i];
      }
      //binary calculation
    printf("\nenter the exponent value");
    scanf("%d",&n1);
    if(n1<4)
      p=2;
      else if(n1<8)
      p=3;
      else if(n1<16)
      p=4;
      else if(n1<32)
        p=5;
      else if(n1<64)
        p=6;
      else if(n1<128)
        p=7;
        else if(n1<256)
        p=8;
        else if(n1<512)
            p=9;
        int n1copy=n1;
      printf("\nthe binary of %d is : ",n1);
      clock_t begin1=clock();
      for(i=8;i>=(9-p);i--)
      {
        binary[i]=n1%2;
        n1=n1/2;
      }
      for(i=(9-p);i<9;i++)
        printf("%d",binary[i]);
      p=p-1;
      printf("\n taking the bits %d" ,p);
        //calculating exponential
        for(i=(n-1),j=4999;i>=0;i--,j--)
        {
            temp=x[i];
           // x[i]=0;
            result[j]=temp;
            xcopy2[j]=temp;
            x1[j]=temp;
        }
        for(i=(9-p);i<9;i++)
        {

            for(j=0;j<5000;j++)
                {
                    xcopy[j]=0;
                    xcopy[j]=result[j];
                    result2[j]=result[j];
                   result[j]=0;
                }
                for(j=4999,pos=0;j>=0;j--,pos++)
                {
                    for(k=4999,c=(4999-pos);k>=0;k--,c--)
                    {
                        result[c]+=(result2[k]*xcopy[j]);
                    }
                    for(k=4999;k>=0;k--)
                    {
                        if(result[k]>9)
                        {
                            result[k-1]+=result[k]/10;
                            result[k]=result[k]%10;
                        }}
                        }
                if(binary[i]==1)
                {

                    for(j=0;j<5000;j++)
                {
                    temp=0;
                    //xcopy2[j]=0;
                    temp=result[j];
                    xcopy[j]=temp;
                    result[j]=0;
                }

                       for(j=4999,pos=0;j>=0;j--,pos++)
                {
                    for(k=4999,c=(4999-pos);k>=0;k--,c--)
                    {
                        result[c]+=(x1[j]*xcopy[k]);
                    }
                    for(k=4999;k>=0;k--)
                    {
                        if(result[k]>9)
                        {
                            result[k-1]+=result[k]/10;
                            result[k]=result[k]%10;
                        }}}}}
                        clock_t end1=clock();
    time=(double)((end1-begin1))/CLOCKS_PER_SEC;
        printf("\nthe value is \t");
        for(i=(5000-(n1copy*n));i<5000;i++)
        {

            printf("%d",result[i]);
        }
        printf("\n time taken is %lfclocks/s \n",time);

    return 0;
}

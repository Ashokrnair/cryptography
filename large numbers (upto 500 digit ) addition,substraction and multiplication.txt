    #include <stdio.h>
    #include <stdlib.h>
     
    int main() {
      
      int i,big[500]={0},x[500]={0},y[500]={0},p,k=0,len;
      printf("enter the number of digits less than 500 \n");
      scanf("%d",&len);
      //inputs
      for(i=0;i<len;i++)
      {
          x[i]=rand()%10;
           printf("%d",x[i]);
      }
      printf("\n");
      for(i=0;i<len;i++)
      {
          y[i]=rand()%10;
           printf("%d",y[i]);
      }
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
          for(k=0;k<len;k++)
          {
            big[k]=y[k];
            y[k]=x[k];
            x[k]=big[k];
          }
      }
      printf(" \n after finding the greater \n"); 
	printf("|n first number \n");
      for(i=0;i<len;i++)
      {
         printf("%d",x[i]);
      }
      printf("\nsecond number \n");
      for(i=0;i<len;i++)
      {
         printf("%d",y[i]);
      }
      //adding
      int b=0,z[500]={0};
      i=0;
      for(i=(len-1),k=499;i>=0;i--,k--)
      {
          z[k]=x[i]+y[i]+b;
          p=k;
          b=0;
          if(z[k]>9)
          {
              b=z[k]/10;
              z[k]=(z[k])%10;
              
          }
          z[p-1]+=b;
      }
      int d1,d=len+1;
      if(d>499)
      {
          d=500;
      }
      printf("\n\n\n the addition is \n");
      for(i=(500-d);i<=499;i++)
      {
      printf("%d",z[i]);
      }
      // multipling
      int j,mul[1001]={0},c=0,m,r=0;
      int dlen=len-1;
      b=0;
      for(i=dlen,k=0;i>=0;i--,k++)
      {
          for(j=dlen,c=(1000-k);j>=0;j--,c--)
            {
                mul[c]+=(x[j]*y[i]);
                p=c;
            }
               for(c=1000;c>=0;c--)
            {
                mul[c]+=b;
                b=0;
                if(mul[c]>9)
                {
                    b=mul[c]/10;
                    mul[c]=(mul[c])%10;
                }
            }
            mul[p-1]+=mul[p]/10;
            
      }
      d=(2*len);
      printf("\n the multiplication is : \n");
      for(i=(1000-d);i<=1000;i++)
      {
          printf("%d",mul[i]);
      }
      int substract[500]={0};
      c=0;
      for(i=dlen,c=499;i>=0;i--,c--)
      {
          substract[c]=x[i]-y[i];
          if(substract[c]<0 && i!=0)
          {
              substract[c]+=10;
              x[i-1]=(x[i-1]-1);
          }
      }
      d=len+1;
      if(d>499)
      {
          d=500;
      }
      printf("\n\n\n the substraction is \n");
      for(i=(500-d);i<=499;i++)
      {
      printf("%d",substract[i]);
      }
    return 0;
    }















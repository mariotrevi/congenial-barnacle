#include <stdio.h>
#define MAXN 18446744073709551615
#define ULL unsigned long long 

    int is_on_list(ULL n);
    int is_on_list_even_index(ULL n);
    ULL calculate_index(ULL n);
    ULL ms(ULL n);

    ULL indexp2[400];
    ULL msatp2[61];

int main(void)
{
    ULL n;
    int i;
    ULL test_number;
    int parities[61];
    ULL driver;
    ULL cumulative;
    ULL p;

    indexp2[1]=1;
    indexp2[2]=2;
    indexp2[3]=3;


    driver = 1;
    cumulative =0;
    p=1;

  for(i=1; i<= 60; i++)
  {
      parities[i]=driver%2;

      if(parities[i]==1)
      {
          cumulative=cumulative + p;
      }

      msatp2[i]=cumulative;


      p = 2*p;

      if(0 == (driver%2))
      {         
          driver = (driver*3)/2;
      }
      else
      {
         driver = (3*(driver+1))/2;
      }
   }




    
    

     
    for(i=4; i<200; i++)
    {
       indexp2[i] = (indexp2[i-1]*3 + (indexp2[i-1]%2) )/2;
    }


    test_number = 18446540085555922926;


//     184465,40085555922926


//     184465,05491073728588


//     184465,29349337310890


//     184465,15130113821910


//     184465,05480451653936

//     184465,03070418745878


//     184465,00628888525536


while(test_number <= MAXN )
{
          
    if( is_on_list(test_number) )
    {
        printf("%llu\n",test_number);
    }
  

    test_number = test_number + 2;
}


return 0;

}



ULL ms(ULL n)
{
    ULL oddpart;
    int expo;
    int ispow2;
    ULL position;
    int onlist;
    ULL p2;
    ULL precursor;
    ULL output;

    oddpart = n;
    expo=0;
    while(0==(oddpart%2))
    {
       oddpart = oddpart/2;
       expo++;
    }


    if(oddpart==1)
    {
      ispow2 = 1;
    }
    else
    {
       ispow2 = 0;
    }

    if((ispow2 == 1) || (n==6))
    {

      if(n==6)
      {
         return 1;
      }

      if(n==1)
      {
         return 3;
      }

      if((n>1)&&(n!=6))
      {
         return msatp2[expo];
      }

    }
    else
    {
       p2=1;
       while((2*p2)< n)
       {
         p2=2*p2;
       }

       precursor = n-p2;
       output = ms(precursor);
       if ( (is_on_list(2*p2-1-n)) || ( 0 == (2*p2-1-n) )   )
       {
           output = output + p2;
       }
       return(output);
    }

}


int is_on_list(ULL n)
{
    ULL oddpart;
    int expo;
    int ispow2;
    ULL position;
    int onlist;
    ULL p2;
    ULL precursor;

 //   printf("hello!\n");


if((n==0) ||(1==(n%2)) )
{
    return 0;
}
else
{
    oddpart = n;
    expo=0;
    while(0==(oddpart%2))
    {
       oddpart = oddpart/2;
       expo++;
    }
    
    if(oddpart==1)
    {
      ispow2 = 1;
    }
    else
    {
       ispow2 = 0;
    }

    if(ispow2 == 1)
    {
       return 1;
    }
    else
    {
       p2=1;
       while(((p2-1)+p2)< n-1)
       {
         p2=2*p2;
       }

       precursor = n-p2;

       return( is_on_list_even_index(precursor) );
    }

}

} 

 
       
 int is_on_list_even_index(ULL n)
 {

    ULL oddpart;
    int expo;
    int ispow2;
    ULL position;
    int onlist;
    ULL p2;
    ULL precursor;
    ULL index;

//    printf("hello!\n");

    oddpart = n;
    expo=0;

    while(0==(oddpart%2))
    {
       oddpart = oddpart/2;
       expo++;
    }

    
    if(oddpart==1)
    {
      ispow2 = 1;
    }
    else
    {
       ispow2 = 0;
    }

    if(ispow2 == 1)
    {
       position = indexp2[expo];
       if((position%2)==1)
       {
         onlist = 0;
       }
       else
       {        
          onlist = 1;
       }

       return onlist;
    }
    else
    {
       p2=1;
       expo=0;
       while((2*p2)< n)
       {
         p2=2*p2;
         expo++;
       }


       precursor = n-p2;


        if( is_on_list(precursor))
        {
          index = calculate_index(precursor);

          if(   0==(index%2)   )
          {
              if( (indexp2[expo]%2)== ((index/2)%2) )
              {
                  return 1;
              }
              else
              {
                 return 0;
              }
          }
          else
          {
                return 0;
          }



        }
        else
        {
           return 0;
        }
    }
}

ULL calculate_index(ULL n)
{

    ULL oddpart;
    int expo;
    int ispow2;
    ULL position;
    int onlist;
    ULL p2;
    ULL precursor;
    ULL index;


    oddpart = n;
    expo=0;

    while(0==(oddpart%2))
    {
       oddpart = oddpart/2;
       expo++;
    }
    
    if(oddpart==1)
    {
      ispow2 = 1;
    }
    else
    {
       ispow2 = 0;
    }

    if(ispow2==1)
    {
      return( indexp2[expo] );
    }
    else
    {
       p2=1;
       expo=0;
       while((2*p2)< n)
       {
         p2=2*p2;
         expo++;
       }
       precursor = n - p2;
       index = indexp2[expo] + calculate_index(precursor)/2;

       return index;
    }
}      

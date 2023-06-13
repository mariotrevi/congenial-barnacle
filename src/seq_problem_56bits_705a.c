#include <stdio.h>
#include <stdlib.h>
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
    int k;
    ULL best;
    int flag;
    ULL test_number;
    int parities[61];
    ULL driver;
    ULL cumulative;
    ULL p;
    int state4[256] = {159,252,240,255,13,107,139,37,70,28,187,62,194,87,71,4,225,196,49,181,173,113,116,175,236,127,111,33,39,88,203,242,180,1,64,110,85,230,78,141,213,57,18,211,134,250,2,222,119,161,26,95,27,45,96,8,103,147,208,138,11,131,68,195,189,247,249,160,145,254,106,140,19,80,214,221,72,243,54,177,166,120,105,104,24,100,182,25,165,81,41,123,199,148,91,133,52,186,152,192,56,58,218,89,20,188,74,185,118,6,98,169,163,136,235,233,59,14,231,35,29,15,117,190,101,251,36,183,246,16,210,50,200,207,53,67,130,237,47,201,90,12,149,73,228,198,162,217,9,75,42,23,0,109,227,137,40,5,223,197,128,77,232,69,179,234,125,55,97,51,115,3,112,172,132,178,238,209,121,31,34,164,253,184,32,229,174,193,76,38,86,167,156,150,93,84,10,122,226,224,170,135,151,219,21,205,244,157,102,44,158,202,46,48,245,248,212,171,43,61,144,94,92,83,215,239,60,7,17,66,176,99,129,191,155,204,114,153,124,143,126,30,108,154,216,22,79,65,146,168,142,82,63,206,241,220}; 




    unsigned long long rnd256;   
    int s4=0;                
    int ix4=0;         
    int i4, temp4, t4; 

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


    test_number =  256;
     best=18;
    n = 18446559485146739168;

    flag=1;








while(test_number <= MAXN )
{
  if(flag)
  {          
     if( is_on_list(test_number)&&(test_number>best) )
    {
        printf("%llu\n",test_number);
         if(test_number > best)
         {
            best = test_number;
         }
    }
  }
  

   //  test_number = n + 65536*((unsigned long long)random())  +    (((unsigned long long)random())%65536)     ;






            rnd256=0;
            for(i4=0; i4<7; i4++)
            {
               ix4++;
               if(ix4 == 256)
               {
                  ix4 = 0;
               }
               s4 = s4 + state4[ix4];
               if(s4>255)
               {
                  s4 = s4 - 256;
               }
               temp4 = state4[s4];
               state4[s4] = state4[ix4];
               state4[ix4] = temp4;
               t4 = state4[ix4] + state4[s4];
               if(t4>255)
               {
                  t4 = t4 - 256;
               }






flag=0;
for(k=0; k< 7; k=k+2)
{
   if( ((((1<<k)&state4[t4])>>k)  &&  (((1<<(k+1))&state4[t4])>>(k+1))) )
   {
       flag=1;
   }   

}


               if(flag)
               {
                   break;
               }
               else
               {

                    rnd256 = rnd256*256 + ((unsigned long long) state4[t4]) ;
               }
            }


   test_number = rnd256;

   test_number = test_number | 67553994410557440 ; 
   test_number = test_number | 69805794224242688 ;

   test_number = test_number | 70931694131085312 ;

   test_number = test_number | 71494644084506624 ;
   

   test_number = test_number | 71776119061217280 ;
   test_number = test_number | 71987225293750272 ;
  //  test_number = test_number & 18446744073709547520;
    test_number = test_number | 71916856549572608 ;

    test_number = test_number | 72022409665839104 ;



flag=1;
for(k=0; k< 36; k=k+2)
{
   if( ((((1<<k)&test_number)>>k)  &&  (((1<<(k+1))&test_number)>>(k+1))) )
   {
      // printf("test_number=%llu flag=%d \n", test_number, flag);
       flag=0;
   }

     //  printf("test_number=%llu flag=%d \n", test_number, flag);

}











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


#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdint.h>
#include<stdlib.h>

uint16_t data[] = {0xff, 0xfF, 0x03, 0x01, 0x02, 0x03,0x00,0x34 };

#define start 0xff
#define end 0x00
int data_check(const uint16_t* data);
int len = 0;


int data_check(const uint16_t* data)
{ 
  int  index=0;
  //size_t length = (sizeof(data)/sizeof(int));
  for(size_t i=0;i<=sizeof(data)-2; i++)
  {
    if((data[i]== start) && (data[i+1]== start))
    {  
      len = data[i+2];  
      if(data[i+3+len]== 0x00)
      {
        index=i+3;
        break;
      }
    }
    if( index != 0)
    {
      return index;
    }
    else 
    {
      return -1;
    }
  }
}

int main ()
{
    int p, i;
    p = data_check(&data); 
    if(p == -1)
    {
      printf("No valid Data Packet Found");
    }
    else
    {
      printf("Valid Data Packet found\n");
      for(i = (p-3); i <= (len+p); i++)
      {
        printf("0x0%x\n",data[i]);
      }
    }
    return 0;
}
 
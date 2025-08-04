#include <stdio.h>
#include "tree.h"

#define MAX_NUM 10
Node* queue[MAX_NUM];
int first=0;
int last=0;
 
void enqueue(Node* data)
{
   if( (last+1)%MAX_NUM == first ){
      printf("キューは満杯で、追加できません\n");
      return;
   }
   queue[last]=data;
   last=(last+1)%MAX_NUM;
   return;
}
 
Node* dequeue(void)
{
   Node* ret;
   if(first==last) return NULL;  // キューが空の場合
   ret=queue[first];
   first=(first+1)%MAX_NUM;
   return ret;
}
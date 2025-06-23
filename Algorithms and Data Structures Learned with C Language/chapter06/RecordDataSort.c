#include <stdio.h>
#include <string.h>
 
typedef struct student{
  int grade;        //学年
  char name[2][20]; //姓名
}Student;
 
void SelectionSort_grade(Student x[],int n); 
void SelectionSort_name(Student x[],int n, int f);
void InsertionSort_grade(Student x[],int n);
void InsertionSort_name(Student x[],int n, int f);
 
void main()
{
    int i;
    Student data[5]={
        {2,{"いとう","たけし"}},
        {2,{"かとう","まさる"}},
        {2,{"いとう","ありさ"}},
        {1,{"たなか","はるき"}},
        {3,{"かとう","さちこ"}}
    };
 
  printf("\n並べ替え前\n");
  for(i=0;i<5;i++)
    printf("%d年 %s %s\n", data[i].grade, data[i].name[0], data[i].name[1]);
 
  printf("\n「名」により 並べ替え\n");
  InsertionSort_name(data,5,1);
  for(i=0;i<5;i++)
    printf("%d年 %s %s\n", data[i].grade, data[i].name[0], data[i].name[1]);
 
  printf("\n「姓」により 並べ替え\n");
  InsertionSort_name(data,5,0);
  for(i=0;i<5;i++)
    printf("%d年 %s %s\n", data[i].grade, data[i].name[0], data[i].name[1]);
 
  printf("\n「学年」により並べ替え\n");
  InsertionSort_grade(data,5);
  for(i=0;i<5;i++)
    printf("%d年 %s %s\n", data[i].grade, data[i].name[0], data[i].name[1]);
 
  return;
}

void SelectionSort_grade(Student x[], int n){
    int i, j, max_id;
    Student tmp;

    for(j = n-1; j > 0; j--){
        max_id = 0;
        for(i = 1; i <= j; i++){
            if(x[max_id].grade < x[i].grade) max_id = i;
        }
        tmp = x[j];
        x[j] = x[max_id];
        x[max_id] = tmp;
    }
    return;
}

void SelectionSort_name(Student x[], int n, int f){
    int i, j, max_id;
    Student tmp;

    for(j = n-1; j > 0; j--){
        max_id = 0;
        for(i = 1; i <= j; i++){
            if(strcmp(x[max_id].name[f], x[i].name[f]) < 0) max_id = i;
        }
        tmp = x[j];
        x[j] = x[max_id];
        x[max_id] = tmp;
    }
    return;
}

void InsertionSort_grade(Student x[], int n){
    int i, j;
    Student tmp;

    for(j = 1; j < n; j++){
        tmp = x[j];
        for(i = j-1; i >= 0; i--){
            if(x[i].grade > tmp.grade) x[i+1] = x[i];
            else break;
        }
        x[i+1] = tmp;
    }
    return;
}

void InsertionSort_name(Student x[], int n, int f){
    int i, j;
    Student tmp;

    for(j = 1; j < n; j++){
        tmp = x[j];
        for(i = j-1; i >= 0; i--){
            if(strcmp(x[i].name[f], tmp.name[f]) > 0) x[i+1] = x[i];
            else break;
        }
        x[i+1] = tmp;
    }
    return;
}
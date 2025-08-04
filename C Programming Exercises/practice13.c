#include <stdio.h>

typedef struct body {
    char name[32];
    int age;
    double height;
    double weight;
} BODY;

BODY input_bodydata(void);
int print_bodydata(BODY data);

int main(void)
{
    BODY Data[10];
    int i, rc, n;
    FILE* fp;
    char filename[32];

    // for (i = 0; i < 10; i++) {
    //     Data[i] = input_bodydata();

    //     printf("入力を継続(1)/終了(0)：");
    //     scanf("%d", &rc);
    //     if (rc == 0) break;
    // }

    // if (i == 10) n = 10;
    // else n = i + 1;

    // printf("\n名前\t年齢\t身長\t体重\n");
    // for (i = 0; i < n; i++)
    //     print_bodydata(Data[i]);

    // printf("\n The file's name:"); scanf("%s", filename);
    // fp=fopen(filename, "a");
    // if(fp==NULL){
    //     printf("Did not open the file\n");
    //     return -1;
    // }
    // printf("Have opened the file\n");

    // for(i=0; i<n; i++){
    //     fprintf(fp, "%s\t %d\t %f\t %f\t \r\n", 
    //         Data[i].name, Data[i].age, Data[i].height, Data[i].weight);
    // }
    // printf("Have written the file");
           
    // fclose(fp);
    // printf("Have closed the file\n");
    
    printf("\n The file's name:"); scanf("%s", filename);
    fp=fopen(filename, "r");
    if(fp==NULL){
        printf("Did not open the file\n");
        return -1;
    }
    printf("Have opened the file\n");

    for(i=0; i<10; i++){
        rc = fscanf(fp, "%s\t %d\t %lf\t %lf\t \r\n", 
            Data[i].name, &Data[i].age, &Data[i].height, &Data[i].weight);
        if(rc == EOF) break;
    }
    if(i==10) n=10; else n=i;   
    printf("Have read %d lines of the file\n", n);
           
    fclose(fp);
    printf("Have closed the file\n");

    printf("\n name\t age\t height\t weight\n");
    for(i=0; i<n; i++) print_bodydata(Data[i]);

    return 0;
}

BODY input_bodydata(void)
{
    BODY data;

    printf("名前："); scanf("%s", data.name);
    printf("年齢："); scanf("%d", &data.age);
    printf("身長："); scanf("%lf", &data.height);
    printf("体重："); scanf("%lf", &data.weight);

    return data;
}

int print_bodydata(BODY data)
{
    printf("%s\t", data.name);
    printf("%d才\t", data.age);
    printf("%.1fcm\t", data.height);
    printf("%.1fkg\n", data.weight);
    return 0;
}
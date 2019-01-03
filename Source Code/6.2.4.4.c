//
// Created by Kevin Luo on 2018/12/12.
//
#include <stdio.h>
#include <stdlib.h>// malloc分配内存必需
#define M 5// M门课程
#define N 5// N个学生
char course_name[M];
char *name[N];// 元素为每个字符串的头指针
int score[N][M];//不要声明成score[N+1][M+1],指针访问会有问题，因为每行最后一个元素未赋值，但指针访问仍能访问到
float stu_average[N],cou_average[M];
void student_average(char* _name[],int* _score)
{
    int sum,i,j;
    for(i=0;i<=N-1;i++)
    {
        sum=0;
        for(j=0;j<=M-1;j++)
            sum+=*(_score+i*M+j);
        stu_average[i]=(float)sum/M;
        printf("Average score of %s is %.2f\n",*(_name+i),stu_average[i]);
    }
}
void course_average(char* _course_name,int *_score)
{
    int sum,i,j;
    for(j=0;j<=M-1;j++)
    {
        sum=0;
        for(i=0;i<=N-1;i++)
            sum+=*(_score+i*M+j);
        cou_average[j]=(float)sum/M;
        printf("Average score of %c is %.2f\n",*(_course_name+j),cou_average[j]);
    }
}
void lower_than_average(char * _course_name, int *_score, float *_cou_average)
{
    int i;
    for(i=0;i<=M-1;i++)
    {
        int j;
        int count[M]={0};
        for(j=0;j<=N-1;j++) {
            if (*(_score+j*M+i)<*(_cou_average+i))
                (*(count+i))++;
        }
        printf("Number of students lower than avg of %c is %d\n",*(_course_name+i),*(count+i));
    }
}
void fail_perfect(char * _course_name, int *_score)
{
    int i;
    for(i=0;i<=M-1;i++)
    {
        int j;
        int count_fail[M]={0};
        for(j=0;j<=N-1;j++) {
            if (*(_score+j*M+i)<60)
                (*(count_fail + i))++;
        }
        printf("Number of students %c fail is %d\n",*(_course_name+i),*(count_fail+i));
    }
    for(i=0;i<=M-1;i++)
    {
        int j;
        int count_perfect[M]={0};
        for(j=0;j<=N-1;j++) {
            if (*(_score+j*M+i)>=90)
                (*(count_perfect+i))++;
        }
        printf("Number of students %c perfect is %d\n",*(_course_name+i),*(count_perfect+i));
    }
}
int main()
{
    int i;
    for(i=0;i<=M-1;i++)
        scanf("%c ",&course_name[i]);
    for(i=0;i<=N-1;i++)//开辟内存，避免野指针,非常重要！！!
        name[i]=(char*)malloc(sizeof(char)*30);
    for(i=0;i<=N-1;i++)
    {
        scanf("%s",name[i]);
        int j;
        for(j=0;j<=M-1;j++)
            scanf("%d", &score[i][j]);
    }
    student_average(name,score[0]);
    course_average(course_name,score[0]);
    lower_than_average(course_name,score[0],cou_average);
    fail_perfect(course_name,score[0]);
    return 0;
}

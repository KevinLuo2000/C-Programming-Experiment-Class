//
// Created by Kevin Luo on 2018/12/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Transcript
{
    char number[15];
    char name[20];
    float English;
    float HigherMaths;
    float GeneralPhysics;
    float CProgramming;
    struct Transcript *Next;
    struct Transcript *Prior;//增加一个前驱指针
    float SUM;
    float AVG;
} transcript;

typedef struct Alter_data
{
    char number[15];
    char course_name[30];//除非直接对字符串赋值，否则不要用字符串的指针声明法
    float score;
} alter_data;

transcript *Create(int N)//创建链表，同时把数据输进去
{
    transcript *Head=NULL,*tail;//链表创建过程用上两个指针，一个头指针，一个尾指针,尾指针同时用于输入数据
    /* if(1)//一开始就碰到结束条件,此题无需判断，因为规定了n为正整数，即至少有一组数据
        ;
        else
        {} */
    //第一次
    Head=(transcript *)malloc(sizeof(transcript));//分配头指针内存
    //Head->data=*p++;//对数据域赋值，同时数据指针右移
    scanf("%s%s%f%f%f%f",Head->number,Head->name,&(Head->English),&(Head->HigherMaths),&(Head->GeneralPhysics),&(Head->CProgramming));
    tail=Head;//tail指向头指针
    //tail=tail->Next;

    //第2-n次
    int i;
    for(i=0;i<N-1;i++)
    {
        tail->Next=(transcript *)malloc(sizeof(transcript));//创建下一个尾指针,放在每次循环最前面
        tail->Next->Prior=tail;//创建prior的指向关系
        tail=tail->Next;//指针右移
        //tail->data = *p++;//输入数据
        scanf("%s%s%f%f%f%f",tail->number,tail->name,&(tail->English),&(tail->HigherMaths),&(tail->GeneralPhysics),&(tail->CProgramming));
        //上一步是输入数据
    }

    //维护末状态
    tail->Next=Head;
    Head->Prior=tail;//形成一个环
    return Head;
}

void Alter(transcript *head_,int N)
{
    int m;
    char *_course_name[4]={"English","Math","Physics","C"};
    scanf("%d",&m);
    alter_data *data=(alter_data *)malloc(sizeof(alter_data));
    //data=(alter_data *)malloc(sizeof(alter_data)*m);动态数组备用
    int i,j;
    for(i=0;i<m;i++)
    {
        scanf("%s%s%f",data->number,data->course_name,&(data->score));//输入待修改的数据
        transcript *node_=head_;
        for(j=0;j<N;j++)//链未结束时
        {
            if(strcmp(node_->number,data->number)==0) {
                if (strcmp(data->course_name, _course_name[0]) == 0)
                    node_->English = data->score;
                if (strcmp(data->course_name, _course_name[1]) == 0)
                    node_->HigherMaths = data->score;
                if (strcmp(data->course_name, _course_name[2]) == 0)
                    node_->GeneralPhysics = data->score;
                if (strcmp(data->course_name, _course_name[3]) == 0)
                    node_->CProgramming = data->score;
            }
            node_=node_->Next;//遍历指针node_右移
        }
    }
    printf("\nAlter:\n");
    printf("%-15s%-20s%-10s%-10s%-10s%-10s\n","ID","Name","English","Math","Physics","C");

    //遍历修改后的链表并输出
    transcript *node_=head_;
    for(i=0;i<N;i++)//链未结束时
    {
        printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",node_->number,node_->name,node_->English,node_->HigherMaths,node_->GeneralPhysics,node_->CProgramming);
        node_=node_->Next;//遍历指针node右移
    }
    //free(data);动态数组备用
}
void Sum_Avg(transcript *head_,int N)
{
    //遍历修改后的链表并输出总成绩及平均成绩
    transcript *_node=head_;
    printf("\nSumAndAvg:\n");
    printf("%-15s%-20s%-10s%-10s\n","ID","Name","SUM","AVG");
    int i;
    for(i=0;i<N;i++)//链未结束时
    {
        _node->SUM=_node->English+_node->HigherMaths+_node->GeneralPhysics+_node->CProgramming;
        _node->AVG=_node->SUM/4;
        printf("%-15s%-20s%-10.2f%-10.2f\n",_node->number,_node->name,_node->SUM,_node->AVG);
        _node=_node->Next;//遍历指针_node右移
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    transcript *node,*_head;//声明结构体指针型的用于遍历的指针
    _head = Create(n);//遍历指针node指向链头
    node = _head;//遍历指针node指向链头
    printf("%-15s%-20s%-10s%-10s%-10s%-10s\n","ID","Name","English","Math","Physics","C");

    //遍历链表并输出
    int i;
    for(i=0;i<n;i++)//链未结束时
    {
        printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",node->number,node->name,node->English,node->HigherMaths,node->GeneralPhysics,node->CProgramming);
        node=node->Next;//遍历指针node右移
    }
    //修改数据
    Alter(_head,n);
    Sum_Avg(_head,n);
    return 0;
}


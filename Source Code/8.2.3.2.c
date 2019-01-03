//
// Created by Kevin Luo on 2018/12/28.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int count;
typedef struct Info
{
    char name[20];
    char workplace[30];
    char phone[20];
    char email[30];
    struct Info *Next;
} info;

//① 创建链表，同时录入每个联系人的基本信息
void Create(info **Head)
{
    info* head=(info*)malloc(sizeof(info));
    info *node=(info*)malloc(sizeof(info));
    head->Next = node;
    node = head;
    printf("请输入联系人的个数，输入后请回车:\n");
    int number;
    scanf("%d",&number);
    printf("请依次输入姓名、单位、电话、邮箱地址信息，以空格分隔。一个人的信息输入完毕后，请按回车键。\n");
    printf("注：姓名相同者需在输入姓名时自行加入编号作区分，如：John_3，张三（2）\n");
    while(number--) {
        node = node->Next;
        scanf("%s%s%s%s", node->name, node->workplace, node->phone, node->email);
        node->Next = (info *) malloc(sizeof(info));
        count++;
    }
    node->Next=NULL;
    *Head = head;
    printf("已成功录入\n");
}

void Show(info **);

//② 从磁盘文件中读取记录到内存；
void Read(info **Head)
{
    printf("\n请确保文件名为data.txt，文件不为空且光标停留在最后一个数据尾（即最后一组数据输入完后无需换行）\n");
    printf("确认读取操作请输入Y，按其他任意键退出\n");
    char Y;
    getchar();
    scanf("%c",&Y);
    if(Y=='Y'||Y=='y') {
        FILE *fp;
        fp = fopen("data.txt", "r");
        if (fp == NULL) {
            printf("data.txt文件未找到或文件为空，程序自动退出");
            exit(0);
        }
        info *ori_head;
        ori_head = *Head;
        info *head = (info *) malloc(sizeof(info));
        info *node = (info *) malloc(sizeof(info));
        info *temp;
        head->Next = node;
        node = head;
        temp = ori_head->Next;
        ori_head->Next = node;
        while (!feof(fp)) {
            node = node->Next;
            fscanf(fp, "%s%s%s%s", node->name, node->workplace, node->phone, node->email);
            node->Next = (info *) malloc(sizeof(info));
            count++;
        }
        //printf("test\n");
        //printf("%s*%s*%s*%s\n",node->name, node->workplace, node->phone, node->email);//***
        node->Next = temp;
        *Head = head;
        printf("已写入内存\n");
        //Show(Head);
        fclose(fp);
    }
    else
    {
        exit(0);
    }
}

//③ 保存记录到磁盘文件；
void Write(info **Head)
{
    printf("\n文件名为data.txt，默认储存在可执行文件所在目录下\n");
    FILE *fp;
    fp = fopen("data.txt","w");
    //遍历链表
    info * p = *Head;
    if(p->Next == NULL)
        printf("无记录可供保存\n");
    //fprintf(fp,"%-22s\t%-30s\t%-22s\t%-30s\t\n", "姓名","单位","电话","邮箱地址");
    else {
        while (p->Next->Next != NULL)//1~n-1次（换行）
        {
            p = p->Next;
            fprintf(fp, "%-22s\t%-30s\t%-22s\t%s\n", p->name, p->workplace, p->phone, p->email);
        }
        p = p->Next;//最后一次 不换行
        fprintf(fp, "%-22s\t%-30s\t%-22s\t%s", p->name, p->workplace, p->phone, p->email);//不要加对齐/空格
        printf("已保存记录到data.txt\n\n");
        //Show(Head);
    }
    fclose(fp);
}

//④ 修改记录；
void Alter(info **Head) {
    printf("请输入待修改记录的姓名，条目及值：\n");
    char name_[20];
    char column[10];
    char data[30];
    //char * c[] = {"单位","电话","邮箱地址"};
    scanf("%s", name_);
    scanf("%s",column);
    scanf("%s",data);
    //遍历链表
    info *p = *Head;
    //info * pre_p = *Head;
    int count_ = 0;
    while (p->Next != NULL)
    {
        p = p->Next;
        if (!strcmp(name_, p->name))
        {
            if(!strcmp(column,"姓名")) {
                strcpy(p->name, data);
                count_++;
            }
            if(!strcmp(column,"单位")) {
                strcpy(p->workplace, data);
                count_++;
            }
            if(!strcmp(column,"电话"))
            {
                strcpy(p->phone,data);
                count_++;
            }

            if(!strcmp(column,"邮箱地址"))
            {
                strcpy(p->email,data);
                count_++;
            }
        }
    }
    if (!count_)
        printf("没有找到相关数据\n");
    else
        printf("已修改\n");
    //Show(Head);
}

//⑤ 插入一条记录；
void Insert(info **Head)
{
    printf("请输入待插入记录：\n");
    info * local_head = *Head;
    info *new = (info *)malloc(sizeof(info));
    new->Next = local_head->Next;
    local_head->Next = new;
    scanf("%s%s%s%s",new->name, new->workplace, new->phone, new->email);
    count++;
    //Show(Head);
    printf("已插入\n");
}

//⑥ 删除一条记录；
void Delete(info **Head)
{
    printf("请输入待删除记录的姓名：\n");
    char name_[20];
    scanf("%s",name_);
    //遍历链表
    info * p = *Head;
    //info * pre_p = *Head;
    int count_=0;
    while(p->Next->Next!=NULL)
    {
        if(!strcmp(name_,p->Next->name)) {//删结点
            p->Next = p->Next->Next;
            count--;
            count_++;
            printf("已删除\n");
        }
        else
            p=p->Next;//一定要写在else里面，因为如果结点被删除了p指针就不要移动了
    }
    if(!strcmp(name_,p->Next->name))//删结点
    {
        p->Next = NULL;
        count--;
        count_++;
        printf("已删除\n");
    }
    if(!count_)
        printf("没有找到相关数据\n");
    //Show(Head);
}

//⑦ 显示所有的记录
void Show(info **Head)
{
    printf("目前共有%d条联系人记录\n",count);
    //遍历链表
    info * p = *Head;
    printf("%-23s%-28s%-24s%s\n", "姓名","单位","电话","邮箱地址");
    while(p->Next!=NULL)
    {
        p=p->Next;
        printf("%-20s%-20s%-20s%s\n",p->name, p->workplace, p->phone, p->email);
    }
}

//⑧ 查找某条记录（顺序查找）
void Find(info **Head)
{
    printf("请输入待查找记录的姓名：\n");
    char name_[20];
    scanf("%s", name_);
    //遍历链表
    info *p = *Head;
    int count_ = 0;
    while (p->Next != NULL)
    {
        p = p->Next;
        if (!strcmp(name_, p->name))
        {
            printf("查询到如下记录：\n");
            printf("%-23s%-28s%-24s%s\n", "姓名","单位","电话","邮箱地址");
            printf("%-20s%-20s%-20s%s\n",p->name, p->workplace, p->phone, p->email);
            count_++;
        }
    }
    if (!count_)
        printf("没有找到相关数据\n");
    //Show(Head);
}

//⑨ 按姓名对记录升序排序
void Sort_ascend(info **Head)
{
    //遍历链表，进行排序
    info * p;
    //printf("按姓名对记录升序排序结果如下:\n");
    int i;
    for(i=0;i<count;i++)
    {
        p = *Head;
        while (p->Next->Next != NULL)//后面用到两个Next下的name值
        {
            if (strcmp(p->Next->name, p->Next->Next->name) > 0)//交换指针域
            {
                info *node1 = p->Next;
                info *temp = node1->Next;
                node1->Next = temp->Next;
                temp->Next = p->Next;
                p->Next = temp;
            }
            p = p->Next;
        }
    }
    printf("已完成排序\n");
    /*遍历链表，输出排序后数据
    p = *Head;
    printf("%-22s\t%-30s\t%-22s\t%-30s\t\n", "姓名","单位","电话","邮箱地址");
    while(p->Next!=NULL)
    {
        p=p->Next;
        printf("%-22s\t%-30s\t%-22s\t%-30s\t\n",p->name, p->workplace, p->phone, p->email);
    }*/
}

//⑩ 退出
void Quit()
{
        exit(0);
}
int main()
{
    info *main_head = (info *) malloc(sizeof(info));
    int num;
    printf("   ____               _                _          __  __                                                            _   \n"
           "  / ___| ___   _ __  | |_  __ _   ___ | |_  ___  |  \\/  |  __ _  _ __    __ _   __ _   ___  _ __ ___    ___  _ __  | |_ \n"
           " | |    / _ \\ | '_ \\ | __|/ _` | / __|| __|/ __| | |\\/| | / _` || '_ \\  / _` | / _` | / _ \\| '_ ` _ \\  / _ \\| '_ \\ | __|\n"
           " | |___| (_) || | | || |_| (_| || (__ | |_ \\__ \\ | |  | || (_| || | | || (_| || (_| ||  __/| | | | | ||  __/| | | || |_ \n"
           "  \\____|\\___/ |_| |_| \\__|\\__,_| \\___| \\__||___/ |_|  |_| \\__,_||_| |_| \\__,_| \\__, | \\___||_| |_| |_| \\___||_| |_| \\__|\n"
           "                                                                               |___/                                    ");

    while(1) {
        if(main_head->Next == NULL)
        {
            printf("\n请选择功能：\n");
            printf("　　① 录入每个联系人的基本信息（姓名、单位、电话、邮件地址）\n"
                   "　　② 从磁盘文件中读取记录到内存；\n"
                   "　　⑤ 插入一条记录；\n"
                   "　　⑩ 退出\n");
            scanf("%d", &num);
            switch (num) {
                case 1:
                    Create(&main_head);
                    break;
                case 2:
                    Read(&main_head);
                    break;
                case 5:
                    Insert(&main_head);
                    break;
                case 10:
                    Quit();
                    break;
            }
        }
        else
        {
            printf("\n请选择功能：\n");
            printf("　　② 从磁盘文件中读取记录到内存；\n"
                   "　　③ 保存记录到磁盘文件；\n"
                   "　　④ 修改记录；\n"
                   "　　⑤ 插入一条记录；\n"
                   "　　⑥ 删除一条记录；\n"
                   "　　⑦ 显示所有的记录；\n"
                   "　　⑧ 查找某条记录\n"
                   "　　⑨ 按姓名对记录升序排序\n"
                   "　　⑩ 退出\n");
            scanf("%d", &num);
            switch (num) {
                case 1:
                    Create(&main_head);
                    break;
                case 2:
                    Read(&main_head);
                    break;
                case 3:
                    Write(&main_head);
                    break;
                case 4:
                    Alter(&main_head);
                    break;
                case 5:
                    Insert(&main_head);
                    break;
                case 6:
                    Delete(&main_head);
                    break;
                case 7:
                    Show(&main_head);
                    break;
                case 8:
                    Find(&main_head);
                    break;
                case 9:
                    Sort_ascend(&main_head);
                    break;
                case 10:
                    Quit();
                    break;
            }
        }
    }
    return 0;
}

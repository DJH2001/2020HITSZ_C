#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
void ReadScore(int score[],long ID[],int *pn);
void printscore(int score[],long ID[],int n);
void total_and_average(int score[],long ID[],int *paverage,int *psum,int n);
void descending(int score[],long ID[],int n);
void ascending(int score[],long ID[],int n);
void ascendingID(int score[],long ID[],int n);
void search(int score[],long ID[],int n);
void static_analysis(int score[],long ID[],int n);
void copy(int cscore[],int score[],long id[],long ID[],int n);
void output(int cscore[],long id[],int n);
void Put(void);

int main()
{
    printf("Number:200110807\n");
    printf("experiment-No.5\n\n");
    int score[N],cscore[N];
    long ID[N],id[N];
    int average;
    int sum;
    int menu,ret,count = 0;
    int n;//定义学生总人数为n
    do
    {
        /**显示如下菜单内容*/
        printf("1.Input record\n");
        printf("2.List record\n");
        printf("3.Calculate total and average score of course\n");
        printf("4.sort in descending order by score\n");
        printf("5.sort in ascending order by score\n");
        printf("6.sort in ascending order by StudentID\n");
        printf("7.Search by StudentID\n");
        printf("8.Statistic analysis\n");
        printf("0.Exit\n");
        printf("Please enter your choice:");

        ret=scanf("%d",&menu);                          /**防止非法字符的输入，且此时ret=1，只能输入一个值*/
        while(count==0&&menu>1||ret!=1||menu<0||menu>8)/**t跳出循环的条件*/
        {
            while (getchar() != '\n');
            printf("Error!Please record first!\n");
            ret=scanf("%d",&menu);
            printf("\n");
            continue;
        }
        /**菜单的其他各种选项*/
        switch(menu)
        {

        case 1:
            Put();
            ReadScore(score,ID,&n);
            copy(cscore,score,id,ID,n);
            Put();
            break;

        case 2:
            Put();
            output(cscore,id,n);
            Put();
            break;

        case 3:
            Put();
            total_and_average(score,ID,&average,&sum,n);
            printf("\n");
            Put();
            break;

        case 4:
            Put();
            descending(score,ID,n);
            printf("The order is :\n");
            printscore(score,ID,n);
            Put();
            break;

        case 5:
            Put();
            ascending(score,ID,n);
            printf("The order is :\n");
            printscore(score,ID,n);
            Put();
            break;

        case 6:
            Put();
            ascendingID(score,ID,n);
            printf("The order is :\n");
            printscore(score,ID,n);
            Put();
            break;

        case 7:
            Put();
            search(score,ID,n);
            Put();
            break;

        case 8:
            Put();
            static_analysis(score,ID,n);
            Put();
            break;

        case 0:
            Put();
            printf("按任意键关闭窗口");
            break;

        default :
            break;
        }
        getchar();
        getchar();
        count++;
        printf("\n");
    }
    while(menu!=0);
    return 0;
}

/*********************************************
**函数名称：ReadScore
**数组：score ID
**指针：pn
**函数功能：录入每个学生的学号和成绩
**********************************************/
void ReadScore(int score[],long ID[],int *pn)
{

    int i;
    printf("学生总人数为:\n");
    scanf("%d",pn);
    for(i=0; i<*pn; i++)
    {
        printf("Input student's ID and score:");
        scanf("%ld%d",&ID[i],&score[i]);
    }
}
/*********************************************
**函数名称：copy
**数组：cscore score id ID
**变量 n
**函数功能：将score 和ID的值复制给从score id
**********************************************/
void copy(int cscore[],int score[],long id[],long ID[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cscore[i]=score[i];
        id[i]=ID[i];
    }
}
/*********************************************
**函数名称：output
**数组：cscore id
**变量 n
**函数功能：按输入的顺序输出
**********************************************/
void output(int cscore[],long id[],int n)
{
    int i;
    printf("ID      and     score:\n");
    for(i=0; i<n; i++)
    {
        printf("%ld \t \t%d",id[i],cscore[i]);
        printf("\n");
    }
}
/*********************************************
**函数名称：printscore
**数组：score ID
**变量 n
**函数功能：输出
**********************************************/
void printscore(int score[],long ID[],int n)
{
    int i;
    printf("ID      and     score:\n");
    for(i=0; i<n; i++)
    {
        printf("%ld \t \t%d",ID[i],score[i]);
        printf("\n");
    }
}

/*********************************************
**函数名称：total_and_average
**数组：score ID
**指针：paverage psum
**变量 n
**函数功能：计算课程总分和平均分
**********************************************/
void total_and_average(int score[],long ID[],int *paverage,int *psum,int n)
{
    int i,total=0;
    for(i=0; i<n; i++)
    {
        total=total+score[i];
    }
    *psum=total;
    *paverage=1.0*total/n;
    printf("总分为:%d\n",*psum);
    printf("课程平均分为:%d",*paverage);
}
/*********************************************
**函数名称：decending
**数组：score ID
**变量 n
**函数功能：按成绩由高到低排出名次表
**********************************************/
void descending(int score[],long ID[],int n)
{
    int i,j,temp1,temp2;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(score[j]>score[i])
            {
                /*交换分数*/
                temp1=score[i];
                score[i]=score[j];
                score[j]=temp1;
                /*交换学号*/
                temp2=ID[j];
                ID[j]=ID[i];
                ID[i]=temp2;
            }
        }
    }
}
/*********************************************
**函数名称：ascending
**数组：score ID
**变量 n
**函数功能：按成绩由低到高排出名次表
**********************************************/
void ascending(int score[],long ID[],int n)
{
    int i,j,temp1;
    long temp2;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(score[j]<score[i])
            {
                temp1=score[j];
                score[j]=score[i];
                score[i]=temp1;

                temp2=ID[j];
                ID[j]=ID[i];
                ID[i]=temp2;
            }
        }
    }
}
/*********************************************
**函数名称：ascendingID
**数组：score ID
**变量 n
**函数功能：按学号由小到大排出成绩表
**********************************************/
void ascendingID(int score[],long ID[],int n)
{
    int i,j,temp1;
    long temp2;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ID[j]<ID[i])
            {
                temp1=ID[j];
                ID[j]=ID[i];
                ID[i]=temp1;

                temp2=score[j];
                score[j]=score[i];
                score[i]=temp2;
            }
        }
    }
}
/*********************************************
**函数名称：search
**数组：score ID
**变量 n
**函数功能：根据学号查找学生成绩和排名
**********************************************/
void search(int score[],long ID[],int n)
{
    int i,j,temp1,count;
    long x,temp2;
    /**先进行排序*/
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(score[j]>score[i])
            {
                temp1=score[i];
                score[i]=score[j];
                score[j]=temp1;

                temp2=ID[i];
                ID[i]=ID[j];
                ID[j]=temp2;
            }
        }
    }
    do
    {
        printf("请输入学号：");
        scanf("%ld",&x);
        count = 0;
        for(i=0; i<n; i++)
        {
            if(ID[i]==x)
            {
                printf("该学生成绩是%d排名是%d",score[i],i+1);
                count++;
                break;
            }

        }
        if (count == 0)
        {
            printf("Input error!");
        }
    }while(count == 0);

}
/*********************************************
**函数名称：static_analysish
**数组：score ID
**变量 n
**函数功能：按优秀（90-100）良好（80-89）中等（70-79）及格（60-69）
不及格（50-59）五个类别，统计每个类别的人数以及所占百分比
**********************************************/
void static_analysis(int score[],long ID[],int n)
{
    int i;
    int a=0,b=0,c=0,d=0,e=0;
    for(i=0; i<n; i++)
    {
        if((score[i]>=90)&&(score[i]<=100))
        {
            a++;
        }
        else if((score[i]<=89)&&score[i]>=80)
        {
            b++;
        }
        else if((score[i]<=79)&&score[i]>=70)
        {
            c++;
        }
        else if((score[i]<=69)&&score[i]>=60)
        {
            d++;
        }
        else if((score[i]<=59)&&score[i]>=60)
        {
            e++;
        }

    }
    printf("优秀人数作战百分比为:%.2f%%\n",100.0*a/n);
    printf("良好人数作战百分比为:%.2f%%\n",100.0*b/n);
    printf("中等人数作战百分比为:%.2f%%\n",100.0*c/n);
    printf("及格人数作战百分比为:%.2f%%\n",100.0*d/n);
    printf("不及格人数作战百分比为:%.2f%%\n",100.0*e/n);
}

void Put(void)
{
    printf("*********************************************************\n");
}


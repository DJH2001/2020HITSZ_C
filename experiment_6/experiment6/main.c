#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define M 40
void ReadScore(char *pname[],int score[],long ID[],int *pn);
void printscore(char *pname[],int score[],long ID[],int n);
void total_and_average(int score[],long ID[],int *paverage,int *psum,int n);
void ascending_by_ID(char *pname[],int score[],long ID[],int n);
void ascending_by_name(char *pname[],int score[],long ID[],int n);
void search_by_ID(char *pname[],int score[],long ID[],int n);
void search_by_name(char *pname[],int score[],long ID[],int n);
void static_analysis(int score[],long ID[],int n);
void ScoreRank(char *pname[],int score[],long ID[],int n,int (*choice)(int Score1,int score2));
int Ascending(int x,int y);
int Decending(int x,int y);
void Exchange_score(int *pa,int *pb);
void Exchange(long *pa,long *pb);
void Exchangename(char *pname[],int i,int j);
void Print(void);
void copy(char *cname[],int cscore[],long id[],char *pname[],int score[],long ID[],int n);

int main()
{
    printf("Number:200110807\n");
    printf("experiment-No.6\n\n");

    int score[N],cscore[N];                                   //定义分数数组
    long ID[M],id[M];                                     //定义学号数组
    char Name[N][N],*pname[N],*cname[N];                      //字符型数组 名字
    int average=0,sum=0,menu,ret,count = 0;         //定义平均数，总数，菜单名称，ret，count
    int n,i;                                          //定义学生总人数为n
     /*二维数组与指针*/
    for(i=0;i<N;i++)
    {
        pname[i]=Name[i];
    }
    do
    {
        /*如下菜单内容*/
        printf("1.Input record\n");
        printf("2.List record\n");
        printf("3.Calculate total and average score of course\n");
        printf("4.Sort in descending order by score\n");
        printf("5.Sort in ascending order by score\n");
        printf("6.Sort in ascending order by StudentID\n");
        printf("7.Sort in dictionary order by StudentID\n");
        printf("8.Search by StudentID\n");
        printf("9.Search by name\n");
        printf("10.Statistic analysis\n");
        printf("0.Exit\n");

        printf("Please enter your choice:");
        ret=scanf("%d",&menu);                             //记录scanf的值
         //确保用户输入的正确性，只有当用户输入的值为1时才能进行下一步
        while(count==0&&menu>1||ret!=1||menu<0||menu>10)
        {
            while (getchar() != '\n');                     //清空缓存区的内容
            printf("Error!Please record first!\n");
            ret=scanf("%d",&menu);
            printf("\n");
            continue;
        }

        /**菜单选项*/
        switch(menu)
        {

        case 1:
            Print();
            ReadScore(pname,score,ID,&n);
            copy(cname,cscore,id,pname,score,ID,n);
            Print();
            break;

        case 2:
            Print();
            printscore(cname,cscore,id,n);
            Print();
            break;

        case 3:
            Print();
            total_and_average(score,ID,&average,&sum,n);
            Print();
            break;

        case 4:
            Print();
            ScoreRank(pname,score,ID,n,Decending);
            printf("The order is :\n");
            printscore(pname,score,ID,n);
            Print();
            break;

        case 5:
            Print();
            ScoreRank(pname,score,ID,n,Ascending);
            printf("The order is :\n");
            printscore(pname,score,ID,n);
            Print();
            break;

        case 6:
            Print();
            ascending_by_ID(pname,score,ID,n);
            printf("The order is :\n");
            printscore(pname,score,ID,n);
            Print();
            break;

        case 7:
            Print();
            ascending_by_name(pname,score,ID,n);
            printf("The order is :\n");
            printscore(pname,score,ID,n);
            Print();
            break;

        case 8:
            Print();
            ScoreRank(pname,score,ID,n,Decending);
            search_by_ID(pname,score,ID,n);
            Print();
            break;
        case 9:
            Print();
            ScoreRank(pname,score,ID,n,Decending);
            search_by_name(pname,score,ID,n);
            printf("\n");
            Print();
            break;

        case 10:
            Print();
            static_analysis(score,ID,n);
            printf("\n");
            Print();
            break;

        case 0:
            Print();
            printf("按任意键关闭窗口");
            break;

        default :
            break;
        }
        getchar();
        //清楚缓存区的内容
        count++;                                        //只有当menu第一次输入不等于1的时候，count才会自增，count++是为了不执行前面while循环
        printf("\n");
    }
    while(menu!=0);                                     //当menu=0的时候，退出程序
    system("Pause");
    return 0;
}
/***********************************************************
**函数名：ReadScore
**指针：pname pn
**数组：ID score
**函数功能:录入每个学生的学号,姓名和成绩
************************************************************/
void ReadScore(char *pname[],int score[],long ID[],int *pn)
{

    int i,ret;
    printf("学生总人数为:");
    printf("\n");
    ret=scanf("%d",pn);
    while (getchar() != '\n');
    /*处理非法输入，只能正数*/
    while (*pn <= 0)
    {
        printf("Input error!\nTotal number:");
        while (getchar() != '\n');
        ret = scanf("%d",pn);
    }
    printf("Start recording!\n");
    for (i=0; i<*pn; i++)
    {
        printf("请输入NO.%d个学生的相关信息\n",i+1);
        printf("Please input name:");
        gets(pname[i]);/**输入学生的名字**/
        printf("Please input ID:");
        ret=scanf("%ld",&ID[i]);
        /**处理非法字符的输入,需要注意score的范围**/
        while(ret!=1||ID[i]<0)
        {
            printf("Input error!Please input again!\n");
            while(getchar()!='\n');
            gets(pname[i]);
            ret=scanf("%ld",&ID[i]);
        }
        printf("Please input NO.%d student's scores:\n",i+1);
        ret = scanf("%d",&score[i]);//此时ret的值应该为2
        while (getchar() != '\n');//清空缓存区
        /*处理非法字符的输入，用户只能一行输入两个数，且需要注意score与id的范围*/
        while (ret != 1||score[i] > 100||score[i] < 0)
        {
            printf("Input error!\n");
            while (getchar() != '\n');
            ret = scanf("%d",&score[i]);
        }
    }
}
/***********************************************************
**函数名：copy
**指针：panme cname
**数组：ID score id cscore
**变量：n
**函数功能:fuzhi
************************************************************/
void copy(char *cname[],int cscore[],long id[],char *pname[],int score[],long ID[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cscore[i]=score[i];
        cname[i]=pname[i];
        id[i]=ID[i];
    }
}
/***********************************************************
**函数名：printscore
**指针：panme
**数组：ID score
**变量：n
**函数功能:输出每个学生的学号,姓名和成绩（要按照顺序输出）
************************************************************/
void printscore(char *pname[],int score[],long ID[],int n)
{
    int i;
    printf("Name\tID\tscore:\n");
        for (i=0;i<n;i++)
        {
            printf("%s\t%ld\t%d\n",pname[i],ID[i],score[i]);
        }
}
/***********************************************************
**函数名：total_and_average
**指针：paverage,psum
**数组：ID score
**变量：n
**函数功能:计算课程总分和平均分
************************************************************/
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
    printf("课程平均分为:%d\n",*paverage);
}
/***********************************************************
**函数名：ScoreRank
**指针：pname
**指针函数：choice
**数组：ID score
**函数功能:利用函数排名
************************************************************/
void ScoreRank(char *pname[],int score[],long ID[],int n,int (*choice)(int score1,int score2))
{
    int i,j,k;                                                         //定义三个变量
    for (i=0;i<n;i++)
    {
        k=i;
        /*做出判断*/                                                         //将i的值暂时赋值给k，相当于对k进行初始化
        for (j=i+1;j<n;j++)
        {
            if ((*choice)(score[k],score[j]))//if的条件句 1为真，0为假
            {
                k=j;
            }
        }
        /*如果if括号中的值为1，则将j的值赋值给k，第一次for循环到找到最大（最小）的那一个，第二次for循环找到第二大（第二小）的那一个……*/

        /*定义的三个交换函数*/
        Exchange_score(&score[i],&score[k]);//此时i的值没有变化，经历过一次for循环后，可以交换分数
        Exchange(&ID[i],&ID[k]);//同理交换学号
        Exchangename(pname,i,k);//同理交换姓名
    }
}
/**降序函数*/
int Decending(int x,int y)
{
    return x<y;         //此时的result返回到函数ScoreRank中去
}
/**升序函数*/
int Ascending(int x,int y)
{
    return x>y;         //此时的result返回到函数ScoreRank中去
}
/***********************************************************
**函数名：Exchange
**指针：pa pb
**函数功能:交换
************************************************************/
void Exchange(long *pa,long *pb)
{
    long Temp;//定义一个中间变量
    Temp = *pa;
    *pa = *pb;
    *pb = Temp;
}
/***********************************************************
**函数名：Exchange_score
**指针：pa pb
**函数功能:交换
************************************************************/
void Exchange_score(int *pa,int *pb)
{
    int Temp;//定义一个中间变量
    Temp = *pa;
    *pa = *pb;
    *pb = Temp;
}
/***********************************************************
**函数名：Exchangename
**指针：pname
**变量：i j
**函数功能:交换名字（即交换字符串
************************************************************/
void Exchangename(char *pname[],int i,int j)
{
    char *Temp[N];
    Temp[i] = pname[i];
    pname[i] = pname[j];
    pname[j] = Temp[i];
}
/***********************************************************
**函数名：ascending_by_ID
**指针：pname
**数组：score ID
**变量：n
**函数功能:按学号由小到大排出成绩表
************************************************************/
void ascending_by_ID(char *pname[],int score[],long ID[],int n)
{
    int i,j,k;
    for (i=0;i<n;i++)
    {
        k=i;
        for (j=i+1;j<n;j++)
        {
            if (Ascending(ID[k],ID[j]))//这里调用了函数做出判断
            {
                k=j;
            }
        }
        Exchange_score(&score[i],&score[k]);
        Exchange(&ID[i],&ID[k]);
        Exchangename(pname,i,k);
    }
}
/***********************************************************
**函数名：search_by_ID
**指针：pname
**数组：score ID
**变量：n
**函数功能:按姓名的字典顺序排出成绩表
************************************************************/
void ascending_by_name(char *pname[],int score[],long ID[],int n)
{
    int i,j,k;
    for (i=0;i<n;i++)
    {
        k = i;
        for (j=i;j<n;j++)
        {
            if (strcmp(pname[k],pname[j])>0)//
            {
                k=j;
            }
        }
        Exchangename(pname,i,k);
        Exchange_score(&score[i],&score[k]);
        Exchange(&ID[i],&ID[k]);
    }
}
/***********************************************************
**函数名：search_by_ID
**指针：pname
**数组：score ID
**变量：n
**函数功能:按学号查询学生排名及其考试成绩
************************************************************/
void search_by_ID(char *pname[],int score[],long ID[],int n)
{
    int i,count;
    long x;
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
        if (count == 0)printf("Input error!");
    }
    while(count == 0);
    printf("\n");
}
/***********************************************************
**函数名：search_by_name
**指针：pname
**数组：score ID
**变量：n
**函数功能:按姓名查询学生排名及其考试成绩
************************************************************/
void search_by_name(char *pname[],int score[],long ID[],int n)
{
    int i,count=0;
    char stuname[N];
    while(getchar()!='\n');
    printf("请输入学生的姓名：");
    gets(stuname);
    do
    {
        count=0;
        for(i=0;i<n;i++)
        {
            if(strcmp(stuname,pname[i]) == 0)
            {
                printf("他的排名为%d,考试成绩为%d\n",i+1,score[i]);
                count++;
                break;
            }
        }
        if(count==0)
        {
            printf("Error!Please input again!\n");
        }
    }while(count==0);
}
/***********************************************************
**函数名：static_analys
**数组：score ID
**变量：n
**函数功能:按优秀（90-100）良好（80-89）中等（70-79）及格（60-69）
不及格（50-59）五个类别，统计每个类别的人数以及所占百分比
************************************************************/
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
void Print(void)
{
    printf("----------------------------------------------------\n");
}








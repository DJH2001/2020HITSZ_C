#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define M 6
#define A 4000
void ReadScore(long ID[],char *pname[],int *score,int *pn,int *pm);
void copy(char *cname[],long id[],int *cscore,float caver[],int ctotal[],long ID[],char *pname[],int *score,float aver[],int total[],int n,int m);
void printscore(char *cname[],long id[],int *cscore,int ctotal[],float caver[],int n,int m);
void total_and_average_course(int *score,int total_C[],int n,int m);
void ascending_by_ID(char *pname[],int *score,int total[],long ID[],int n,int m);
void ascending_by_name(char *pname[],int *score,int total[],long ID[],int n,int m);
void search_by_ID(char *pname[],int *score,int total[],long ID[],int n,int m);
void search_by_name(char *pname[],int *score,int total[],long ID[],int n,int m);
void static_analysis(int *score,int n,int m);
void ScoreRank(char *pname[],int *score,int total[],long ID[],int n,int m,int (*choice)(int Score1,int score2));
int Ascending(int x,int y);
int Descending(int x,int y);
void Exchange(int *pa,int *pb);
void Exchange_id(long *a,long *b);
void Exchangename(char *pname[],int i,int j);
void Output(long ID[],char *pname[],int *score,int total[],int n,int m);
void Total(char *pname[],int *score,long ID[],int total[],float aver[],int n,int m);
void Print(void);

int main()
{
    printf("Number:200110807\n段佳慧\n");
    printf("experiment-No.7\n\n");

    /**定义平均数，总数，菜单名称，ret，定义学生总人数为n,count ,定义分数数组*/
    int score[N][M],cscore[N][M],menu,ret,count = 0,n,i,m;
    int total[N],total_C[M],ctotal[N];
    long ID[A],id[A];
    float aver[N],caver[N];                                 /**定义学号数组*/
    char Name[N][N],*pname[N],*cname[N];                      /**字符型数组 名字*/
    /**二维数组与指针*/
    for(i=0; i<N; i++)
    {
        pname[i]=Name[i];
    }
    do
    {
        /**如下菜单内容*/
        printf("1.Input record\n");
        printf("2.List record\n");
        printf("3.Calculate total and average score of course\n");
        printf("4.Calculate total and average score of every student\n");
        printf("5.Sort in descending order by score of every student\n");
        printf("6.Sort in ascending order by score of every student\n");
        printf("7.Sort in ascending order by StudentID\n");
        printf("8.Sort in dictionary order by name\n");
        printf("9.Search by StudentID\n");
        printf("10.Search by name\n");
        printf("11.Statistic analysis for every course\n");
        printf("0.Exit\n");
        printf("Please enter your choice:");
        ret=scanf("%d",&menu);                             /**记录scanf的值*/
        /**确保用户输入的正确性，只有当用户输入的值为1时才能进行下一步**/
        while(count==0&&menu>1||ret!=1||menu<0||menu>11)
        {
            while (getchar() != '\n');                     /**清空缓存区的内容**/
            printf("Error!Please record first!\n");
            ret=scanf("%d",&menu);
            printf("\n");
            continue;
        }

        /**菜单选项**/
        switch(menu)
        {

        case 1:/**录入每个学生的学号,姓名和各科成绩*/
            Print();
            ReadScore(ID,pname,*score,&n,&m);
            Total(pname,*score,ID,total,aver,n,m);
            copy(cname,id,*cscore,caver,ctotal,ID,pname,*score,aver,total,n,m);
            Print();
            break;

        case 2:/**输出每个学生的学号,姓名和各科考试成绩，总分，平均分（要按照顺序输出）*/
            Print();
            printscore(cname,id,*cscore,ctotal,caver,n,m);
            Print();
            break;

        case 3:/**计算每门课程总分和平均分*/
            Print();
            printscore(cname,id,*cscore,ctotal,caver,n,m);
            total_and_average_course(*score,total_C,n,m);
            Print();
            break;

        case 4:/**计算每个学生的总分和平均分*/
            Print();
            Total(pname,*score,ID,total,aver,n,m);
            Output(ID,pname,*score,total,n,m);
            Print();
            break;

        case 5:/**按照每个学生的总分由高到低排出名次表*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Descending);
            printf("The order is :\n");
            Output(ID,pname,*score,total,n,m);
            Print();
            break;
        case 6:/**按照每个学生的总分由低到高排出名次表*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Ascending);
            printf("The order is :\n");
            Output(ID,pname,*score,total,n,m);
            Print();
            break;

        case 7:/**按照学号由小到大排出成绩表**/
            Print();
            ascending_by_ID(pname,*score,total,ID,n,m);
            printf("The order is :\n");
            Output(ID,pname,*score,total,n,m);
            Print();
            break;

        case 8:/**按照姓名的字典顺序排出成绩表*/
            Print();
            ascending_by_name(pname,*score,total,ID,n,m);
            printf("The order is :\n");
            Output(ID,pname,*score,total,n,m);
            Print();
            break;

        case 9:/**按照学号查询学生排名和各科考试成绩*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Descending);
            search_by_ID(pname,*score,total,ID,n,m);
            Print();
            break;

        case 10:/**按照姓名查询学生排名及其各科考试成绩*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Descending);
            search_by_name(pname,*score,total,ID,n,m);
            Print();
            break;

        case 11:/**按照优秀，良好……对每门课程分别统计每个类别的人数及其所占百分比*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Descending);
            static_analysis(*score,n,m);
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
        getchar();                                     /**清楚缓存区的内容**/
        /**只有当menu第一次输入不等于1的时候，count才会自增，count++是为了不执行前面while循环**/
        count++;
        printf("\n");
    }
    while(menu!=0);                                     /**当menu=0的时候，退出循环以及程序**/
    system("Pause");
    return 0;
}
/*****************************************************************
**函数名：ReadScore
**指针：score pname pn pm
**数组：score ID
**函数功能：录入每个学生的学号,姓名和各科成绩
******************************************************************/
void ReadScore(long ID[],char *pname[],int *score,int *pn,int *pm)
{
    int i,ret,j;
    printf("学生总人数为:");
    printf("\n");
    ret=scanf("%d",pn);
    while (getchar() != '\n');
    /**处理非法输入，只能正数**/
    while (ret!=1||*pn <= 0)
    {
        printf("Input error!\nPlease input again!");
        while (getchar() != '\n');
        ret = scanf("%d",pn);
    }
    printf("学生考试的总课程数目为：");
    ret=scanf("%d",pm);
    while(getchar()!='\n');
    while (*pm <= 0||*pm>6)
    {
        printf("Input error!\nPlease input again!");
        while (getchar() != '\n');
        ret = scanf("%d",pm);
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
        for(j=0; j<*pm; j++)
        {
            printf("第%d门课成绩为：",j+1);
            ret=scanf("%d",&score[i*(*pm)+j]);
            /**处理非法字符的输入,需要注意score的范围**/
            while(ret!=1||score[i*(*pm)+j]>100||score[i*(*pm)+j]<0)
            {
                printf("输入格式有误，重新录入！\n");
                ret=scanf("%d",&score[i*(*pm)+j]);
            }
        }
        while (getchar() != '\n');/**清空缓存区**/
    }
}
/*****************************************************************
**函数名：copy
**指针：cscore cname
**数组：score
**变量：n m
**函数功能：复制，确保输出时候仍然按照原顺序输出
******************************************************************/
void copy(char *cname[],long id[],int *cscore,float caver[],int ctotal[],long ID[],char *pname[],int *score,float aver[],int total[],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
           cname[i]=pname[i];
           id[i]=ID[i];
           caver[i]=aver[i];
           ctotal[i]=total[i];
           for(j=0;j<m;j++)
           {
               cscore[i*m+j]=score[i*m+j];
           }
    }
}
/*****************************************************************
**函数名：printscore
**指针：score pname
**变量：n m
**函数功能：按顺序输出每个学生的学号，姓名，和各科考试成绩,总分 平均分
******************************************************************/
void printscore(char *cname[],long id[],int *cscore,int ctotal[],float caver[],int n,int m)
{
    int i,j;
    printf("学生的成绩表如下:\n");
    printf("姓名\t学号\t各科成绩\t总分\t平均分\n");
    for (i=0; i<n; i++)
    {
        printf("%s\t%ld\t",cname[i],id[i]);
        for(j=0; j<m; j++)
        {
            printf("%d ",cscore[i*m+j]);
        }
        printf("\t\t%d\t%f",ctotal[i],caver[i]);
        printf("\n");
    }
}


/*****************************************************************
**函数名：total_and_average_course
**指针：score
**数组：total_C
**变量：n m
**函数功能：计算每门课程的总分和平均分，并将数据存在total_C中
******************************************************************/
void total_and_average_course(int *score,int total_C[],int n,int m)
{
    int i,j;
    float average;
    for(j=0; j<m; j++)
    {
        total_C[j]=0;
        average=0;
        for(i=0; i<n; i++)
        {
            total_C[j]=score[i*m+j]+total_C[j];
        }
        average=total_C[j]/(1.0*n);
        printf("第%d门学科的总成绩为:%d,平均分为:%.2f\n",j+1,total_C[j],average);
    }
}
/*****************************************************************
**函数名：Total
**指针：score，pname
**数组：total，ID，aver
**变量：n m
**函数功能：计算总分
**计算总分，并将总分存储在数组total中,将平均分存储在aver中
******************************************************************/
void Total(char *pname[],int *score,long ID[],int total[],float aver[],int n,int m)
{
    int i,j,k,sum;
    float average;
    for(i=0; i<n; i++)
    {
        for(k=0; k<m; k++)
        {
            sum=0;
            average=0;
            for(j=0; j<m; j++)
            {
                sum=score[i*m+j]+sum;
            }
            total[i]=sum;
            average=sum/(1.0*m);
            aver[i]=average;
        }
    }
}
/*****************************************************************
**函数名：ScoreRank
**指针：pname score
**指针函数：choice
**数组：total ID
**变量名：n m
**函数功能：利用指针函数进行排序
**排序思想：如果if括号中的值为1，则将j的值赋值给k，第一次for循环到找到最大（最小）的那一个
第二次for循环找到第二大（第二小）的那一个……
******************************************************************/
void ScoreRank(char *pname[],int *score,int total[],long ID[],int n,int m,int (*choice)(int Score1,int score2))
{
    int i,j,k;
    for (i=0; i<n; i++)
    {
        k=i;                           /**将i的值暂时赋值给k，相当于对k进行初始化**/
        for (j=i+1; j<n; j++)
        {
            if ((*choice)(total[k],total[j]))
            {
                k=j;
            }
        }
        Exchange(&total[i],&total[k]);/**交换函数：此时i的值没有变化，经历过一次for循环后，可以交换分数**/
        /**循环交换每个人的分数**/
        for(j=0; j<m; j++)
        {
            Exchange(&score[i*m+j],&score[k*m+j]);
        }
        Exchange_id(&ID[i],&ID[k]);
        Exchangename(pname,i,k);
    }
}
/*****************************************************************
**函数名：Descending
**变量：x y
**函数功能：比较大小 返回（降序）
******************************************************************/
int Descending(int x,int y)
{
    return x<y;
}
/*****************************************************************
**函数名：Ascending
**变量：x y
**函数功能：比较大小 返回（升序）
******************************************************************/
int Ascending(int x,int y)
{
    return x>y;
}
/*****************************************************************
**函数名：Exchange
**指针：pa pb
**函数功能：实现分数的交换
******************************************************************/
void Exchange(int *pa,int *pb)
{
    int Temp;/**定义一个中间变量**/
    Temp = *pa;
    *pa = *pb;
    *pb = Temp;
}
/*****************************************************************
**函数名：Exchange_id
**变量：a b
**函数功能：实现学号的交换
******************************************************************/
void Exchange_id(long *a,long *b)
{
    long TEMP;
    TEMP=*a;
    *a=*b;
    *b=TEMP;
}
/*****************************************************************
**函数名：Exchangename
**指针：score，pname
**变量：i j
**函数功能：实现名字的交换（即交换字符串）
******************************************************************/
void Exchangename(char *pname[],int i,int j)
{
    char *TempN[N];
    TempN[i] = pname[i];
    pname[i] = pname[j];
    pname[j] = TempN[i];
}
/*****************************************************************
**函数名：ascending_by_ID
**指针：score，pname
**数组：total，ID
**变量：n m
**函数功能：按学号由小到大排出成绩表
******************************************************************/
void ascending_by_ID(char *pname[],int *score,int total[],long ID[],int n,int m)
{
    int i,j,k;
    for (i=0; i<n; i++)
    {
        k=i;
        for (j=i+1; j<n; j++)
        {
            if (Ascending(ID[k],ID[j]))/**这里调用了函数做出判断**/
            {
                k=j;
            }
        }
        Exchange(&total[i],&total[k]);/**此时i的值没有变化，经历过一次for循环后，可以交换分数**/
        for(j=0; j<m; j++)
        {
            Exchange(&score[i*m+j],&score[k*m+j]);
        }
        Exchange_id(&ID[i],&ID[k]);
        Exchangename(pname,i,k);
    }
}
/*****************************************************************
**函数名：ascending_by_name
**指针：score，pname
**数组：total，ID
**变量：n m
**函数功能：按姓名的字典顺序排出成绩表
******************************************************************/
void ascending_by_name(char *pname[],int *score,int total[],long ID[],int n,int m)
{
    int i,j,k;
    for (i=0; i<n; i++)
    {
        k = i;
        for (j=i; j<n; j++)
        {
            if (strcmp(pname[k],pname[j])>0)
            {
                k=j;
            }
        }
        Exchange(&total[i],&total[k]);//此时i的值没有变化，经历过一次for循环后，可以交换分数
        for(j=0; j<m; j++)
        {
            Exchange(&score[i*m+j],&score[k*m+j]);
        }
        Exchange_id(&ID[i],&ID[k]);//同理交换学号
        Exchangename(pname,i,k);//同理交换姓名
    }
}
/*****************************************************************
**函数名：searc_by_ID
**指针：score，pname
**数组：total，ID
**变量：n m
**函数功能：根据学号查找学生成绩和排名
******************************************************************/
void search_by_ID(char *pname[],int *score,int total[],long ID[],int n,int m)
{
    int i,j,count;
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
                printf("该学生是%s\n",pname[i]);
                printf("%s排名是%d \n",pname[i],i+1);
                printf("%s的各科考试成绩为：",pname[i]);
                for(j=0; j<m; j++)
                {
                    printf("%d ",score[i*m+j]);
                }
                printf("\n%s的总成绩为%d",pname[i],total[i]);
                count++;
                break;
            }
        }
        if (count == 0)
        {
            printf("Input error!");
        }
        printf("\n");
    }
    while(count == 0);
}
/*****************************************************************
**函数名：search_by_name
**指针：score，pname
**数组：total，ID
**变量：n m
**函数功能：按姓名查询学生排名及其考试成绩
******************************************************************/
void search_by_name(char *pname[],int *score,int total[],long ID[],int n,int m)
{
    int i,j,count=0;
    char stuname[N];
    do
    {
        while(getchar()!='\n');
        printf("请输入学生的姓名：");
        gets(stuname);
        count=0;
        for(i=0; i<n; i++)
        {
            if(strcmp(stuname,pname[i]) == 0)
            {
                printf("他的排名为%d\n",i+1);
                printf("他的各科考试成绩是：");
                for(j=0; j<m; j++)
                {
                    printf("%d ",score[i*m+j]);
                }
                printf("\n该学生的总成绩为%d",total[i]);
                count++;
                break;
            }
        }
        if(count==0)
        {
            printf("Error!Please input again!\n");
        }
        while(getchar()!='\n');
    }
    while(count==0);
}
/*****************************************************************
**函数名：static_analysis
**指针：score
**变量：n m
**函数功能：按优秀（90-100）良好（80-89）中等（70-79）及格（60-69）不及格（50-59）五个类别
统计每个类别的人数以及所占百分比
*****************************************************************/
void static_analysis(int *score,int n,int m)
{
    int i,j;
    int a=0,b=0,c=0,d=0,e=0;
    for(j=0; j<m; j++)
    {
        a=0,b=0,c=0,d=0,e=0;
        for(i=0; i<n; i++)
        {
            if((score[i*m+j]>=90)&&(score[i*m+j]<=100))
            {
                a++;
            }
            else if((score[i*m+j]<=89)&&score[i*m+j]>=80)
            {
                b++;
            }
            else if((score[i*m+j]<=79)&&score[i*m+j]>=70)
            {
                c++;
            }
            else if((score[i*m+j]<=69)&&score[i*m+j]>=60)
            {
                d++;
            }
            else if(score[i*m+j]<=59)
            {
                e++;
            }
        }
        printf("第%d门课程优秀人数作战百分比为:%.2f%%\n",j+1,100.0*a/n);
        printf("第%d门课程良好人数作战百分比为:%.2f%%\n",j+1,100.0*b/n);
        printf("第%d门课程中等人数作战百分比为:%.2f%%\n",j+1,100.0*c/n);
        printf("第%d门课程及格人数作战百分比为:%.2f%%\n",j+1,100.0*d/n);
        printf("第%d门课程不及格人数作战百分比为:%.2f%%\n",j+1,100.0*e/n);
        printf("\n");
    }
}
/*****************************************************************
**函数名：Output
**指针：score，pname
**数组：total，ID
**变量：n m
**函数功能：输出成绩表
******************************************************************/
void Output(long ID[],char *pname[],int *score,int total[],int n,int m)
{
    int i,j;
    printf("学生的成绩表如下:\n");
    printf("姓名\t学号\t各科成绩\t总成绩\n");
    for (i=0; i<n; i++)
    {

        printf("%s\t%ld\t",pname[i],ID[i]);
        for(j=0; j<m; j++)
        {
            printf("%d ",score[i*m+j]);
        }
        printf("\t\t");
        printf("%d",total[i]);
        printf("\n");
    }

}

void Print(void)
{
    printf("==================================================================================\n");
}








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
    printf("Number:200110807\n�μѻ�\n");
    printf("experiment-No.7\n\n");

    /**����ƽ�������������˵����ƣ�ret������ѧ��������Ϊn,count ,�����������*/
    int score[N][M],cscore[N][M],menu,ret,count = 0,n,i,m;
    int total[N],total_C[M],ctotal[N];
    long ID[A],id[A];
    float aver[N],caver[N];                                 /**����ѧ������*/
    char Name[N][N],*pname[N],*cname[N];                      /**�ַ������� ����*/
    /**��ά������ָ��*/
    for(i=0; i<N; i++)
    {
        pname[i]=Name[i];
    }
    do
    {
        /**���²˵�����*/
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
        ret=scanf("%d",&menu);                             /**��¼scanf��ֵ*/
        /**ȷ���û��������ȷ�ԣ�ֻ�е��û������ֵΪ1ʱ���ܽ�����һ��**/
        while(count==0&&menu>1||ret!=1||menu<0||menu>11)
        {
            while (getchar() != '\n');                     /**��ջ�����������**/
            printf("Error!Please record first!\n");
            ret=scanf("%d",&menu);
            printf("\n");
            continue;
        }

        /**�˵�ѡ��**/
        switch(menu)
        {

        case 1:/**¼��ÿ��ѧ����ѧ��,�����͸��Ƴɼ�*/
            Print();
            ReadScore(ID,pname,*score,&n,&m);
            Total(pname,*score,ID,total,aver,n,m);
            copy(cname,id,*cscore,caver,ctotal,ID,pname,*score,aver,total,n,m);
            Print();
            break;

        case 2:/**���ÿ��ѧ����ѧ��,�����͸��ƿ��Գɼ����ܷ֣�ƽ���֣�Ҫ����˳�������*/
            Print();
            printscore(cname,id,*cscore,ctotal,caver,n,m);
            Print();
            break;

        case 3:/**����ÿ�ſγ��ֺܷ�ƽ����*/
            Print();
            printscore(cname,id,*cscore,ctotal,caver,n,m);
            total_and_average_course(*score,total_C,n,m);
            Print();
            break;

        case 4:/**����ÿ��ѧ�����ֺܷ�ƽ����*/
            Print();
            Total(pname,*score,ID,total,aver,n,m);
            Output(ID,pname,*score,total,n,m);
            Print();
            break;

        case 5:/**����ÿ��ѧ�����ܷ��ɸߵ����ų����α�*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Descending);
            printf("The order is :\n");
            Output(ID,pname,*score,total,n,m);
            Print();
            break;
        case 6:/**����ÿ��ѧ�����ܷ��ɵ͵����ų����α�*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Ascending);
            printf("The order is :\n");
            Output(ID,pname,*score,total,n,m);
            Print();
            break;

        case 7:/**����ѧ����С�����ų��ɼ���**/
            Print();
            ascending_by_ID(pname,*score,total,ID,n,m);
            printf("The order is :\n");
            Output(ID,pname,*score,total,n,m);
            Print();
            break;

        case 8:/**�����������ֵ�˳���ų��ɼ���*/
            Print();
            ascending_by_name(pname,*score,total,ID,n,m);
            printf("The order is :\n");
            Output(ID,pname,*score,total,n,m);
            Print();
            break;

        case 9:/**����ѧ�Ų�ѯѧ�������͸��ƿ��Գɼ�*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Descending);
            search_by_ID(pname,*score,total,ID,n,m);
            Print();
            break;

        case 10:/**����������ѯѧ������������ƿ��Գɼ�*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Descending);
            search_by_name(pname,*score,total,ID,n,m);
            Print();
            break;

        case 11:/**�������㣬���á�����ÿ�ſγ̷ֱ�ͳ��ÿ����������������ռ�ٷֱ�*/
            Print();
            ScoreRank(pname,*score,total,ID,n,m,Descending);
            static_analysis(*score,n,m);
            printf("\n");
            Print();
            break;

        case 0:
            Print();
            printf("��������رմ���");
            break;

        default :
            break;
        }
        getchar();                                     /**���������������**/
        /**ֻ�е�menu��һ�����벻����1��ʱ��count�Ż�������count++��Ϊ�˲�ִ��ǰ��whileѭ��**/
        count++;
        printf("\n");
    }
    while(menu!=0);                                     /**��menu=0��ʱ���˳�ѭ���Լ�����**/
    system("Pause");
    return 0;
}
/*****************************************************************
**��������ReadScore
**ָ�룺score pname pn pm
**���飺score ID
**�������ܣ�¼��ÿ��ѧ����ѧ��,�����͸��Ƴɼ�
******************************************************************/
void ReadScore(long ID[],char *pname[],int *score,int *pn,int *pm)
{
    int i,ret,j;
    printf("ѧ��������Ϊ:");
    printf("\n");
    ret=scanf("%d",pn);
    while (getchar() != '\n');
    /**����Ƿ����룬ֻ������**/
    while (ret!=1||*pn <= 0)
    {
        printf("Input error!\nPlease input again!");
        while (getchar() != '\n');
        ret = scanf("%d",pn);
    }
    printf("ѧ�����Ե��ܿγ���ĿΪ��");
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
        printf("������NO.%d��ѧ���������Ϣ\n",i+1);
        printf("Please input name:");
        gets(pname[i]);/**����ѧ��������**/
        printf("Please input ID:");
        ret=scanf("%ld",&ID[i]);
        /**����Ƿ��ַ�������,��Ҫע��score�ķ�Χ**/
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
            printf("��%d�ſγɼ�Ϊ��",j+1);
            ret=scanf("%d",&score[i*(*pm)+j]);
            /**����Ƿ��ַ�������,��Ҫע��score�ķ�Χ**/
            while(ret!=1||score[i*(*pm)+j]>100||score[i*(*pm)+j]<0)
            {
                printf("�����ʽ��������¼�룡\n");
                ret=scanf("%d",&score[i*(*pm)+j]);
            }
        }
        while (getchar() != '\n');/**��ջ�����**/
    }
}
/*****************************************************************
**��������copy
**ָ�룺cscore cname
**���飺score
**������n m
**�������ܣ����ƣ�ȷ�����ʱ����Ȼ����ԭ˳�����
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
**��������printscore
**ָ�룺score pname
**������n m
**�������ܣ���˳�����ÿ��ѧ����ѧ�ţ��������͸��ƿ��Գɼ�,�ܷ� ƽ����
******************************************************************/
void printscore(char *cname[],long id[],int *cscore,int ctotal[],float caver[],int n,int m)
{
    int i,j;
    printf("ѧ���ĳɼ�������:\n");
    printf("����\tѧ��\t���Ƴɼ�\t�ܷ�\tƽ����\n");
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
**��������total_and_average_course
**ָ�룺score
**���飺total_C
**������n m
**�������ܣ�����ÿ�ſγ̵��ֺܷ�ƽ���֣��������ݴ���total_C��
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
        printf("��%d��ѧ�Ƶ��ܳɼ�Ϊ:%d,ƽ����Ϊ:%.2f\n",j+1,total_C[j],average);
    }
}
/*****************************************************************
**��������Total
**ָ�룺score��pname
**���飺total��ID��aver
**������n m
**�������ܣ������ܷ�
**�����ܷ֣������ִܷ洢������total��,��ƽ���ִ洢��aver��
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
**��������ScoreRank
**ָ�룺pname score
**ָ�뺯����choice
**���飺total ID
**��������n m
**�������ܣ�����ָ�뺯����������
**����˼�룺���if�����е�ֵΪ1����j��ֵ��ֵ��k����һ��forѭ�����ҵ������С������һ��
�ڶ���forѭ���ҵ��ڶ��󣨵ڶ�С������һ������
******************************************************************/
void ScoreRank(char *pname[],int *score,int total[],long ID[],int n,int m,int (*choice)(int Score1,int score2))
{
    int i,j,k;
    for (i=0; i<n; i++)
    {
        k=i;                           /**��i��ֵ��ʱ��ֵ��k���൱�ڶ�k���г�ʼ��**/
        for (j=i+1; j<n; j++)
        {
            if ((*choice)(total[k],total[j]))
            {
                k=j;
            }
        }
        Exchange(&total[i],&total[k]);/**������������ʱi��ֵû�б仯��������һ��forѭ���󣬿��Խ�������**/
        /**ѭ������ÿ���˵ķ���**/
        for(j=0; j<m; j++)
        {
            Exchange(&score[i*m+j],&score[k*m+j]);
        }
        Exchange_id(&ID[i],&ID[k]);
        Exchangename(pname,i,k);
    }
}
/*****************************************************************
**��������Descending
**������x y
**�������ܣ��Ƚϴ�С ���أ�����
******************************************************************/
int Descending(int x,int y)
{
    return x<y;
}
/*****************************************************************
**��������Ascending
**������x y
**�������ܣ��Ƚϴ�С ���أ�����
******************************************************************/
int Ascending(int x,int y)
{
    return x>y;
}
/*****************************************************************
**��������Exchange
**ָ�룺pa pb
**�������ܣ�ʵ�ַ����Ľ���
******************************************************************/
void Exchange(int *pa,int *pb)
{
    int Temp;/**����һ���м����**/
    Temp = *pa;
    *pa = *pb;
    *pb = Temp;
}
/*****************************************************************
**��������Exchange_id
**������a b
**�������ܣ�ʵ��ѧ�ŵĽ���
******************************************************************/
void Exchange_id(long *a,long *b)
{
    long TEMP;
    TEMP=*a;
    *a=*b;
    *b=TEMP;
}
/*****************************************************************
**��������Exchangename
**ָ�룺score��pname
**������i j
**�������ܣ�ʵ�����ֵĽ������������ַ�����
******************************************************************/
void Exchangename(char *pname[],int i,int j)
{
    char *TempN[N];
    TempN[i] = pname[i];
    pname[i] = pname[j];
    pname[j] = TempN[i];
}
/*****************************************************************
**��������ascending_by_ID
**ָ�룺score��pname
**���飺total��ID
**������n m
**�������ܣ���ѧ����С�����ų��ɼ���
******************************************************************/
void ascending_by_ID(char *pname[],int *score,int total[],long ID[],int n,int m)
{
    int i,j,k;
    for (i=0; i<n; i++)
    {
        k=i;
        for (j=i+1; j<n; j++)
        {
            if (Ascending(ID[k],ID[j]))/**��������˺��������ж�**/
            {
                k=j;
            }
        }
        Exchange(&total[i],&total[k]);/**��ʱi��ֵû�б仯��������һ��forѭ���󣬿��Խ�������**/
        for(j=0; j<m; j++)
        {
            Exchange(&score[i*m+j],&score[k*m+j]);
        }
        Exchange_id(&ID[i],&ID[k]);
        Exchangename(pname,i,k);
    }
}
/*****************************************************************
**��������ascending_by_name
**ָ�룺score��pname
**���飺total��ID
**������n m
**�������ܣ����������ֵ�˳���ų��ɼ���
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
        Exchange(&total[i],&total[k]);//��ʱi��ֵû�б仯��������һ��forѭ���󣬿��Խ�������
        for(j=0; j<m; j++)
        {
            Exchange(&score[i*m+j],&score[k*m+j]);
        }
        Exchange_id(&ID[i],&ID[k]);//ͬ����ѧ��
        Exchangename(pname,i,k);//ͬ��������
    }
}
/*****************************************************************
**��������searc_by_ID
**ָ�룺score��pname
**���飺total��ID
**������n m
**�������ܣ�����ѧ�Ų���ѧ���ɼ�������
******************************************************************/
void search_by_ID(char *pname[],int *score,int total[],long ID[],int n,int m)
{
    int i,j,count;
    long x;
    do
    {
        printf("������ѧ�ţ�");
        scanf("%ld",&x);
        count = 0;
        for(i=0; i<n; i++)
        {
            if(ID[i]==x)
            {
                printf("��ѧ����%s\n",pname[i]);
                printf("%s������%d \n",pname[i],i+1);
                printf("%s�ĸ��ƿ��Գɼ�Ϊ��",pname[i]);
                for(j=0; j<m; j++)
                {
                    printf("%d ",score[i*m+j]);
                }
                printf("\n%s���ܳɼ�Ϊ%d",pname[i],total[i]);
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
**��������search_by_name
**ָ�룺score��pname
**���飺total��ID
**������n m
**�������ܣ���������ѯѧ���������俼�Գɼ�
******************************************************************/
void search_by_name(char *pname[],int *score,int total[],long ID[],int n,int m)
{
    int i,j,count=0;
    char stuname[N];
    do
    {
        while(getchar()!='\n');
        printf("������ѧ����������");
        gets(stuname);
        count=0;
        for(i=0; i<n; i++)
        {
            if(strcmp(stuname,pname[i]) == 0)
            {
                printf("��������Ϊ%d\n",i+1);
                printf("���ĸ��ƿ��Գɼ��ǣ�");
                for(j=0; j<m; j++)
                {
                    printf("%d ",score[i*m+j]);
                }
                printf("\n��ѧ�����ܳɼ�Ϊ%d",total[i]);
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
**��������static_analysis
**ָ�룺score
**������n m
**�������ܣ������㣨90-100�����ã�80-89���еȣ�70-79������60-69��������50-59��������
ͳ��ÿ�����������Լ���ռ�ٷֱ�
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
        printf("��%d�ſγ�����������ս�ٷֱ�Ϊ:%.2f%%\n",j+1,100.0*a/n);
        printf("��%d�ſγ�����������ս�ٷֱ�Ϊ:%.2f%%\n",j+1,100.0*b/n);
        printf("��%d�ſγ��е�������ս�ٷֱ�Ϊ:%.2f%%\n",j+1,100.0*c/n);
        printf("��%d�ſγ̼���������ս�ٷֱ�Ϊ:%.2f%%\n",j+1,100.0*d/n);
        printf("��%d�ſγ̲�����������ս�ٷֱ�Ϊ:%.2f%%\n",j+1,100.0*e/n);
        printf("\n");
    }
}
/*****************************************************************
**��������Output
**ָ�룺score��pname
**���飺total��ID
**������n m
**�������ܣ�����ɼ���
******************************************************************/
void Output(long ID[],char *pname[],int *score,int total[],int n,int m)
{
    int i,j;
    printf("ѧ���ĳɼ�������:\n");
    printf("����\tѧ��\t���Ƴɼ�\t�ܳɼ�\n");
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








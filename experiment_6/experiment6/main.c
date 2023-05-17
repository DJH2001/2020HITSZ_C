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

    int score[N],cscore[N];                                   //�����������
    long ID[M],id[M];                                     //����ѧ������
    char Name[N][N],*pname[N],*cname[N];                      //�ַ������� ����
    int average=0,sum=0,menu,ret,count = 0;         //����ƽ�������������˵����ƣ�ret��count
    int n,i;                                          //����ѧ��������Ϊn
     /*��ά������ָ��*/
    for(i=0;i<N;i++)
    {
        pname[i]=Name[i];
    }
    do
    {
        /*���²˵�����*/
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
        ret=scanf("%d",&menu);                             //��¼scanf��ֵ
         //ȷ���û��������ȷ�ԣ�ֻ�е��û������ֵΪ1ʱ���ܽ�����һ��
        while(count==0&&menu>1||ret!=1||menu<0||menu>10)
        {
            while (getchar() != '\n');                     //��ջ�����������
            printf("Error!Please record first!\n");
            ret=scanf("%d",&menu);
            printf("\n");
            continue;
        }

        /**�˵�ѡ��*/
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
            printf("��������رմ���");
            break;

        default :
            break;
        }
        getchar();
        //���������������
        count++;                                        //ֻ�е�menu��һ�����벻����1��ʱ��count�Ż�������count++��Ϊ�˲�ִ��ǰ��whileѭ��
        printf("\n");
    }
    while(menu!=0);                                     //��menu=0��ʱ���˳�����
    system("Pause");
    return 0;
}
/***********************************************************
**��������ReadScore
**ָ�룺pname pn
**���飺ID score
**��������:¼��ÿ��ѧ����ѧ��,�����ͳɼ�
************************************************************/
void ReadScore(char *pname[],int score[],long ID[],int *pn)
{

    int i,ret;
    printf("ѧ��������Ϊ:");
    printf("\n");
    ret=scanf("%d",pn);
    while (getchar() != '\n');
    /*����Ƿ����룬ֻ������*/
    while (*pn <= 0)
    {
        printf("Input error!\nTotal number:");
        while (getchar() != '\n');
        ret = scanf("%d",pn);
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
        ret = scanf("%d",&score[i]);//��ʱret��ֵӦ��Ϊ2
        while (getchar() != '\n');//��ջ�����
        /*����Ƿ��ַ������룬�û�ֻ��һ������������������Ҫע��score��id�ķ�Χ*/
        while (ret != 1||score[i] > 100||score[i] < 0)
        {
            printf("Input error!\n");
            while (getchar() != '\n');
            ret = scanf("%d",&score[i]);
        }
    }
}
/***********************************************************
**��������copy
**ָ�룺panme cname
**���飺ID score id cscore
**������n
**��������:fuzhi
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
**��������printscore
**ָ�룺panme
**���飺ID score
**������n
**��������:���ÿ��ѧ����ѧ��,�����ͳɼ���Ҫ����˳�������
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
**��������total_and_average
**ָ�룺paverage,psum
**���飺ID score
**������n
**��������:����γ��ֺܷ�ƽ����
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

    printf("�ܷ�Ϊ:%d\n",*psum);
    printf("�γ�ƽ����Ϊ:%d\n",*paverage);
}
/***********************************************************
**��������ScoreRank
**ָ�룺pname
**ָ�뺯����choice
**���飺ID score
**��������:���ú�������
************************************************************/
void ScoreRank(char *pname[],int score[],long ID[],int n,int (*choice)(int score1,int score2))
{
    int i,j,k;                                                         //������������
    for (i=0;i<n;i++)
    {
        k=i;
        /*�����ж�*/                                                         //��i��ֵ��ʱ��ֵ��k���൱�ڶ�k���г�ʼ��
        for (j=i+1;j<n;j++)
        {
            if ((*choice)(score[k],score[j]))//if�������� 1Ϊ�棬0Ϊ��
            {
                k=j;
            }
        }
        /*���if�����е�ֵΪ1����j��ֵ��ֵ��k����һ��forѭ�����ҵ������С������һ�����ڶ���forѭ���ҵ��ڶ��󣨵ڶ�С������һ������*/

        /*�����������������*/
        Exchange_score(&score[i],&score[k]);//��ʱi��ֵû�б仯��������һ��forѭ���󣬿��Խ�������
        Exchange(&ID[i],&ID[k]);//ͬ����ѧ��
        Exchangename(pname,i,k);//ͬ��������
    }
}
/**������*/
int Decending(int x,int y)
{
    return x<y;         //��ʱ��result���ص�����ScoreRank��ȥ
}
/**������*/
int Ascending(int x,int y)
{
    return x>y;         //��ʱ��result���ص�����ScoreRank��ȥ
}
/***********************************************************
**��������Exchange
**ָ�룺pa pb
**��������:����
************************************************************/
void Exchange(long *pa,long *pb)
{
    long Temp;//����һ���м����
    Temp = *pa;
    *pa = *pb;
    *pb = Temp;
}
/***********************************************************
**��������Exchange_score
**ָ�룺pa pb
**��������:����
************************************************************/
void Exchange_score(int *pa,int *pb)
{
    int Temp;//����һ���м����
    Temp = *pa;
    *pa = *pb;
    *pb = Temp;
}
/***********************************************************
**��������Exchangename
**ָ�룺pname
**������i j
**��������:�������֣��������ַ���
************************************************************/
void Exchangename(char *pname[],int i,int j)
{
    char *Temp[N];
    Temp[i] = pname[i];
    pname[i] = pname[j];
    pname[j] = Temp[i];
}
/***********************************************************
**��������ascending_by_ID
**ָ�룺pname
**���飺score ID
**������n
**��������:��ѧ����С�����ų��ɼ���
************************************************************/
void ascending_by_ID(char *pname[],int score[],long ID[],int n)
{
    int i,j,k;
    for (i=0;i<n;i++)
    {
        k=i;
        for (j=i+1;j<n;j++)
        {
            if (Ascending(ID[k],ID[j]))//��������˺��������ж�
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
**��������search_by_ID
**ָ�룺pname
**���飺score ID
**������n
**��������:���������ֵ�˳���ų��ɼ���
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
**��������search_by_ID
**ָ�룺pname
**���飺score ID
**������n
**��������:��ѧ�Ų�ѯѧ���������俼�Գɼ�
************************************************************/
void search_by_ID(char *pname[],int score[],long ID[],int n)
{
    int i,count;
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
                printf("��ѧ���ɼ���%d������%d",score[i],i+1);
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
**��������search_by_name
**ָ�룺pname
**���飺score ID
**������n
**��������:��������ѯѧ���������俼�Գɼ�
************************************************************/
void search_by_name(char *pname[],int score[],long ID[],int n)
{
    int i,count=0;
    char stuname[N];
    while(getchar()!='\n');
    printf("������ѧ����������");
    gets(stuname);
    do
    {
        count=0;
        for(i=0;i<n;i++)
        {
            if(strcmp(stuname,pname[i]) == 0)
            {
                printf("��������Ϊ%d,���Գɼ�Ϊ%d\n",i+1,score[i]);
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
**��������static_analys
**���飺score ID
**������n
**��������:�����㣨90-100�����ã�80-89���еȣ�70-79������60-69��
������50-59��������ͳ��ÿ�����������Լ���ռ�ٷֱ�
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
    printf("����������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*a/n);
    printf("����������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*b/n);
    printf("�е�������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*c/n);
    printf("����������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*d/n);
    printf("������������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*e/n);
}
void Print(void)
{
    printf("----------------------------------------------------\n");
}








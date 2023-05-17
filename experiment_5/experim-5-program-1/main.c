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
    int n;//����ѧ��������Ϊn
    do
    {
        /**��ʾ���²˵�����*/
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

        ret=scanf("%d",&menu);                          /**��ֹ�Ƿ��ַ������룬�Ҵ�ʱret=1��ֻ������һ��ֵ*/
        while(count==0&&menu>1||ret!=1||menu<0||menu>8)/**t����ѭ��������*/
        {
            while (getchar() != '\n');
            printf("Error!Please record first!\n");
            ret=scanf("%d",&menu);
            printf("\n");
            continue;
        }
        /**�˵�����������ѡ��*/
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
            printf("��������رմ���");
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
**�������ƣ�ReadScore
**���飺score ID
**ָ�룺pn
**�������ܣ�¼��ÿ��ѧ����ѧ�źͳɼ�
**********************************************/
void ReadScore(int score[],long ID[],int *pn)
{

    int i;
    printf("ѧ��������Ϊ:\n");
    scanf("%d",pn);
    for(i=0; i<*pn; i++)
    {
        printf("Input student's ID and score:");
        scanf("%ld%d",&ID[i],&score[i]);
    }
}
/*********************************************
**�������ƣ�copy
**���飺cscore score id ID
**���� n
**�������ܣ���score ��ID��ֵ���Ƹ���score id
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
**�������ƣ�output
**���飺cscore id
**���� n
**�������ܣ��������˳�����
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
**�������ƣ�printscore
**���飺score ID
**���� n
**�������ܣ����
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
**�������ƣ�total_and_average
**���飺score ID
**ָ�룺paverage psum
**���� n
**�������ܣ�����γ��ֺܷ�ƽ����
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
    printf("�ܷ�Ϊ:%d\n",*psum);
    printf("�γ�ƽ����Ϊ:%d",*paverage);
}
/*********************************************
**�������ƣ�decending
**���飺score ID
**���� n
**�������ܣ����ɼ��ɸߵ����ų����α�
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
                /*��������*/
                temp1=score[i];
                score[i]=score[j];
                score[j]=temp1;
                /*����ѧ��*/
                temp2=ID[j];
                ID[j]=ID[i];
                ID[i]=temp2;
            }
        }
    }
}
/*********************************************
**�������ƣ�ascending
**���飺score ID
**���� n
**�������ܣ����ɼ��ɵ͵����ų����α�
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
**�������ƣ�ascendingID
**���飺score ID
**���� n
**�������ܣ���ѧ����С�����ų��ɼ���
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
**�������ƣ�search
**���飺score ID
**���� n
**�������ܣ�����ѧ�Ų���ѧ���ɼ�������
**********************************************/
void search(int score[],long ID[],int n)
{
    int i,j,temp1,count;
    long x,temp2;
    /**�Ƚ�������*/
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
        if (count == 0)
        {
            printf("Input error!");
        }
    }while(count == 0);

}
/*********************************************
**�������ƣ�static_analysish
**���飺score ID
**���� n
**�������ܣ������㣨90-100�����ã�80-89���еȣ�70-79������60-69��
������50-59��������ͳ��ÿ�����������Լ���ռ�ٷֱ�
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
    printf("����������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*a/n);
    printf("����������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*b/n);
    printf("�е�������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*c/n);
    printf("����������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*d/n);
    printf("������������ս�ٷֱ�Ϊ:%.2f%%\n",100.0*e/n);
}

void Put(void)
{
    printf("*********************************************************\n");
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void right();//��ȷ�Ļش���
void wrong();//����Ļش�ĺ���

int main()
{
    printf("Number:200110807\n");
    printf("subject No.4-program No.2\n\n\n");

    int i,j,a,sum,t;
    int counter=0;
    int score=0;
    int n=0;
    srand((unsigned)time(NULL));//���������
    do
    {
        score=0;
        do
        {
            i=rand()%10+1;
            j=rand()%10+1;
            //����1-10�������

            t=rand()%4+1;
            //������������ķ���

            counter++;//������+1
            if(t==1)
            {
                do
                {
                    n++;
                    sum=i+j;
                    printf("%d+%d=?\n",i,j);
                    scanf("%d",&a);
                    if(fabs(sum-a)<1e-6)//�ж�ʵ��ֵ���û��������ֵ�Ƿ����
                    {
                        score++;//�÷�+1
                        right();//����right����
                    }
                    else
                    {
                        wrong();//����wrong����
                    }
                }
                while(n<1);//����һ�ν���ѭ��
            }
            //��t�������Ϊ1ʱ�򣬼���ӷ�
            if(t==2)
            {
                do
                {
                    n++;
                    sum=i-j;
                    printf("%d-%d=?\n",i,j);
                    scanf("%d",&a);
                    if(fabs(sum-a)<1e-6)//�ж�ʵ��ֵ���û��������ֵ�Ƿ����
                    {
                        score++;//����+1
                        right();//����right����
                    }
                    else
                    {
                        wrong();//����wrong����
                    }
                }
                while(n<1);
            }
            //��t=2��ʱ��������
            if(t==3)
            {
                do
                {
                    n++;
                    sum=i*j;
                    printf("%d*%d=?\n",i,j);
                    scanf("%d",&a);
                    if(fabs(sum-a)<1e-6)//�ж�ʵ��ֵ���û��������ֵ�Ƿ����
                    {
                        score++;
                        right();//����right����
                    }
                    else
                    {
                        wrong();//����wrong����
                    }
                }
                while(n<1);
            }
            //��t=3��ʱ�����˷�
            if(t==4)
            {
                do
                {
                    n++;
                    sum=1.0*i/j;
                    printf("%d/%d=?\n",i,j);
                    scanf("%d",&a);
                    if(fabs(sum-a)<1e-6)//�ж�ʵ��ֵ���û��������ֵ�Ƿ����
                    {
                        score++;
                        right();//����right����
                    }
                    else
                    {
                        wrong();//����wrong����
                    }
                }
                while(n<1);//ֻ�������һ��
            }
            //��t=4��ʱ��������
        }
        while(counter<10);//ѭ��������������=10
        printf("\n");
        printf("ִ�д���%d\n",counter);
        printf("��ķ�����%d\n",score);
        if(score>=8)//�ж��û��÷����
        {
            printf("Your have passed this test!\n");
            counter=11;
        }
        else
        {
            printf("No!You have to the next test!\n");
            counter=0;
        }
    }
    while(counter<10);
    //ֻ�е��û��÷�������ڵ���8��ʱ�򣬲��ܽ�����Ŀ��ѵ��
    system("Pause");
    return 0;
}
/****************************************************
**�������ƣ�right
**�������ܣ���Сѧ���ش���ȷ��ʱ�򣬸�����ͬ�龰�Ĵ�
****************************************************/
void right()
{
    int b;
    switch(b=rand()%3+1)
    {
    case 1:
    {
        printf("Well done!\n");
        break;
    }

    case 2:
    {
        printf("Excellent!\n");
        break;
    }

    case 3:
    {
        printf("Good job!\n");
        break;
    }

    }
}
/****************************************************
**�������ƣ�wrong
**�������ܣ���Сѧ���ش�����ʱ�򣬸�����ͬ�龰�Ĵ�
****************************************************/
void wrong()
{
    int b;
    switch(b=rand()%3+1)
    {
    case 1:
    {
        printf("Keep trying!\n");
        break;
    }

    case 2:
    {
        printf("Be careful!\n");
        break;
    }

    case 3:
    {
        printf("Don't give up!\n");
        break;
    }

    }
}

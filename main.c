#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <windows.h>
int size=0;
char player[20];

void color(const unsigned short color1)
{
    if(color1>=0&&color1<=15)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

    int q=0;
    int x,y,xx,yy,t=0,l=0,ll=0,jj=0,kk=0,h=0,hh=0;
    /*qΪ��ʼ�˵���ѡ�����*/
    /*x��yΪС�������*/
    /*xx��yyΪС��������*/
    /*tΪ������֮��*/
    /*l��llΪ��ɫ��Ӧ��λ�ò���*/
    /*jj��kkΪ��ɫ��ʵ��λ�ò���*/
    /*h��hhΪ��ɫ�ߵĵĴ���*/
    int moneyA=20000;
    int moneyB=20000;
    char c;
    char d[10]={"��Ϸ������"};
    struct millionaire
    {
        char name[6];
        int rent;
        int belong;
    }b[30]={
        "�й�",30000,6,
        "����˹",28000,0,
        "�ձ�",20000,0,
        "����",10000,0,
        "������",22000,0,
        "����",15000,0,
        "�Ϸ�",14000,0,
        "��ʿ",12000,0,
        "�¹�",20000,0,
        "������",30000,3,
        "����",10000,0,
        "����",25000,0,
        "Ӣ��",25000,0,
        "����",30000,4,
        "����",10000,0,
        "ͣ����",30000,5,
        "����",25000,0,
        "�Ű�",10000,0,
        "���ô�",35000,0,
        "����",10000,0,
        "�ϼ���",5000,0,
        "������",11000,0,
        "������",30000,3,
        "����",20000,0,
        "������",10000,0,
        "�ɹ�",16000,0,
        "�¼���",30000,0,
        "����",9000,0,
        "����",30000,4,
        "ӡ��",11000,0
    };
    char a[22][100]={
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
    "0000000000111111111111111111111111111111111111111111111111111111111111111111111111111111111111100000",
    "0000000000100000020000002000000200000020000002000000200000020000002000000200000020000002000000100000",
    "0000000000100000020000002000000200000020000002000000200000020000002000000200000020000002000000100000",
    "00000000001�¼���20�ɹ�02������20����02������2������2�ϼ���20����02���ô�20�Ű�020����02ͣ����100000",
    "0000000000122222211111111111111111111111111111111111111111111111111111111111111111111111222222100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "000000000010����0100000000000000000000000000000000000000000000000000000000000000000000010����0100000",
    "0000000000122222210000000000000000000000000000000000000000000000000000000000000000000001222222100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "00000000001000000100000000000000000000000000000��������0000000000000000000000000000001000000100000",
    "000000000010����010000000000000000000000000000���������硷0000000000000000000000000000010����0100000",
    "0000000000122222210000000000000000000000000000000000000000000000000000000000000000000001222222100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "000000000010ӡ��0100000000000000000000000000000000000000000000000000000000000000000000010Ӣ��0100000",
    "0000000000122222211111111111111111111111111111111111111111111111111111111111111111111111222222100000",
    "0000000000100000020000002000000200000020000002000000200000020000002000000200000020000002000000100000",
    "0000000000100000020000002000000200000020000002000000200000020000002000000200000020000002000000100000",
    "000000000010�й�02����˹20�ձ�020����02������20����020�Ϸ�020��ʿ020�¹�02������20����020����0100000",
    "0000000000111111111111111111111111111111111111111111111111111111111111111111111111111111111111100000",
    };



struct user
{
    char password[30];
    char name[20];
    int times;
    struct user *next;
};

struct suser
{
    char password[30];
    char name[20];
    int times;
}statics[];


void screen()
{
        int i,j,r;
        char p,temp1,temp2;
        //printf("l=%d,ll=%d,jj=%d,kk=%d",l,ll,jj,kk);
        //printf("x=%d,y=%d,",x,y);printf("xx=%d,yy=%d\n",xx,yy);
        printf("���ã�%s\n",player);


        for(i=0;i<22;i++)  //�Ѷ�ά����ת��Ϊͼ����ʾ
        {
            for(j=0;j<100;j++)
            {
                if(j==x&&i==y)
                {
                    temp1=a[i][j];
                    a[i][j]='3';
                }
                if(j==xx&&i==yy)
                {
                    temp2=a[i][j];
                    a[i][j]='4';
                }
                p=a[i][j];
                switch(p)
                {
                    case '0':printf(" ");break;
                    case '1':color(2);printf("H");color(16);break;
                    case '2':color(2);printf("\"");color(16);break;
                    case '3':color(12); printf("\b\b\bС��");color(16);  break;
                    case '4':color(9); printf("\b\b\bС��");color(16);break;
                    default:color(15);printf("%c",a[i][j]);color(16);break;
                }
                if(j==x&&i==y)
                {
                    a[i][j]=temp1;
                }
                if(j==xx&&i==yy)
                {
                    a[i][j]=temp2;
                }
            }
            printf("\n");

        }
        color(6);
        printf("          �ʲ�  С��:%d   С��",moneyA);//��ʾ��ɫ����
        if(q==1){printf("�����ԣ�");}
        printf(":%d\n          ����",moneyB);
        j=0;
        printf("  С��:");
        for(i=0;i<30;i++)
        {
            if(b[i].belong==1)
            {for(j=0;j<6;j++)
            {
                printf("%c",b[i].name[j]);

            }printf("%d ",b[i].rent);
            }
        }
        if(j==0)printf("�޷���   ");
        j=0;
        printf("\n                С��");
        if(q==1){printf("�����ԣ�");}
        printf(":");
        for(i=0;i<30;i++)
        {
            if(b[i].belong==2)
            {for(j=0;j<6;j++)
            {
                printf("%c",b[i].name[j]);

            }printf("%d ",b[i].rent);
            }
        }
        if(j==0)printf("�޷���   ");
        printf("\n");
        color(16);
        //printf("\nh=%d,hh=%d\n",h,hh);
        if(h>0&&t%2==0&&b[jj].belong==6)
            {
                moneyA+=10000;
                printf("\n          С���������Ȧ������10000Ԫ��\n          ");
                h=-1;
                system("pause");
                system("cls");screen();
            }
        else if(hh>0&&t%2==1&&b[kk].belong==6)
            {
                moneyB+=10000;
                hh=-1;
                printf("\n          С����������Ȧ������10000Ԫ��\n          ");system("pause");
                system("cls");screen();
            }

}

void start()
{
    int i,j,r;

    while(1)
    {
        screen();
        printf("          �����ֵ���");

        if(t%2==0)
        {
            printf("С��\n          ");
            r=dice();
            delay();delay();delay();delay();delay();delay();delay();delay();delay();
            system("pause");
        }
        else
        {
            printf("С��\n");
            if(q==2){r=dice();printf("          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();system("pause");}
            else{r=dice();delay();delay();}
        }

        printf("          �������ˣ�%d\n",r);
        delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();
        color(16);
        system("cls");
        go(r);


        r=dice();

        t++;
    }
}

void purchase()
{
    int j;

    char get;
    if(t%2==0)
        {
            h++;
            printf("          С�쵽��");
            puts(b[jj].name);
            if(b[jj].belong==0||b[jj].belong==6)
            {
                delay();
                printf("          �˵���δ����\n");
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          ��������%dԪ�ʲ�\n",moneyA);
                printf("          ��ǰ���ڵ�%s�ؼ�Ϊ%dԪ",b[jj].name,b[jj].rent);
                if(moneyA>=b[jj].rent)
                {
                    delay();delay();delay();delay();delay();delay();delay();delay();delay();
                    printf("\n          �Ƿ���<y/n>");
                    while(1)
                    {
                            get=getch();
                            if(get=='`')over(1);//���Խ���������
                            if (get=='y'||get=='n')break;
                    }

                    if (get=='y')
                    {
                        b[jj].belong=1;
                        moneyA=moneyA-b[jj].rent;
                        delay();
                        printf("\n          ����ɹ�����֧��%dԪ������",b[jj].rent);
                        for(j=0;j<6;j++){printf("%c",b[jj].name[j]);}
                        printf("������%dԪ�ʲ�\n          ",moneyA);delay();delay();delay();delay();delay();delay();delay();delay();delay();
                        system("pause");
                    }
                    else if (get=='n'){}
                }
                else
                {
                    printf("���޷�����\n          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();system("pause");
                }
            }
            else if(b[jj].belong==1)
            {
                printf("          ��ϲ���ص��Լ������µĵ���:)\n          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();
                system("pause");
            }
            else if(b[jj].belong==2)
            {
                printf("          �ܱ�Ǹ��������С�������µĵ��̣���Ҫ֧��%s�ؼ۵�һ��%dԪ��Ϊ��·��\n",b[jj].name,b[jj].rent/2);
                moneyA=moneyA-b[jj].rent/2;
                moneyB=moneyB+b[jj].rent/2;
                delay();delay();delay();delay();delay();delay();delay();delay();delay();printf("          ");system("pause");
                printf("          ��������%dԪ�ʲ�\n",moneyA);
                tips();
            }
            else if(b[jj].belong==3)//���˴�����
            {
                if(jj==9)
                {
                    delay();delay();delay();delay();delay();delay();
                    jj=22;
                    l=l+13;
                    location1(jj);
                    screen();
                    return;
                }
                if(jj==22)
                {
                    delay();delay();delay();delay();delay();delay();
                    jj=9;
                    l=l-13;
                    location1(jj);
                    screen();
                    return;
                }
            }
            else if(b[jj].belong==4)//��ȡ������
            {
                delay();delay();delay();delay();delay();delay();printf("          ");system("pause");fate();
            }
            else if(b[jj].belong==5)//����ͣ����
            {
                printf("          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();
                system("pause");
                return;
            }

        }
        else
        {
            hh++;
            printf("          С������");
            puts(b[kk].name);
            if(b[kk].belong==0)
            {
                delay();
                printf("          �˵���δ����\n");
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          ��������%dԪ�ʲ�\n",moneyB);
                printf("          ��ǰ���ڵ�%s�ؼ�Ϊ%dԪ",b[kk].name,b[kk].rent);
                if(moneyB>=b[kk].rent)
                {
                    delay();delay();delay();delay();delay();delay();delay();delay();delay();
                    printf("\n          �Ƿ���<y/n>");
                    while(1)
                    {

                            if(q==2){get=getch();}
                            else if(q==1&&moneyB>0){get='y';delay();delay();delay();delay();delay();printf("  С��������");}
                            if (get=='y'||get=='n')break;
                    }

                    if (get=='y')
                    {
                        b[kk].belong=2;
                        moneyB=moneyB-b[kk].rent;
                        delay();delay();delay();delay();delay();delay();delay();delay();delay();
                        printf("\n          ����ɹ�����֧��%dԪ������",b[kk].rent);
                        for(j=0;j<6;j++){printf("%c",b[kk].name[j]);}
                        printf("������%dԪ�ʲ�\n          ",moneyB);delay();delay();delay();delay();delay();delay();delay();delay();delay();
                        system("pause");
                    }
                    else if (get=='n'){}
                }
                else
                {
                    printf("���޷�����\n          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();system("pause");
                }
            }
            else if(b[kk].belong==2)
            {
                printf("          ��ϲ���ص��Լ������µĵ���:)\n          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();
                system("pause");
            }
            else if(b[kk].belong==1)
            {
                printf("          �ܱ�Ǹ��������С�칺���µĵ��̣���Ҫ֧��%s�ؼ۵�һ��%dԪ��Ϊ��·��\n",b[kk].name,b[kk].rent/2);
                moneyB=moneyB-b[kk].rent/2;
                moneyA=moneyA+b[kk].rent/2;
                delay();delay();delay();delay();delay();delay();delay();delay();delay();printf("          ");system("pause");
                printf("          ��������%dԪ�ʲ�\n",moneyB);
                tips();
            }
            else if(b[kk].belong==3)
            {
                if(kk==9)
                {
                    delay();delay();delay();delay();delay();delay();
                    kk=22;
                    ll=ll+13;
                    location2(kk);
                    screen();
                    return;
                }
                if(kk==22)
                {
                    delay();delay();delay();delay();delay();delay();
                    kk=9;
                    ll=ll-13;
                    location2(kk);
                    screen();
                    return;
                }
            }
            else if(b[kk].belong==4)
            {
                delay();delay();delay();delay();delay();delay();printf("          ");system("pause");fate();
            }
            else if(b[kk].belong==5)
            {
                printf("          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();
                system("pause");
                return;
            }
        }
}

void go(int r)//ǰ������
{
    int i;
    if(t%2==0)
    {
        l=l+r;
        go1(l,r);//����С��
    }
    else
    {
        ll=ll+r;
        go2(ll,r);//����С��
    }
}

void go1(int l,int r)
{
    int i;

        for(i=0;i<r;i++)
        {
            jj++;
            if(jj==30)//jj:С���λ��
            {
                jj=0;
                r=l%30+1;
                i=0;//r:С��Ĳ���
                location1(jj);
                system("cls");
                screen();
                delay();
                continue;
            }
            location1(jj);
            system("cls");
            screen();

            delay();
            if(i<r-1)system("cls");
        }
        purchase();
        system("cls");
}

void go2(int ll,int r)
{
    int i;

        for(i=0;i<r;i++)
        {
            kk++;
            if(kk==30)
            {
                kk=0;
                r=ll%30+1;
                i=0;
                location2(kk);
                system("cls");
                screen();
                delay();
                continue;
            }
            location2(kk);
            system("cls");
            screen();

            delay();
            if(i<r-1)system("cls");
        }
        purchase();
        system("cls");
}

void tips()
{
    if(t%2==0)
    {
        if(moneyA<0&&moneyA>=-20000)
            {
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          С�죬����Ƿծ��Ƿծ����20000���Ʋ�\n          ");
                system("pause");
            }
        else if(moneyA<-20000)
            {
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          С��������%dԪ�ʲ������Ʋ�\n",moneyA);
                over(1);
            }
    }
    else
    {
        if(moneyB<0&&moneyB>=-20000)
            {
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          С��������Ƿծ��Ƿծ����20000���Ʋ�\n          ");
                system("pause");
            }
        else if(moneyB<-20000)
            {
                printf("          С��������%dԪ�ʲ������Ʋ�\n",moneyB);
                over(2);
            }
    }
}

void location1(int l) //С�������
{
    switch(l)
    {
        case 0: 	x=15;	y=18;	break;
        case 1: 	x=22;	y=18;	break;
        case 2: 	x=29;	y=18;	break;
        case 3:	    x=36;	y=18;	break;
        case 4:	    x=43;	y=18;	break;
        case 5:	    x=50;	y=18;	break;
        case 6:	    x=57;	y=18;	break;
        case 7: 	x=64;	y=18;	break;
        case 8: 	x=71;	y=18;	break;
        case 9:	    x=78;	y=18;	break;
        case 10:	x=85;	y=18;	break;
        case 11:	x=92;	y=18;	break;
        case 12:	x=92;	y=14;	break;
        case 13:	x=92;	y=10;	break;
        case 14:	x=92;	y=6;	break;
        case 15:	x=92;	y=2;	break;
        case 16:	x=85;	y=2;	break;
        case 17:	x=78;	y=2;	break;
        case 18:	x=71;	y=2;	break;
        case 19:	x=64;	y=2;	break;
        case 20:	x=57;	y=2;	break;
        case 21:	x=50;	y=2;	break;
        case 22:	x=43;	y=2;	break;
        case 23:	x=36;	y=2;	break;
        case 24:	x=29;	y=2;	break;
        case 25:	x=22;	y=2;	break;
        case 26:	x=15;	y=2;	break;
        case 27:	x=15;	y=6;	break;
        case 28:	x=15;	y=10;	break;
        case 29:	x=15;	y=14;	break;
        case 30:	x=15;	y=18;	break;
    }
}

void location2(int ll) //С��������
{
    switch(ll)
    {
        case 0: 	xx=15;	yy=18;	break;
        case 1: 	xx=22;	yy=18;	break;
        case 2: 	xx=29;	yy=18;	break;
        case 3:	    xx=36;	yy=18;	break;
        case 4:	    xx=43;	yy=18;	break;
        case 5:	    xx=50;	yy=18;	break;
        case 6:	    xx=57;	yy=18;	break;
        case 7: 	xx=64;	yy=18;	break;
        case 8: 	xx=71;	yy=18;	break;
        case 9:	    xx=78;	yy=18;	break;
        case 10:	xx=85;	yy=18;	break;
        case 11:	xx=92;	yy=18;	break;
        case 12:	xx=92;	yy=14;	break;
        case 13:	xx=92;	yy=10;	break;
        case 14:	xx=92;	yy=6;	break;
        case 15:	xx=92;	yy=2;	break;
        case 16:	xx=85;	yy=2;	break;
        case 17:	xx=78;	yy=2;	break;
        case 18:	xx=71;	yy=2;	break;
        case 19:	xx=64;	yy=2;	break;
        case 20:	xx=57;	yy=2;	break;
        case 21:	xx=50;	yy=2;	break;
        case 22:	xx=43;	yy=2;	break;
        case 23:	xx=36;	yy=2;	break;
        case 24:	xx=29;	yy=2;	break;
        case 25:	xx=22;	yy=2;	break;
        case 26:	xx=15;	yy=2;	break;
        case 27:	xx=15;	yy=6;	break;
        case 28:	xx=15;	yy=10;	break;
        case 29:	xx=15;	yy=14;	break;
        case 30:	xx=15;	yy=18;	break;
    }
    yy++;
}

int random()//����
{
    int r=0;
    srand((unsigned)time(0));
    r=rand() % 6 + 1;
    return r;
}

int random2()//��ȡ������
{
    int r=0;
    srand((unsigned)time(NULL));
    r=rand() % 8 + 1;
    return r;
}

void fate()
{

    int r=random2();
    int s;
    int i;
    while(1)
    {
        switch(r)
        {
            case 1:printf("          ���˺��£�����10000Ԫ������\n          ");
                    system("pause");
                    if(t%2==0){moneyA+=10000;printf("          ��������%dԪ�ʲ�\n",moneyA);}
                    else{moneyB+=10000;printf("          ��������%dԪ�ʲ�\n",moneyB);}
                    break;
            case 2:printf("          ϷŪС���ѣ���ʧ8000Ԫ\n          ");
                    system("pause");
                    if(t%2==0){moneyA-=8000;printf("          ��������%dԪ�ʲ�\n",moneyA);}
                    else{moneyB-=8000;printf("          ��������%dԪ�ʲ�\n",moneyB);}
                    tips();
                    break;
            case 3:printf("          ��Ϣ����Ϣһ��\n          ");
                    system("pause");
                    return;
                    break;
            case 4:printf("          ǰ���������˻�%d��\n          ",s=random());
                    system("pause");
                    if(t%2==0){jj-=s;l-=s;location1(jj);screen();}
                    else{kk-=s;ll-=s;location2(kk);screen();}
                    break;
            case 5:printf("          ��ϲ���������еķ�������20\%\n          ");
                    system("pause");
                    if(t%2==0)
                    {
                        for(i=0;i<30;i++)
                        {
                            if(b[i].belong==1){b[i].rent*=1.2;}
                        }
                    }
                    else
                    {
                        for(i=0;i<30;i++)
                        {
                            if(b[i].belong==2){b[i].rent*=1.2;}
                        }
                    }
                    break;
            case 6:if(t%2==0&&0>moneyA&&moneyA>-10000)
                    {
                            printf("          �ʽ�������ɸ�ת��\n          ");
                            system("pause");
                            moneyA*=-1;
                            printf("          ��������%dԪ�ʲ�\n",moneyA);
                    }
                    else if(t%2==1&&0>moneyB&&moneyB>-10000)
                    {
                            printf("          �ʽ�������ɸ�ת��\n          ");
                            system("pause");
                            moneyB*=-1;
                            printf("          ��������%dԪ�ʲ�\n",moneyB);
                    }
                    else
                    {
                        r=random();continue;
                    }
                    break;
            case 7:if(t%2==0&&moneyA<-5000)
                    {
                            printf("          ��̫���ˣ�ѩ����̿��ϵͳ����8000Ԫ\n          ");
                            system("pause");
                            moneyA+=8000;
                            printf("          ��������%dԪ�ʲ�\n",moneyA);
                    }
                    else if(t%2==1&&moneyB<-5000)
                    {
                            printf("          ��̫���ˣ�ѩ����̿��ϵͳ����8000Ԫ\n          ");
                            system("pause");
                            moneyB+=8000;
                            printf("          ��������%dԪ�ʲ�\n",moneyB);
                    }
                    else
                    {
                        r=random();continue;
                    }
                    break;
            case 8:if(t%2==0&&moneyA>10000)
                    {
                            printf("          ����20\�����ֽ�������\n          ");
                            system("pause");
                            moneyA*=0.8;
                            printf("          ��������%dԪ�ʲ�\n",moneyA);
                    }
                    else if(t%2==1&&moneyB>10000)
                    {
                            printf("          ����20\�����ֽ�������\n          ");
                            system("pause");
                            moneyB*=0.8;
                            printf("          ��������%dԪ�ʲ�\n",moneyB);
                    }
                    else
                    {
                        r=random();continue;
                    }
                    break;
        }break;
    }
}

int dice()
{
    int r,i;
    char temp[100];
    r=random();
    return r;
}

int over(int x)
{
	char get;
	int i;
	printf("\n          ��Ϸ������ ");
    system("pause");
    system("cls");
    screen2(14);
    if(x==1)
    {
        printf("\n\n\n                      ʤ���Ѿ����˾�С���Ǵ��̣�С������ʲ���%d��С�������ʲ���%d",moneyA,moneyB);
    }
    if(x==2)
    {
        printf("\n\n\n                      ʤ���Ѿ����˾�С���Ǵ��̣�С������ʲ���%d��С������ʲ���%d",moneyB,moneyA);
    }


        FILE *fp;//��ȡ�������
        if((fp=fopen("users.txt","r"))==NULL)
        {   puts("                      δ�ܴ��ļ�");exit(1);}
        for(i=0;i<size;i++)
         {
             fscanf(fp,"%s %s %d\n",&statics[i].name,&statics[i].password,&statics[i].times);
             if(strcmp(statics[i].name,player)==0)
             {
                 statics[i].times+=1;
                 printf("\n\n                      �װ���%s����������%d����ô�����Ϸ����������:)\n",statics[i].name,statics[i].times);
             }
         }
        fclose(fp);
        FILE *fp2;//�����������
        if((fp2=fopen("users.txt","w"))==NULL)
        {   puts("                      δ�ܴ��ļ�");exit(1);}
         for(i=0;i<size;i++)
         {
             fprintf(fp2,"%s %s %d\n",statics[i].name,statics[i].password,statics[i].times);
         }
        fclose(fp2);


                printf("\n\n                      ����һ�֣�<y/n>");
                while(1)
                {
                        get=getch();
                        if (get=='y'||get=='n')break;
                }



                if (get=='y')
                {
                    system("cls");main();
                }
                else
                {
                    exit(0);
                }
				return 0;
}


int delay()
{
    int i,j;
    for(i=0;i<30000;i++)
    for(j=0;j<1000;j++);
	return 0;
}

//��ӭ����
char w[22][100]={
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
    "0000000000000000111111111111111111111111111111111111111111111111111111111111111111111111100000",
    "0000000000000000100000000000000000000000000000000000000000000000000000000000000000000000100000",
    "0000000000000000100000000000000000000000000000000000000000000000000000000000000000000000100000",
    "0000000000000000100000000000000000000000000000000000000000000000000000000000000000000000100000",
    "0000000000000000100000222222222222222222222222222222222222222222222222222222222222200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "000000000000000010000020000000000000000000000000��������000000000000000000000000200000100000",
    "00000000000000001000002000000000000000000000000���������硷00000000000000000000000200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "0000000000000000100000200000000000000000000000000000000000000000000000000000000000200000100000",
    "0000000000000000100000222222222222222222222222222222222222222222222222222222222222200000100000",
    "0000000000000000100000000000000000000000000000000000000000000000000000000000000000000000100000",
    "0000000000000000100000000000000000000000000000000000000000000000000000000000000000000000100000",
    "0000000000000000100000000000000000000000000000000000000000000000000000000000000000000000100000",
    "0000000000000000111111111111111111111111111111111111111111111111111111111111111111111111100000",
    };

int screen2(int x)//��ʾ��ӭ����
{
    int i,j;
    for(i=0;i<19;i++)
        {
            for(j=0;j<100;j++)
            {
                switch(w[i][j])
                {
                    case '0':printf(" ");break;
                    case '1':printf(" ");break;//color(10);printf("H");color(16);break;
                    case '2':color(x);printf("$");color(16);break;
                    case '3':printf(" ");break;
                    case '4':printf(" ");break;
                    default:color(15);printf("%c",w[i][j]);color(16);break;
                }
            }
            printf("\n");
            }
	return 0;
}


int enroll(int n)
{
    system("cls");
    screen2(13);
    printf("                      ע�����\n");
    int i=0;
    struct user *head,*p,*q;
    while(i<n)
    {
        FILE *fp1;//��ȡ�������
        if((fp1=fopen("size.txt","r"))==NULL)
        {   puts("                      δ�ܴ��ļ�");   exit(1) ;   }
        fscanf(fp1,"%d",&size);
        fclose(fp1);

        p=(struct user*)malloc(sizeof(struct user));
        if(i==0)
        {head=p;q=p;}

        printf("\n                      �ǳ�:");
        gets(p->name);

        FILE *fp3;                                   //���û��ļ�
        char ch;
        char *filename2="users.txt";
        if((fp3=fopen(filename2,"r"))==NULL)
         {    printf("                      δ�ܴ��ļ�\n");
          return;
         }

         for(i=0;i<size;i++)
         {
             fscanf(fp3,"%s %d %d\n",&statics[i].name,&statics[i].password,&statics[i].times);
         }
         fclose(fp3);
         for(i=0;i<size;i++)
         {
            if(strcmp(p->name,statics[i].name)==0)
            {
                printf("\n                      ������ͬ���\n\n                      ");
                free(p);
                system("pause");
                int k;
                return 0;
            }
         }

        printf("\n                      ����:");
        gets(p->password);

        p->next=NULL;
        if(i!=0)
         {q->next=p;q=p;}
        i++;

        FILE *fp;//��������
        if((fp=fopen("users.txt","a"))==NULL)
        {   puts("                      δ�ܴ��ļ�");   exit(1) ;   }
        fprintf(fp,"%s %s 0 \n",p->name,p->password);
        fclose(fp);

        FILE *fp2;//���������һ
        if((fp2=fopen("size.txt","w"))==NULL)
        {   puts("                      δ�ܴ��ļ�");   exit(1) ;   }
        size=size+1;
        fprintf(fp2,"%d",size);
        fclose(fp2);

        printf("\n                      ע��ɹ���\n\n                      ");
        system("pause");
        system("cls");

    }
    return 1;
}

int login()
{

    char get1[20],get2[30];
    int i,j,k;
    system("cls");
    screen2(12);
    printf("                      ��¼����\n");
    printf("\n                      �ǳƣ�");
    gets(get1);

    FILE *fp1;                                 //��size�ļ�
    char *filename1="size.txt";
    if((fp1=fopen(filename1,"r"))==NULL)
     {    printf("                      δ�ܴ��ļ�\n");
	  return;
     }

    fscanf(fp1,"%d",&size);
    fclose(fp1);

    FILE *fp;                                   //���û��ļ�
    char *filename2="users.txt";
    if((fp=fopen(filename2,"r"))==NULL)
     {    printf("                      δ�ܴ��ļ�\n");
	  return;
     }

     for(i=0;i<size;i++)
     {
         fscanf(fp,"%s %s %d\n",&statics[i].name,&statics[i].password,&statics[i].times);
         if(strcmp(get1,statics[i].name)==0){break;}
     }
     fclose(fp);
     if(i==size)
     {
         printf("\n                      û�и������Ϣ\n\n                      ");
         system("pause");
         for(k=10;k<15;k++)
        {
            system("cls");
            screen2(k);
        }
        welcome();
     }

    printf("\n                      ���룺");
    gets(get2);
    if(strcmp(get2,statics[i].password)==0)
    {
        printf("\n                      ��¼�ɹ���\n\n                      ");strcpy(player,get1);system("pause");return 1;
    }
    else
    {
        printf("\n                      �ǳƻ��������\n\n                      ");system("pause");system("cls");
        for(k=10;k<15;k++)
        {
            system("cls");
            screen2(k);
        }
        return 0;
    }
}

void welcome()
{
    int k;
    while(1)
    {
        switch(welcome1())
        {
            case '1':k=login();break;
            case '2':enroll(1);k=0;

                    for(k=10;k<15;k++)
                    {
                        system("cls");
                        screen2(k);
                    }break;

            case '3':strcpy(player,"���������ο����");k=1;break;
        }
        if(k==1)break;
    }
    system("cls");
    q=welcome2();
}

int welcome1()
{
	char get;
    int i,j;
    printf("                      (1)������¼  (2)����ע��  (3)�οͽ���");
    delay();delay();delay();delay();delay();delay();delay();delay();delay();

                printf("\n\n                      ��ѡ��  <1/2/3>");
                while(1)
                {
                        get=getch();
                        if (get=='1'||get=='2'||get=='3')break;
                }
    return get;
}

int welcome2()
{
	char get;
    int i,j,k;
    screen2(10);
    printf("                      (1)������Ϸ  (2)˫����Ϸ  (3)��Ϸ˵��");

                printf("\n\n                      ��ѡ��  <1/2/3>");
                while(1)
                {
                        get=getch();
                        if (get=='1'||get=='2'||get=='3')break;
                }
                if (get=='1')
                {
                    printf("     ");
                    for(i=0;i<10;i++)
                    {
                        printf("%c",d[i]);
                        delay();
                    }
                    delay();delay();
                    system("cls");
                    return 1;
                }
                else if (get=='2')
                {
                    printf("\t\t ");
                    for(i=0;i<10;i++)
                    {
                        printf("%c",d[i]);
                        delay();
                    }
                    delay();delay();
                    system("cls");
                    return 2;
                }
                else if (get=='3')
                {
                    system("cls");
                    printf("\n\n\n     ��������  ��Ϸ˵����");delay();delay();delay();delay();delay();delay();delay();
                    printf("\n\n          ��Ϸ���н�ɫС���С���໥��ƴ��С���С������ӵ��һ���������ʲ����ڹ��򷿲���");delay();delay();
                    printf("\n\n          ��ĳ�ط��������򣬶���·���˵�ʱ������ɷ��������һ����Ϊ��·�Ѹ�����ӵ��һ����");delay();delay();
                    printf("\n\n          ��ɫÿ����һȦ��������10000Ԫ�Ľ�����");delay();delay();
                    printf("\n\n          �ֽ��ʲ�����-20000ʱ���ý�ɫ���Ʋ�����Ϸ��������һ����ʤ��");delay();delay();
                    printf("\n\n          ·�������ˡ�ʱ����ɫ�ɳ�ȡ�����ƣ���ȡ�Ľ�����ܶ��Լ�������Ҳ���ܶ��Լ�������");delay();delay();
                    printf("\n\n          ·���������š�ʱ����ɫ��ͨ�������Ŵ��͵���һ����Ӧ�ص㣬����¼��ɸ�Ȧ�����档");delay();delay();
                    printf("\n\n          �ڿ�ʼ�˵��п���ѡ������Ϸ��˫����Ϸ���ڵ�����Ϸ�У����Ϊ��ɫС�죬����Ϊ��ɫС����");delay();delay();
                    printf("\n\n          ����Ϸ�����ͽ���ȨΪ�ͬѧ���С�");delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();

                    printf("\n\n     ��Ҫ�������˵���");system("pause");
                    main();
                }
}



int main()
{
	struct millionaire c[30]={//���ݳ�ʼ��
        "�й�",30000,6,
        "����˹",28000,0,
        "�ձ�",20000,0,
        "����",10000,0,
        "������",22000,0,
        "����",15000,0,
        "�Ϸ�",14000,0,
        "��ʿ",12000,0,
        "�¹�",20000,0,
        "������",30000,3,
        "����",10000,0,
        "����",25000,0,
        "Ӣ��",25000,0,
        "����",30000,4,
        "����",10000,0,
        "ͣ����",30000,5,
        "����",25000,0,
        "�Ű�",10000,0,
        "���ô�",35000,0,
        "����",10000,0,
        "�ϼ���",5000,0,
        "������",11000,0,
        "������",30000,3,
        "����",20000,0,
        "������",10000,0,
        "�ɹ�",16000,0,
        "�¼���",30000,0,
        "����",9000,0,
        "����",30000,4,
        "ӡ��",11000,0
    };
    int i;
    for(i=0;i<30;i++)
    {
        strcpy(b[i].name,c[i].name);
        b[i].rent=c[i].rent;
        b[i].belong=c[i].belong;
    }
    system("mode con cols=106 lines=36");
    moneyA=20000;
    moneyB=20000;
    q=0;t=0;l=0;ll=0;jj=0;kk=0;h=0;hh=0;
    x=15;y=18;xx=15;yy=19;

    int k;
    for(k=10;k<15;k++)
    {
        system("cls");
        screen2(k);
    }
    welcome();
    system("cls");
    start();
	return 0;
}



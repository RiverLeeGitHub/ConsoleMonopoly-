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
    /*q为开始菜单的选择参数*/
    /*x和y为小红的坐标*/
    /*xx和yy为小蓝的坐标*/
    /*t为总轮数之和*/
    /*l和ll为角色的应到位置参数*/
    /*jj和kk为角色的实际位置参数*/
    /*h和hh为角色走的的次数*/
    int moneyA=20000;
    int moneyB=20000;
    char c;
    char d[10]={"游戏加载中"};
    struct millionaire
    {
        char name[6];
        int rent;
        int belong;
    }b[30]={
        "中国",30000,6,
        "俄罗斯",28000,0,
        "日本",20000,0,
        "伊朗",10000,0,
        "阿联酋",22000,0,
        "埃及",15000,0,
        "南非",14000,0,
        "瑞士",12000,0,
        "德国",20000,0,
        "传送门",30000,3,
        "荷兰",10000,0,
        "法国",25000,0,
        "英国",25000,0,
        "命运",30000,4,
        "巴西",10000,0,
        "停车场",30000,5,
        "美国",25000,0,
        "古巴",10000,0,
        "加拿大",35000,0,
        "澳洲",10000,0,
        "南极洲",5000,0,
        "新西兰",11000,0,
        "传送门",30000,3,
        "韩国",20000,0,
        "阿富汗",10000,0,
        "蒙古",16000,0,
        "新加坡",30000,0,
        "朝鲜",9000,0,
        "命运",30000,4,
        "印度",11000,0
    };
    char a[22][100]={
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
    "0000000000111111111111111111111111111111111111111111111111111111111111111111111111111111111111100000",
    "0000000000100000020000002000000200000020000002000000200000020000002000000200000020000002000000100000",
    "0000000000100000020000002000000200000020000002000000200000020000002000000200000020000002000000100000",
    "00000000001新加坡20蒙古02阿富汗20韩国02传送门2新西兰2南极洲20澳洲02加拿大20古巴020美国02停车场100000",
    "0000000000122222211111111111111111111111111111111111111111111111111111111111111111111111222222100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "000000000010朝鲜0100000000000000000000000000000000000000000000000000000000000000000000010巴西0100000",
    "0000000000122222210000000000000000000000000000000000000000000000000000000000000000000001222222100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "00000000001000000100000000000000000000000000000大富翁桌游0000000000000000000000000000001000000100000",
    "000000000010命运010000000000000000000000000000《走向世界》0000000000000000000000000000010命运0100000",
    "0000000000122222210000000000000000000000000000000000000000000000000000000000000000000001222222100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "0000000000100000010000000000000000000000000000000000000000000000000000000000000000000001000000100000",
    "000000000010印度0100000000000000000000000000000000000000000000000000000000000000000000010英国0100000",
    "0000000000122222211111111111111111111111111111111111111111111111111111111111111111111111222222100000",
    "0000000000100000020000002000000200000020000002000000200000020000002000000200000020000002000000100000",
    "0000000000100000020000002000000200000020000002000000200000020000002000000200000020000002000000100000",
    "000000000010中国02俄罗斯20日本020伊朗02阿联酋20埃及020南非020瑞士020德国02传送门20荷兰020法国0100000",
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
        printf("您好！%s\n",player);


        for(i=0;i<22;i++)  //把二维数组转换为图像显示
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
                    case '3':color(12); printf("\b\b\b小红");color(16);  break;
                    case '4':color(9); printf("\b\b\b小蓝");color(16);break;
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
        printf("          资产  小红:%d   小蓝",moneyA);//显示角色数据
        if(q==1){printf("（电脑）");}
        printf(":%d\n          房产",moneyB);
        j=0;
        printf("  小红:");
        for(i=0;i<30;i++)
        {
            if(b[i].belong==1)
            {for(j=0;j<6;j++)
            {
                printf("%c",b[i].name[j]);

            }printf("%d ",b[i].rent);
            }
        }
        if(j==0)printf("无房产   ");
        j=0;
        printf("\n                小蓝");
        if(q==1){printf("（电脑）");}
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
        if(j==0)printf("无房产   ");
        printf("\n");
        color(16);
        //printf("\nh=%d,hh=%d\n",h,hh);
        if(h>0&&t%2==0&&b[jj].belong==6)
            {
                moneyA+=10000;
                printf("\n          小红获得走完该圈的收益10000元！\n          ");
                h=-1;
                system("pause");
                system("cls");screen();
            }
        else if(hh>0&&t%2==1&&b[kk].belong==6)
            {
                moneyB+=10000;
                hh=-1;
                printf("\n          小蓝获得走完该圈的收益10000元！\n          ");system("pause");
                system("cls");screen();
            }

}

void start()
{
    int i,j,r;

    while(1)
    {
        screen();
        printf("          现在轮到：");

        if(t%2==0)
        {
            printf("小红\n          ");
            r=dice();
            delay();delay();delay();delay();delay();delay();delay();delay();delay();
            system("pause");
        }
        else
        {
            printf("小蓝\n");
            if(q==2){r=dice();printf("          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();system("pause");}
            else{r=dice();delay();delay();}
        }

        printf("          您骰到了：%d\n",r);
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
            printf("          小红到了");
            puts(b[jj].name);
            if(b[jj].belong==0||b[jj].belong==6)
            {
                delay();
                printf("          此地尚未购买\n");
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          您现在有%d元资产\n",moneyA);
                printf("          当前所在的%s地价为%d元",b[jj].name,b[jj].rent);
                if(moneyA>=b[jj].rent)
                {
                    delay();delay();delay();delay();delay();delay();delay();delay();delay();
                    printf("\n          是否购买？<y/n>");
                    while(1)
                    {
                            get=getch();
                            if(get=='`')over(1);//测试结束界面用
                            if (get=='y'||get=='n')break;
                    }

                    if (get=='y')
                    {
                        b[jj].belong=1;
                        moneyA=moneyA-b[jj].rent;
                        delay();
                        printf("\n          购买成功，您支付%d元买下了",b[jj].rent);
                        for(j=0;j<6;j++){printf("%c",b[jj].name[j]);}
                        printf("，现有%d元资产\n          ",moneyA);delay();delay();delay();delay();delay();delay();delay();delay();delay();
                        system("pause");
                    }
                    else if (get=='n'){}
                }
                else
                {
                    printf("，无法购买\n          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();system("pause");
                }
            }
            else if(b[jj].belong==1)
            {
                printf("          恭喜您回到自己购买下的地盘:)\n          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();
                system("pause");
            }
            else if(b[jj].belong==2)
            {
                printf("          很抱歉，您到了小蓝购买下的地盘，需要支付%s地价的一半%d元作为过路费\n",b[jj].name,b[jj].rent/2);
                moneyA=moneyA-b[jj].rent/2;
                moneyB=moneyB+b[jj].rent/2;
                delay();delay();delay();delay();delay();delay();delay();delay();delay();printf("          ");system("pause");
                printf("          您现在有%d元资产\n",moneyA);
                tips();
            }
            else if(b[jj].belong==3)//到了传送门
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
            else if(b[jj].belong==4)//抽取命运牌
            {
                delay();delay();delay();delay();delay();delay();printf("          ");system("pause");fate();
            }
            else if(b[jj].belong==5)//到了停车场
            {
                printf("          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();
                system("pause");
                return;
            }

        }
        else
        {
            hh++;
            printf("          小蓝到了");
            puts(b[kk].name);
            if(b[kk].belong==0)
            {
                delay();
                printf("          此地尚未购买\n");
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          您现在有%d元资产\n",moneyB);
                printf("          当前所在的%s地价为%d元",b[kk].name,b[kk].rent);
                if(moneyB>=b[kk].rent)
                {
                    delay();delay();delay();delay();delay();delay();delay();delay();delay();
                    printf("\n          是否购买？<y/n>");
                    while(1)
                    {

                            if(q==2){get=getch();}
                            else if(q==1&&moneyB>0){get='y';delay();delay();delay();delay();delay();printf("  小蓝决定买！");}
                            if (get=='y'||get=='n')break;
                    }

                    if (get=='y')
                    {
                        b[kk].belong=2;
                        moneyB=moneyB-b[kk].rent;
                        delay();delay();delay();delay();delay();delay();delay();delay();delay();
                        printf("\n          购买成功，您支付%d元买下了",b[kk].rent);
                        for(j=0;j<6;j++){printf("%c",b[kk].name[j]);}
                        printf("，现有%d元资产\n          ",moneyB);delay();delay();delay();delay();delay();delay();delay();delay();delay();
                        system("pause");
                    }
                    else if (get=='n'){}
                }
                else
                {
                    printf("，无法购买\n          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();system("pause");
                }
            }
            else if(b[kk].belong==2)
            {
                printf("          恭喜您回到自己购买下的地盘:)\n          ");delay();delay();delay();delay();delay();delay();delay();delay();delay();
                system("pause");
            }
            else if(b[kk].belong==1)
            {
                printf("          很抱歉，您到了小红购买下的地盘，需要支付%s地价的一半%d元作为过路费\n",b[kk].name,b[kk].rent/2);
                moneyB=moneyB-b[kk].rent/2;
                moneyA=moneyA+b[kk].rent/2;
                delay();delay();delay();delay();delay();delay();delay();delay();delay();printf("          ");system("pause");
                printf("          您现在有%d元资产\n",moneyB);
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

void go(int r)//前进函数
{
    int i;
    if(t%2==0)
    {
        l=l+r;
        go1(l,r);//控制小红
    }
    else
    {
        ll=ll+r;
        go2(ll,r);//控制小蓝
    }
}

void go1(int l,int r)
{
    int i;

        for(i=0;i<r;i++)
        {
            jj++;
            if(jj==30)//jj:小红的位置
            {
                jj=0;
                r=l%30+1;
                i=0;//r:小红的步数
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
                printf("          小红，您已欠债，欠债超过20000将破产\n          ");
                system("pause");
            }
        else if(moneyA<-20000)
            {
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          小红现在有%d元资产，已破产\n",moneyA);
                over(1);
            }
    }
    else
    {
        if(moneyB<0&&moneyB>=-20000)
            {
                delay();delay();delay();delay();delay();delay();delay();delay();delay();
                printf("          小蓝，您已欠债，欠债超过20000将破产\n          ");
                system("pause");
            }
        else if(moneyB<-20000)
            {
                printf("          小蓝现在有%d元资产，已破产\n",moneyB);
                over(2);
            }
    }
}

void location1(int l) //小红的坐标
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

void location2(int ll) //小蓝的坐标
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

int random()//骰子
{
    int r=0;
    srand((unsigned)time(0));
    r=rand() % 6 + 1;
    return r;
}

int random2()//抽取命运牌
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
            case 1:printf("          好人好事，银行10000元奖励！\n          ");
                    system("pause");
                    if(t%2==0){moneyA+=10000;printf("          您现在有%d元资产\n",moneyA);}
                    else{moneyB+=10000;printf("          您现在有%d元资产\n",moneyB);}
                    break;
            case 2:printf("          戏弄小朋友，丢失8000元\n          ");
                    system("pause");
                    if(t%2==0){moneyA-=8000;printf("          您现在有%d元资产\n",moneyA);}
                    else{moneyB-=8000;printf("          您现在有%d元资产\n",moneyB);}
                    tips();
                    break;
            case 3:printf("          休息，休息一下\n          ");
                    system("pause");
                    return;
                    break;
            case 4:printf("          前方塞车，退回%d步\n          ",s=random());
                    system("pause");
                    if(t%2==0){jj-=s;l-=s;location1(jj);screen();}
                    else{kk-=s;ll-=s;location2(kk);screen();}
                    break;
            case 5:printf("          恭喜您，您持有的房价上涨20\%\n          ");
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
                            printf("          资金的数额由负转正\n          ");
                            system("pause");
                            moneyA*=-1;
                            printf("          您现在有%d元资产\n",moneyA);
                    }
                    else if(t%2==1&&0>moneyB&&moneyB>-10000)
                    {
                            printf("          资金的数额由负转正\n          ");
                            system("pause");
                            moneyB*=-1;
                            printf("          您现在有%d元资产\n",moneyB);
                    }
                    else
                    {
                        r=random();continue;
                    }
                    break;
            case 7:if(t%2==0&&moneyA<-5000)
                    {
                            printf("          你太穷了！雪中送炭，系统送你8000元\n          ");
                            system("pause");
                            moneyA+=8000;
                            printf("          您现在有%d元资产\n",moneyA);
                    }
                    else if(t%2==1&&moneyB<-5000)
                    {
                            printf("          你太穷了！雪中送炭，系统送你8000元\n          ");
                            system("pause");
                            moneyB+=8000;
                            printf("          您现在有%d元资产\n",moneyB);
                    }
                    else
                    {
                        r=random();continue;
                    }
                    break;
            case 8:if(t%2==0&&moneyA>10000)
                    {
                            printf("          花费20\％的现金做慈善\n          ");
                            system("pause");
                            moneyA*=0.8;
                            printf("          您现在有%d元资产\n",moneyA);
                    }
                    else if(t%2==1&&moneyB>10000)
                    {
                            printf("          花费20\％的现金做慈善\n          ");
                            system("pause");
                            moneyB*=0.8;
                            printf("          您现在有%d元资产\n",moneyB);
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
	printf("\n          游戏结束！ ");
    system("pause");
    system("cls");
    screen2(14);
    if(x==1)
    {
        printf("\n\n\n                      胜负已决，此局小蓝是大富翁！小红的总资产：%d，小蓝的总资产：%d",moneyA,moneyB);
    }
    if(x==2)
    {
        printf("\n\n\n                      胜负已决，此局小红是大富翁！小红的总资产：%d，小红的总资产：%d",moneyB,moneyA);
    }


        FILE *fp;//读取玩家数据
        if((fp=fopen("users.txt","r"))==NULL)
        {   puts("                      未能打开文件");exit(1);}
        for(i=0;i<size;i++)
         {
             fscanf(fp,"%s %s %d\n",&statics[i].name,&statics[i].password,&statics[i].times);
             if(strcmp(statics[i].name,player)==0)
             {
                 statics[i].times+=1;
                 printf("\n\n                      亲爱的%s，这是您第%d次玩该大富翁游戏，常来看看:)\n",statics[i].name,statics[i].times);
             }
         }
        fclose(fp);
        FILE *fp2;//保存玩家数据
        if((fp2=fopen("users.txt","w"))==NULL)
        {   puts("                      未能打开文件");exit(1);}
         for(i=0;i<size;i++)
         {
             fprintf(fp2,"%s %s %d\n",statics[i].name,statics[i].password,statics[i].times);
         }
        fclose(fp2);


                printf("\n\n                      再来一局？<y/n>");
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

//欢迎界面
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
    "000000000000000010000020000000000000000000000000大富翁桌游000000000000000000000000200000100000",
    "00000000000000001000002000000000000000000000000《走向世界》00000000000000000000000200000100000",
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

int screen2(int x)//显示欢迎界面
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
    printf("                      注册界面\n");
    int i=0;
    struct user *head,*p,*q;
    while(i<n)
    {
        FILE *fp1;//读取玩家总数
        if((fp1=fopen("size.txt","r"))==NULL)
        {   puts("                      未能打开文件");   exit(1) ;   }
        fscanf(fp1,"%d",&size);
        fclose(fp1);

        p=(struct user*)malloc(sizeof(struct user));
        if(i==0)
        {head=p;q=p;}

        printf("\n                      昵称:");
        gets(p->name);

        FILE *fp3;                                   //打开用户文件
        char ch;
        char *filename2="users.txt";
        if((fp3=fopen(filename2,"r"))==NULL)
         {    printf("                      未能打开文件\n");
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
                printf("\n                      存在相同玩家\n\n                      ");
                free(p);
                system("pause");
                int k;
                return 0;
            }
         }

        printf("\n                      密码:");
        gets(p->password);

        p->next=NULL;
        if(i!=0)
         {q->next=p;q=p;}
        i++;

        FILE *fp;//保存数据
        if((fp=fopen("users.txt","a"))==NULL)
        {   puts("                      未能打开文件");   exit(1) ;   }
        fprintf(fp,"%s %s 0 \n",p->name,p->password);
        fclose(fp);

        FILE *fp2;//玩家总数加一
        if((fp2=fopen("size.txt","w"))==NULL)
        {   puts("                      未能打开文件");   exit(1) ;   }
        size=size+1;
        fprintf(fp2,"%d",size);
        fclose(fp2);

        printf("\n                      注册成功！\n\n                      ");
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
    printf("                      登录界面\n");
    printf("\n                      昵称：");
    gets(get1);

    FILE *fp1;                                 //打开size文件
    char *filename1="size.txt";
    if((fp1=fopen(filename1,"r"))==NULL)
     {    printf("                      未能打开文件\n");
	  return;
     }

    fscanf(fp1,"%d",&size);
    fclose(fp1);

    FILE *fp;                                   //打开用户文件
    char *filename2="users.txt";
    if((fp=fopen(filename2,"r"))==NULL)
     {    printf("                      未能打开文件\n");
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
         printf("\n                      没有该玩家信息\n\n                      ");
         system("pause");
         for(k=10;k<15;k++)
        {
            system("cls");
            screen2(k);
        }
        welcome();
     }

    printf("\n                      密码：");
    gets(get2);
    if(strcmp(get2,statics[i].password)==0)
    {
        printf("\n                      登录成功！\n\n                      ");strcpy(player,get1);system("pause");return 1;
    }
    else
    {
        printf("\n                      昵称或密码错误！\n\n                      ");system("pause");system("cls");
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

            case '3':strcpy(player,"现在您是游客身份");k=1;break;
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
    printf("                      (1)立即登录  (2)现在注册  (3)游客进入");
    delay();delay();delay();delay();delay();delay();delay();delay();delay();

                printf("\n\n                      请选择：  <1/2/3>");
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
    printf("                      (1)单人游戏  (2)双人游戏  (3)游戏说明");

                printf("\n\n                      请选择：  <1/2/3>");
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
                    printf("\n\n\n     大富翁桌游  游戏说明：");delay();delay();delay();delay();delay();delay();delay();
                    printf("\n\n          游戏中有角色小红和小蓝相互比拼。小红和小蓝各自拥有一定数量的资产用于购买房产。");delay();delay();
                    printf("\n\n          当某地房产被购买，对手路过此地时将会缴纳房产数额的一半作为过路费给房产拥有一方。");delay();delay();
                    printf("\n\n          角色每走完一圈，将会获得10000元的奖励。");delay();delay();
                    printf("\n\n          现金资产少于-20000时，该角色将破产，游戏结束，另一方获胜。");delay();delay();
                    printf("\n\n          路过“命运”时，角色可抽取命运牌，抽取的结果可能对自己有利，也可能对自己不利。");delay();delay();
                    printf("\n\n          路过“传送门”时，角色将通过传送门传送到另一个相应地点，不记录完成改圈的收益。");delay();delay();
                    printf("\n\n          在开始菜单中可以选择单人游戏或双人游戏。在单人游戏中，玩家为角色小红，电脑为角色小蓝。");delay();delay();
                    printf("\n\n          本游戏制作和解释权为李江同学所有。");delay();delay();delay();delay();delay();delay();delay();delay();delay();delay();

                    printf("\n\n     若要返回主菜单，");system("pause");
                    main();
                }
}



int main()
{
	struct millionaire c[30]={//数据初始化
        "中国",30000,6,
        "俄罗斯",28000,0,
        "日本",20000,0,
        "伊朗",10000,0,
        "阿联酋",22000,0,
        "埃及",15000,0,
        "南非",14000,0,
        "瑞士",12000,0,
        "德国",20000,0,
        "传送门",30000,3,
        "荷兰",10000,0,
        "法国",25000,0,
        "英国",25000,0,
        "命运",30000,4,
        "巴西",10000,0,
        "停车场",30000,5,
        "美国",25000,0,
        "古巴",10000,0,
        "加拿大",35000,0,
        "澳洲",10000,0,
        "南极洲",5000,0,
        "新西兰",11000,0,
        "传送门",30000,3,
        "韩国",20000,0,
        "阿富汗",10000,0,
        "蒙古",16000,0,
        "新加坡",30000,0,
        "朝鲜",9000,0,
        "命运",30000,4,
        "印度",11000,0
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



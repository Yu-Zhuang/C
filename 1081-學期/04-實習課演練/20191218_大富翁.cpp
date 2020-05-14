

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Dice(void);
void PMoney();
int Fund();
void end();
void house();

char Richman[44]; //map
int player[2]={5000,5000}; //players's money
int position[2]={0,0}; //player's position
int game=1; //控制遊戲是否進行
int n=1,flag=0; //n:遊戲回合數, flag是否直接跑完

int main(){
    srand(time(NULL));
    int i;
    for(i=0;i<44;i++){ //初始化map
        Richman[i]='z';
    }
    Richman[0]='r'; //0,22休息
    Richman[22]='r';
    Richman[11]='f'; //11,33獲得機會
    Richman[33]='f';
    
    printf("= = = 大 富 翁 遊 戲 = = =\n"); //前敘述
    printf("位置0及22是休息一次\n位置11及33獲得'機會'一次\n");
    printf("預設玩家一開始有5000元進行遊戲\n");
    printf("先獲得10萬元者贏;或先破產者輸\n");
    printf("= = = = 遊 戲 開 始 = = = =\n\n");
    
    while(game){ //begin
        //玩家1
        printf("-+玩家1+-\n玩家1擲骰子: ");
        position[0]=(position[0]+Dice())%44; //Dice
        printf("玩家1走到 %d 號位置\n動作: ",position[0]);
        if(Richman[position[0]]=='f'){ //走到fund 獲得機會
            player[0]+=Fund();
        }else if(Richman[position[0]]=='b'){ //走到b
            player[0]-=200;
            player[1]+=200;
            printf("走到對方地盤,我方-200,對方+200\n");
        }else if(Richman[position[0]]=='z'&&player[0]>500){ //買地
            player[0]-=500;
            Richman[position[0]]='a';
            printf("此為空地,購買地盤-500\n");
        }else
            printf("pass\n");
        //玩家2
        printf("\n-+玩家2+-\n玩家2擲骰子: ");
        position[1]=(position[1]+Dice())%44; //Dice
        printf("玩家2走到 %d 號位置\n動作: ",position[1]);
        if(Richman[position[1]]=='f'){ //走到fund
            player[1]+=Fund();
        }else if(Richman[position[1]]=='a'){ //走到a
            player[1]-=200;
            player[0]+=200;
            printf("走到對方地盤,我方-200,對方+200\n");
        }else if(Richman[position[1]]=='z'&&player[1]>500){ //買地
            player[1]-=500;
            Richman[position[1]]='b';
            printf("此為空地,購買地盤-500\n");
        }else
            printf("pass\n");
        //end or not
        if(player[1]<=0||player[0]<=0||player[1]>=100000||player[0]>=100000){ //end
            end(); //正常跑到完
        }else if(flag==0){ //非直接跑完的ask
            n+=1;
            PMoney();
            printf("繼續下一回合按1,結束按0,直接跑完按2,查看各自土地按3: ");
            scanf(" %d",&game);
            while(game!=0&&game!=1&&game!=2&&game!=3){ //FPD
                printf("輸入錯誤, 請重新輸入\n");
                printf("繼續下一回合按1,結束按0,直接跑完按2,查看各自土地按3: ");
                scanf(" %d",&game);
            }
            if(game==3){ //查看土地
                game-=2;
                house();
                printf("繼續下一回合按1,結束按0,直接跑完按2: "); //ask
                scanf(" %d",&game);
                while(game!=0&&game!=1&&game!=2&&game!=3){ //FPD
                    printf("輸入錯誤, 請重新輸入\n");
                    printf("繼續下一回合按1,結束按0,直接跑完按2: ");
                    scanf(" %d",&game);
                }
                printf("\n");
            }
            if(game==2){ //準備 快轉跑完
                flag=1;
                game-=1;
            }
            if(game==1) //下一回合
                printf("\n========第%d回合========\n",n);
            else{ //按0直接遊戲結束
                printf("\n===遊戲結束===\n");
            }
                
        }else if(flag){ //選擇直接跑完後會執行
            n+=1;
            PMoney();
            if(game==1)
                printf("\n========第%d回合========\n",n);
            else{ //game==0
                printf("\n===遊戲結束===\n");
            }
        }
    }
    return 0;
}

int Dice(){ //Dice
    int ret=rand()%6+1;
    printf("擲出%d點\n",ret);
    return ret;
}
void PMoney(){ //print money
    printf("\n玩家1的錢: %d\n玩家2的錢: %d\n",player[0],player[1]);
}
int Fund(){ //機會
    int ret=rand()%5001;
    printf("機會: 獲得獎金%d\n",ret);
    return ret;
}
void house(){ //house
    int i=0,count_a=0,count_b=0;
    printf("玩家1的土地有: ");
    while(i!=44){
        if(Richman[i]=='a'){
            printf("%d ",i);
            count_a+=1;
        }
        i+=1;
    }
    printf("號位置,共%d塊地\n",count_a);
    i=0;
    printf("玩家2的土地有: ");
    while(i!=44){
        if(Richman[i]=='b'){
            printf("%d ",i);
            count_b+=1;
        }
        i+=1;
    }
    printf("號位置,共%d塊地\n",count_b);
}
void end(){ //end
    PMoney();
    house();
    if(player[0]==player[1])
        printf("平手\n遊戲結束\n");
    else if(player[0]<player[1])
        printf("玩家2贏得勝利!\nGame over\n");
    else
        printf("玩家1贏得勝利!\nGame over\n");
    game=0; //將game歸零
}

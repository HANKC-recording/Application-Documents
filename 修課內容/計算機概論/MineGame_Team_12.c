#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void around(int a[], int b, int c[], int d, int e, int f, int g, int z);
void printans(int a[], int b);
void printmap(int a[], int b);

int main(){
    double record[1000]; //歷史紀錄的資料庫
    int regame = 0;      //紀錄已進行幾次遊戲
    int game = 0;        //輸入面板的變數
    int maingame = 1;     //開始遊戲的變數

    for(int i = 0; i < 1000; i++){
        record[i] = -1;
    }

    while(maingame == 1){
        //遊戲面板        
        printf("◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆\n\n");
        printf("-------*開始遊戲*-------\n");
        printf("-------*請輸入:1*-------\n\n");
        printf("-------#結束遊戲#-------\n");
        printf("-------#請輸入:0#-------\n\n");
        printf("-------§查看遊戲紀錄§----\n");
        printf("-------§請輸入:2§------\n\n");
        printf("◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆ ◆\n");
        printf("輸入:");
        scanf("%d",&game);

        //輸入不在面板上，結束遊戲
        if(game !=1 && game !=2){
            maingame = 0;
        }

        //用於顯示歷史紀錄
        int printrecord = 0;

        if(game == 2){
            system("cls");
            printf("◎ 紀錄:\n");
        }

        while(game == 2){

            if(record[printrecord] != -1){
                printf("   %5.1lf [是否勝利: %2.0lf , 花費時間: %7.2lfsec , 使用步數: %4.0lf步]\n", record[printrecord], record[printrecord+1], record[printrecord+2], record[printrecord+3]);
                printrecord = printrecord+4;
            }

            else{
                printf("\n輸入1開始遊戲, 0回到主選單");
                scanf("%d",&game);
                system("cls");
            }
        }

        //進入踩地雷遊戲
        while(game == 1){
            regame++;

            double begin = 0; //開始時間
            double end = 0;   //結束時間
            int step = 0;     //使用步數
            int size = 0;     //設定地圖大小的變數
            int n = 99999;    //設定地雷數量的變數

            //輸入地圖大小
            system("cls");
            printf("輸入範圍(r*r) :");
            scanf("%d",&size);

            //輸入地雷數量
            while(n > size*size-1){
                printf("炸彈數量 :");
                scanf("%d",&n);

                if(n >= size*size){
                    printf("!!!【請重新輸入】!!!\n");
                }
            }

            //設定串列的原始數值
            int a[size*size];
            int c = 0;
            for(int i = 0; i < size*size; i++){
                a[i] = 0 ;
            }

            //在地圖中放地雷
            while(c < n){
                //取隨機數
                srand(time(NULL)*(c+1));
                int pos = rand()%(size*size);                
                around(a, size, a, 1, 1000, 1, 10, pos);
                c++;
            }

            //設定初始地圖
            int amap[size*size];
            for(int i = 0; i < size*size; i++){
                amap[i] = 99;
            }

            //遊戲開始前先顯示地圖
            printmap(amap,size);

            //開始遊戲
            int start = 1;
            int t = 0;
            begin = time(NULL); //記錄遊戲開始時間

            while(start == 1){
                //輸入操作的三個數值
                int x = -1;
                int y = -1;
                int function = 0;

                //輸入X座標
                while(x >= size || x < 0){ //迴圈用於確定輸入範圍正確
                    printf("\nX: ");
                    scanf("%d",&x);
                }
                
                //輸入Y座標
                while(y >= size || y < 0){
                    printf("Y: ");
                    scanf("%d",&y);
                }

                //輸入要執行的功能（1是翻開，2是標記，3是作弊：顯示解答）
                while(function !=1 && function !=2 && function !=3){
                    printf("Function: ");
                    scanf("%d",&function);
                }
                step++; //完成一次輸入則步數+1

                //執行功能：顯示解答
                if(function == 3){
                    printans(a,size);
                }

                //執行功能：標記
                else if(function == 2){
                    if(amap[x+y*size] < 100){
                        amap[x+y*size] = 100;
                    }

                    //執行功能：取消標記
                    else{
                        amap[x+y*size] = 99;
                    }
                    
                    //標記後顯示地圖
                    printmap(amap,size);

                    //顯示需要翻開的格子數以及已翻開的格子數
                    printf("\n  需翻開:%d , 已翻開:%d\n", size*size-n, t);
                }
                
                else{
                    //失敗條件：踩到炸彈
                    if(a[x+y*size] >= 1000){
                        printf("! ★ ☆ BOOM ☆ ★ !");
                        printf("\n\n\nmap:\n");
                        printf("\n ");
                        record[regame*4-3] = 0;

                        //失敗後顯示地圖
                        printans(a,size);
                        start = 0;
                    }

                    //勝利條件：翻開所有不是炸彈的格子
                    else if(size*size-n <= t+1){
                        printf("! ★ ☆ 勝利 ☆ ★ !\n");
                        record[regame*4-3] = 1;

                        //勝利後顯示地圖
                        printans(a,size);
                        start = 0;
                    }

                    //執行功能：翻開
                    else{                        
                        amap[x+y*size] = a[x+y*size];

                        //加分項目：翻開周圍的格子
                        around(amap, size, a, 9999999, -10, 0, 0, 0); //9999999為限制運算次數用

                        int check = 0;
                        while(check < size*size){
                            if(amap[check] == 0){
                                amap[check] = -10;
                            }
                            check++;
                        }

                        //計算已翻開格子數
                        t = 0;
                        for(int i = 0; i<size*size; i++){
                            if(amap[i] < 50){
                                t++;
                            }
                        }

                        //顯示目前的地圖
                        printmap(amap,size);

                        printf("\n  需翻開:%d , 已翻開:%d\n", size*size-n, t);
                    }    
                }
            }

            end = time(NULL); //紀錄遊戲結束時間

            //遊戲結束
            printf("\n【遊戲結束】!\n 時間為: %.3lf sec\n",end - begin);
            record[regame*4-1] = step;
            record[regame*4-2] = end - begin;
            record[regame*4-4] = regame;
            printf("\n1 : 重新遊戲\n0 : 返回選單\n");
            scanf("%d",&game);    
        }   
    }     
    return 0;
}

void around(int a[],int b,int c[],int d,int e,int f,int g,int z){ //處理地圖邊緣特殊狀況
    int y = 0;

    while(z < b*b && y < d){
        if(a[z] <= g && a[z]>=0){
            if(z % b != b - 1){
                a[z+1] = c[z+1]+f;
            }
            if(z % b != 0){
                a[z-1] = c[z-1]+f;
            }
            if(z / b != b - 1){
                a[z+b] = c[z+b]+f;
            }
            if(z / b != 0){
                a[z-b] = c[z-b]+f;
            }
            if(z / b != b - 1 && z % b != b - 1){
                a[z+b+1] = c[z+b+1]+f;
            }
            if(z / b != b - 1 && z % b != 0){
                a[z+b-1] = c[z+b-1]+f;
            }
            if(z / b != 0 && z % b != 0){
                a[z-b-1] = c[z-b-1]+f;
            }
            if(z / b != 0 && z % b != b - 1){
                a[z-b+1] = c[z-b+1]+f;
            }
            a[z] = e;
            z = 0;
            y++;
        }

        else{
            z++;
        }        
    }
}

void printans(int a[],int b){ //顯示解答
    printf("    ");
    for(int i = 0; i < b; i++){
        printf("(%2d)",i);
    }

    for(int j = 0;j < b;j++){
        printf("\n(%2d)",j);

        for(int i = 0;i <b;i++){
            if(a[i+j*b] >= 1000){
                printf("  \033[41;5m* \033[0m");
            }

            else{
                printf(" \033[42;5m%2d \033[0m",a[i+j*b]);
            }    
        }
    }
}

void printmap(int a[],int b){ //顯示地圖
    printf("\n ");

    for(int i = 0;i <b;i++){
        printf(" %2d",i);
    }

    for(int j = 0;j <b;j++){
        printf("\n%2d",j);

        for(int i = 0;i <b;i++){
            if(a[i+j*b] == -10){
                printf(" \033[42;5m%d \033[0m",0);
            }
            else if(a[i+j*b] == 100){
                printf(" P ");
            }
            else if(a[i+j*b] > 50){
                printf(" ■ ");
            }
            else{
                printf(" \033[42;5m%d \033[0m",a[i+j*b]);
            }
            
        }
    }
}

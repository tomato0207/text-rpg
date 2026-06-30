#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include <conio.h> 
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	//前導介紹 //設定參數 
	srand(time(NULL));
	char key=' ';
	char firstshow0[17]="歡迎來到這個世界";
	char firstshow1[62]="在這個世界 你可以選擇冒險 強化裝備 學習技能以及抽獎來增強自己";
	char firstshow2[24]="以擊敗魔王為目標前進吧!";
	char mainshow0[9]="今天是第";
	char mainshow1[15]="請選擇你的行動";
	char choose[60]="行動選項:1.冒險 2.強化裝備 3.學習技能 4.抽獎 5.裝備 6.休息";
	char tired[23]="今天太累了 先休息了吧!";
	char meet[13]="遇見魔物 是:";
	char battle[30]="戰鬥選項:1.攻擊 2.技能 3.逃跑";
	char finishcoin[19]="討伐完成 獲得金幣:";
	char finishexp[8]="經驗值:";
	char levelupshow[21]="恭喜升級 等級提升至:";
	string skill[4]={"治癒之風","三重打擊","鋼鐵之盾","毒蛇打擊"};
	string skill_e[4]={"回復40%血量(不會超過角色最大血量)","下次攻擊傷害翻三倍","格檔怪物下三次攻擊","攻擊後每回合削減怪物10%血量"};
	string weapon[7]={"空手","勇者之劍","銀影之劍","戰神之刃","不滅之劍","獅心劍","一顆番茄"};
	string monstername[10] = {"史萊姆","鋼鐵巨獸","暗影魅魔","熔岩巨蟲","冰霜妖精","幽冥幻影","雷霆狼人","烈焰魅魔","巨角犀牛","魔王"};
	bool getweapon[7]={1,0,0,0,0,0,0};
	bool getskill[5]={0,0,0,0,0};
	char weaponup[12]="目前武器為:";
	char weaponup1[16]="是否要進行強化?";
	char prize[14]="恭喜獲得武器:";
	char lottery[24]="是否進行抽獎? 花費金幣:";
	char chooseweapon[19]="請選擇要裝備的武器";
	bool win=false,rest=false,fight,run,finishweapon,finishlottery,finishchoose,poison;
	int surviveday=1,energy,level=1,monster,coin=0,getcoin,exp=0,getexp,levelup=10,HP=10,MP=10,power=1,damage,weaponlevel[5],weaponlevelup=10,wear=0
	,lotterycoin=level*100,lotterynum,monsterHP,monsterDamage,c_HP=10,c_MP=10,learnskill=0,defense;
	int weaponpower[7]={1,5,10,20,40,100,9999};
	for(int i=0;i<7;i++){
		weaponlevel[i]=0;
	}
	Sleep(300);
	for(int i=0;i<17;i++){
		cout<<firstshow0[i];
		Sleep(30);
	}
	Sleep(500);
	cout<<endl;
	for(int i=0;i<62;i++){
		cout<<firstshow1[i];
		Sleep(30);
	}
	Sleep(500);
	cout<<endl;
	for(int i=0;i<24;i++){
		cout<<firstshow2[i];
		Sleep(30);
	}
	cout<<endl<<"按下空格鍵繼續"<<endl;
	while(key!=13){
		key = getch();
	}
	
	//遊戲主要 
	do{
		//每天重置起始 
		cout<<endl;
		for(int i=0;i<9;i++){
			cout<<mainshow0[i];
			Sleep(30);
		} 
		cout<<surviveday<<"天"<<endl;
		for(int i=0;i<15;i++){
			cout<<mainshow1[i];
			Sleep(30);
		}
		cout<<endl;
		rest=false;
		energy=5;
		
			while(1){
				if(win){
				cout<<endl<<"恭喜你於第"<<surviveday<<"天擊敗魔王 通關此遊戲!";
				return 0;
				}
				if(rest)break;
				if(exp>=levelup){
					level++;
					exp-=levelup;
					levelup*=3;
					power+=5,c_HP*=2;c_MP*=2;
					if(c_MP>100)c_MP=100;
					for(int i=0;i<21;i++){
						cout<<levelupshow[i];
						Sleep(30);
					}
					cout<<level;
					cout<<endl<<"血量提升至:"<<c_HP<<"魔力提升至:"<<c_MP<<endl; 
					if(level==10){
						levelup=999999999;
					}
					continue;
				}
				cout<<endl<<"目前等級為:"<<level<<" 金幣為:"<<coin<<" 經驗值為:"<<exp<<"/"<<levelup<<" 精力值剩餘:"<<energy<<" 目前使用武器:"<<weapon[wear];
				if(weaponlevel[wear]>0){
					cout<<"+"<<weaponlevel[wear];
				}
				cout<<endl;
				
				for(int i=0;i<60;i++){
					cout<<choose[i];
					Sleep(30);
				}
				cout<<endl;
				key = getch();
				switch(key){
					//選擇冒險 
					case'1':
					fight=true,run=false,HP=c_HP;MP=c_MP;
					if(energy<=0){
						for(int i=0;i<23;i++){
						cout<<tired[i];
						}
						cout<<endl;
						continue;
					}
					
					monster=rand()%100;
					if(monster==0){
						char treasure[16]="發現了稀有寶藏!"; 
						for(int i=0;i<16;i++){
							cout<<treasure[i];
							Sleep(30);
						}
						cout<<endl;
						getcoin=rand()%50+50*level;
						cout<<"獲得了"<<getcoin<<"個金幣!"<<endl;
						coin+=getcoin; 
						energy--;
						break;
					}
					do{
					monster=rand()%level;
					}while(monster<0||monster>9);
					for(int i=0;i<13;i++){
							cout<<meet[i];
							Sleep(30);
						}
					cout << monstername[monster] << "lv." << monster + 1 << endl;

                    // 設定怪物血量及傷害
                    monsterHP = 10 * pow(2,monster);  
                    monsterDamage = 2 * pow(2,monster);
					if(monster==9){
						monsterHP = 20 * pow(3,monster);  
                    	monsterDamage = 2 * pow(2,monster);
					}  
					poison=false;
					defense=0;
					energy--;
                    // 開始戰鬥
                    do {
                    	finishchoose=false;
                        if (run) break;
                        int damage = rand() % monsterDamage + 1;
                        if(defense>0){
                        	cout<<"格檔"<<monstername[monster]<<"的攻擊!"<<endl; 
                        	defense--;
						}else{
                        cout << monstername[monster] << "對你造成了" << damage << "點的傷害!" << endl;
                        Sleep(500);
                        HP -= damage;
                    	}
                        if (HP <= 0) {
                            cout << "討伐失敗 將回到村落" << endl;
                            Sleep(2000);
                            break;
                        }
                        do{
                        cout << "角色目前血量為:" << HP << "魔力為:" << MP << endl;
                        Sleep(500);
                        cout << monstername[monster] << "目前血量剩餘:" << monsterHP << endl << endl;
                        Sleep(300);
                        for (int i = 0; i < 30; i++) {
                            cout << battle[i];
                            Sleep(30);
                        }
                        cout << endl;
                        key = getch();
                        switch (key) {
                            case '1':
                                // 計算造成的傷害
                                damage=power+level*2+(weaponlevel[wear]*(1+(weaponpower[wear]/10)))+weaponpower[wear]
							+(rand()%((power+level*2+(weaponlevel[wear]*(1+(weaponpower[wear]/10)))+weaponpower[wear])/2))
							-(rand()%((power+level*2+(weaponlevel[wear]*(1+(weaponpower[wear]/10)))+weaponpower[wear])/2));
                                monsterHP -= damage;
                                Sleep(50);
                                cout << "你對" << monstername[monster] << "造成傷害:" << damage << endl;
                                Sleep(500);
                                finishchoose=true;
                                break;

                            case '2':
                            	if(learnskill==0){
                            		cout<<"尚未學習任何技能!"; 
                            		break;
								}
                                for(int i=0;i<4;i++){
                                	if(getskill[i]){
                                	cout<<i+1<<":"<<skill[i]<<"消耗魔力:"<<20+i/2*10<<endl;	
									}
								}
                                key = getch();
                                switch (key) {
                                	//治癒術 
                                	case '1':
                                		if(getskill[0]&&MP>=20){
                                			HP+=c_HP*0.4;
                                			if(HP>c_HP)HP=c_HP;
                                			MP-=20;
                                			cout<<endl<<"角色血量回復至"<<HP<<"!"<<endl; 
                                			finishchoose=true;
                                			break;
										}
										else{
											cout<<endl<<"魔力不足或尚未學習技能"<<endl;
											break;
										}
									//雙重打擊 
									case '2':
                                		if(getskill[1]&&MP>=20){
                                			MP-=20;
                                			damage=power+level*2+(weaponlevel[wear]*(1+(weaponpower[wear]/10)))+weaponpower[wear]
											+(rand()%((power+level*2+(weaponlevel[wear]*(1+(weaponpower[wear]/10)))+weaponpower[wear])/2))
											-(rand()%((power+level*2+(weaponlevel[wear]*(1+(weaponpower[wear]/10)))+weaponpower[wear])/2));
                           				    monsterHP -= damage*3;
                                			Sleep(50);
                                			cout << "你使用三重打擊對" << monstername[monster] << "造成傷害:" << damage*3 << endl;
                                			Sleep(500);
                                			finishchoose=true;
                                			break;
										}
										else{
											cout<<endl<<"魔力不足或尚未學習技能"<<endl;
											break;
										}
									//格檔 
									case '3':
                                		if(getskill[2]&&MP>=30){
                                			MP-=30;
                                			defense=2;
                                			finishchoose=true;
                                			break;
										}
										else{
											cout<<endl<<"魔力不足或尚未學習技能"<<endl;
											break;
										}
									//毒擊 
									case '4':
                                		if(getskill[3]&&MP>=30){
                                			MP-=30;
                                			poison=true;
                                			finishchoose=true;
                                			break;
										}
										else{
											cout<<endl<<"魔力不足或尚未學習技能"<<endl;
											continue;
										}
									default:break;
								}
                                break;

                            case '3':
							fight=false;
							cout<<"已逃脫戰鬥"<<endl;
							finishchoose=true;
							run=true;
							break;
					 	
						}}
						while(finishchoose==false);
							if(poison&&monsterHP>0){
								cout<<endl<<"毒擊削弱了"<<monstername[monster]<<monsterHP/10<<"點血量!"<<endl;
								monsterHP*=0.9;
							}
							if(monsterHP<=0){
								if(monster==9){
									win=true;
									cout<<"討伐魔王!";
								}
								else{
								getexp=5*(monster+1)*(monster+1)*(monster+1)*(monster+1);
								getcoin=5*(monster+1)*(monster+1)*(monster+1)*(monster+1);
								for(int i=0;i<19;i++){
									cout<<finishcoin[i];
									Sleep(30);
								}
								cout<<getcoin<<endl;
								for(int i=0;i<8;i++){
									cout<<finishexp[i];
									Sleep(30);
								}
								cout<<getexp<<endl;
								exp+=getexp,coin+=getcoin;
								}
							}
						}while(monsterHP>0&&fight);
						break;
					case'2':
						if(energy<=0){
						for(int i=0;i<23;i++){
						cout<<tired[i];
						}
						cout<<endl;
						continue;
					}
					finishweapon=false;
					cout<<endl;
					weaponlevelup=weaponlevel[wear]*10+10+weaponpower[wear]*(weaponlevel[wear]+1);
					for(int i=0;i<12;i++){
						cout<<weaponup[i];
						Sleep(30);
					}
					cout<<weapon[wear];
					if(weaponlevel[wear]>0){
					cout<<"+"<<weaponlevel[wear];
					}
					cout<<endl;
					for(int i=0;i<16;i++){
						cout<<weaponup1[i];
						Sleep(30);
					}
					cout<<endl<<"所需金幣為:"<<weaponlevelup<<endl<<"1.是 2.取消"<<endl; 
					do{
						key = getch();
						switch(key){
							case'1':
								if(coin>=weaponlevelup){
									coin-=weaponlevelup,weaponlevel[wear]++;
									cout<<"強化完成! 目前武器等級為+"<<weaponlevel[wear]<<endl; 
									energy--;
									finishweapon=true;
									break;
								}else{
									cout<<"金幣不足!";
								}
								break;
							case'2':
								finishweapon=true;
								break;
							default:{
								cout<<"輸入錯誤指令!";
								break;
							}
						}
					}while(finishweapon==false);
					break;
					//學習技能 
					case'3':
						if(energy<=0){
						for(int i=0;i<23;i++){
						cout<<tired[i];
						}
						cout<<endl;
						continue;
					}
						finishchoose=false;
						cout<<"技能列表如下:"<<endl;
						for(int i=0;i<4;i++){
							cout<<i+1<<":"<<skill[i]<<"技能效果: "<<skill_e[i]<<" 需求等級為:"<<(i+1)*2<<"  學習金錢為:"<<(i+1)*200<<endl;
						}
						cout<<endl<<"輸入其他鍵退出選單";
						do{
						key = getch();
                        switch (key) {
                            case '1':
                            	if(level>=2&&coin>=200&&getskill[0]==false){
                            		cout<<endl<<"確定學習技能"<<skill[0]<<"嗎? 將花費200$"<<endl<<"1:確定"<<endl<<"2:取消";
									key = getch();
									switch (key) {
										case '1':
											coin-=200;
											getskill[0]=true;
											cout<<endl<<"已學成技能"<<skill[0]<<"!"; 
											finishchoose=true;
											learnskill++;
											energy--;
											break;
										default:{
											break;
										}
									} 
								}else{
									cout<<endl<<"已學習過技能或是經驗/金錢不足!"<<endl;
								}break;
                            default:{
                            	finishchoose=true;
								break;
							}
							case '2':
                            	if(level>=4&&coin>=400&&getskill[1]==false){
                            		cout<<endl<<"確定學習技能"<<skill[1]<<"嗎? 將花費400$"<<endl<<"1:確定"<<endl<<"2:取消";
									key = getch();
									switch (key) {
										case '1':
											coin-=400;
											getskill[1]=true;
											cout<<endl<<"已學成技能"<<skill[1]<<"!"; 
											learnskill++;
											energy--;
											finishchoose=true;
											break;
										default:{
											finishchoose=true;
											break;
										}
									} 
								}else{
									cout<<endl<<"已學習過技能或是經驗/金錢不足!"<<endl;
								}break;
							case '3':
                            	if(level>=6&&coin>=600&&getskill[2]==false){
                            		cout<<endl<<"確定學習技能"<<skill[2]<<"嗎? 將花費600$"<<endl<<"1:確定"<<endl<<"2:取消";
									key = getch();
									switch (key) {
										case '1':
											coin-=600;
											getskill[2]=true;
											cout<<endl<<"已學成技能"<<skill[2]<<"!"; 
											learnskill++;
											energy--;
											finishchoose=true;
											break;
										default:{
											finishchoose=true;
											break;
										}
									} 
								}else{
									cout<<endl<<"已學習過技能或是經驗/金錢不足!"<<endl;
								}break;
							case '4':
                            	if(level>=8&&coin>=800&&getskill[3]==false){
                            		cout<<endl<<"確定學習技能"<<skill[3]<<"嗎? 將花費800$"<<endl<<"1:確定"<<endl<<"2:取消";
									key = getch();
									switch (key) {
										case '1':
											coin-=800;
											getskill[3]=true;
											cout<<endl<<"已學成技能"<<skill[3]<<"!"; 
											learnskill++;
											energy--;
											finishchoose=true;
											break;
										default:{
											finishchoose=true;
											break;
										}
									} 
								}else{
									cout<<endl<<"已學習過技能或是經驗/金錢不足!"<<endl;
								}break;
                   		}}while(finishchoose==false);
                   		break;
					//抽武器 
					case'4':
						cout<<endl;
						lotterycoin=level*100;
						for(int i=0;i<24;i++){
							cout<<lottery[i];
							Sleep(30);
						}
						cout<<lotterycoin<<endl<<"1.抽獎 2.十連抽 3.取消";
						do{
						key = getch();
						switch(key){
							case'1':
								if(coin>=lotterycoin){
									coin-=lotterycoin; 
									lotterynum=rand()%(level*10)+1;
									for(int i=0;i<14;i++){
										cout<<prize[i];
										Sleep(30);
									}
									if(lotterynum>=100){
										cout<<"一顆番茄";
										if(getweapon[6]){
											cout<<endl<<"已擁有此武器 返還金幣10$"<<endl;
											coin+=10;
										}else
										getweapon[6]=true;
									}else if(lotterynum>=80){
										cout<<"獅心劍";
										if(getweapon[5]){
											cout<<endl<<"已擁有此武器 返還金幣10$"<<endl;
											coin+=10;
										}else
										getweapon[5]=true;
									}else if(lotterynum>=60){
										cout<<"不滅之劍";
										if(getweapon[4]){
											cout<<endl<<"已擁有此武器 返還金幣10$"<<endl;
											coin+=10;
										}else
										getweapon[4]=true;
									}else if(lotterynum>=40){
										cout<<"戰神之刃";
										if(getweapon[3]){
											cout<<endl<<"已擁有此武器 返還金幣10$"<<endl;
											coin+=10;
										}else
										getweapon[3]=true;
									}else if(lotterynum>=20){
										cout<<"銀影之劍";
										if(getweapon[2]){
											cout<<endl<<"已擁有此武器 返還金幣10$"<<endl;
											coin+=10;
										}else
										getweapon[2]=true;
									}else{
										cout<<"勇者之劍";
										if(getweapon[1]){
											cout<<endl<<"已擁有此武器 返還金幣10$"<<endl;
											coin+=10;
										}else
										getweapon[1]=true;
									}
									finishlottery=true;
								}else{
									cout<<endl<<"金幣不足!"<<endl;
								}
								break;
							case'2':
								if(coin>=lotterycoin*10){	
									cout<<endl;
									for(int i=0;i<10;i++){
										coin-=lotterycoin; 
										lotterynum=rand()%(level*10)+1;
										for(int i=0;i<14;i++){
											cout<<prize[i];
											Sleep(30);
										}
										if(lotterynum>=100){
											cout<<"一顆番茄(傳說)";
											if(getweapon[6]){
											cout<<endl<<"已擁有此武器 返還金幣10$";
											coin+=10;
										}else
											getweapon[6]=true;
											}else if(lotterynum>=80){
											cout<<"獅心劍";
											if(getweapon[5]){
											cout<<endl<<"已擁有此武器 返還金幣10$";
											coin+=10;
											}else
											getweapon[5]=true;
										}else if(lotterynum>=60){
											cout<<"不滅之劍";
											if(getweapon[4]){
											cout<<endl<<"已擁有此武器 返還金幣10$";
											coin+=10;
											}else
											getweapon[4]=true;
										}else if(lotterynum>=40){
											cout<<"戰神之刃";
											if(getweapon[3]){
											cout<<endl<<"已擁有此武器 返還金幣10$";
											coin+=10;
											}else
											getweapon[3]=true;
										}else if(lotterynum>=20){
											cout<<"銀影之劍";
											if(getweapon[2]){
											cout<<endl<<"已擁有此武器 返還金幣10$";
											coin+=10;
											}else
											getweapon[2]=true;
										}else{
											cout<<"勇者之劍";
											if(getweapon[1]){
											cout<<endl<<"已擁有此武器 返還金幣10$";
											coin+=10;
											}else
											getweapon[1]=true;
										}
										finishlottery=true;
										cout<<endl;
									}
								}else{
									cout<<endl<<"金幣不足!"<<endl;
									finishlottery=true;
									break;
								}
							case'3':
								finishlottery=true;
								break;
							default:{
								cout<<"輸入錯誤指令!";
								break;
							}
						}
					}while(finishlottery==false);
					break;
					case'5':
						finishchoose=false;
						cout<<"目前擁有裝備:";
						for(int i=0;i<7;i++){
							if(getweapon[i])cout<<i+1<<":"<<weapon[i]<<" ";
							Sleep(15);
						}
						cout<<endl;
						do{
							for(int i=0;i<19;i++){
								cout<<chooseweapon[i];
								Sleep(30);
							}cout<<endl<<"按下其他鍵取消"<<endl;
							key = getch();
							switch(key){
								case'1':
									cout<<"已裝備武器:"<<weapon[0];
									wear=0;
									break;
								case'2':
									if(getweapon[1]){
										cout<<"已裝備武器:"<<weapon[1];
										wear=1;
										break; 
									}else{
										break;
									}
								case'3':
									if(getweapon[2]){
										cout<<"已裝備武器:"<<weapon[2];
										wear=2;
										break; 
									}else{
										break;
									}
								case'4':
									if(getweapon[3]){
										cout<<"已裝備武器:"<<weapon[3];
										wear=3;
										break; 
									}else{
										break;
									}
								case'5':
									if(getweapon[4]){
										cout<<"已裝備武器:"<<weapon[4];
										wear=4;
										break; 
									}else{
										break;
									}
								case'6':
									if(getweapon[5]){
										cout<<"已裝備武器:"<<weapon[5];
										wear=5;
										break; 
									}else{
										break;
									}
								case'7':
									if(getweapon[6]){
										cout<<"已裝備武器:"<<weapon[6];
										wear=6;
										break; 
									}else{
										break;
									}
								default:
									finishchoose=true;
								}
							}while(finishchoose=false);
							break;					
					case'6':
					for(int i=0;i<5;i++){
						cout<<"z";
						Sleep(500);
					}
					cout<<endl;
					rest=true;
					break;
					default:cout<<"輸入錯誤指令"<<endl;continue;
				}
				
			} 
		surviveday++;
	}while(1);
}

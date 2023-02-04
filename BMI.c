#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
struct my_msg{
		float height;//身高
		float weight;//体重
	};
struct result{
	//记录结果
	char* resultMsg;
	float sum;
};
struct my_msg m;
struct result re;
int main(){
	int flag=1;
	int hit=1;
	int start_flag=2;//开始flag
	puts("************************************************************");
	puts("Welcome to Sun Zhenhuan's BMI program");
	puts("************************************************************");
	puts("");
	puts("Wait a minute.......");
	Sleep(3000);
	puts("Please enter your height(m)");
	
	scanf("%f",&m.height);
	
	puts("Please enter your weight(kg)");
	
	scanf("%f",&m.weight);
	
	//resultMsg
	re.sum=m.weight/pow(m.height,2);
	//成年人BMI的正常值在18.5-23.9kg/㎡之间，
	//如果BMI低于18.5kg/㎡，属于体重过轻，
	//BMI达到24-27kg/㎡属于体重超重，
	//BMI在28-32kg/㎡之间属于肥胖。
	//如果BMI超过32kg/㎡，就是过度肥胖
	while(flag){
		if(start_flag==2){
			puts("===============================================");
			puts("Please select the action you want to perform first!\n(Press 1 to start calculation and 0 to exit program)");
			puts("===============================================)");
			scanf("%d",&start_flag);
		}
		else{
			if(start_flag==1){
				puts("");
				puts("");
				puts("");
				puts("=============================Start calculating BMI===============================");
				if(hit==0){
					puts("=======================");
					puts("Let's start counting again!");
					puts("=======================");
				}
				if(re.sum<18.5f){
					printf("Young man, your weight is abnormal. Eat moreBMI===%.2f\n",re.sum);
					hit=0;
				}	
				else{
					if(re.sum<=23.8f){
						printf("Congratulations! Your weight is within the normal rangeBMI===%.2f\n",re.sum);
					}
					else{
						if(re.sum<=23.9f){
							printf("You are very close to being overweightBMI===%.2f\n",re.sum);
							hit=0;
						}
						else{
							if(re.sum<=27.0f){
								printf("You are already overweight! Please take care to exercise properlyBMI====%.2f\n",re.sum);
								hit=0;
							}	
							else if(re.sum<=32.0f){
								printf("Your weight is already obese.\nIf you want to keep a good figure\nplease pay attention to losing weightBMI===%.2f\n",re.sum);
								hit=0;
							}	
							else{
								printf("You are now obese! You should lose weight right away or you might get sickBMI===%.2f\n",re.sum);
								puts("Such as the following diseases---------");
								puts("The case of overweight will cause a series of diseases \n common diseases have heart failure \n high blood pressure \n so the need for active weight control \n in diet should be low protein \n low fat diet \n and appropriate exercise \n For overweight people, from the way of life intervention \n also should carry out diet control \n at the same time to combine eating appropriate exercise \n");
								puts("Suggestions are as follows-------------");
								puts("It is recommended to develop good dietary hygiene habits at ordinary times, n eat more vegetables and fruits, supplement vitamins, improve immunity, n appropriate daily exercise, work and rest, enhance resistance.");
								hit=0;
							}
						}
					}
				}
				flag=0;
				puts("Do you want to continue? Press 1 to continue and 0 to exit");
				scanf("%d",&flag);
				if(flag==1){
					start_flag=2;//重新开始!
					continue;
				}
				else if(flag==0){
						exit(0);
						break;
				}
				else{
					puts("You didn't press a 1 or a 0!");
					Sleep(1000);
					exit(0);
				}
			}
			else{
				//为零
				int mill=0;
				while(1){
					if(mill==2){
						puts("About to quit!");
						flag=0;
						Sleep(1000);
						exit(0);
						break;
					}
					Sleep(1000);//一秒mill+1
					mill++;
				}
			}
		}	
	}
	system("pause");
    return 0;
}

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

using namespace std;
int main()
{


			system("echo 210000 > /sys/devices/ocp.2/pwm_test_P9_16.15/duty");
			system("echo 500000 > /sys/devices/ocp.2/pwm_test_P9_14.14/duty");
//	cout << "led flash start" << endl;
	//FILE *LedHandle = NULL;
	//char *Led_duty_cycle = "/sys/devices/ocp.2/pwm_test_P9_14.14/duty";
		for (;;)
		{ /*LedHandle = fopen(Led_duty_cycle,"r+");
			if(LedHandle!=NULL)
			{ fwrite("250000",sizeof(char),1,LedHandle) ;
				fclose(LedHandle) ;
			}*/
			system("echo 500000 > /sys/devices/ocp.2/pwm_test_P9_14.14/duty");
			sleep(3);
			system("echo 250000 > /sys/devices/ocp.2/pwm_test_P9_14.14/duty");
			/*LedHandle = fopen(Led_duty_cycle,"r+")
			if (LedHandle!=NULL)
			{ fwrite("500000",sizeof(char),1,LedHandle) ;
				fclose(LedHandle) ;
			}*/
			sleep(3);
		}
	// cout << "led flash ended" << endl;
	return 0;
}

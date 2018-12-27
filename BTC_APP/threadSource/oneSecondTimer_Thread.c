#include "api.h"
#include "globalParams.h"
#include "sensor.h"

bool oledUserFlag = false;	// �Զ��� OLED �����Ƿ�ʹ�ñ�־λ
bool oledSwitchFlag = false;	// �Զ��� OLED ���û������л���־λ
bool sensorTxDataFlag = false; // ���� Sensor ���ݱ�־λ
bool startSWTmr = false; // ��ʼ���㰴��չʾʱ��
int oledUserTimer = 0;		// չʾ�û�����ʱ��
int sensorPeriodTmr = 55; // ��һ�������Ϸ����� 5 S ���ʹ�������Ϣ
int connectTmr = 0; // ���ӷ�������ʱ������Ӧ��գ�����Ӧ +1

// �����л���ʱ�¼�
void keyHandle_OLED()
{
	if(startSWTmr == true)
	{
		swTimer ++;
	}
	if(swTimer == 3)
	{
		startSWTmr = false;
		swTimer = 0;
		OLED_Welcome();	
	}				
}
// OLED �Զ������û������л��¼�
void userDefChange_OLED()
{
	if(oledUserFlag == true)
	{
		oledUserTimer++;
		if(oledUserTimer % 5 == 0)
		{
			oledUserTimer = 0;
			if(oledSwitchFlag == false)
			{
				OLED_Welcome();
				oledSwitchFlag = true;
			}
			else
			{
				showUserDEF();
				oledSwitchFlag = false;
			}
		}
	}	
}
// ���ʹ��������ݼ�ʱ�¼�
void sendSensorDataTmr()
{
	sensorPeriodTmr ++;
//	printf("sensorTmr = %d\n\r",sensorPeriodTmr);
	if(sensorPeriodTmr % 60 == 0)
	{
		sensorTxDataFlag = true;
		sensorPeriodTmr = 0;
	}	
}
// �����쳣��ʱ�¼�
void connectTmr_Exp()
{			
	connectTmr++;
	if(connectTmr % 60 == 0)
	{
		expEvent.connectErrorFlag = true;
	}	
}

void oneSecondTimer_thread(void *arg){
	LWIP_UNUSED_ARG(arg);	
	while(1){
		if(ConnectAuthorizationFlag)
		{
			keyHandle_OLED();
			sendSensorDataTmr();
			userDefChange_OLED();
			connectTmr_Exp();
		}
		vTaskDelay(1000);	
	}	
}

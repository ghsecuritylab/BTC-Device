#include "ip_addr.h"
#include "cJSON.h"
#define SOCKET_OUT_BUFFER_SIZE 256
#define SOCKET_IN_BUFFER_SIZE (4096+256)


typedef struct _SocketInfo {
    char inBuffer[SOCKET_IN_BUFFER_SIZE];
    char outBuffer[SOCKET_OUT_BUFFER_SIZE];
} SocketInfo;

typedef struct _OTAInfo {
	  int blockOffset;      
		int blockSize;        
		int versionSize;      
		int checkSum ;
		char versionSN[33];   
} OTAInfo;


typedef struct _BTCInfo {
		int deviceRegister;
		int deviceID;
		int userID;
		int apiId;
		int deviceStatus;
		int module;
		int configBuffer[10];
		char msgId[10]; 	
		char placeholder [10]; // ռλ��
		char oledOneLine[20];
		char oledSecondLine[20];
		char oledThirdLine[20];
	  char oledForthLine[20];
		char mac[12];	

} BTCInfo;

typedef struct _EventFlag {
    bool heatbeatFlag;
    bool getLatestFWFromServerFlag; 
	  bool firstConnectFlag ; 
		bool downLoadFinshFWFromServerFlag;

} SystemEventHandle;

extern BTCInfo btcInfo;
extern char versionSN [33];
extern int respCode;
extern OTAInfo otaInfo;
extern SystemEventHandle eventHandle;
extern char tempBuffer[256];
extern SocketInfo socketInfo;
extern struct netconn *tcpsocket;
extern ip_addr_t server_ipaddr;

extern bool server_connect_Flag;
extern volatile bool ConnectAuthorizationFlag;
/***************/
extern float x, y, z;//���ٶ�
extern int UVA_data, UVB_data;
extern int lx;//�����ȼ�
extern uint32_t persure;
extern float temp, hum;
extern int light_res;
extern int red, green, blue;

extern bool oledUserFlag;   // oled �û�ʹ���Զ���
extern bool oledSwitchFlag; // oled �û��Զ���������ʼ�����л�
extern int oledUserTimer; // oled �û�ʹ�����Զ�����濪ʼ��ʱ

extern bool sensorTxDataFlag; // Sensor �������ͱ�־λ


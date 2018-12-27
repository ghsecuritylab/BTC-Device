#include "ip_addr.h"
#include "cJSON.h"
#define SOCKET_OUT_BUFFER_SIZE 256
#define SOCKET_IN_BUFFER_SIZE (4096+256)
typedef struct _ExpEvent {
	bool connectErrorFlag;
} ExpEvent;

typedef struct _SocketInfo {
    char inBuffer[SOCKET_IN_BUFFER_SIZE];   // Socket ͨѶ���� Buffer
    char outBuffer[SOCKET_OUT_BUFFER_SIZE]; // Socket ͨѶ���� Buffer
} SocketInfo;

typedef struct _OTAInfo {
	  int blockOffset;  // ����ķְ���ĵ�����ƫ����
		int blockSize;   // ����ķְ���ĵ������ļ���С     
		int versionSize; // ����İ汾�ļ���С     
		int checkSum ; // OTA CRC16 У��ֵ
		char versionSN[33];   // OTA MD5 У��ֵ
} OTAInfo;


typedef struct _BTCInfo {
		int deviceRegister; // �豸�Ƿ�ע�ᣬ1 ע�ᣬ0 Ϊע��
		int deviceID; // �豸 ID
		int userID; // �û� ID
		int apiId; // ����������� API ID
		int deviceStatus; // �豸״̬����Ϊ 10 ��ʾ OTA ���������Ϊ 11 OTA ����ʧ��
		int module; // �����������ģ����
		int configBuffer[10]; // ����������� API Config ����
		char msgId[10]; 	// ����������Ϣ��־λ
		char placeholder [10]; // ռλ��
		char oledOneLine[20]; // oled ����һ�е�����
		char oledSecondLine[20]; // oled ���ڶ��е�����
		char oledThirdLine[20]; // oled �������е�����
	  char oledForthLine[20]; // oled �������е�����
		char mac[12];	// �豸 MAC ��ַ��� Buffer

} BTCInfo;

typedef struct _EventFlag {
    bool getLatestFWFromServerFlag; // �ӷ�������ʼ��ȡָ�����豸�̼���־λ

} SystemEventHandle;

extern BTCInfo btcInfo; // �������豸��׼��Ϣ
extern char versionSN [33]; // md5 У���ֵ
extern int respCode; // ����������Ӧ����
extern OTAInfo otaInfo; //OTA �ṹ��
extern SystemEventHandle eventHandle; // �����¼�����ṹ��
extern char tempBuffer[256]; // ota �����汾��Ϣʹ�õ� Buffer
extern SocketInfo socketInfo; // Socket �ṹ��
extern struct netconn *tcpsocket; // Socket �׽���
extern ip_addr_t server_ipaddr; //  �������� IP ��ַ
extern bool server_connect_Flag; // �����Ƿ�������
extern volatile bool ConnectAuthorizationFlag; // �û��Ƿ��÷���������֤ͨ��
extern float x, y, z;//���ٶȴ������ɼ���ֵ
extern int UVA_data, UVB_data; // �����ߴ������ɼ���ֵ
extern int lx;// ��ǿ�������ɼ���ֵ
extern uint32_t persure; // ��ѹ�Ʋɼ���ֵ
extern float temp, hum; //  ��ʪ�ȴ������ɼ���ֵ
extern int light_res; // �������� ADC �ɼ���ֵ
extern int red, green, blue; // rgb �Ʋ���
extern bool oledUserFlag;   // oled �û�ʹ���Զ���
extern bool oledSwitchFlag; // oled �û��Զ���������ʼ�����л�
extern int oledUserTimer; // oled �û�ʹ�����Զ�����濪ʼ��ʱ
extern bool sensorTxDataFlag; // Sensor �������ͱ�־λ
extern bool sw1PressBtn; // SW1 ���±�־λ
extern bool sw2PressBtn; // SW2 ���±�־λ
extern int sw1Status; // SW1 ״̬
extern int sw2Status; // SW2 ״̬
extern int swTimer; // ��������չʾʱ��
extern bool startSWTmr; // ��ʼ����չʾʱ���ʱ��־λ 
extern ExpEvent expEvent; // �쳣����ṹ������
extern int connectTmr; // ���ӷ�������ʱ������Ӧ��գ�����Ӧ +1

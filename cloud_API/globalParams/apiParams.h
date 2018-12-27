// �豸��һ���������ӣ��ж��豸�Ƿ�ע�ᣬ���Ƿ�ͨ��������У��
#define API_AUTH_Sendpack "{\"apiId\":%d,\"versionSN\":\"%s\",\"mac\":\"%02x%02x%02x%02x%02x%02x\",\"userId\":%d,\"deviceId\":%d}"		//cloud api
// �豸�����������������
#define API_Heartpack_Sendpack "{\"apiId\":%d}"
// �豸���ʹ���������
#define API_SenSorData_Sendpack "{\"apiId\":%d,\"userId\":%d,\"deviceId\":%d,\"sensorData\":{\"temp\":%d,\"humidity\":%d,\"lightRes\":%d,\"uva\":%d,\"uvb\":%d,\"luxInt\":%d}}"
// �豸���������Ӧ�Ƿ�ɹ����յ��豸��Ϣ����Ϣ
#define API_SendData_Response "{\"apiId\":%d,\"respCode\":%d,\"msgId\":\"%s\"}"
// �豸���Ͱ���״̬
#define API_SendKeyData_Sendpack "{\"apiId\":%d,\"userId\":%d,\"deviceId\":%d,\"key\":{\"first\":%d,\"second\":%d}}"
// �豸�����������ְ���ĵ��Ǹ�������Ϣ
#define NOTIFY_REQ_updateVersion     "{\"apiId\":%d,\"versionSN\":\"%s\",\"blockOffset\":%d,\"blockSize\":%d}"
// �豸���������Ӧ�Ƿ���յ��˷������İ汾������Ϣ
#define CMD_RESP_otaUpdate           "{\"msgId\":\"%s\",\"apiId\":%d,\"respCode\":%d}"
// �豸����������� OTA �����Ƿ���ɵ���Ϣ�� deviceStatus : 10 ���������11 ����ʧ��
#define	NOTIFY_REQ_otaDeviceStatus	 "{\"apiId\":%d,\"deviceStatus\":%d}"	


#define ERR_Code 1	// ������δ֪����
#define ERR_Connect 2	// ���ӳ���
#define ERR_Packet 3	// ������
#define ERR_Device 4	// �豸����
#define ERR_Server 5	// ����������
#define ERR_Success 100  // �ɹ���־λ

//  Device �������ݵ� API ID
enum API_SEND
{
	API_SEND_AUTH = 1U,
	API_SEND_Heartpack,
	API_SEND_DATA,
	API_SEND_OTA,
};
// Device �������ݵ���Ӧ API ID
enum API_RES
{
    API_RES_AUTH = 1U, 
		API_RES_Heartpack,  
		API_RES_SendData,	              	 
	  API_RES_OTA,
		API_RES_SERVER_SEND, 
		
};
enum API_module
{

    API_module_pwm = 2U,     // ����������� PWM Moudle
    API_module_rgb = 3U,     // ����������� RGB Moudle
    API_module_oled = 4U,    // ����������� OLED Moudle
		API_module_ota = 100U,   // ����������� OTA Moudle

};



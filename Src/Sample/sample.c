#include "sample.h"
#include "variable.h"
#include "string.h"
#include "function.h"
#include "RS485/bsp_usartx_RS485.h"
#include "crc16.h"
#include <ctype.h>


/**
  * 函数功能: 将str字符以spl分割,存于dst中，并返回
  * 输入参数: 目标字符串 dst，源字符串 str 分割字符串 spl 
  * 返 回 值: 子字符串数量
  * 说    明：无
  */ 
int split(char dst[][80], char* str, const char* spl)
{
    int n = 0;
    char *result = NULL;
    result = strtok(str, spl);
    
    while( result != NULL )
    {
        strcpy(dst[n++], result);
        result = strtok(NULL, spl);
    }
    return n;
}

/**
  * 函数功能: 将十六进制的字符串转换成整数 
  * 输入参数: 十六进制字节组s 
  * 返 回 值: 转换结果 
  * 说    明：无
  */ 
 
int htoi(char s[])  
{  
    int i;  
    int n = 0;  
    if (s[0] == '0' && (s[1]=='x' || s[1]=='X'))  
    {  
        i = 2;  
    }  
    else  
    {  
        i = 0;  
    }  
    for (; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z');++i)  
    {  
        if (tolower(s[i]) > '9')  
        {  
            n = 16 * n + (10 + tolower(s[i]) - 'a');  
        }  
        else  
        {  
            n = 16 * n + (tolower(s[i]) - '0');  
        }  
    }  
    return n;  
} 
/**
  * 函数功能: 采集数据
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：采集数据，error次数包括超出正常范围和传感器接收数据失败，循环采集所以配置的传感器
  */
void Sample_RS485(void)
{
  char dst[20][80];
  int n,i,j,e;
  int cnt;
  unsigned char command[50] = {0};
  Sensor *p;
  uint8_t len;
 
  
  for(i=0;i<5;i++){
    //有传感器
   // if(sensor_array[i].num > 0){
    p = sensor_array[i].frist_node;
    for(j=0;j<sensor_array[i].num;j++){
        printf("\ncollection cmd:%s\n",p->command);

        if(strlen(p->command)>0){
            strcpy(command,p->command);
            cnt = split(dst,command, ".");
            for (e = 0; e < cnt; e++){
                n = htoi(dst[e]);
               // Bit.i = n;
                command[e] = (char)n;
            }
             RS485_Send_Data(command,cnt);
             printf("\nSend num:%d\n ",cnt);
             RS485_Receive_Data(&len);
             if(len > 0){
              //处理数据
                Modbusprocess(RS485_Rx_buf,p,sensor_array[i].type);
             }
             else{
                p->error++;
             }
        
        }//if
        p = p->next; 
    }//for
    //采集结束
  }//for
}




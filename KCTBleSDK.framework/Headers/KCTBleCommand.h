//
//  KCTBleCommand.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/9/15.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, KCTBleCMD) {
    // 设置命令 0X02
    KCTBleCMD_setIngTime = 1,        //!< 时间设置 0X20
    KCTBleCMD_setAlarmClock,     //!< 闹钟设置 0x21
    KCTBleCMD_setSportTarget,    //!< 运动目标设置 0x22
    KCTBleCMD_setUserInfo,       //!< 用户信息设置 0x23
    KCTBleCMD_setTheLost,        //!< 防丢设置 0x24
    KCTBleCMD_setSedentary,      //!< 久坐设置 0x25
    KCTBleCMD_setSleep,          //!< 自动睡眠设置 0x26
    KCTBleCMD_setSystemUser,     //!< 系统用户设置 0x27
    KCTBleCMD_setDrinkRemind,    //!< 喝水提醒设置 0x28
    KCTBleCMD_setPush,           //!< 推送设置 0x29
    KCTBleCMD_readBraceletSet,   //!< 读取手环设置请求 0x2D
    KCTBleCMD_readProfile,       //!< 读取手环配置请求 0x2E
    KCTBleCMD_sleepStartStopTime,//!< 睡眠开始结束时间 0x31
    // 天气命令 0x03
    KCTBleCMD_weatherPush,       //!< 天气推送 key 0x30
    KCTBleCMD_ultravioletPush,   //!< 紫外线推送 key 0x31
    KCTBleCMD_airPressurePush,   //!< 气压推送 key 0x33
    KCTBleCMD_altitudePush,      //!< 海拔推送 key 0x35
    
    // 设备命令 0X04
    KCTBleCMD_requestBattery,    //!< 设备电量请求 0x40
    KCTBleCMD_batteryBack,       //!< 设备电量返回 0x41
    KCTBleCMD_unbundledDevice,   //!< 解除绑定命令 0x42
    KCTBleCMD_unbundledReply,    //!< 解除绑定回应 0x43
    KCTBleCMD_bindingReply,      //!< 设备绑定回应 0x45
    KCTBleCMD_relationDisplay,   //!< 横竖显示 0x49
    KCTBleCMD_gesturesControl,   //!< 抬手亮屏 0x4A
    KCTBleCMD_bindingDevice,     //!< 绑定请求 0X44
    KCTBleCMD_cameraSwitch,      //!< 拍照开关 0X46
    KCTBleCMD_cameraON,          //!< 拍照 0X47
    KCTBleCMD_cameraOFF,         //!< 退出拍照 0X48
    KCTBleCMD_syncContact,       //!< 同步联系人 0X4B
    KCTBleCMD_inputStart,        //!< 协助输入开始 0X4D
    KCTBleCMD_inputSend,         //!< 发送协助输入 0X16
    KCTBleCMD_shearPlate,        //!< 发送剪切板数据 0X17
    KCTBleCMD_inputEnd,          //!< 协助输入结束 0X18
    KCTBleCMD_dialPush,          //!< 表盘推送 0X4E
    KCTBleCMD_dialData,          //!< 表盘数据 0X4F
    KCTBleCMD_urgentDial,        //!< 紧急拨号 0X15
    KCTBleCMD_watchWifi,         //!< 手表WIFI 0X4C
    KCTBleCMD_wifiList,          //!< 获取WIFI列表 0x19
    KCTBleCMD_wifiPassWord,      //!< WIFI需要密码 0x1A
    KCTBleCMD_wifiLink,          //!< 已保存的WIFI 0X1B
    KCTBleCMD_wifiNoPassWord,    //!< WIFI无需密码 0X1C
    
    // 查找命令 0X05
    KCTBleCMD_findPhone,         //!< 查找手机 0X51
    KCTBleCMD_findDevice,        //!< 查找设备 0X50
    
    // 运动数据命令 0X07
    KCTBleCMD_sportQequest,      //!< 运动数据请求 0X70
    KCTBleCMD_stepBack,          //!< 计步数据返回 0X71
    KCTBleCMD_hearSpeedBack,     //!< 心率、速度、步频数据返回 0X72
    KCTBleCMD_paceBack,          //!< 配速数据返回 0X73
    KCTBleCMD_trackBack,         //!< 轨迹数据返回 0X74
    
    // 健康数据 0x0A
    KCTBleCMD_syncHealth,        //!< 同步健康数据指令 0xA0
    KCTBleCMD_syncBack,          //!< 同步健康返回 0xA1
    KCTBleCMD_sleepData,         //!< 睡眠数据 0xA2   //新协议修改
    KCTBleCMD_HeartData,         //!< 心率数据 0xA4
    KCTBleCMD_stepData,          //!< 计步数据 0xA3
    KCTBleCMD_realTimesync,      //!< 同步实时数据 0xA6
    KCTBleCMD_realStep,          //!< 实时计步数据 0xAC
    KCTBleCMD_realHeartData,     //!< 实时心率数据 0xAB
    KCTBleCMD_bloodPressure,     //!< 血压数据返回 0xAD
    KCTBleCMD_bloodOxygen,       //!< 血氧数据返回 0xAE
    KCTBleCMD_realBloodPressure, //!< 实时血压数据返回 0xB1
    KCTBleCMD_realBloodOxygen,   //!< 实时血氧数据返回 0xB2
    KCTBleCMD_sportStateToDevice, //!< 运动状态同步到设备 0xB3
    KCTBleCMD_sportStateToIphone,   //!< 运动状态同步到手机 0xB4
    
    // 固件升级 0x01
    KCTBleCMD_firmwareUpdate,    //!< 固件升级启动 0x10
    KCTBleCMD_firmwareVersion,   //!< 固件版本信息 0x12
    
    // 提醒命令 0x06
    KCTBleCMD_remindSwitch,      //!< 提醒开关 0x60
    KCTBleCMD_messageRemind,     //!< 短信提醒 0x61
    KCTBleCMD_QQRemind,          //!< QQ提醒 0x62
    KCTBleCMD_WeChatRemind,      //!< 微信提醒 0x63
    KCTBleCMD_notDisturb,        //!< 勿扰模式 0x64
    KCTBleCMD_remindModel,       //!< 提醒模式 0x65
    KCTBleCMD_messageSync,       //!< 配置信息同步 0x66
    
    // 睡眠命令 0x08
    KCTBleCMD_getSleepData,      //!< 睡眠数据请求 0x80
    KCTBleCMD_sleepDataBack,     //!< 睡眠数据返回 0x81
    
    // 校准命令 0x0B
    KCTBleCMD_checkDaySport,     //!< 当天运动校准 0x0B
    
    // 心率命令 0x09
    KCTBleCMD_heartRateCheck,    //!< 心率检测 0x92
    
    // 推送命令 0x0E
    KCTBleCMD_qrCodePush,        //!< 二维码推送 0xE0
    KCTBleCMD_weatherIndex,      //!< 气象指数推送 0xE1
    KCTBleCMD_unitSetting,       //!< 单位设置 0x01
    
    // 工厂命令 0x0C
    KCTBleCMD_restoreFactory,    //!< 恢复出厂 0xC7(协议中定义为重启，但部分设备以此作为恢复出厂设置)
    KCTBleCMD_reset,              //!< 重置 0xCC
    
    // 发送FLASH数据命令 0x13
    KCTBleCMD_flashStart,       //!< 开始数据指令 0x01
    KCTBleCMD_flashSendData,    //!< 发送数据 0x03
    KCTBleCMD_flashVersion,    //!< 查询FLASH数据版本号 0x05
    
    // 车辆命令 0x14
    KCTBleCMD_carKeyDetail       //!< 手机返回车钥匙详情 0x02
 
};

@interface KCTBleCommand : NSObject
+ (instancetype)shareInstance;
+ (NSDictionary *)dataFromCmd:(KCTBleCMD)cmd;

@end

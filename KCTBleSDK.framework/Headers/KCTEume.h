//
//  KCTEume.h
//  KCTFunFit
//
//  Created by mac on 17/5/17.
//  Copyright © 2017年 KCT. All rights reserved.
//

#ifndef KCTEume_h
#define KCTEume_h

/**
 所有平台设备功能枚举
 */
typedef NS_ENUM(NSInteger, KCTFunctionType) {
    KCTFunctionType_dialPush,         //!< 表盘推送
    KCTFunctionType_connection,       //!< 连接设备
    KCTFunctionType_cameraSwitch,     //!< 拍照开关
    KCTFunctionType_APPNotice,        //!< 应用通知开关设置(微信,QQ)
    KCTFunctionType_inputSend,        //!< 协助输入
    KCTFunctionType_findDevice,       //!< 查找设备
    KCTFunctionType_switchSkin,       //!< 切换皮肤
    KCTFunctionType_syncContact,      //!< 同步联系人
    KCTFunctionType_urgentDial,       //!< 紧急拨号
    KCTFunctionType_callNotify,       //!< 来电通知开关
    KCTFunctionType_SMSNotify,        //!< 短信通知开关
    KCTFunctionType_QQNotify,         //!< QQ通知开关
    KCTFunctionType_WeChatNotify,     //!< 微信通知开关
    KCTFunctionType_WhatsAppNotify,   //!< whatsapp通知开关
    KCTFunctionType_MessengerNotify,  //!< Messenger通知开关
    KCTFunctionType_TwitterNotify,    //!< Twitter通知开关
    KCTFunctionType_LinkedinNotify,   //!< linkedin通知开关
    KCTFunctionType_InstagramNotify,  //!< Instagram通知开关
    KCTFunctionType_FacebookNotify,   //!< Facebook通知开关
    KCTFunctionType_ALLAppNotify,     //!< 所有应用通知开关
    KCTFunctionType_sedentary,        //!< 久坐提醒
    KCTFunctionType_drinkRemind,      //!< 喝水提醒
    KCTFunctionType_remindModel,      //!< 提醒模式
    KCTFunctionType_alarmClock,       //!< 闹钟提醒
    KCTFunctionType_gesturesControl,  //!< 抬手亮屏
    KCTFunctionType_heartRateMonitor, //!< 心率检测
    KCTFunctionType_qrCodePush,       //!< 二维码推送
    KCTFunctionType_notDisturb,       //!< 勿扰模式
    KCTFunctionType_firmwareUpgrade,  //!< 固件升级
    KCTFunctionType_userHelp,         //!< 用户帮助
    KCTFunctionType_about,            //!< 关于
    KCTFunctionType_blueToothCall,    //!< 蓝牙通话3.0
    KCTFunctionType_appleHealth,      //!< 苹果健康
    KCTFunctionType_WeChatSport,      //!< 微信运动
    KCTFunctionType_bloodPressure,    //!< 血压监测
    KCTFunctionType_bloodOxygen,      //!< 血氧监测
    KCTFunctionType_weatherPush,      //!< 天气推送
    KCTFunctionType_movementPatterns, //!< 运动模式
    KCTFunctionType_unitSetting,      //!< 单位设置
    KCTFunctionType_checkPointer,      //!< 时钟机芯校准
    KCTFunctionType_electronicInvoice, //!< 电子发票
    KCTFunctionType_watchPay,          //!< 手表支付
    KCTFunctionType_receiveQrCode      //!< 收款二维码
};


/**
 所有运动模式
 */
typedef NS_ENUM(NSInteger, KCTSportModeType) {
    KCTSportModeType_walking = 1,           //!< 健走
    KCTSportModeType_runOutdoors,           //!< 户外跑
    KCTSportModeType_runInside,             //!< 室内跑`
    KCTSportModeType_climbing,              //!< 登山
    KCTSportModeType_crossRun,              //!< 越野跑
    KCTSportModeType_halfHorse,             //!< 半马
    KCTSportModeType_marathon,              //!< 全马
    KCTSportModeType_jumpRope,              //!< 跳绳
    KCTSportModeType_badminton,             //!< 羽毛球
    KCTSportModeType_basketball,            //!< 篮球
    KCTSportModeType_cycling,               //!< 骑行
    KCTSportModeType_skating,               //!< 滑冰
    KCTSportModeType_fitness,               //!< 健身房
    KCTSportModeType_yoga,                  //!< 瑜伽
    KCTSportModeType_tennis,                //!< 网球
    KCTSportModeType_pingpong,              //!< 乒乓球
    KCTSportModeType_football,              //!< 足球
    KCTSportModeType_swimming,              //!< 游泳
    KCTSportModeType_sex                    //!< 性爱
};

#endif /* KCTEume_h */

//
//  MtkBleToothEume.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/11/15.
//  Copyright © 2017年 kct. All rights reserved.
//

#ifndef MtkBleToothEume_h
#define MtkBleToothEume_h

typedef NS_ENUM(NSInteger, MtkBleCMD) {
    MtkBleCMD_findDevice,        //!< 查找设备 0X50
    MtkBleCMD_syncHealth,        //!< 同步健康数据指令 0xA0
    MtkBleCMD_sportType,                                          //计步指令
    MtkBleCMD_sleepType,                                          //睡眠指令
    MtkBleCMD_heartType,                                          //心率指令
    MtkBleCMD_bloodPressureType,                                  //血压指令
    MtkBleCMD_bloodOxygenType,                                    //血氧指令
    MtkBleCMD_SendCurrentSport_Type,                              //发送当前计步数据指令
    MtkBleCMD_SendCurrentSleep_Type,                              //发送当前睡眠数据指令
    MtkBleCMD_SendHeartEnd_Type,                                  //发送心率结束指令
    MtkBleCMD_SendBloodPressureEnd_Type,                          //发送血压结束指令
    MtkBleCMD_SendBloodOxygenEnd_Type,                            //发送血氧结束指令
    MtkBleCMD_sportModeData_Type,                                 //发送运动模式数据请求指令
    MtkBleCMD_SendCurrentSportMode_Type,                          //发送当前运动模式下标
    MtkBleCMD_syncPhoneState,                                     //同步手机前后台状态
    MtkBleCMD_findPhoneOff,                                       //关闭找手机
    MtkBleCMD_syncLanguage,                                     //同步语言
    MtkBleCMD_cameraBack,                                           //获取拍照指令 给手表一个返回值
    MtkBleCMD_bindingDevice,     //!< 绑定请求 0X44
    MtkBleCMD_sportQequest,      //!< 运动数据请求 0X70
    MtkBleCMD_realTimesync,      //!< 同步实时数据 0xA6
    MtkBleCMD_cameraSwitch,      //!< 拍照开关 0X46
    MtkBleCMD_setUserInfo,       //!< 用户信息设置 0x23
    // 心率命令 0x09
    MtkBleCMD_heartRateCheck,    //!< 心率检测 0x92
    // 天气命令 0x03
    MtkBleCMD_weatherPush,       //!< 天气推送 key 0x30
    MtkBleCMD_setSedentary,      //!< 久坐设置 0x25
    MtkBleCMD_setDrinkRemind,    //!< 喝水提醒设置 0x28
    MtkBleCMD_weatherIndex,      //!< 气象指数推送 0xE1
    MtkBleCMD_unitSetting,       //!< 单位设置 0x01
    MtkBleCMD_setIngTime,        //!< 时间设置 0X20
    MtkBleCMD_gesturesControl,   //!< 抬手亮屏 0x4A
    MtkBleCMD_emergency_call,    //!< 紧急呼叫
    
    MtkBleCMD_fetchDialInfos,    //!< 获取表盘信息
    MtkBleCMD_pushAnalogDial,    //!< 推送模拟表盘数据
    MtkBleCMD_pushDigitalDial,    //!< 推送数字表盘
    MtkBleCMD_setDigitalDialCoordinage //!< 设置数字表盘坐标
};


#endif /* MtkBleToothEume_h */

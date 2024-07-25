//
//  KCTDataPack.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/9/15.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KCTEume.h"

typedef NS_ENUM(NSInteger, KCTPackType) {
    KCTPackTypeBracelet,            //!< 1458平台(分动手环)
    KCTPackTypeAndroid             //!< 72/80平台(Funfit)
};

@interface KCTDataPack : NSObject

+ (instancetype)shareInstance;
/** 数据打包设备类型 */
@property (nonatomic, assign) KCTPackType packType;

/* 时间设置 */
- (NSData *)setTimePack;
/**
 一个闹钟的数据
 @param hour 小时
 @param minute 分钟
 @param repeat 重复
 @param label 标签
 @param status 开关
 */
- (NSData *)oneAlarmClockData:(NSInteger)hour
                       Minute:(NSInteger)minute
                       Repeat:(NSString *)repeat
                        Label:(NSInteger)label
                       Status:(NSInteger)status;

/**
 闹钟设置
 @param alarmClock 闹钟数据
 */
- (NSData *)alarmClockSettingPack:(NSMutableData *)alarmClock;
/**
 运动目标设置
 @param targetSteps 运动目标步数
 @param sportMode   运动模式 0:计步 1:跑步 2:骑行 3:爬山
 */
- (NSData *)setSportTargetWithTargetSteps:(NSInteger)targetSteps
                                SportMode:(NSInteger)sportMode;
/**
 用户信息设置
 @param gender 性别
 @param age    年龄
 @param height 身高
 @param weight 体重
 @param goal   运动目标
 */
- (NSData *)setUserInfoWithGender:(NSInteger)gender age:(NSInteger)age height:(NSInteger)height weight:(NSInteger)weight Goal:(NSInteger)goal;

/**
 久坐设置
 
 @param ONOFF            0:关闭 1:开启
 @param StartTime        开始时间
 @param endTime          结束时间
 @param cycle            周期
 @param sittingTime      久坐时间
 @param sittingThreshold 久坐阈值
 */
- (NSData *)setSedentaryWithONOFF:(BOOL)ONOFF
                        StartTime:(NSString *)StartTime
                          EndTime:(NSString *)endTime
                            Cycle:(NSString *)cycle
                      SittingTime:(NSString *)sittingTime
                 SittingThreshold:(NSString *)sittingThreshold;

/**
 系统用户设置(key 0x27)
 */
- (NSData *)setSystemUser;
/**
 喝水提醒设置(key 0x28)
 @param ONOFF     喝水使能 0:关 1：开
 @param startTime 开始时间 小时+分钟
 @param endTime   结束时间 小时+分钟
 @param cycle     周期
 @param interval  喝水间隔设置 分钟
 */
- (NSData *)setDrinkRemindWithDrinkONOFF:(BOOL)ONOFF
                               StartTime:(NSString *)startTime
                                 EndTime:(NSString *)endTime
                                   Cycle:(NSString *)cycle
                                Interval:(NSString *)interval;

/**
 推送设置
 
 @param status 当前的推送状态
 */
- (NSData *)setPushWithBleWithStatus:(NSInteger)status;

/**
 读取手环设置请求（key 0x2D)
 */
- (NSData *)readBraceletSet;
/**
 读取手环配置请求（key 0x2E)
 */
- (NSData *)readBraceletProfile;
/**
 设置天气
 @param lowTemperature 低温
 @param highTemperature 高温
 @param weatherType 天气类型
 */
- (NSData *)setWeatherPushWithLowTemperature:(NSInteger)lowTemperature
                             HighTemperature:(NSInteger)highTemperature
                                 WeatherType:(NSInteger)weatherType;
/**
 设置天气  协议版本号60以后使用
 @param lowTemperature 低温
 @param highTemperature 高温
 @param weatherType 天气类型
 @param nowTemperature 天气类型
 */
- (NSData *)setWeatherPushWithLowTemperature:(NSInteger)lowTemperature
                             HighTemperature:(NSInteger)highTemperature
                                 WeatherType:(NSInteger)weatherType
                              nowTemperature:(NSInteger)nowTemperature;

/**
 抬手亮屏显示(key 0x4A)
 
 @param hand  0:左手  1:右手
 @param raise 0:抬手亮屏关闭  1:抬手亮屏开启
 @param flip  0:翻腕亮屏关闭  1:翻腕亮屏开启
 */
- (NSData *)gesturesControlWithHand:(NSInteger)hand
                              Raise:(BOOL)raise
                               Flip:(BOOL)flip;

/**
 绑定请求
 */
- (NSData *)bindingDevice;
/**
 拍照开关(key 0x46) ->手环使用
 
 @param ONOFF 0:相机已关闭 1:相机已打开
 */
- (NSData *)cameraSwitch:(BOOL)ONOFF;
/**
 协助输入开始
 */
- (NSData *)inputStart;
/**
 查找设备
 */
- (NSData *)findDevice;
/**
 勿扰模式（key 0x64）
 @param ONOFF     勿扰使能 1: 开启 0: 关闭
 @param startTime 开始时间
 @param endTime   结束时间
 */
- (NSData *)notDisturbWithONOFF:(BOOL)ONOFF
                      StartTime:(NSString *)startTime
                        EndTime:(NSString *)endTime;

/**
 提醒模式（key 0x65）
 
 @param remindType 提醒方式 1:亮屏 2:震动 3:亮屏+震动
 */
- (NSData *)remindModelWithRemindType:(NSInteger)remindType;
/**
 心率检测设置
 @param ONOFF 开关
 @param startTime 开始时间
 @param endTime 结束时间
 @param interval 间隔时间
 */
- (NSData *)setHeartRateCheckWithRateONOFF:(BOOL)ONOFF
                                 StartTime:(NSString *)startTime
                                   EndTime:(NSString *)endTime
                                  Interval:(NSInteger)interval;
/**
 单位设置
 @param measure 度量单位 （0:公制 1:英制）
 @param temperature 温度 （0: 摄氏度 1:华氏摄氏度）
 */
- (NSData *)unitSettingWithMeasure:(NSInteger)measure
                       temperature:(NSInteger)temperature;
/**
 气象指数推送
 @param UV 紫外线
 @param pressure 气压
 @param altitude 海拔
 */
- (NSData *)weatherIndexWithUV:(NSInteger)UV
                      Pressure:(NSInteger)pressure
                      Altitude:(NSInteger)altitude;
/**
 运动数据请求
 */
- (NSData *)sportQequest;
/**
 获取设备固件版本信息
 */
- (NSData *)firmwareVersion;
/**
 手表WIFI
 */
- (NSData *)watchWifi;
/**
 同步健康数据（key 0xA0）
 
 @param type    1：睡眠，2：心率，3：计步，4：运动模式 (手环使用,72平台传0同步所有) 5:血压 6:血氧
 @param time 传时间戳
 */
- (NSData *)syncHealthType:(NSInteger)type
                      Time:(NSString *)time;
/**
 同步实时数据（key 0xA6）
 
 @param syncType 1：睡眠 2：心率 3：计步 4：运动模式
 */
- (NSData *)realTimesyncWithSyncType:(NSInteger)syncType;

/**
 Nordic平台 固件升级启动
 */
- (NSData *)nordicFirmwareUpdate;
/**
 Dialog平台固件升级启动
 @param fileName 固件包文件路径
 */
- (NSData *)dialogFirmwareUpdate:(NSString *)fileName;

/**
 恢复出厂设置(协议中定义为重启，但部分设备以此作为恢复出厂设置)
 */
- (NSData *)restoreFactory;


/**
 重置设备
 */
-(NSData *)reset;

/**
 蓝牙命令的通用接口
 
 @param CMDID 命令ID
 @param CMDKey 命令Key
 @param Value 参数拼接的字节流（没参传入0）
 */
- (NSData *)UniversalInterfaceWithCMDID:(NSInteger)CMDID
                                 CMDKey:(NSInteger)CMDKey
                                  Value:(NSData *)Value;
/**
 运动状态同步到设备
 
 @param statu 0运动开始，0x01运动结束
 @param Type 运动类型
 */
- (NSData *)sportStateToDeviceWithStatu:(NSInteger)statu AndType:(NSInteger)Type;
/**
    睡眠开始结束时间
 
 @param startHour 睡眠开始时间，小时
 @param startMinute 睡眠开始时间，分钟
 @param startSeconed 睡眠开始时间，秒
 @param stopHour 睡眠结束时间，小时
 @param stopMinute 睡眠结束时间，分钟
 @param stopSeconed 睡眠结束时间，秒
 */
- (NSData *)setSleepStartStopTimeWithStartHour:(NSInteger)startHour
                                   startMinute:(NSInteger)startMinute
                                  startSeconed:(NSInteger)startSeconed
                                     stopHour:(NSInteger)stopHour
                                   stopMinute:(NSInteger)stopMinute
                                   stopSeconed:(NSInteger)stopSeconed;
/**
 查询FLASH数据版本号
 @param type 0: AGPS 1: UI 2:字库 3.其他
 */
-(NSData *)flashVersionWithType:(int)type;
/**
 写入flash数据开始命令
 */
-(NSData *)flashStartWithType:(int)type first:(int)first second:(int)second third:(int)third fourth:(int)fourth;
/**
 flash 数据发送命令
 */
-(NSData *)flashSendDataWithPackCount:(int)count packIndex:(int)index packData:(NSData *)data;
/**
 车钥匙详情
 
 @param version 版本
 @param dataId 数据id
 @param electric 电量
 @param anomaly 异常项
 @param stateSet 状态集
 @param temp 车内温度
 @param time 行驶时间
 @param distance 行驶里程
 @param speed 行驶速度
 */
- (NSData *)keyToCarDetailWithVersion:(int)version dataId:(int)dataId electric:(int)electric anomaly:(int)anomaly stateSet:(int)stateSet temp:(int)temp time:(int)time distance:(int)distance speed:(int)speed;
@end

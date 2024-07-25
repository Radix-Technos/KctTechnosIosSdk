//
//  MtkDataPack.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/11/17.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface MtkDataPack : NSObject
/**
 初始化单例
 */
+ (instancetype)shareInstance;
/**
 实时同步数据
 */
- (NSData *)realTimesync;
/**
 同步健康数据
 */
- (NSData *)syncHealth;
/**
 同步语言
 */
- (NSData *)syncLanguage;
/**
 告诉设备当前app状态
 */
- (NSData *)syncPhoneState;
/**
 查找设备
 */
- (NSData *)findDevice;
/**
 设置时间
 */
- (NSData *)settingTime;
/**
 运动数据请求
 */
- (NSData *)sportQequest;
/**
 获取历史数据
 
 @param type 1. 记步 2.睡眠 3.心率 4.血压 5.血氧
 */
- (NSData *)sportHistoryWithType:(int)type;

/**
 发送总包熟和 当前的包数到手表 请求下一条数据
 
 @param type 1. 记步 2.睡眠 3.心率 4.血压 5.血氧
 @param numIndex 总报数 （仅记步、睡眠需要）
 @param currIndex 当前包 （仅记步、睡眠需要）
 */
- (NSData *)endSportHistoryCommandWithType:(int)type
                               numberIndex:(NSInteger)numIndex
                              currentindex:(NSInteger)currIndex;

/**
 拍照开关(key 0x46) ->手环使用
 @param ONOFF 0:相机已关闭 1:相机已打开
 */
- (NSData *)cameraSwitchWitONOFF:(BOOL)ONOFF;



/**
 设置用户信息
 @param goal 运动目标
 @param sex 性别
 @param height 身高
 @param weight 体重
 */
- (NSData *)setUserInfoWithGoal:(NSString *)goal
                            sex:(NSInteger)sex
                         height:(NSString *)height
                         weight:(NSString *)weight;
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
                                  Interval:(NSString *)interval;
/**
 天气推送
 */
- (NSData *)setWeatherPushWithCity:(NSString *)city
                                    date:(NSString *)date
                          lowTemperature:(NSString *)lowTemperature
                          higTemperature:(NSString *)higTemperature
                            weatherImage:(NSString *)weatherImage
                                   date2:(NSString *)date2
                         lowTemperature2:(NSString *)lowTemperature2
                         higTemperature2:(NSString *)higTemperature2
                           weatherImage2:(NSString *)weatherImage2
                                   date3:(NSString *)date3
                         lowTemperature3:(NSString *)lowTemperature3
                         higTemperature3:(NSString *)higTemperature3
                           weatherImage3:(NSString *)weatherImage3;

/**
 久坐设置
 
 @param ONOFF            0:关闭 1:开启
 @param StartTime        开始时间
 @param endTime          结束时间
 @param cycle            周期
 @param sittingTime      久坐时间
 */
- (NSData *)setSedentaryWithONOFF:(BOOL)ONOFF
                        StartTime:(NSString *)StartTime
                          EndTime:(NSString *)endTime
                            Cycle:(NSString *)cycle
                      SittingTime:(NSString *)sittingTime;
/**
 喝水提醒设置
 
 @param ONOFF     喝水使能 0:关 1：开
 @param startTime 开始时间
 @param endTime   结束时间
 @param interval  喝水间隔设置
 */
- (NSData *)setDrinkRemindWithDrinkONOFF:(BOOL)ONOFF
                               StartTime:(NSString *)startTime
                                 EndTime:(NSString *)endTime
                                Interval:(NSString *)interval;
/**
 气象指数推送
 
 @param UV 紫外线
 @param pressure 气压
 @param altitude 海拔
 @param temp 当前温度
 @param sunrise 日出时间
 @param sunset 日落时间
 @param hum 相对湿度
 */
- (NSData *)weatherIndexWithUV:(NSString *)UV
                      Pressure:(NSString *)pressure
                      Altitude:(NSString *)altitude
                          temp:(NSString *)temp
                       sunrise:(NSString *)sunrise
                        sunset:(NSString *)sunset
                           hum:(NSString *)hum;
/**
 单位设置
 @param measure 度量单位 （0:公制 1:英制）
 @param temperature 温度 （0: 摄氏度 1:华氏摄氏度）
 */
- (NSData *)unitSettingWithMeasure:(NSInteger)measure
                       temperature:(NSInteger)temperature;

/**
 抬手亮屏
 @param raise 0:抬手亮屏关闭  1:抬手亮屏开启
 */
- (NSData *)gesturesControlWithRaise:(BOOL)raise;
/**
 紧急呼叫号码设置
 
 @param numArray 号码数组
 */
- (NSData *)emergency_call:(NSArray *)numArray;



/**
 获取表盘信息
 */
-(NSData *)fetchDialInfos;


/**
推送模拟表盘

 @param index 时钟索引（从1开始，表盘在手表端的id，以此id对表盘进行删除）
 @param type 图片类型，1为预览图片(150x150)，2是时钟底图(240x240)，3为时针，4为分针，5为秒针
 @param packetSum 总包数(传送的data最大为5000字节，过大的图片需要将其拆分为多个包进行传输)
 @param packetIndex 当前数据包索引(从1开始)
 @param data 图片或拆分后的图片数据
 @return 拼接好的数据
 */
-(NSData *)pushAnalogDialWithIndex:(NSInteger)index type:(NSInteger)type packetSum:(NSInteger)packetSum packetIndex:(NSInteger)packetIndex data:(NSData *)data;



/**
 推送数字表盘

 @param index 时钟索引（从1开始，表盘在手表端的id，以此id对表盘进行删除）
 @param type 图片类型，1为预览图片(150x150)，2是时钟底图(240x240)，3-12为数字0-9,13为横排数字表盘的冒号
 @param packetSum 总包数(传送的data最大为5000字节，过大的图片需要将其拆分为多个包进行传输)
 @param packetIndex 当前数据包索引(从1开始)
 @param data 图片或拆分后的图片数据
 @return 拼接好的数据
 */
-(NSData *)pushDigitalDialWithIndex:(NSInteger)index type:(NSInteger)type packetSum:(NSInteger)packetSum packetIndex:(NSInteger)packetIndex data:(NSData *)data;



/**
 设置数字表盘的坐标

 @param index 表盘index
 @param h0Point 小时十位坐标
 @param h1Point 小时个位坐标
 @param m0Point 分钟十位坐标
 @param m1Point 分钟个位坐标
 @param colonPoint 冒号坐标
 @return 拼接好的数据
 */
-(NSData *)setDigitalDialCoordinateWithIndex:(NSInteger)index h0Point:(CGPoint)h0Point h1Point:(CGPoint)h1Point m0Point:(CGPoint)m0Point m1Point:(CGPoint)m1Point colonPoint:(CGPoint)colonPoint;

@end

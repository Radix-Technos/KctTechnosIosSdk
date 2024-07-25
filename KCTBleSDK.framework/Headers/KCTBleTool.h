//
//  KCTBleTool.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/9/15.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KCTEume.h"

@interface KCTBleTool : NSObject
/**
 获取系统当前时区时间数据
 */
+ (NSData *)getCurrenTime;
/**
 获取系统当前语言
 */
+ (NSString *)getCurrentLanguage;

/**
 根据开关类型更新本地开关设置
 
 @param functionType 推送类型
 @param pushSet  推送设置(两个字节按位处理)
 @param isON 开关状态
 @return 更新后的推送设置状态值
 */
+ (NSInteger)getCurrenAPPPushSwitchWithFunctionType:(KCTFunctionType)functionType
                                            pushSet:(NSInteger)pushSet
                                               isON:(BOOL)isON;
/**
 根据类型返回对应位开关状态

 @param functionType 功能类型
 @param status 推送设置状态
 @return 开关状态 0:关闭 1:开启
 */
+ (NSInteger)getAPPPushSwitchWithFunctionType:(KCTFunctionType)functionType
                                       Status:(NSInteger)status;

/**
 *  16进制转10进制数字
 *
 *  @param data data
 *
 *  @return 十进制数据
 */
+ (NSString *)HexToInt:(NSData *)data dataRange:(NSRange)range;
/**
 获取时间戳
 
 @param time 2017-01-01-12-12-12格式的时间
 @return 时间戳字符串
 */
+ (NSString *)getTimestampWithTime:(NSString *)time;
/**
 将时间戳按指定格式时间以及系统时区输出
 
 @param spString  秒
 @param formatStr 指定格式
 
 @return 指定格式时间戳
 */
+ (NSString*)nsdateToTime:(long long)spString formatStr:(NSString *)formatStr;
/**
 分割数据
 
 @param data 数据源
 @return 包含分割后data的数组
 */
+ (NSArray *)sepratorData:(NSData *)data;
/**
 16进账转单精度
 
 @param data 16进制数据
 @param range 范围
 @return 单精度
 */
+ (NSString *)HexToFloat:(NSData *)data dataRange:(NSRange)range;
/**
 *  16进制字符串转10进制数字
 *
 *  @param hexString 16进制字符串
 *
 *  @return 十进制数据
 */
+ (NSString *)intFromHexSrting:(NSString *)hexString;
/**
 将周期int类型转成位字符串（十进制转二进制字符串）
 */
+ (NSString *)cycleIntToString:(int)cycle;
/**
 正序mac地址
 */
+ (NSString *)getPositiveSequenceMacWithData:(NSData *)data;
/**
 16进制转双精度
 
 @param data 16进制数据
 @param range 范围
 @return 双精度
 */
+ (NSString *)HexToDouble:(NSData *)data dataRange:(NSRange)range;
//将NSDate按yyyy-MM-dd HH:mm:ss格式时间输出
+(NSString*)nsdateToString:(NSDate *)date;
/**
 将指定格式时间转NSDate输出
 */
+ (NSDate *)nsdateToformatStr:(NSString *)formatStr;

@end

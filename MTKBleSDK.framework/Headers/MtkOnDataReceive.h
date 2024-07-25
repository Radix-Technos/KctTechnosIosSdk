//
//  MtkOnDataReceive.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/11/15.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MtkBleToothEume.h"
@class CBPeripheral;
@protocol MtkOnDataReceiveDelegate <NSObject>
@optional
/**
 接收数据代理回调
 */
- (void)mtkOnDataReceive:(NSDictionary *)dic;
- (void)deviceHandShakeSuccese;//握手
/**
 获取设备的状态
 @param state 状态标识 连接成功2（握手成功才能同步数据），已经断开连接0。
 */
- (void)mtkConnectedPeripheral:(CBPeripheral *)peripheral connectionState:(int)state;

@end

@interface MtkOnDataReceive : NSObject

/** 代理*/
@property (nonatomic, weak) id<MtkOnDataReceiveDelegate> delegate;

/**
 写入数据到设备
 
 @param data 数据流
 @param isTimeOut 是否需要超时
 */
- (void)writeDataToDeviceWithData:(NSData *)data
                        IsTimeOut:(BOOL)isTimeOut;

/**
 初始化单例
 */
+ (instancetype)shareInstance;

/**
 解析MTK平台数据（适用于项目中已经集成了MTK库，不使用KCTBleBussinessSDK中
 处理MTK平台的蓝牙业务）
 处理后的数据 -(void)mtkOnDataReceive:(NSDictionary *)dic回调中输出
 @param receviceData 接收到的数据
 */
- (void)saveMtkWatchSycnData:(NSData *)receviceData;

@end

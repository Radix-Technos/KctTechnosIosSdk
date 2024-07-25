//
//  MTKBleProcess.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/11/30.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CBPeripheral;

@interface MTKBleProcess : NSObject


+ (instancetype)shareInstance;
/** 开始 MTK 搜索方法 */
- (void)mtkStartScan;
/** 停止 MTK 搜索方法 */
- (void)mtkStopScan;
/**
 MTK连接设备
 */
- (void)mtkConnectDevice:(CBPeripheral *)peripheral;
/**
 MTK断开连接
 */
- (void)mtkDisconnectDevice:(CBPeripheral *)peripheral;
/**
 MTK忽略设备
 */
- (void)mtkForgetPeripheral;
/**
 MTK终止应用程序时调用
 */
- (void)mtkTerminateApplication;

@end

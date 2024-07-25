//
//  KCTBleManager.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/9/15.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class CBCentralManager;
@class CBPeripheral;
@class KCTBleModel;
@class CBUUID;

@protocol KCTBleManagerDelegate <NSObject>

@optional
/**
 *搜索设备回调方法
 */
- (void)kct_centralManger:(CBCentralManager *)central devices:(NSMutableArray *)devices;
/**
 *连接设备回调方法
 */
- (void)kct_centralManager:(CBCentralManager *)central connectedPeripherial:(KCTBleModel *)bleModel error:(NSError *)error;
/**
 蓝牙断开连接回调
 */
- (void)kct_centralManager:(CBCentralManager *)central disconnectedPeripherial:(KCTBleModel *)bleModel error:(NSError *)error;

/**
 *  业务处理完成回调方法
 */
- (void)kct_centralManager:(CBCentralManager *)central finishedHandle:(NSData *)data sid:(NSInteger)sid cmd:(NSInteger)cmd;
/**
 *  业务处理超时回调方法
 */
- (void)kct_centralManager:(CBCentralManager *)central timeOutHandle:(NSData *)data sid:(NSInteger)sid cmd:(NSInteger)cmd;
/* 蓝牙连接成功，并监听特征值成功 */
- (void)kct_centralManager:(CBCentralManager *)central shakeHandsSuccess:(CBPeripheral *)peripherial;
#pragma mark MTK 业务
/* 握手成功回调 */
- (void)kct_MTKcentralManager:(CBCentralManager *)central shakeHandsSuccess:(KCTBleModel *)bleModel;
/**
    MTK接收数据代理回调
 */
- (void)kct_MTKDataReceive:(NSDictionary *)dic;
/**
 获取设备的状态
 @param state 状态标识
 */
- (void)kct_MTKReceiveConnectStateChange:(int)state;
/**
 获取设备的状态
 @param state 状态标识 连接成功2（握手成功才能同步数据），已经断开连接0。
 */
- (void)kct_MTKConnectedPeripheral:(CBPeripheral *)peripheral connectionState:(int)state; 
    
@end

@interface KCTBleManager : NSObject

/** 代理*/
@property (nonatomic, weak) id<KCTBleManagerDelegate> delegate;
/** 当前连接的外设 */
//@property (nonatomic, strong) CBPeripheral *curentPeripheral;
/** 设备对象*/
@property (nonatomic, strong) KCTBleModel *currentBleModel;

/** bk升级状态中 YES升级中 NO不在升级 */
@property (nonatomic, assign) BOOL bkUpgrade;
/**  开始固件升级的方式，只发送一个通知 */
@property (nonatomic, assign) BOOL bkUpgradeOncePost;


+ (instancetype)shareManger;

/** 开始搜索 */
- (void)startScan:(NSArray *)uuidArray;
/** 停止搜索 */
- (void)stopScan;
/** 连接外设 */
- (void)connectPeripheral:(KCTBleModel *)bleModel;
/** 连接外设通过UUID */
- (void)connectPeripheralWithUUID:(NSString *)deviceUUID;
/** 断开连接 */
- (void)cancelConnectPeripheral:(KCTBleModel *)bleModel;
/**
 断开连接,bk平台专用
 
 @param bleModel 退出这个模型
 @param type 退出类型，0保持连接
 */
- (void)cancelConnectPeripheral:(KCTBleModel *)bleModel WithType:(int)type;
///**
// MTK 忽略掉设备
// */
//- (void)forgetPeripheral;
/**
 重连设备
 */
- (void)reconnectToPeripheralWithServices:(NSArray <CBUUID *>*)Services;
/**
 设备配对后重连
 
 @param Services 服务UUID
 */
- (void)pairedReconnedToPeripheralWithServices:(NSArray<CBUUID *>*)Services;
/**
 获取已配对的设备
 
 @param Services 服务UUID
 */
- (NSMutableArray *)getPairedConnectedArray;

/*
 发送数据
 */
- (void)sendDataToBLE:(NSData *)data;
/**
 写固件包给手环，bk专用
 
 @param data 数据包
 @param WriteType 写的类型 0认证 1传数据
 */
- (void)sendDataToBLE:(NSData *)data WithWriteType:(int)WriteType;
/**
 设置接受数据的超时时间
 
 @param deviceTimeOut 超时时间间隔。默认是1.0 如果数据大了可以设置为2.0，3.0
 */
-(void)setDeviceTimeOut:(float)deviceTimeOut;

/**
 写入数据到设备
 
 @param data 数据流
 @param isTimeOut 是否需要超时
 */
- (void)writeDataToDeviceWithData:(NSData *)data
                        IsTimeOut:(BOOL)isTimeOut;
@end

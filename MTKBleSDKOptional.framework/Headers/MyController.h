//
//  MyController.h
//  Mediatek SmartDevice
//
//  Created by kct on 15/6/8.
//  Copyright (c) 2015年 Mediatek. All rights reserved.
//

#import "Controller.h"

@protocol myProtocol;

@interface MyController : Controller

@property(nonatomic,strong) id<myProtocol>delegate;

+(id)getMyControllerInstance;
//发送命令
- (void)sendSOSCAllCMD: (NSString *)cmdHeader sendData: (NSData *)data;
- (void)onReceive: (NSData *)recvData;
- (void)onConnectStateChange: (int)state;

@end


@protocol myProtocol<NSObject>
//连上之后  数据更新 返回方法
- (void)onDataReceive:(NSData *)recvData;
//蓝牙状态改变
- (void)onConnectStateChange:(int)state;
- (void)onHandShakeSucceseDone;//握手

@end

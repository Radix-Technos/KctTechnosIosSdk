//
//  KCTHTTPRequstManager.h
//  KCTBLESDKDemo
//
//  Created by kct on 2018/3/21.
//  Copyright © 2018年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>

//成功回调Block
typedef void (^httpSuccess)(id responseObject);
//失败的回调
typedef void (^httpFailure) (NSError *error);

@interface KCTHTTPRequstManager : NSObject

+ (instancetype)shareInstance;

/**
 获取服务器上的版本信息
 
 @param adapterNumber 手环的适配号码
 */
- (void)getVersionInfoFromServiceWithAdapterNumber:(NSInteger)adapterNumber
                                           Success:(httpSuccess)success
                                           Failure:(httpFailure)failure;
/**
 下载最新的固件
 
 @param urlString url地址
 @param success 成功回调
 @param failure 失败回调
 */
- (void)downloadNewestFirmwareFileWithURL:(NSString *)urlString
                                  Success:(httpSuccess)success
                                  Failure:(httpFailure)failure;
/**
 下载最新的Agps
 
 @param success 成功回调
 @param failure 失败回调
 */
+(void)flashFirmwareSuccess:(httpSuccess)success
                    Failure:(httpFailure)failure;
@end

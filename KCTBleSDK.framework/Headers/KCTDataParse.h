//
//  KCTDataParse.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/9/19.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KCTDataParseDelegate <NSObject>

@optional
- (void)dataParseSuccessWith:(NSDictionary *)dic;
/* 固件升级回调 1:升级成功 0:升级失败*/
- (void)onFirmwareUpdate:(NSString *)result;

@end

@interface KCTDataParse : NSObject

+ (instancetype)shareInstance;
- (void)dataParseHandler:(NSData *)data;

/** 数据解析代理 */
@property (nonatomic, weak) id<KCTDataParseDelegate> delegate;

/**
 将步数转换为卡路里,公里(此算法与手环算法一致)
 
 @param steps 步数
 @param type  0:卡路里 1:公里
 @param height 身高(单位：厘米 默认：175cm)
 @param weight 体重(单位：千克 默认：60kg）
 */
- (NSString *)stepsConversionCaloriesAndKmStpes:(NSString *)steps
                                         height:(NSString *)height
                                         weight:(NSString *)weight
                                           type:(NSInteger)type;

@end

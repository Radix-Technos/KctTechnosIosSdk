//
//  KCTDFUTool.h
//  KCTBLESDKDemo
//
//  Created by kct on 2018/3/29.
//  Copyright © 2018年 kct. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KCTDFUTool : NSObject
/**
 检查是否可以更新
 */
+ (BOOL)checkUpdateCurrenVersion:(NSString *)currenVersion NewVersion:(NSString *)newVersion;
/**
 获取固件
 
 @param macString MAC地址
 @param upgradeVersion 要升级的版本
 @param currentVersion 当前版本
 @return 固件保存路径
 */
+ (NSString *)getFirewareDataSaveFilePath:(NSString *)macString
                           upgradeVersion:(NSString *)upgradeVersion
                           currentVersion:(NSString *)currentVersion;

/**
 *  16进制字符串转10进制数字
 *
 *  @param hexString 16进制字符串
 *
 *  @return 十进制数据
 */
+ (int)intFromHexSrting:(NSString *)hexString;
/**
 10进制转16进制字符串
 
 @param hexNumber 10进制
 
 @return 十六进制字符串
 */
+ (NSString *)stringWithHexNumber:(int)hexNumber;

@end

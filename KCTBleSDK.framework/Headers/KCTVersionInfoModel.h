//
//  KCTVersionInfoModel.h
//  KCTBLESDKDemo
//
//  Created by kct on 2018/3/22.
//  Copyright © 2018年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KCTVersionInfoModel : NSObject
/** 版本号*/
@property (nonatomic, copy) NSString *application_version;
/** 内容*/
@property (nonatomic, copy) NSString *context;
/** 版本标识*/
@property (nonatomic, copy) NSString *device_revision;
/** 文件路径*/
@property (nonatomic, copy) NSString *file;
/** 文件大小*/
@property (nonatomic, copy) NSString *file_size;
/** 初始化 */
- (instancetype)initWithDictionary:(NSDictionary *)dic;

@end

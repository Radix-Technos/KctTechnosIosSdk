//
//  KCTBleModel.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/10/11.
//  Copyright © 2017年 kct. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

typedef NS_ENUM(NSInteger, KCTDeviceType) {
    AndroidDeviceType,            //!< 72/80平台(Funfit)
    WearDeviceType,               //!< 2502/2503平台(分动穿戴)
    BraceletDeviceType,            //!< 1458平台(分动手环)
    UnKnowDeviceType               //!未知设备或无设备
};


@interface KCTBleModel : NSObject
/** 信号强度 */
@property (nonatomic, strong) NSNumber *RSSI;
/** 外设携带数据 */
@property (nonatomic, strong) NSDictionary *advertisementData;
/** 外设 */
@property (nonatomic, strong) CBPeripheral *peripheral;
/** 中心管理 */
@property (nonatomic, strong) CBCentralManager *central;
/** 设备类型 */
@property (nonatomic, assign) KCTDeviceType deviceType;
/** uuid唯一标识（暂时使用这个后期更换mac地址）*/
@property (nonatomic, copy  ) NSString *UUIDString;
/** MAC地址 */
@property (nonatomic, copy  ) NSString *MACString;
/** 是否系统已配对的设备 */
@property (nonatomic, assign) BOOL isPaired;

/**
 构造一个BLE模型
 
 @param central           中心管理
 @param peripheral        外设
 @param advertisementData 外设携带数据
 @param RSSI              信号强度
 @param UUIDString        uuid
 */
- (instancetype)initWithCentral:(CBCentralManager *)central
                     Peripheral:(CBPeripheral *)peripheral
              AdvertisementData:(NSDictionary *)advertisementData
                           RSSI:(NSNumber *)RSSI
                     deviceType:(KCTDeviceType)deviceType
                     UUIDString:(NSString *)UUIDString
                      MACString:(NSString *)MACString;

@end

//
//  MTKBleProximityService.h
//  BleProfile
//
//  Created by ken on 14-7-7.
//  Copyright (c) 2014年 MTK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <math.h>
#import "BLEClientProfile.h"

extern NSString *const UserDefaultKey_deviceSetting;
extern NSString *const UserDefaultKey_threshHold;

@class MTKBleManager;

typedef enum {
    kStatusFail = 0,
    kStatusSucc = 1,
}Status;

const static int RANGE_ALERT_NEAR     = 0;
const static int RANGE_ALERT_MIDDLE   = 1;
const static int RANGE_ALERT_FAR      = 2;

//customizable values
const static int RANGE_ALERT_THRESH_NEAR = 68;
const static int RANGE_ALERT_THRESH_MIDDLE = 82;
const static int RANGE_ALERT_THRESH_FAR = 92;

//link lost alert levle
const static int LINK_LOST_ALERT_NO     = 0;
const static int LINK_LOST_ALERT_MILD   = 1;
const static int LINK_LOST_ALERT_HIGH   = 2;

const static int RANGE_ALERT_IN     = 0;
const static int RANGE_ALERT_OUT    = 1;

//Cabibration read RSSI delay time
const static float CALIBRATE_READ_RSSI_DELAY_TIME=0.2;

//Alert Status
const static int NO_ALRT = 0;
const static int DISCONNECTED_ALERT = 1;
const static int IN_RANGE_ALERT = 2;
const static int OUT_RANGE_ALERT = 3;

//RSSI tolerance
const static int DEFAULT_RSSI_TOLERANCE = 3;

//PXP algorithm
const static int DEFAULT_SWITCH_SIZE = 5;
const static int DEFAULT_AVERAGE_SIZE = 20;
const static double DEFAULT_ILLEGAL_DIFFRATE = 0.25;
const static int DEFAULT_READ_RSSI_DELAY = 0;//s

typedef struct {
    BOOL alertEnabler;
    BOOL rangeAlertEnabler;
    int rangAlertInOut;
    int rangAlertDistance;
    int rangAlertThreshhold;
    bool disconnectAlertEnabler;
}DeviceSetting;

/* Service UUID */
extern NSString *const kLinkLossServiceUUIDString;
extern NSString *const kImmediateAlertServiceUUIDString;
extern NSString *const kTxPowerServiceUUIDString;
extern NSString *const kCurrentTimeUUIDString;

/* Charactistic UUID */
extern NSString *const kAlertLevelCharactisticUUIDString;
extern NSString *const kTxPowerLevelCharactisticUUIDString;

@protocol ProximityAlarmProtocol <NSObject>

- (void)distanceChangeAlarm: (CBPeripheral *)peripheral distance: (int)distanceValue;
- (void)alertStatusChangeAlarm: (BOOL)alerted;
@optional
- (void)rssiReadBack: (CBPeripheral *)peripheral status: (int)status rssi: (int)rss;
- (void)linkLostAlertLevelSetBack: (CBPeripheral *)peripheral status: (int)status;
- (void)txPowerReadBack: (CBPeripheral *)peripheral status: (int)status txPower: (int)txPwoer;

@end

@protocol CalibrateProtocol <NSObject>

-(void)calibrateFinished:(BOOL)result;

@end

@interface MTKBleProximityService : BLEClientProfile

+ (id)getInstance;

- (void)registerProximityDelgegate: (id<ProximityAlarmProtocol>)proximityDelegate;
- (void)unRegisterProximityDelgegate: (id<ProximityAlarmProtocol>)proximityDelegate;
- (void)registerCalibrateDelegate:(id<CalibrateProtocol>)calibrateDelegate;
- (void)unRegisterCalibrateDelegate:(id<CalibrateProtocol>)calibrateDelegate;

- (int)queryDistance: (CBPeripheral *) peripheral;

-(void)calibrateThreshold:(int)distance delay:(int)time;
- (void) writeAlertLevelResultBack:(CBCharacteristic *)characteristic error: (NSError *)error;


- (void) updatePxpSetting: (NSString *)peripheralId
             alertEnabler: (int)alertEnabler
                    range: (int)rangeAlertEnabler
                rangeType: (int)rangeType
            alertDistance: (int)distance
   disconnectAlertEnabler: (int)disconnectAlertEnabler;

- (BOOL) getIsNotifyRemote: (CBPeripheral *)peripheral;
- (void) updateAlertThreshold: (int)near midThreshold: (int)middle farThreshold: (int)far;

//set & get algorithm paramerter
- (void)setTolerance: (int)tolerance;
- (int)getTolerance;
- (void)setIllegalDiffRate: (double)illegalRate;
- (void)setReadRssiDelay: (int)delaySeconds;//0: without delay
- (void)setRssiPolisherParamerters: (int)switchArraySize averageArraySize: (int)averageArraySize illegalDiffRate: (double)illegalRate;
- (int)getCurrentThreshold;

@property (readonly) CBPeripheral *peripheral;
@property int rssi;
@property int txPower;
@property DeviceSetting deviceSetting;
@property int alertStatus;
@property (nonatomic)BOOL isNotifyRemote;
@property (nonatomic)BOOL isCalibrateSuccess;
@property (assign,nonatomic)id<CalibrateProtocol> calibtateDelegate;

@end

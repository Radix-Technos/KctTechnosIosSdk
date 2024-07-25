//
//  GATTLinker.h
//  MTKBleManager
//
//  Created by user on 11/7/14.
//  Copyright (c) 2014 ___MTK___. All rights reserved.
//

#import "Linker.h"
#import "MTKBleManager.h"

extern NSString *const kDOGPServiceUUIDString;
extern NSString *const kDOGPReadCharUUIDString;
extern NSString *const kDOGPWriteCharUUIDString;

const static int STATE_READ_NONE = 0;
const static int STATE_READ_WAIT_FOR_RESPONSE = 1;
const static int STATE_READ_NEED_TO_READ = 2;

@protocol LinkerListenerProtocol <NSObject>

- (void)onDataArrived: (NSData *)data;
- (void)onDataSent: (float)percent Tag: (NSString *)sessionTag;
- (void)onConnectionStateChange: (int)newState;

@end

@interface GATTLinker : Linker

+ (id) initGattLinkerInstance;
+ (id) getGattLinkerInstance;

-(void)setGattParameter: (CBPeripheral *)peripheral readChar:(CBCharacteristic *)readCh writeChar:(CBCharacteristic *)writeCh;

-(void)close;

- (void) write: (NSData *)data;

-(void)clearData:(NSString *)tag;

-(void)readNextDataValue;

-(void)writeDataDirectly:(NSData*)data;

- (void) changeDataBuffer: (int)SessionDataSize;

//for MTKBleManager
- (void) onReadCharacteristicCallBack: (CBCharacteristic *)ch error: (NSError *)er;
- (void) onWriteCharacteristicCallBack: (CBCharacteristic *)ch error: (NSError *)er;

-(void)onConnectionStateChange:(int)newState;

-(BOOL)isConnected;
-(BOOL)isHandShakeDone;

-(void)setHandShakeDone:(BOOL)done;

-(void)setRemoteDeviceVersion:(int)version;

-(BOOL)setMaxWriteLength:(int)length;

@property (nonatomic) id<LinkerListenerProtocol> mLinkerListener;

@end

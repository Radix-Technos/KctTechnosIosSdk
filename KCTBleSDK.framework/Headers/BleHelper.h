//
//  BleHelper.h
//  KCTBLESDKDemo
//
//  Created by kct on 17/9/18.
//  Copyright © 2017年 kct. All rights reserved.
//

#ifndef BleHelper_h
#define BleHelper_h

#include <stdio.h>

/**
 二进制字符串转十进制数字
 @param bit_str 二进制字符串
 */
int bitToDecimal(char *bit_str);

/**
 十进制数转成星期的二进制
 
 @param dec IN 十进制数
 @return 二进制数 必须用调用free()函数释放
 */
char *weedyCycleDecimalToBit(int dec);
/**
 十进制数转成星期的二进制
 
 @param cycle IN 传入字符数组地址 OUT 赋值后输出字符组地址
 @param decimal IN
 */
void weedyCycleFromDecimal(char *cycle, int decimal);


#endif /* BleHelper_h */

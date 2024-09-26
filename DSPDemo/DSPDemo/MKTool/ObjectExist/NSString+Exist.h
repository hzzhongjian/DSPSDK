//
//  NSString+Exist.h
//
//  Created by Mountain King on 2022/5/18.
//

#import <Foundation/Foundation.h>
#import "NSNumber+Exist.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Exist)
/// 返回一个sha256加密后的字符串
- (NSString *)sha256String;

/// 返回一个md5加密后的字符串
-(NSString *)md5String;

/// 判断字符串是否存在（是否为空，YES为非空）
-(BOOL)exist;

@end

NS_ASSUME_NONNULL_END

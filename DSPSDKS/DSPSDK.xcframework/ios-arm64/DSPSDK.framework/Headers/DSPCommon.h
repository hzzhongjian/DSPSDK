//
//  DSPCommon.h
//  DSPSDK
//
//  Created by 麻明康 on 2023/12/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DSPCommon : NSObject

+ (CGFloat)getStatusBarHeight;

//获取时间戳（毫秒）
+ (NSInteger )getTimestampSince1970;

+ (UIWindow *)getCurrentWindow;

/// 获取当前控制器
+ (UIViewController *)getCurrentVC;

/// 获取当前窗口根控制器
+ (UIViewController *)getCurrentRootVC;

/// 获取KeyWindow根控制器
+ (UIViewController *)getKeyRootVC;

+ (UIWindow *)getKeyWindow;

// 判断字符串是否为空（YES：空）
+ (BOOL)isEmptyString:(NSString *)string;

// 将时间戳转换为指定的时间格式（如 HH:mm:ss.SS）
+ (NSString *)convertTimestampToTimeFormat:(NSTimeInterval)timestamp format:(NSString *)format;

+ (UIViewController *)topViewControllerFromKeyWindow;

@end

NS_ASSUME_NONNULL_END

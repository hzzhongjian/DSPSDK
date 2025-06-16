//
//  DspPrivacyProvider.h
//  DSPSDK
//
//  Created by 麻明康 on 2025/6/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DspPrivacyProvider <NSObject>

/**
 是否允许获取IDFA信息，默认为可以获取使用
 */
- (BOOL)canUseIDFA;

/**
 是否允许获取IDFV信息，默认可获取使用
 */
- (BOOL)canUseIDFV;

@end

NS_ASSUME_NONNULL_END

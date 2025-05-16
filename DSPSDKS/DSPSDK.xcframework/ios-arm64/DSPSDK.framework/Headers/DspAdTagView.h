//
//  DspAdTagView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/20.
//

#import <UIKit/UIKit.h>
#import <DSPSDK/DspAdItem.h>

NS_ASSUME_NONNULL_BEGIN

// 展示dsp的logo和广告字样

@interface DspAdTagView : UIView

+ (instancetype)create;

- (void)styleClear;

- (void)setAdLog:(DspAdItem *)adItem;

@end

NS_ASSUME_NONNULL_END

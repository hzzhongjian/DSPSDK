//
//  UIView+ViewVisiable.h
//  DSPSDK
//
//  Created by 麻明康 on 2024/3/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (DSPViewVisiable)

- (BOOL)dsp_isViewVisible;

- (BOOL)dsp_isSubViewVisible;

@end

NS_ASSUME_NONNULL_END

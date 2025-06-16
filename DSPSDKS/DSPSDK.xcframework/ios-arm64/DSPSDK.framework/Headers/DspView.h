//
//  DspView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/19.
//

#import <UIKit/UIKit.h>
#import <DSPSDK/DspViewDelegate.h>
#import <DSPSDK/DSPSDKEnum.h>
#import <DSPSDK/DspConstant.h>
#import <DSPSDK/DspComplianceGuidanceView.h>


NS_ASSUME_NONNULL_BEGIN

@interface DspView : UIView

@property (nonatomic, strong) DspAdItem *adItem;

@property (nonatomic, weak) id <DspViewDelegate> delegate;

//-(BOOL) isShowingOnKeyWindow;

@property (nonatomic, assign) NSTimeInterval click_up_ms;

@property (nonatomic, assign) NSTimeInterval material_down_fin_ms;

@property (nonatomic, assign) NSInteger dpl_fail_reason;

// 点击动作，用来记录事件上报
@property (nonatomic, assign) DSPAdViewClickAction click_action;

// 摇一摇
@property (nonatomic, assign) double shake_shake_x;

@property (nonatomic, assign) double shake_shake_z;

@property (nonatomic, assign) double shake_shake_y;

@property (nonatomic, strong) DspComplianceGuidanceView *dspComplianceGuidanceView;

// 自己的事件上报参数
- (NSDictionary *)reportParams;

// 用户点击屏幕的位置，包含按下/松开的x，y值
- (NSDictionary *)click_point;

@property (nonatomic, assign) BOOL hasShow;

@end

NS_ASSUME_NONNULL_END

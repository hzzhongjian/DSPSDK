//
//  UIView+Twist.h
//  DSPSDK
//
//  Created by 麻明康 on 2025/3/3.
//

#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>
#import <DSPSDK/UIView+ViewVisiable.h>
#import <objc/message.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^TwistActionHandler)(double accelerameter, double x, double y, double z, NSError *error);


@interface UIView (Twist)

@property (strong, nonatomic,nullable) CMMotionManager *motionManager;

@property(nonatomic,strong) NSString *twist_power;

@property (assign, nonatomic) BOOL disableViewVisibleDetect;

@property (nonatomic, copy) TwistActionHandler motionEvent;

@property (assign, nonatomic) BOOL appStatusNotifyAdded;

- (void)loadMotionMonitorWithEvent:(TwistActionHandler)motionEvent;

/// 根据当前视图是否显示在最上层，决定打开或暂停摇一摇
- (void)autoManageMotionMonitorState;

/// 只有当视图在最上层的时候会启动摇一摇。否则情况较多，前后台事件要放到外部去处理，耦合较大
- (void)startMotionMonitor;

/// 不考虑视图层级，直接打开摇一摇
- (void)startMotionMonitorWithoutDetect;

- (void)stopMotionMonitor;

/// 使用完必须销毁
- (void)removeMotionMonitor;


@end

NS_ASSUME_NONNULL_END

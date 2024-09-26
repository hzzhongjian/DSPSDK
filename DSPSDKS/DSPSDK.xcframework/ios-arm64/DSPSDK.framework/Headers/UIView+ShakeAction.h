//
//  UIView+ShakeAction.h
//  DSPSDK
//
//  Created by 麻明康 on 2024/2/2.
//

#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>
#import <objc/message.h>
#import <DSPSDK/UIView+ViewVisiable.h>
NS_ASSUME_NONNULL_BEGIN
typedef void(^ShakeActionHandler)(double accelerameter, NSError *error);

/// 摇一摇功能
@interface UIView (ShakeAction)
@property (strong, nonatomic,nullable) CMMotionManager *motionManager;
@property (assign, nonatomic) BOOL appStatusNotifyAdded;
@property (assign, nonatomic) BOOL disableViewVisibleDetect;

@property(nonatomic,strong) NSString *shake_power;
@property (nonatomic, copy) ShakeActionHandler motionEvent;
-(void)loadMotionMonitorWithEvent:(ShakeActionHandler)motionEvent;;
/// 根据当前视图是否显示在最上层，决定打开或暂停摇一摇
-(void)autoManageMotionMonitorState;

/// 只有当视图在最上层的时候会启动摇一摇。否则情况较多，前后台事件要放到外部去处理，耦合较大
-(void)startMotionMonitor;


/// 不考虑视图层级，直接打开摇一摇
-(void)startMotionMonitorWithoutDetect;

-(void)stopMotionMonitor;

/// 使用完必须销毁
-(void)removeMotionMonitor;
@end

NS_ASSUME_NONNULL_END

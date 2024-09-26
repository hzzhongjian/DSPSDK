//
//  DspSplashView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/19.
//

#import <DSPSDK/DspView.h>
#import <DSPSDK/DspViewDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class DspSplashView;
@protocol DspSplashViewDelegate <DspViewDelegate>
-(void) dspSplashViewCountDownEnd:(DspSplashView*) dspSplashView;
@optional



@end

@interface DspSplashView : DspView

@property(nonatomic,copy) NSString *imageUrl;
@property(nonatomic,assign) NSInteger shkipTimes;

@property(nonatomic,assign) BOOL area_enable;
@property(nonatomic,copy) NSString *shake_power;
@property(nonatomic,weak) id<DspSplashViewDelegate> delegate;

#warning show方法统一，放到协议中
#warning 但是splash没有show方法，媒体直接addsubView操作。
@end

NS_ASSUME_NONNULL_END

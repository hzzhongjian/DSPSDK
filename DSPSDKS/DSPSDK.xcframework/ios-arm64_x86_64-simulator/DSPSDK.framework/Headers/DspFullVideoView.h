//
//  DspFullVideoView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/27.
//

#import <DSPSDK/DspView.h>
#import <DSPSDK/DspInfoView.h>
#import <DSPSDK/DspVideoView.h>
#import <DSPSDK/DspImageView.h>
#import <DSPSDK/DspFullVideoDelegate.h>
#import <DSPSDK/UIView+ShakeAction.h>


NS_ASSUME_NONNULL_BEGIN

@interface DspFullVideoView : DspView<DspVideoViewDelegate>
//@property(nonatomic,weak) id<DspViewDelegate> delegate;
//@property(nonatomic,strong,readonly) DspImageView *bgImageView;
//@property(nonatomic,strong,readonly) DspVideoView *videoPlayView;
//@property(nonatomic,strong,readonly) DspInfoView *infoView;
//@property(nonatomic,copy) NSString *shake_power;
@property (nonatomic,assign)BOOL videoMuted;
@property(nonatomic,weak) id<DspFullVideoDelegate> delegate;
@property(nonatomic,weak) UIViewController* rootViewController;

-(void) render;
-(void) start;
-(void) pause;
-(void) close;
@end

NS_ASSUME_NONNULL_END

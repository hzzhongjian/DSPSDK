//
//  DspVideoView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/27.
//

#import <DSPSDK/DspView.h>
#import <DSPSDK/DspViewDelegate.h>
#import <DSPSDK/DspImageView.h>
#import <AVFoundation/AVFoundation.h>
NS_ASSUME_NONNULL_BEGIN
@class DspVideoView;
@protocol DspVideoViewDelegate <DspViewDelegate>

@optional
-(void) dspVideoView:(DspVideoView*) dspVideoView statusChanged:(AVPlayerItemStatus) status;
-(void) dspVideoView:(DspVideoView*) dspVideoView playProgressChanged:(NSTimeInterval) times;
-(void) dspVideoViewPlayFinished:(DspVideoView*) dspVideoView;
@end

@interface DspVideoView : DspView

@property(nonatomic,weak) id<DspVideoViewDelegate> delegate;
@property(nonatomic,strong) DspImageView *bgImageView;
@property(nonatomic,copy) NSString *videoUrlStr;
@property(nonatomic,assign) NSInteger duration;
-(void) start;
-(void) pause;
-(void) play;
-(void) close;

@property (nonatomic,assign)BOOL muted;
@end

NS_ASSUME_NONNULL_END

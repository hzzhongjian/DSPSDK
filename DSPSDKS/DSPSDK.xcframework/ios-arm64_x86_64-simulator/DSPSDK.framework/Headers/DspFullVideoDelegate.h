//
//  DspFullVideoDelegate.h
//  DSPSDK
//
//  Created by 麻明康 on 2024/3/4.
//

#import <Foundation/Foundation.h>
#import <DSPSDK/DspViewDelegate.h>
#import <DSPSDK/DSPSDKEnum.h>
NS_ASSUME_NONNULL_BEGIN

@protocol DspFullVideoDelegate <DspViewDelegate>
@optional
- (void)dspFullVideoView:(DspView *)dspView  playerStatusChanged:(DSPMediaPlayerStatus)playerStatus;
-(void) dspFullVideoView:(DspView*) dspVideoView playProgressChanged:(NSTimeInterval) times;
-(void) dspFullVideoViewPlayFinish:(DspView*) dspView;
//-(void) dspFullVideoView:(DspView*) dspVideoView displayFailWithError:(nullable NSError *)error;
-(void) dspFullVideoViewAdDetailDidPresent;
@end

NS_ASSUME_NONNULL_END


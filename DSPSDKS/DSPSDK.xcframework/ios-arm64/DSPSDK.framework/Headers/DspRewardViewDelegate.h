//
//  DspRewardViewDelegate.h
//  DSPSDK
//
//  Created by 麻明康 on 2024/1/29.
//

#import <Foundation/Foundation.h>
#import <DSPSDK/DspViewDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@class DspRewardVideoView;
@protocol DspRewardViewDelegate <DspViewDelegate>

-(void) dspRewardVideoView:(DspView*) dspVideoView playProgressChanged:(NSTimeInterval) times;
-(void) dspRewardVideoViewPlayFinish:(DspRewardVideoView*) dspView;
-(void) dspRewardVideoView:(DspView*) dspVideoView displayFailWithError:(nullable NSError *)error;
@end

NS_ASSUME_NONNULL_END

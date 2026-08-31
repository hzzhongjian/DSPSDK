//
//  DspImageView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/20.
//

#import <UIKit/UIKit.h>
#import <DSPSDK/DspViewBlocks.h>

NS_ASSUME_NONNULL_BEGIN

@interface DspImageView : UIImageView

- (void)dsp_setImageWithURLStr:(NSString *)urlStr;

/// 播放本地GIF
- (void)dsp_gif_playWithName:(NSString *)name;

/// 停止播放
- (void)dsp_gif_stop;

/// 是否正在播放
- (BOOL)dsp_gif_isPlaying;

@end

NS_ASSUME_NONNULL_END

//
//  FullScreenVideoViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/16.
//

#import "FullScreenVideoViewController.h"

@interface FullScreenVideoViewController ()<DspFullScreenVideoAdDelegate>
@property (nonatomic,strong)DspFullScreenVideoAd *fullVideoAd;
@end

@implementation FullScreenVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

-(void)loadAD{
    self.fullVideoAd = [[DspFullScreenVideoAd alloc] init];
    self.fullVideoAd.zjad_id = Appid;
    self.fullVideoAd.ad_id = AdId_FullScreenVideo1;
    self.fullVideoAd.ad_type = DspADType_FullVideoAd;
    self.fullVideoAd.delegate = self;
    NSDictionary *params = @{
        @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
        @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width]
    };
    [self.fullVideoAd loadAdDate:params];
}

-(void)showAD{
    if (self.fullVideoAd) {
        [self.fullVideoAd presentFullScreenVideoAdFromRootViewController:self];
    }
}

#pragma mark DspFullScreenVideoAdDelegate

- (void)dspFullScreenVideoAdDidShow:(DspFullScreenVideoAd *)ad{
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspFullScreenVideoAdDidClick:(DspFullScreenVideoAd *)ad{
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspFullScreenVideoAdDidClose:(DspFullScreenVideoAd *)ad{
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspFullScreenVideoAdDidFail:(DspFullScreenVideoAd *)ad error:(nullable NSError *)error{
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}

- (void)dspFullScreenVideoAd:(DspFullScreenVideoAd *)ad  playerStatusChanged:(DSPMediaPlayerStatus)playerStatus{
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspFullScreenVideoAdDetailDidPresent:(DspFullScreenVideoAd *)ad{
    MKLog(@"======%s",__FUNCTION__);
}

-(void) dspAdLoadSuccessful:(DspAd*) dspAd{
    MKLog(@"======%s",__FUNCTION__);
}

-(void) dspAdLoadFail:(DspAd*) dspAd error:(NSError*) error{
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}

-(void) dspAdDetailClosed:(DspAd*) dspAd adView:(UIView*) adView{
    MKLog(@"======%s",__FUNCTION__);
}

- (void)DspRewardVideoAd:(nonnull DspRewardVideoAd *)provider didFailWithError:(nonnull NSError *)error {
    MKLog(@"======%s",__FUNCTION__);
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

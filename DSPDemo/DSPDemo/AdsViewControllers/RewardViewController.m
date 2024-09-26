//
//  RewardViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/16.
//

#import "RewardViewController.h"

@interface RewardViewController ()<DspRewardVideoAdProviderDelegate>
{
    DspRewardVideoAd *_dspRewardVideoAd;
}
@end

@implementation RewardViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

-(void)loadAD{
    _dspRewardVideoAd = [DspRewardVideoAd new];
    _dspRewardVideoAd.zjad_id = Appid;
    _dspRewardVideoAd.ad_id = AdId_Reward1;
    _dspRewardVideoAd.shake_power = @"2";
    _dspRewardVideoAd.ad_type = DspADType_RewardVideo;
    _dspRewardVideoAd.delegate = self;
    NSDictionary *params = @{
        @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
        @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width]
    };
    [_dspRewardVideoAd loadAdDate:params];
}

-(void)showAD{
    if(_dspRewardVideoAd){
        [_dspRewardVideoAd showAdInViewController:self];
    }
}

#pragma mark DspRewardVideoAdProviderDelegate

- (void)dspAdLoadFail:(nonnull DspAd *)dspAd error:(nonnull NSError *)error {
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}

- (void)dspAdLoadSuccessful:(nonnull DspAd *)dspAd {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspRewardVideoAdVideoDidLoad:(nonnull DspRewardVideoAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspRewardVideoAdDidShow:(nonnull DspRewardVideoAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspRewardVideoAdDidClicked:(nonnull DspRewardVideoAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspRewardVideoAdDidClose:(nonnull DspRewardVideoAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspRewardVideoAd:(DspRewardVideoAd *)dspRewardVideoAd displayFailWithError:(NSError *)error{
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);

}

- (void)dspRewardVideoAdDidRewardEffective:(nonnull DspRewardVideoAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspRewardVideoAdDidPlayFinish:(nonnull DspRewardVideoAd *)provider {
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

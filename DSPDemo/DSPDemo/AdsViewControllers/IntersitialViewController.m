//
//  IntersitialViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/2.
//

#import "IntersitialViewController.h"

@interface IntersitialViewController ()<DspInterstitialAdDelegate>
{
    DspInterstitialAd *_dspInterstitialAd;
}

@end

@implementation IntersitialViewController

- (void)viewDidLoad {
    [super viewDidLoad];

}
-(void)loadAD{
    _dspInterstitialAd = [DspInterstitialAd new];
    _dspInterstitialAd.zjad_id = Appid;
    _dspInterstitialAd.ad_id = AdId_Interstitial1;
    _dspInterstitialAd.ad_type = DspADType_Interstitial;
    _dspInterstitialAd.delegate = self;
    _dspInterstitialAd.shake_power = @"2";
    NSDictionary *params = @{
        @"image_height":[NSNumber numberWithDouble:KScreenSize.height],
        @"image_width":[NSNumber numberWithDouble:KScreenSize.width]
    };
    [_dspInterstitialAd loadAdDate:params];
}

-(void)showAD{
    if(_dspInterstitialAd){
        [_dspInterstitialAd presentAdFromRootViewController:self];
    }
}

#pragma mark DspRewardVideoAdProviderDelegate

- (void)dspAdLoadFail:(nonnull DspAd *)dspAd error:(nonnull NSError *)error {
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}

- (void)dspAdLoadSuccessful:(nonnull DspAd *)dspAd {
    MKLog(@"======%s",__FUNCTION__);
    [self showAD];
}

-(void) dspAdDetailClosed:(DspAd*) dspAd adItem:(DspAdItem*) adItem{
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspInterstitialAdDetailDidClose:(nonnull DspInterstitialAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspInterstitialAdDidClick:(nonnull DspInterstitialAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspInterstitialAdDidClose:(nonnull DspInterstitialAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspInterstitialAdDidFail:(nonnull DspInterstitialAd *)provider error:(NSError * _Nullable)error {
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}

- (void)dspInterstitialAdDidPresentScreen:(nonnull DspInterstitialAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspInterstitialAdDidRewardEffective:(nonnull DspInterstitialAd *)provider {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)DspRewardVideoAd:(nonnull DspRewardVideoAd *)provider didFailWithError:(nonnull NSError *)error {
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}


#pragma mark =============== 竞胜竞败 二价上报 ================
- (NSInteger)eCPM{
    return [_dspInterstitialAd getEcpm];
}

- (void)biddingSuccess:(NSInteger )secondPrice{
    [_dspInterstitialAd setBidEcpm:secondPrice];
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

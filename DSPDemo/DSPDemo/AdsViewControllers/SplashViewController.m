//
//  SplashViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/9.
//

#import "SplashViewController.h"
#import <DSPSDK/DspSplashAd.h>

@interface SplashViewController ()<DspSplashAdDelegate>
{
    @private
    DspSplashAd *_dspSplashAd;
    UIView *_bottomView;
}

@end

@implementation SplashViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)loadAD{
    _dspSplashAd = [DspSplashAd new];
    _dspSplashAd.zjad_id = Appid;
    _dspSplashAd.ad_id = AdId_Splash1;
    _dspSplashAd.ad_type = DspADType_Splash;
    _dspSplashAd.shake_power = @"2";
    _dspSplashAd.delegate = self;
    NSDictionary *params = @{
        @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
        @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width]
    };
    [_dspSplashAd loadAdDate:params];
}

-(void)showAD{
    if(_dspSplashAd){
        [[UIWindow currentWindow].rootViewController.view addSubview:_dspSplashAd.splashView];
    }
}


#pragma mark DspSplashAdDelegate

- (void)dspAdLoadFail:(nonnull DspAd *)dspAd error:(nonnull NSError *)error {
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}

- (void)dspAdLoadSuccessful:(nonnull DspAd *)dspAd {
//    [self hidenBackgroundView];
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspSplashAdSuccessPresentScreen:(nonnull DspSplashAd *)dspSplashAd {
    MKLog(@"======%s",__FUNCTION__);
}

- (void)dspSplashAdClicked:(nonnull DspSplashAd *)dspSplashAd {
    MKLog(@"======%s",__FUNCTION__);

}

- (void)dspSplashAdApplicationWillEnterBackground:(nonnull DspSplashAd *)dspSplashAd {
    MKLog(@"======%s",__FUNCTION__);

}

- (void)dspSplashAdCountdownEnd:(nonnull DspSplashAd *)dspSplashAd {
    MKLog(@"======%s",__FUNCTION__);

}

- (void)dspSplashAdClosed:(nonnull DspSplashAd *)dspSplashAd {
    MKLog(@"======%s",__FUNCTION__);

}

-(void) dspAdDetailClosed:(DspAd*) dspAd adItem:(DspAdItem*) adItem{
    //[self z]
}

- (void)dspSplashAdError:(nonnull DspSplashAd *)dspSplashAd withError:(nonnull NSError *)error {
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}


- (NSInteger)eCPM{
    return [_dspSplashAd getEcpm];
}

- (void)biddingSuccess:(NSInteger )secondPrice{
    [_dspSplashAd setBidEcpm:secondPrice];
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

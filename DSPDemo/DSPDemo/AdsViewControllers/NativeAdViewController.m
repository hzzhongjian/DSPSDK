//
//  NativeAdViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2025/2/8.
//

#import "NativeAdViewController.h"
#import <DSPSDK/DspNativeAd.h>
#import <DSPSDK/DspNativeAdManager.h>
//#import <DSPSDK/DspNativeAdRelatedView.h>

@interface NativeAdViewController () <DspNativeAdManagerDelegate, DspNativeAdDelegate, UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) DspNativeAdManager *nativeAdManager;

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, strong) NSArray *datasource;

@property (nonatomic, assign) BOOL firstLoad;

@property (nonatomic, strong) DspVideoView *videoView;

@end

@implementation NativeAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.firstLoad = YES;
    // Do any additional setup after loading the view.
    UIButton *refreshBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [refreshBtn setTitle:@"刷新广告" forState:UIControlStateNormal];
    [refreshBtn setBackgroundColor:[UIColor brownColor]];
    [refreshBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [refreshBtn addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    refreshBtn.frame = CGRectMake(0, 0, KScreenSize.width, 40);
    [self.view addSubview:refreshBtn];
    [self.view addSubview:self.tableView];
    
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    if (self.firstLoad) {
        self.firstLoad = NO;
        [self loadAd];
    }
}

- (void)loadAd
{
    _nativeAdManager = [DspNativeAdManager new];
    _nativeAdManager.zjad_id = Appid;
    _nativeAdManager.ad_id = AdId_NativeAd1;
    _nativeAdManager.ad_type = DspADType_Native;
    _nativeAdManager.delegate = self;
    _nativeAdManager.videoMuted = NO;
    _nativeAdManager.adSize = CGSizeMake(self.view.frame.size.width, 0);
    NSDictionary *params = @{
        @"image_height":@0,
        @"image_width":[NSNumber numberWithDouble:KScreenSize.width],
        @"ad_count":@3
    };
    [_nativeAdManager loadAdDate:params];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    if (_videoView) {
        [_videoView close];
        _videoView = nil;
    }
}

#pragma mark - DspNativeAdManagerDelegate
- (void)dspNativeAdManagerSuccessToLoad:(DspNativeAdManager *)adsManager nativeAds:(NSArray<DspNativeAd *> *)nativeAds
{
    NSLog(@"===>>>%s", __func__);
    self.datasource = nativeAds;
    [self.tableView reloadData];
}

- (void)dspAdLoadFail:(DspAd *)dspAd error:(NSError *)error
{
    NSLog(@"===>>>%s", __func__);
}

#pragma mark - UITableViewDelegate
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.datasource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass(UITableViewCell.class) forIndexPath:indexPath];
    cell.backgroundColor = [UIColor grayColor];
    [cell performSelector:@selector(removeAllSubviews) withObject:nil];
    DspNativeAd *nativeAd = self.datasource[indexPath.row];
    nativeAd.delegate = self;
    if (nativeAd.materialType == DspAdMaterialTypeSingle) {
        UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(cell.frame) / 3 * 1, CGRectGetHeight(cell.frame))];
        NSData *data = [NSData dataWithContentsOfURL:[NSURL URLWithString:nativeAd.image]];
        imageView.image = [UIImage imageWithData:data];
        [cell addSubview:imageView];
        
        UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetWidth(cell.frame) / 3 * 1 + 10, 0, CGRectGetWidth(cell.frame) / 3 * 2 - 10, 30)];
        titleLabel.text = nativeAd.title;
        [cell addSubview:titleLabel];
        
        UILabel *descLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(titleLabel.frame), CGRectGetHeight(cell.frame) - 30, CGRectGetWidth(titleLabel.frame), 30)];
        descLabel.text = nativeAd.adDesc;
        [cell addSubview:descLabel];
        
        DspAdTagView *logoView = nativeAd.logoView;
        [logoView setFrame:CGRectMake(CGRectGetWidth(cell.frame) - 44 - 10, CGRectGetHeight(cell.frame) - 18, 44, 18)];
        [cell addSubview:logoView];
        [nativeAd registerContainer:cell withClickableViews:@[imageView, titleLabel, descLabel, logoView]];
        [nativeAd refreshData:nativeAd];
    } else {
        if (_videoView) {
            [_videoView close];
        }
        _videoView = nativeAd.videoAdView;
        [_videoView setFrame:CGRectMake(0, 0, CGRectGetWidth(cell.frame) / 3 * 1, CGRectGetHeight(cell.frame))];
        nativeAd.delegate = self;
        [_videoView start];
        [cell addSubview:_videoView];
        
        UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetWidth(cell.frame) / 3 * 1 + 10, 0, CGRectGetWidth(cell.frame) / 3 * 2 - 10, 30)];
        titleLabel.text = nativeAd.title;
        [cell addSubview:titleLabel];
        
        UILabel *descLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(titleLabel.frame), CGRectGetHeight(cell.frame) - 30, CGRectGetWidth(titleLabel.frame), 30)];
        descLabel.text = nativeAd.adDesc;
        [cell addSubview:descLabel];
        
        DspAdTagView *logoView = nativeAd.logoView;
        [logoView setFrame:CGRectMake(CGRectGetWidth(cell.frame) - 44 - 10, CGRectGetHeight(cell.frame) - 18, 44, 18)];
        [cell addSubview:logoView];
        [nativeAd registerContainer:cell withClickableViews:@[_videoView, titleLabel, descLabel, logoView]];
        [nativeAd refreshData:nativeAd];
    }
    
    return cell;
}

#pragma mark - UITableViewDataSource
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 100;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    MKLog(@"==%ld",(long)indexPath.row);
}

#pragma mark - Lazy
- (UITableView *)tableView
{
    if (!_tableView) {
        self.tableView = [[UITableView alloc]initWithFrame:CGRectMake(0, 40, KScreenSize.width, KScreenSize.height-TopBar_H) style:UITableViewStyleGrouped];
        self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        self.tableView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        self.tableView.estimatedRowHeight = 0;
        self.tableView.estimatedSectionHeaderHeight = 0;
        self.tableView.estimatedSectionFooterHeight = 0;
        self.tableView.backgroundColor = [UIColor whiteColor];
        self.tableView.delegate = self;
        self.tableView.dataSource = self;
        [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:NSStringFromClass(UITableViewCell.class)];
    }
    return _tableView;
}

#pragma mark - DspNativeAdDelegate
- (void)dspNativeAdDidClick:(DspNativeAd *)nativeAd withView:(UIView *_Nullable)view
{
    NSLog(@"===>>>%s", __func__);
}

- (void)dspNativeAdDidShowOtherController:(DspNativeAd *)nativeAd
{
    NSLog(@"===>>>%s", __func__);
}

- (void)dspNativeAdDidCloseOtherController:(DspNativeAd *)nativeAd
{
    NSLog(@"===>>>%s", __func__);
}

- (void)dspNativeAdDidShow:(DspNativeAd *)nativeAd
{
//    NSLog(@"===>>>%s==%@", __func__, nativeAd.getExtraInfo[@"request_id"]);
}

- (void)dspNativeAdVideoReadyToPlay:(DspNativeAd *)nativeAd
{
    NSLog(@"===>>>%s", __func__);
}

- (void)dspNativeAdVideoStartPlay:(DspNativeAd *)nativeAd
{
    NSLog(@"===>>>%s", __func__);
}

- (void)dspNativeAdVideoPlayFinished:(DspNativeAd *)nativeAd
{
    NSLog(@"===>>>%s", __func__);
}

- (void)dspNativeAdVideoPlayError:(DspNativeAd *)nativeAd
{
    NSLog(@"===>>>%s", __func__);
}

@end

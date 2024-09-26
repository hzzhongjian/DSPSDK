//
//  NativeExpressViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/17.
//

#import "NativeExpressViewController.h"
#import "NativeExpressViewCell.h"
@interface NativeExpressViewController ()<UITableViewDelegate,UITableViewDataSource,DspFeedAdDelegate,DspFeedAdViewDelegate>
@property (nonatomic,strong)UITableView *table;

@property (nonatomic,strong)DspFeedAd *dspFeedAd;

@property (nonatomic,strong)NSMutableArray *dataArray;
@property (nonatomic,strong)NSArray <DspFeedAdView *>*adArray;
@property (nonatomic, assign) BOOL firstLoad;

@end

@implementation NativeExpressViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.firstLoad = YES;
    self.view.backgroundColor = [UIColor whiteColor];
    // Do any additional setup after loading the view.
    UIButton *refreshBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [refreshBtn setTitle:@"刷新广告" forState:UIControlStateNormal];
    [refreshBtn setBackgroundColor:[UIColor brownColor]];
    [refreshBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [refreshBtn addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    refreshBtn.frame = CGRectMake(0, 0, KScreenSize.width, 40);
    [self.view addSubview:self.table];
    [self.view addSubview:refreshBtn];
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    if (self.firstLoad) {
        self.firstLoad = NO;
        [self loadAd];
    }
}
-(void)loadAd{
    _dspFeedAd = [DspFeedAd new];
//    _dspFeedAd.zjad_id = @"Z9663789745";
//    _dspFeedAd.ad_id = @"J0128142431";
    _dspFeedAd.zjad_id = Appid;
    _dspFeedAd.ad_id = AdId_ExpressAd1;
    _dspFeedAd.ad_type = DspADType_Feed;
    _dspFeedAd.delegate = self;
    _dspFeedAd.adSize = CGSizeMake(self.table.frameWidth, 0);
    NSDictionary *params = @{
        @"image_height":@0,
        @"image_width":[NSNumber numberWithDouble:KScreenSize.width],
        @"ad_count":@3
    };
    [_dspFeedAd loadAdDate:params];
}

#pragma mark =============== createTable ===============
- (UITableView *)table{
    if (!_table) {
        _table = [[UITableView alloc]initWithFrame:CGRectMake(0, 0, KScreenSize.width, KScreenSize.height-TopBar_H) style:UITableViewStyleGrouped];
        _table.separatorStyle = UITableViewCellSeparatorStyleNone;
        _table.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
        _table.estimatedRowHeight = 0;
        _table.estimatedSectionHeaderHeight = 0;
        _table.estimatedSectionFooterHeight = 0;
        _table.backgroundColor = [UIColor whiteColor];
        _table.delegate = self;
        _table.dataSource = self;
        [_table registerClass:[NativeExpressViewCell class] forCellReuseIdentifier:NSStringFromClass(NativeExpressViewCell.class)];
        [_table registerClass:[UITableViewCell class] forCellReuseIdentifier:@"ZJDemoNormalCell"];
    }
    
    return _table;
}

#pragma mark =============== UITableViewDataSource ===============
-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.dataArray.count;
}
-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    UITableViewCell *cell = nil;
     id object =  self.dataArray[indexPath.row];
     if ([object isKindOfClass:[DspFeedAdView class]]) {
         cell = [self.table dequeueReusableCellWithIdentifier:NSStringFromClass(NativeExpressViewCell.class) forIndexPath:indexPath];
         [(NativeExpressViewCell *)cell refreshWithAd:(DspFeedAdView *)object];
     }else{
         cell = [self.table dequeueReusableCellWithIdentifier:@"ZJDemoNormalCell" forIndexPath:indexPath];
         cell.selectionStyle = UITableViewCellSelectionStyleNone;
         cell.backgroundColor = [UIColor whiteColor];
         cell.textLabel.textColor = [UIColor blackColor];
         cell.textLabel.font = [UIFont boldSystemFontOfSize:16];
         cell.textLabel.text = (NSString *)object;
     }

    return cell;
}

#pragma mark =============== UITableViewDelegate ===============
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    id object =  self.dataArray[indexPath.row];
    if ([object isKindOfClass:[DspFeedAdView class]]) {
        CGFloat height = ((DspFeedAdView *)object).frame.size.height;
        return height;
    }else{
        return 44;;
    }
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    MKLog(@"==%ld",(long)indexPath.row);
}

/**
 #pragma mark-======header
 - (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
 return <#headHeight#>;
 }
 - (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
 UIView * headBagView = [UIView new];
 headBagView.frame = CGRectMake(0, 0, <#FUll_VIEW_WIDTH#>, <#FUll_VIEW_HEIGHT#>);
 headBagView.backgroundColor = [UIColor lightGrayColor];
 UILabel * headlabel =[[UILabel alloc]initWithFrame:CGRectMake(10, 0, <#FUll_VIEW_WIDTH#>, headBagView.frameHeight)];
 headlabel.text = @"头部";
 [headBagView addSubview:headlabel];
 return <#headBagView#>;
 }
 #pragma mark-======footer
 - (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
 return <#headHeight#>;
 }
 - (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section{
 UIView * headBagView = [UIView new];
 headBagView.frame = CGRectMake(0, 0, <#FUll_VIEW_WIDTH#>, <#FUll_VIEW_HEIGHT#>);
 headBagView.backgroundColor = [UIColor lightGrayColor];
 UILabel * headlabel =[[UILabel alloc]initWithFrame:CGRectMake(10, 0, <#FUll_VIEW_WIDTH#>, headBagView.height)];
 headlabel.text = @"底部";
 [headBagView addSubview:headlabel];
 return headBagView;
 }
 */

#pragma mark =============== DspFeedAdDelegate ===============
- (void)dspFeedAdLoadSuccess:(nonnull DspFeedAd *)dspFeedAd views:(nonnull NSArray<__kindof DspFeedAdView *> *)views {
    MKLog(@"======%s",__FUNCTION__);
    for (int i = 0; i<views.count; i++) {

//        views[i].rootViewController = self;
//        views[i].delegate = self;
        [views[i] render];
        
        NSInteger index = i*3;
        if (index >= self.dataArray.count) {
            [self.dataArray addObject:views[i]];
        }else{
            [self.dataArray insertObject:views[i] atIndex:index];
        }
    }
    self.adArray = views;
}


- (void)dspAdLoadFail:(nonnull DspAd *)dspAd error:(nonnull NSError *)error {
    MKLog(@"======%s",__FUNCTION__);
    MKLog(@"======error:%@",error);
}

- (void)dspAdLoadSuccessful:(nonnull DspAd *)dspAd {
    MKLog(@"======%s",__FUNCTION__);

}

- (void)dspAdDetailClosed:(nonnull DspAd *)dspAd adView:(nonnull UIView *)adView {
    MKLog(@"======%s",__FUNCTION__);

}

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewRenderSuccess:(DspFeedAdView *)dspFeedView{
    [self.table reloadData];
}
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidClick:(DspFeedAdView *)dspFeedView{
    MKLog(@"======%s",__FUNCTION__);
}
#pragma mark =============== LazyLoad ===============
-(NSMutableArray *)dataArray{
    if (!_dataArray) {
        NSMutableArray *array = [NSMutableArray array];
        for (int i = 0 ; i <= 10; i++) {
            NSString *string = [NSString stringWithFormat:@"数据_%d",i];
            [array addObject:string];
        }
        _dataArray = array;
    }
    return _dataArray;
}

@end

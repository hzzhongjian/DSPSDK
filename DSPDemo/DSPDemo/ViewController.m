//
//  ViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2023/12/20.
//

#import "ViewController.h"
#import "ADCell.h"

#import "IntersitialViewController.h"
#import "SplashViewController.h"
#import "RewardViewController.h"
#import "FullScreenVideoViewController.h"
#import "NativeExpressViewController.h"
#import "BannerViewController.h"

@interface ViewController ()<UICollectionViewDelegate,UICollectionViewDataSource>
@property (nonatomic, strong) UICollectionView *collection;
@property (nonatomic, strong) NSMutableArray <ADTypeModel *>*dataArray;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    UIButton *button1 = [UIButton buttonWithFrame:CGRectMake(100, 200, 100, 100) title:@"开屏" titleColor:[UIColor whiteColor] backgroundColor:[UIColor tiffanyBlue] font:[UIFont systemFontOfSize:15]  normalImage:nil highlightedImage:nil backgroundImage:nil target:self selector:@selector(showSplashAdVC)];
    
    
    [self setNavBar];
    [self setNavTitle:[NSString stringWithFormat:@"DSPSDK-%@",[DSPSDKConfig SDKVersion]]];
    [self.view addSubview:self.collection];
}


#pragma mark =============== UICollectionViewDelegate ===============
-(CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout referenceSizeForHeaderInSection:(NSInteger)section{
    CGSize size={KScreenSize.width-30,72};
    return size;
}
//footer的大小
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout referenceSizeForFooterInSection:(NSInteger)section{
     CGSize size={KScreenSize.width-30,25};
       return size;
}

////这个也是最重要的方法 获取Header的 方法。
//- (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath
//{
//    if([kind isEqualToString:UICollectionElementKindSectionHeader]){
//        UICollectionReusableView *cell = [collectionView dequeueReusableSupplementaryViewOfKind:UICollectionElementKindSectionHeader withReuseIdentifier:@"Header" forIndexPath:indexPath];
//        return cell;
//    }else{
//        UICollectionReusableView *cell = [collectionView dequeueReusableSupplementaryViewOfKind:UICollectionElementKindSectionFooter withReuseIdentifier:@"Footer" forIndexPath:indexPath];
//        return cell;
//    }
//}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath{
    //    MedalSingleCheckViewController *vc = [[MedalSingleCheckViewController alloc]init];
    //    vc.wallModel = self.medalWallAllList[indexPath.section][indexPath.row];
    //    [self.navigationController pushViewController:vc animated:YES];
    UIViewController *vc  = [[NSClassFromString(self.dataArray[indexPath.row].VCClassName) alloc] init];
    vc.title = _dataArray[indexPath.row].title;
    [self.navigationController pushViewController:vc animated:YES];
}

#pragma mark =============== UICollectionViewDataSource ===============
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section{
    return self.dataArray.count;
}

- (nonnull __kindof UICollectionViewCell *)collectionView:(nonnull UICollectionView *)collectionView cellForItemAtIndexPath:(nonnull NSIndexPath *)indexPath { 
    ADCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"ADCell" forIndexPath:indexPath];
//    self.medalWallAllList[indexPath.section][indexPath.row].position = indexPath.row%3;
//    cell.model = self.medalWallAllList[indexPath.section][indexPath.row];
//    cell.backgroundColor = [UIColor yellowColor];
    cell.model = _dataArray[indexPath.row];
    return cell;
}


#pragma mark =============== UICollectionViewDelegateFlowLayout ===============
//同一行的cell的最小间距
- (CGFloat)collectionView:(UICollectionView *)collectionView
                   layout:(UICollectionViewLayout*)collectionViewLayout
minimumInteritemSpacingForSectionAtIndex:(NSInteger)section
{
    return 0;
}

//上下行的cell的最小间距
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout minimumLineSpacingForSectionAtIndex:(NSInteger)section
{
    return 0;
}


#pragma mark =============== lazyLoad ===============
- (UICollectionView *)collection{
    if (!_collection) {
        UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
        layout.scrollDirection = UICollectionViewScrollDirectionVertical;
        layout.itemSize = CGSizeMake((KScreenSize.width-30)/3, 134);
        layout.sectionInset = UIEdgeInsetsMake(0,0,0,0);
        _collection = [[UICollectionView alloc] initWithFrame:CGRectMake(15, 0, self.view.frame.size.width-30,KScreenSize.height-TopBar_H) collectionViewLayout:layout];
        _collection.layer.masksToBounds = YES;
        _collection.showsVerticalScrollIndicator = NO;
        _collection.showsHorizontalScrollIndicator = NO;
        _collection.delegate = self;
        _collection.dataSource = self;
        _collection.alwaysBounceVertical = YES;
        _collection.contentInset = UIEdgeInsetsZero;
        [_collection registerClass:[UICollectionReusableView class] forSupplementaryViewOfKind:UICollectionElementKindSectionHeader withReuseIdentifier:@"MedalSectionHeader"];
        [_collection registerClass:[UICollectionReusableView class] forSupplementaryViewOfKind:UICollectionElementKindSectionFooter withReuseIdentifier:@"MedalSectionFooter"];
//        [self.collection registerClass:[ADCell class] forCellWithReuseIdentifier:@"ADCell"];

        [self.collection registerNib:[UINib nibWithNibName:@"ADCell" bundle:nil] forCellWithReuseIdentifier:@"ADCell"];
        _collection.contentOffset = CGPointZero;
        _collection.backgroundColor = [UIColor clearColor];
    }
    return _collection;
}

ADTypeModel *ADTypeDic(NSString *title, NSString *imageName, NSString *VCClassName) {
    return [ADTypeModel parseDic:@{@"title":title,@"imageName":imageName,@"VCClassName":VCClassName}];
}

- (NSMutableArray *)dataArray{
    if (!_dataArray) {
        _dataArray = [[NSMutableArray alloc]init];
//        ad_icon_banner
//        ad_icon_fullscreenVideo
//        ad_icon_interstitial
//        ad_icon_native_express
//        ad_icon_reward
//        ad_icon_splash
        [_dataArray addObject:ADTypeDic(@"开屏", @"ad_icon_splash", NSStringFromClass([SplashViewController class]))];
        [_dataArray addObject:ADTypeDic(@"插屏", @"ad_icon_interstitial", NSStringFromClass([IntersitialViewController class]))];
        [_dataArray addObject:ADTypeDic(@"激励", @"ad_icon_reward", NSStringFromClass([RewardViewController class]))];
        [_dataArray addObject:ADTypeDic(@"全屏视频", @"ad_icon_splash", NSStringFromClass([FullScreenVideoViewController class]))];
        [_dataArray addObject:ADTypeDic(@"信息流", @"ad_icon_native_express", NSStringFromClass([NativeExpressViewController class]))];
        [_dataArray addObject:ADTypeDic(@"Banner", @"ad_icon_native_express", NSStringFromClass([BannerViewController class]))];

//                               @{@"title":@"开屏",@"imageName":@"ad_icon_splash",@"VCClassName":NSStringFromClass([SplashViewController class])}]];
    }
    return _dataArray;
}

@end

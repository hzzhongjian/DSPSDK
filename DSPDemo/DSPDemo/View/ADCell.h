//
//  ADCell.h
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/16.
//

#import <UIKit/UIKit.h>
#import "ADTypeModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface ADCell : UICollectionViewCell
@property (nonatomic, strong) ADTypeModel *model;
@property (weak, nonatomic) IBOutlet UILabel *adTitle;
@property (weak, nonatomic) IBOutlet UIImageView *adIcon;
@end

NS_ASSUME_NONNULL_END

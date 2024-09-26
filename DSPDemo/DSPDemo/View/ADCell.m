//
//  ADCell.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/16.
//

#import "ADCell.h"

@implementation ADCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setModel:(ADTypeModel *)model{
    _model = model;
    
    self.adIcon.image = [UIImage imageNamed:_model.imageName];
    self.adTitle.text =_model.title;
}
@end

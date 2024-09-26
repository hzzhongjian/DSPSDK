//
//  ADTypeModel.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/16.
//

#import "ADTypeModel.h"

@implementation ADTypeModel
+ (instancetype)parseDic:(NSDictionary*)dic{
    ADTypeModel *model = [[ADTypeModel alloc] init];
    model.title = dic[@"title"];
    model.imageName = dic[@"imageName"];
    model.VCClassName = dic[@"VCClassName"];
    return model;
}

@end

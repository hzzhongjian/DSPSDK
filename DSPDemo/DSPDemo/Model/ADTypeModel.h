//
//  ADTypeModel.h
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADTypeModel : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *imageName;
@property (nonatomic, strong) NSString *VCClassName;
+ (instancetype)parseDic:(NSDictionary*)dic;
@end

NS_ASSUME_NONNULL_END

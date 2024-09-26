---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: true

print_background: true
---

# DSPSDK更新日志 {ignore=true}
## <span id="jump1">版本更新日志</span>
| 最新版本更新日志 | 修订日期  | 修订说明       |
| ---------------- | --------- | -------------- |
|v1.1.4|2023-12-22|DSP独立拆分|
历史版本信息见 [历史版本更新日志](#历史版本更新日志)
## <span id="jump1">一、iOS SDK接入说明</span>

### <span id="jump1.1">1.1、工程设置导入framework</span>

#### <span id="jump1.1.1">1.1.1、申请应用的AppID</span>

```
请找运营人员获取应用ID和广告位ID。
```

#### <span id="jump1.1.2">1.1.2、引入framework</span>

**1. CocoaPods接入方式**
***1.1 一般引入方式***
```
#引入常用广告模块  
pod 'DSPSDK'
```



**2.手动方式**

1.下载SDK文件，解压后直接将 DSPSDKS 文件夹拖入工程即可。

2.前往项目的Build Setting中的Enable Bitcode设置为NO

3.Build Settings中Other Linker Flags 增加参数-ObjC，字母o和c大写

4.升级SDK的同学必须同时更新xcframework和bundle文件，否则可能出现部分页面无法展示的问题，老版本升级的同学需要重新引入DSPSDK.xcframework，拖入完请确保Copy Bundle Resources中有DSPSDKBundle.bundle,否则可能出现icon图片加载不出来的情况。




##历史版本更新日志

| 历史版本更新日志 | 修订日期  | 修订说明       |
| ---------------- | --------- | -------------- |
|v1.1.4|2023-12-22|DSP独立拆分|

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [版本更新日志](#span-idjump1版本更新日志span)
- [一、iOS SDK接入说明](#span-idjump1一-ios-sdk接入说明span)
  - [1.1、工程设置导入framework](#span-idjump1111-工程设置导入frameworkspan)
    - [1.1.1、申请应用的AppID](#span-idjump111111-申请应用的appidspan)
    - [1.1.2、引入framework](#span-idjump112112-引入frameworkspan)
- [历史版本更新日志](#历史版本更新日志)

<!-- /code_chunk_output -->




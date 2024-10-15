Pod::Spec.new do |s|
  s.name = "DSPSDK"
  s.version = "1.0.1.4"
  s.summary = "DSPSDK广告"
  s.description      = <<-DESC
    DSPSDKS广告，提供丰富的广告源
                     DESC
  s.authors = {"hzzhongjian"=>"opentwo@hzzhongjian.cn"}
  s.homepage = "https://github.com/hzzhongjian/DSPSDK.git"
  s.license      = "MIT"
  s.platform     = :ios, "11.0"
  s.frameworks = ["Foundation", "UIKit", "MobileCoreServices", "CoreGraphics", "Security", "SystemConfiguration", "CoreTelephony", "AdSupport", "CoreData", "StoreKit", "AVFoundation", "MediaPlayer", "CoreMedia", "WebKit", "Accelerate", "CoreLocation", "CoreMotion"]
  s.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi"]
  s.source = { :git => "https://github.com/hzzhongjian/DSPSDK.git" , :tag => s.version.to_s}
  s.resource = 'DSPSDKS/*.bundle'

  s.ios.deployment_target = '11.0'
  s.vendored_framework   = 'DSPSDKS/*.xcframework'
  s.preserve_paths =  'DSPSDKS/*.xcframework'
end

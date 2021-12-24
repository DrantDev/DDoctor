Pod::Spec.new do |s|
  s.name             = 'DrantDoctor'
  s.version= "3.1.8.12241731"

  s.summary          = 'A short description of DrantDoctor.'

  s.description      = <<-DESC
  TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'git@github.com:DrantDev/DrantDoctor.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'drant' => 'cyjjdsp@163.com' }
  s.source           = { :git => 'https://github.com/DrantDev/DrantDoctor.git', :tag => s.version.to_s }
  # s.social_media_url = ‘https://twitter.com/<TWITTER_USERNAME>'


  s.resources = 'DrantDoctor/resource/*.*'
   
  s.vendored_frameworks =  'DrantDoctor/*.framework'
  
  s.frameworks = 'SystemConfiguration', 'MobileCoreServices', 'AVFoundation', 'CoreTelephony', 'VideoToolbox', 'AudioToolbox', 'CoreMedia'
  s.libraries    =  'z', 'sqlite3.0', 'c++', 'resolv.9'
  
  s.ios.deployment_target = '9.0'
  
  s.pod_target_xcconfig = {
    'OTHER_LDFLAGS' => '-ObjC',
    'ENABLE_BITCODE' => 'NO',
  }

  s.dependency 'TXIMSDK_iOS'

end

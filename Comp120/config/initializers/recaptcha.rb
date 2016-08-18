# config/initializers/recaptcha.rb
Recaptcha.configure do |config|
  config.public_key  = '6Le3wB0TAAAAAJadd0KXkcMgDw3DD-UBvxkqCt1_'
  config.private_key = '6Le3wB0TAAAAAKjcSMNUEWKm7ehSrnEUlvG4RmGb'
  # Uncomment the following line if you are using a proxy server:
  # config.proxy = 'http://myproxy.com.au:8080'
end
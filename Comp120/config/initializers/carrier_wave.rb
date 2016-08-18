CarrierWave.configure do |config|
  config.fog_credentials = {
    :provider              => 'AWS',
    :aws_access_key_id     => 'AKIAJX37A7E76PZC2P4A',
    :aws_secret_access_key => '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'
  }

  if Rails.env.test? || Rails.env.cucumber?
    config.storage = :file
    config.enable_processing = false
    config.root = "#{Rails.root}/tmp"
  else
    config.storage = :fog
  end

  config.cache_dir = "#{Rails.root}/tmp/uploads"

  config.fog_directory = 'reporterphotos'
end
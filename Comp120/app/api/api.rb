require 'grape'

module API
  class Base < Grape::API
  	default_format :json

    mount API::Microposts => '/microposts'
    mount API::Users => '/users'

    add_swagger_documentation(
      base_path: "/api",
      hide_documentation_path: true
    )

  end
end
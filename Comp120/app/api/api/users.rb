module API
	class Users < Grape::API
		use Rack::JSONP

		def permitted_params
			@permitted_params ||= declared(params, include_missing: false)
		end

		desc 'Retrieve all users'
			get do 
				present User.all
			end

		desc 'Retrieve a specific user'
			params do
				requires :id, type: Integer, desc: "The id of the desired user"
			end
			get ':id' do
				present User.find(params[:id])
			end

		desc 'Create a new user'
			params do
				requires :first_name, type: String, desc: "The first name of the new user"
				requires :last_name, type: String, desc: "The last name of then new user"
				requires :phone_number, type: String, desc: "The new user's phone number"
				requires :email, type: String, desc: "The new user's email address"
				requires :password, type: String, desc: "The new user's password"
				requires :password_confirmation, type: String, desc: "Password-confirmation for the new user, must match original password"
				optional :department, type: String, desc: "The University department the new user is under"
				optional :admin, type: Boolean, desc: "Is the new user an administrator with special privileges? (true -> yes, false -> no)"
			end
			post do
				{ 'declared_params' => declared(params) }
			end

		desc 'Update a specific user'
			params do
				requires :id, type: Integer, desc: "The id of the user you wish to update"
				requires :first_name, type: String, desc: "Change the first name of the desired user"
				requires :last_name, type: String, desc: "Change the last name of then desired user"
				requires :phone_number, type: String, desc: "Update the desired user's phone number"
				requires :email, type: String, desc: "Update the desired user's email address"
				requires :password, type: String, desc: "Change the desired user's password"
				requires :password_confirmation, type: String, desc: "Password-confirmation for the updated password, must match new password"
				optional :department, type: String, desc: "Change the University department the desired user is under"
				optional :admin, type: Boolean, desc: "Update if the desired user is an administrator with special privileges? (true -> yes, false -> no)" 
			end
			put ':id' do
				{ 'declared_params' => declared(params) }
			end

			desc 'Delete a specific user'
				params do
					requires :id, type: Integer, desc: "The id of the user you wish to destroy"
				end
				delete ':id' do
					{ 'declared_params' => declared(params) }
				end

	end
end
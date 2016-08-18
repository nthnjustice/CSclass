module API
  class Microposts < Grape::API
    use Rack::JSONP

  	def permitted_params
  		@permitted_params ||= declared(params, include_missing: false)
		end

  desc 'Retrieve all incident reports'
    get do
      present Micropost.all
  	end

  desc 'Send a new report'
  	params do
			requires :user_id, type: Integer, desc: "Provide a valid user id number for relation"
			requires :subject, type: String, desc: "Subject line for the report"
			requires :content, type: String, desc: "Details of the report"
			requires :location, type: String, desc: "Location of the incident"
			optional :emergency, type: Boolean, desc: "Is the incident an emergency? (true -> yes, false -> no)"
			optional :open, type: Boolean, desc: "Is the report still open (not responded to)? (true -> yes, false -> no)"
			optional :picture, type: String, desc: "Picture upload url"
		end
		post do
			{ 'declared_params' => declared(params) }
		end

	desc 'Retrieve a specific report'
  	params do
  		requires :id, type: Integer, desc: "The id of the desired report"
		end
		get ':id' do
  		present	Micropost.find(params[:id])
		end

	desc 'Update a specific report'
		params do
			requires :id, type: Integer, desc: "The id of the report you wish to update"
			optional :user_id, type: Integer, desc: "Change the user id relation"
			optional :subject, type: String, desc: "Change the report subject"
			optional :content, type: String, desc: "Change the details of the report"
			optional :location, type: String, desc: "Change the location of the report"
			optional :emergency, type: Boolean, desc: "Change whether or not the incident is an emergency (true -> yes, false -> no)"
			optional :open, type: Boolean, desc: "Change whether or not the inciden thas been responded to (true -> yes, false -> no)"
			optional :picture, type: String, desc: "Change the photo upload url"
		end
		put ':id' do
			{ 'declared_params' => declared(params) }
		end

		desc 'Delete a specific report'
			params do
				requires :id, type: Integer, desc: "The id of the report you wish to destroy"
			end
		delete ':id' do
			{ 'declared_params' => declared(params) }
		end

	end
end
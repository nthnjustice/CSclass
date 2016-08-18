class MicropostsController < ApplicationController
	before_action :logged_in_user, only: [:create]
	before_action :correct_user, only: [:update]

	def show
		@micropost = Micropost.find(params[:id])
		cookies[:lat] = @micropost.location_lat
		cookies[:lng] = @micropost.location_long
	end

	def create
		@micropost = current_user.microposts.build(micropost_params)
		@micropost.location_lat = cookies[:lat]
		@micropost.location_long = cookies[:lng]
		if @micropost.save
    		flash[:success] = "Your report has been submitted."
    		redirect_to @micropost
    	else
      		render 'shared/_micropost_form'
    	end
	end

	def update
		if @micropost.update(micropost_params)
			flash[:success] = "This report has been updated."
			redirect_to @micropost
		else
			flash[:danger] = "Unsuccessful update - please provide all of the necessary information."
			redirect_to @micropost
		end
	end

	def destroy
		@micropost = Micropost.find(params[:id])
		@micropost.destroy
		flash[:success] = "The report has been deleted."
		redirect_to root_url
	end

	def resolve_micropost
		@micropost = Micropost.find(params[:report_id])
		@micropost.update_attribute(:open, false)
		flash[:success] = "This report has been marked as resolved."
		redirect_to @micropost
	end

	private

	def micropost_params
		params.require(:micropost).permit(:details, :user_id, :picture, :subject, :location, :emergency, :open, :location_lat, :location_long, :report_id)
	end

	def correct_user
    @micropost = current_user.microposts.find_by(id: params[:id])
    redirect_to root_url if @micropost.nil?
  end
  
end
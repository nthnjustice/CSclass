class StaticPagesController < ApplicationController
  def home
  	if logged_in?
  		@micropost = current_user.microposts.build
  		@feed_items = current_user.cached_feed.paginate(page: params[:page])
    else 
      redirect_to root_url
  	end
  end

  def about
  end

  def contact
  end

  def polling
    @feed_items = current_user.feed.paginate(page: params[:page])
    respond_to do |format|
      format.js 
    end
  end

  def data_visualization
    @reports = Micropost.all
  end
  
end

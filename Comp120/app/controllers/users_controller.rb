class UsersController < ApplicationController
  before_action :logged_in_user, only: [:edit, :update]
  before_action :correct_user, only: [:edit, :update]
  before_action :admin_user, only: [:index, :edit, :update, :destroy]

  def index
    if current_user.admin == true
      @users = User.paginate(page: params[:page])
    else
      flash[:danger] = "You are not authorized to view this page."
      redirect_to root_url
    end
  end

	def show
    if current_user.admin == true || current_user.id == User.find(params[:id]).id
  		@user = User.find(params[:id])
      @microposts = @user.microposts.paginate(page: params[:page])
    else
      flash[:danger] = "You are not authorized to view this page."
      redirect_to root_url
    end
	end

	def new
		@user = User.new
	end

  def create
  	@user = User.new(user_params)
  	if verify_recaptcha(model: @user) && @user.save
      log_in @user
  	  flash[:success] = "Welcome to Dutchess University's Incident Reporter!"
      redirect_to root_url
    else
      render 'new'
    end
  end

  def edit
    @user = User.find(params[:id])
  end

  def update
    @user = User.find(params[:id])
    if @user.update_attributes(user_params)
      flash[:success] = "Profile updated"
      redirect_to @user
    else
      render 'edit'
    end
  end

  def destroy
    User.find(params[:id]).destroy
    flash[:success] = "User deleted"
    redirect_to users_url
  end

  private

  def correct_user
    @user = User.find(params[:id])
    redirect_to(root_url) unless current_user?(@user)
  end

  def user_params
  	params.require(:user).permit(:first_name, :last_name, :phone_number, :email, :department, :password, :password_confirmation)
  end

  def admin_user
    redirect_to(root_url) unless current_user.admin?
  end

end

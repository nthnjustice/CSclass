class ChangePictureDefault < ActiveRecord::Migration
  def change
  	change_column_default :microposts, :picture, "empty"
  	change_column_default :microposts, :picture, nil
  end
end

class AddConstraintsToMicroposts < ActiveRecord::Migration
  def change
  	change_column_null :microposts, :content, false
  	change_column_null :microposts, :user_id, false
  	change_column_null :microposts, :subject, false
  	change_column_null :microposts, :location, false
  	change_column_null :microposts, :open, false
  	change_column_null :microposts, :emergency, false
  	change_column_default :microposts, :emergency, false
  	change_column_default :microposts, :open, true
  end
end

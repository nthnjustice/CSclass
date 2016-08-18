class AddConstraintsToUsers < ActiveRecord::Migration
  def change
  	change_column_null :users, :first_name, false
  	change_column_null :users, :last_name, false
  	change_column_null :users, :phone_number, false
  	change_column_null :users, :email, false
  	change_column_default :users, :admin, false
  end
end

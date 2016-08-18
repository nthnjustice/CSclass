class ChangeMicropostColumnName < ActiveRecord::Migration
  def change
  	rename_column :microposts, :content, :details
  end
end

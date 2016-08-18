class AddColumnsToMicroposts < ActiveRecord::Migration
  def change
  	add_column :microposts, :subject, :string
  	add_column :microposts, :location, :text
  	add_column :microposts, :emergency, :boolean
  	add_column :microposts, :open, :boolean
  	add_column :microposts, :location_lat, :decimal
  	add_column :microposts, :location_long, :decimal
  end
end

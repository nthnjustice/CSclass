class AddMoreDefaultsToMicroposts < ActiveRecord::Migration
  def change
  	change_column_default :microposts, :location_lat, 0.00
  	change_column_default :microposts, :location_long, 0.00
  end
end

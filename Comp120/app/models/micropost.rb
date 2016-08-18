class Micropost < ActiveRecord::Base
  belongs_to :user, touch: true
  default_scope -> { order(created_at: :desc) }
  mount_uploader :picture, PictureUploader
  validates :user_id, presence: true
  validates :details, presence: true, length: { maximum: 1000 }
  validates :subject, presence: true, length: { maximum: 100 }
  validates :location, presence: true, length: { maximum: 250 }
  validates :open, presence: true
  validate :picture_size

  private

  def picture_size
  	if picture.size > 5.megabytes
  		errors.add(:picture, "should be less than 5MB")
  	end
  end
end

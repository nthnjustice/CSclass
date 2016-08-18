# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)
User.create!(first_name: "Nathan", last_name: "Justice", phone_number: 123456789, email: "nathan.justice@dutchess.edu", department: "Biology", password: "password", password_confirmation: "password", admin: true)
User.create!(first_name: "Eric", last_name: "Snyder", phone_number: 123456789, email: "eric.snyder@dutchess.edu", department: "Engineering", password: "password", password_confirmation: "password", admin: true)
User.create!(first_name: "Luke", last_name: "Johnson", phone_number: 123456789, email: "luke.johnson@dutchess.edu", department: "Computer Science", password: "password", password_confirmation: "password", admin: true)

User.create!(first_name: "Bob", last_name: "Ross", phone_number: 123456789, email: "bob.ross@dutchess.edu", department: "Art", password: "password", password_confirmation: "password")

Micropost.create!(details: "Hazardous stuff everywhere...", user_id: 1, subject: "Chemical Spill", location: "Pearson", emergency: true, open: true, location_lat: 42.404781, location_long: -71.120336)
Micropost.create!(details: "I need Cadmium Yellow.", user_id: 4, subject: "Out of Paint", location: "Aidekman", emergency: false, location_lat: 42.404372, location_long: -71.118803)
Micropost.create!(details: "Dewick, make my dreams come true.", user_id: 2, subject: "No cheesy eggs :(", location: "Dewick", emergency: false, open: true, location_lat: 42.405193, location_long: -71.121287)
Micropost.create!(details: "I'm deep in the depths of hell!", user_id: 3, subject: "Lost in the stacks", location: "Tisch", emergency: true, location_lat: 42.405837, location_long: -71.119067)
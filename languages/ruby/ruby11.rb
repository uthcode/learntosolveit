require "open-uri"

open("http://www.uthcode.com") do |lost|
    puts lost.read
end

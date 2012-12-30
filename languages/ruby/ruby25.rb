begin
  puts "Hello, world!"
  1/0
rescue => e
  puts e
  puts "rescue"
else
  puts "else"
ensure
  puts "ensure"
end

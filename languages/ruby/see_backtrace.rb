def a
  raise "boom"
end

def b
  a()
end

begin
  b()
rescue => detail
  print detail.backtrace.join("\n")
end

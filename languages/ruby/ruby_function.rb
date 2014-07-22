module RubyModule
    def rubyfunction(num)
        puts "within rubyfunction"
        puts num
    end
    module_function :rubyfunction
end

class NewTypeError < ArgumentError
end

def inverse(x)
    begin
        raise NewTypeError, 'Argument is not numeric' unless x.is_a? Numeric
    rescue SecurityError =>e
        puts "it is a security error"
    rescue ArgumentError => e
        puts e.message
        puts e.backtrace.inspect
    end
end

inverse(2)
inverse('not a number')

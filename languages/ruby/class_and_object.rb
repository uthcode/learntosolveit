class Rectangle
    def initialize(length, breadth)
        @length = length
        @breadth = breadth
    end

    def perimeter
        2 * (@length + @breadth)
    end

    def area
        @length * @breadth
    end
end

rect = Rectangle.new(10,
                     20)

# In ruby, you initialize an object using the new method
#
puts rect.perimeter
puts rect.area

module Debug
  def whoAmI?
    "#{self.type.name} (\##{self.id}): #{self.to_s}"
  end
end
class Phonograph
  include Debug

  def initialize(title)
    @title = title
  end
  def type
    self.class
  end
  def id
    self.object_id
  end
  def to_s
    @title
  end
end
class EightTrack
  include Debug
  
  def initialize(title)
    @title = title
  end
  
  def type
    self.class
  end
  
  def id
    self.object_id
  end
  
  def to_s
    @title
  end
end

ph = Phonograph.new("West End Blues")
et = EightTrack.new("Surrealistic Pillow")
p ph.whoAmI?
p et.whoAmI?

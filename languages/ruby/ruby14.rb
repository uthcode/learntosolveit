module Debug
  def whoAmI?
    "#{self.type.name} (\##{self.id}): #{self.to_s}"
  end
end
class Phonograph
  include Debug
  # ...
end
class EightTrack
  include Debug
  # ...
end

# Gives ArgumentError - Has something happened in the Ruby version?

ph = Phonograph.new("West End Blues")
et = EightTrack.new("Surrealistic Pillow")
p ph.whoAmI?
p et.whoAmI?

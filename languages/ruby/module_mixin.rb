# Ruby module Mixin example.

module Debug
  def whoAmI?
    "#{self.type.name} (\##{self.id}): "
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
ph = Phonograph.new
et = EightTrack.new
ph.whoAmI? #»   "Phonograph (#537766170): West End Blues"
et.whoAmI? #»   "EightTrack (#537765860): Surrealistic Pillow"

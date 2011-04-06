class Set():
    def new(self):
        self.elements = []
        return self
    def add(self, e):
        if e not in self.elements:
            self.elements.append(e)
    def remove(self, e):
        if e in self.elements:
            for i in range(len(self.elements)):
                if self.elements[i] = e:
                    del self.elements[i]
                    break
    def is_element(self, e):
        return e in self.elements
    def size(self):
        return len(self.elements)

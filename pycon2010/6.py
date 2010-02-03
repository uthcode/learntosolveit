# Example of String Template method
import string

# make a template from  string where some identifiers are marked with $

template = string.Template('this is a $template')
print template.substitute({'template':5})
print template.substitute({'template':'five'})

# even keyword arguments is possible

print template.substitute(template=5)
print template.substitute(template='five')


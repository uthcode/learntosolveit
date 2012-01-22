source = "import os;print os.listdir(os.getcwd())"
obj = compile(source,'<string>','exec')
eval(obj)
exec(obj)
